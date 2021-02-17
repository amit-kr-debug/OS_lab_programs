#include <stdio.h>

int main(void)
{
  int file[] = {40, 20, 500, 30, 30, 10};
  int partition[] = {60, 20, 50, 10};
  int flag;
  int len_file = 6;
  int len_partition = 4;

  for (int i = 0; i < len_file; i++)
  {
    flag = 0;
    for (int j = 0; j < len_partition; j++)
    {
      if (file[i] <= partition[j])
      {
        partition[j] -= file[i];
        printf("file %d is allocated to partition %d and after fragmentation available size is %d\n", i + 1, j + 1, partition[j]);
        flag = 1;
        break;
      }
    }
    if (flag == 0)
    {
      printf("Couldn't allocate any partition for file %d\n", i + 1);
    }
  }

  for (int i = 0; i < len_partition; i++)
  {
    printf("Partition %d available =>\t %d\n", i + 1, partition[i]);
  }

  return 0;
}
