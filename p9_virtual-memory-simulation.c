#include <stdio.h>

int main()
{
  int memory_size, page_size, totalPages, process, process_pages[100];
  int page_table[100][100];
  printf("\nEnter the memory size -- ");
  scanf("%d", &memory_size);

  printf("\nEnter the page size -- ");
  scanf("%d", &page_size);

  totalPages = memory_size / page_size;
  printf("\nThe no. of pages available in memory are -- %d ", totalPages);

  printf("\nEnter number of processes -- ");
  scanf("%d", &process);

  int i = 0;
  for (i = 0; i < process; i++)
  {
    printf("Enter the number of pages required for process %d ", i + 1);
    scanf("%d", &process_pages[i]);
    if (process_pages[i] > totalPages)
    {
      printf("\nMemory is Full\n");
      break;
    }
    else
    {
      totalPages -= process_pages[i];
      printf("\nEnter pagetable for process %d --- ", i + 1);
      for (int j = 0; j < process_pages[i]; j++)
        scanf("%d", &page_table[i][j]);
    }
  }

  int p, pageno, offset;
  printf("\nEnter Logical Address to find Physical Address ");
  printf("\nEnter process no. and pagenumber and offset -- ");
  scanf("%d %d %d", &p, &pageno, &offset);

  if (p > process || pageno >= process_pages[p] || offset >= page_size)
  {
    printf("invalid\n %d\t %d\t%d\t%d\t%d\t%d\t ", p, process, pageno, process_pages[p], offset, page_size);
  }
  else
  {
    int pa;
    pa = page_table[p - 1][pageno] * page_size + offset;
    printf("\nThe Physical Address is -- %d", pa);
  }
  return 0;
}
