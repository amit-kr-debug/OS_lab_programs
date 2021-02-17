#include <stdio.h>
#include <stdlib.h>

int mutex = 0, full = 0, empty = 3, item = 0;

int wait(int s)
{
  return --s;
}

int signal(int s)
{
  return ++s;
}

void producer()
{
  mutex = wait(mutex);
  full = signal(full);
  empty = wait(empty);
  item++;
  printf("Producer has produced item no %d\n", item);
  mutex = signal(mutex);
}

void consumer()
{
  mutex = wait(mutex);
  full = wait(full);
  empty = signal(empty);
  printf("Producer has produced item no %d\n", item);
  item--;
  mutex = signal(mutex);
}

int main()
{
  int n;
  while (1)
  {
    printf("\n1.producer\n2.consumer\n3.exit\n");
    printf("Select any one of the above\n");
    scanf("%d", &n);
    printf("%d", empty);
    switch (n)
    {
    case 1:
      if (mutex == 0 && empty != 0)
      {
        producer();
      }
      else
      {
        printf("Buffer is full\n");
      }
      break;
    case 2:
      if (mutex == 0 && full != 0)
      {
        consumer();
      }
      else
      {
        printf("Buffer is empty\n");
      }
      break;
    case 3:
      exit(0);
      break;
    default:
      printf("Not a vaild input! Try again\n");
      break;
    }
  }

  return 0;
}
