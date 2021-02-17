#include <stdio.h>

int main(void)
{
  int file[] = {40, 20, 500, 30, 30, 10};
  int partition[] = {60, 20, 50, 10};
  int min_sep, best_index;
  int len_file = 6;
  int len_partition = 4;

  for (int i = 0; i < len_file; i++)
  {
    min_sep = 1000000;
    best_index = -1;
    for (int j = 0; j < len_partition; j++)
    {
      if (partition[j] - file[i] < min_sep && partition[j] - file[i] >= 0)
      {
        min_sep = partition[j] - file[i];
        best_index = j;
      }
    }
    if (best_index == -1)
    {
      printf("Couldn't allocate partition for file %d\n", i + 1);
    }
    else
    {
      partition[best_index] -= file[i];
      printf("file %d is allocated to partition %d and after fragmentation available size is %d\n", i + 1, best_index + 1, partition[best_index]);
    }
  }

  for (int i = 0; i < len_partition; i++)
  {
    printf("Partition %d available =>\t %d\n", i + 1, partition[i]);
  }

  return 0;
}
