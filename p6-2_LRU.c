#include <stdio.h>

int main()
{
  printf("LRU\n");
  int pages = 20,
      page[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1},
      frame[10],
      frames = 3,
      lru[10];

  int i, j, k, flag, pf = 0, count = 0, next = 1, min_lru, index;

  for (i = 0; i < frames; i++)
  {
    frame[i] = -1;
  }

  for (i = 0; i < pages; i++)
  {
    flag = 0;
    if (i < frames)
    {
      frame[i] = page[i];
      lru[i] = next++;
      pf++;
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
    else
    {
      for (j = 0; j < frames; j++)
      {
        if (page[i] == frame[j])
        {
          flag = 1;
          lru[j] = next++;

          break;
        }
      }
      if (flag == 0)
      {
        pf++;
        min_lru = 10000;
        index = -1;
        for (j = 0; j < frames; j++)
        {
          if (lru[j] < min_lru)
          {
            min_lru = lru[j];
            index = j;
          }
        }
        frame[index] = page[i];
        lru[index] = next++;
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
  }

  return 0;
}
