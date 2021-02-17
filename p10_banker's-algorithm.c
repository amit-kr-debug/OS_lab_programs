#include <stdio.h>

struct proc
{
  int alc[10];
  int max[10];
  int need[10];
  int flag;
};

int main()
{
  struct proc p[10];
  int avail[10];
  int i, j, n, r, seq[100];

  printf("Enter number of processes -- ");
  scanf("%d", &n);
  printf("Enter number of resources -- ");
  scanf("%d", &r);

  for (i = 0; i < n; i++)
  {
    printf("Enter details for P%d", i);
    printf("\nEnter allocation\t -- \t");
    for (j = 0; j < r; j++)
    {
      scanf("%d", &p[i].alc[j]);
    }

    printf("Enter Max\t\t -- \t");
    for (j = 0; j < r; j++)
      scanf("%d", &p[i].max[j]);
    p[i].flag = 0;
  }
  printf("\nEnter Available Resources\t -- \t");
  for (i = 0; i < r; i++)
    scanf("%d", &avail[i]);

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < r; j++)
    {
      p[i].need[j] = p[i].max[j] - p[i].alc[j];
      if (p[i].need[j] < 0)
        p[i].need[j] = 0;
    }
  }

  int count = 0, iterator = 0, all_avail = 0, safe_state;
  while (count != n)
  {
    safe_state = 0;
    for (i = 0; i < n; i++)
    {
      if (p[i].flag == 0)
      {
        all_avail = 0;
        for (j = 0; j < n; j++)
        {
          if (avail[j] >= p[i].need[j])
            all_avail += 1;
          else
            all_avail -= 1;
        }

        if (all_avail == r)
        {
          printf("\nP%d is visited", i);
          seq[iterator++] = i;
          p[i].flag = 1;
          printf("(");
          for (j = 0; j < r; j++)
          {
            avail[j] = avail[j] + p[i].alc[j];
            printf(" %d", avail[j]);
          }
          printf(")");

          count++;
          safe_state = 1;
        }
      }
    }
    if (safe_state == 0)
    {
      printf("\n REQUEST NOT GRANTED -- DEADLOCK OCCURRED");
      printf("\n SYSTEM IS IN UNSAFE STATE");
      goto label1;
    }
  }
  printf("\nSYSTEM IS IN SAFE STATE");
  printf("\nThe Safe Sequence is -- (");
  for (i = 0; i < iterator; i++)
    printf("P%d ", seq[i]);
  printf(")");

label1:
  printf("\nProcess\t\tAllocation\t\tMax\t\t\tNeed\n");
  for (i = 0; i < n; i++)
  {
    printf("P%d\t", i);
    for (j = 0; j < r; j++)
      printf("%6d", p[i].alc[j]);
    for (j = 0; j < r; j++)
      printf("%6d", p[i].max[j]);
    for (j = 0; j < r; j++)
      printf("%6d", p[i].need[j]);
    printf("\n");
  }

  return 0;
}
