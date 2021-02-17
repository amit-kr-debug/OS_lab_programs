#include <stdio.h>

int main()
{
  int tm, process = 0, process_size[10];
  printf("MVT\n");
  printf("Enter the total memory available\n");
  scanf("%d", &tm);
  int tm_cp = tm;
  char ch = 'y';
  do
  {
    process++;
    printf("Enter memory required for process %d\n", process);
    scanf("%d", &process_size[process]);
    if (process_size[process] < tm)
    {
      tm -= process_size[process];
    }
    else
    {
      printf("Memory is Full");
      break;
    }
    printf("\nDo you want to continue(y/n) -- ");
    scanf(" %c", &ch);
  } while (ch == 'y');

  printf("Total memory %d\n", tm_cp);
  printf("Pid\tmemory\n");
  for (int i = 1; i <= process; i++)
  {
    printf("%d\t%d\n", i, process_size[i]);
  }
  return 0;
}
