#include <stdio.h>
#include <conio.h>
int wt[100], tat[100];
void SJF(int pro[], int bt[], int len){
	int tot_Waiting_Time = 0, tot_Turn_Around_Time = 0, i, j, t1, t2;
	float avg_Waiting_Time, avg_Turn_Around_Time;
	for(i = 0;i < len;i++){
		for(j = i + 1;j < len;j++){
			if(bt[i] > bt[j]){
				t1 = bt[i];
				bt[i] = bt[j];
				bt[j] = t1;
				t2 = pro[i];
				pro[i] = pro[j];
				pro[j] = t2;
			}
		}
	}
	wt[0] = 0;
	for(i = 1;i < len;i++){
		wt[i] = wt[i - 1] + bt[i - 1];
		tot_Waiting_Time = tot_Waiting_Time + wt[i];
	}
	for(i = 0;i < len;i++){
		tat[i] = wt[i] + bt[i];
		tot_Turn_Around_Time = tot_Turn_Around_Time + tat[i];
	}
	printf("Process\tWaiting Time\tBurst Time\n");
	for(i = 0;i < len;i++){
		printf("%d\t%d\t%d", pro[i], wt[i], bt[i]);
		printf("\n");
	}
	avg_Waiting_Time = (float)tot_Waiting_Time / len;
	avg_Turn_Around_Time = (float)tot_Turn_Around_Time / len;
	printf("The Average Waiting time is %.2f", avg_Waiting_Time);
	printf("\nThe Average Turn Around Time is %.2f", avg_Turn_Around_Time);

}
void main(){
	int burstArr[100], process[100], i, noOfProcess;
	printf("\nEnter the Number of Processes : ");
	scanf("%d", &noOfProcess);
	for(i = 0;i < noOfProcess;i++){
		process[i] = i + 1;
		printf("Enter the Burst time for Process %d : ",process[i]);
		scanf("%d", &burstArr[i]);
	}
	SJF(process, burstArr, noOfProcess);
	getch();
}