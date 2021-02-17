#include<stdio.h>
#include<unistd.h>

int main(){
int process_id = getpid();
int parent_id = getppid();
printf("process id:=>\t%d\n",process_id);
printf("parent id:=>\t%d\n",parent_id);
return 0;}

