#include <stdio.h>

int main()
{
  int bt[] = {10, 6, 7, 12};
  int pid[] = {1, 2, 3, 4};
  int bt_c[10], tat[10], wt[10];
  int quantumT = 3;
  int n = 4;
  int i, j, elapsed_t = 0, maxbt = 0;

  float avg_wt, avg_tat;

  for (i = 0; i < n; i++)
  {
    bt_c[i] = bt[i];
    if (maxbt < bt[i])
      maxbt = bt[i];
  }
  //printf("%d\n", maxbt);

  for (i = 0; i < (maxbt / quantumT) + 1; i++)
  {
    for (j = 0; j < n; j++)
    {
      //printf("%d\t%d\t%d\n", elapsed_t, bt[j], j);
      if (bt[j] != 0)
      {
        if (bt[j] <= quantumT)
        {
          elapsed_t += bt[j];
          tat[j] = elapsed_t;
          bt[j] = 0;
        }
        else
        {
          bt[j] -= quantumT;
          elapsed_t += quantumT;
        }
      }
    }
  }

  for (i = 0; i < n; i++)
  {
    wt[i] = tat[i] - bt_c[i];
    avg_wt += wt[i];
    avg_tat += tat[i];
  }

  printf("Round Robin\npid\tbt\ttat\twt\t\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t%d\t%d\t%d\n", pid[i], bt_c[i], tat[i], wt[i]);
  }
  printf("average turn around time = %.2f\n", avg_tat / n);
  printf("average wait time = %.2f\n", avg_wt / n);
}
