#include <stdio.h>

int main()
{
  int tm, bs, process = 0, process_size[10];
  printf("MFT\n");
  printf("Enter the total memory available\n");
  scanf("%d", &tm);
  printf("Enter block size\n");
  scanf("%d", &bs);
  printf("Enter num of processes\n");
  scanf("%d", &process);
  int tm_cp = tm;
  char ch = 'y';
  int num_block = tm / bs;

  for (int i = 0; i < process; i++)
  {
    printf("Enter memory required for process %d\n", i + 1);
    scanf("%d", &process_size[i]);
  }

  int allocate = 0;
  printf("Pid \tmr\t Al\tINTERNAL FRAGMENTATION\n");
  while (num_block != 0 && allocate <= process)
  {
    if (process_size[allocate] > bs)
    {
      printf("%d\t %d\t NO\t ----\n", allocate + 1, process_size[allocate]);
    }

    else
    {
      printf("%d\t %d\t YES\t %d\n", allocate + 1, process_size[allocate], bs - process_size[allocate]);
      num_block -= 1;
    }

    allocate++;
  }

  if (num_block == 0)
  {
    printf("Memory FULL\n");
  }
  return 0;
}
