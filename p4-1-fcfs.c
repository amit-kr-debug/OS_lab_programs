#include <stdio.h>
#include <stdlib.h>

void sort(int arr1[], int arr2[], int arr3[], int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr1[j] > arr1[j + 1])
			{
				temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;

				temp = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = temp;

				temp = arr3[j];
				arr3[j] = arr3[j + 1];
				arr3[j + 1] = temp;
			}
		}
	}
}

float calculate_wt_ct(int at[], int bt[], int pid[], int wt[], int ct[], int n)
{
	wt[0] = at[0];
	ct[0] = at[0] + bt[0];
	float avg_wt = 0;
	for (int i = 1; i < n; i++)
	{
		wt[i] = ct[i - 1] - at[i];
		if (wt[i] < 0)
			wt[i] = 0;
		ct[i] = ct[i - 1] + bt[i];
		avg_wt += wt[i];
	}
	return (float)avg_wt / n;
}

float calculate_tat(int ct[], int at[], int tat[], int n)
{
	float avg_tat = 0;
	for (int i = 0; i < n; i++)
	{
		tat[i] = ct[i] - at[i];
		avg_tat += tat[i];
	}
	return (float)avg_tat / n;
}

int main()
{
	/**
	 pid => process id
	 bt => burst time
	 at => arrival time
	 tat => turn around time
	 wt => wait time
	 ct => completion time
	 **/
	int pid[] = {1, 2, 3, 4, 5, 6};
	int bt[] = {4, 5, 1, 2, 4, 5};
	int at[] = {3, 4, 2, 0, 5, 6};
	int n = 6;
	int wt[n], wat[n], tat[n], ct[n];
	float avg_tat, avg_wt;

	sort(at, bt, pid, n);
	//printf("%d %d %d %d",at[0],at[1],at[2],at[3]);
	avg_wt = calculate_wt_ct(at, bt, pid, wt, ct, n);
	avg_tat = calculate_tat(ct, at, tat, n);

	printf("FCFS\npid\tat\tbt\tct\ttat\twt\t\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
	}
	return 0;
}
