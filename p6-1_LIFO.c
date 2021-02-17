#include <stdio.h>

int main()
{
  printf("LIFO");
  int pages = 20,
      page[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1},
      frame[10],
      frames = 3;

  int i, j, k, flag, pf = 0, count = 0;

  for (i = 0; i < frames; i++)
  {
    frame[i] = -1;
  }

  for (i = 0; i < pages; i++)
  {
    flag = 0;
    for (j = 0; j < frames; j++)
    {
      if (page[i] == frame[j])
      {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
    {
      frame[count] = page[i];
      count += 1;
      pf++;
    }
    if (count == frames)
    {
      count = 0;
    }
    for (j = 0; j < frames; j++)
    {
      printf("%d ", frame[j]);
    }

    if (flag == 0)
    {
      printf("Page fault occured %d", pf);
    }

    printf("\n");
  }
  return 0;
}
