#include <stdio.h>
#include <conio.h>
int wt[100], tat[100];
void PRIORITY(int pro[], int bt[], int prior[], int len){
	int i, j, tot_Waiting_Time, tot_Turn_Around_Time, t1, t2, t3;
	float avg_Waiting_Time, avg_Turn_Around_Time;
	for(i = 0;i < len;i++){
		for(j = i + 1;j < len;j++){
			if(prior[i] > prior[j]){
				t1 = prior[i];
				prior[i] = prior[j];
				prior[j] = t1;
				t2 = bt[i];
				bt[i] = bt[j];
				bt[j] = t2;
				t3 = pro[i];
				pro[i] = pro[j];
				pro[j] = t3;
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
	printf("Process\tWaiting Time\tBurst Time\tPriority\n");
	for(i = 0;i < len;i++){
		printf("%d\t%d\t\t%d\t\t%d", pro[i], wt[i], bt[i], prior[i]);
		printf("\n");
	}
	avg_Waiting_Time = (float)tot_Waiting_Time / len;
	avg_Turn_Around_Time = (float)tot_Turn_Around_Time / len;
	printf("The Average Waiting time is %.2f", avg_Waiting_Time);
	printf("\nThe Average Turn Around Time is %.2f", avg_Turn_Around_Time);

}
void main(){
	int burstArr[100], process[100], i, noOfProcess, priority[100];
	printf("\nEnter the Number of Processes : ");
	scanf("%d", &noOfProcess);
	for(i = 0;i < noOfProcess;i++){
		process[i] = i + 1;
		printf("Enter the Burst time for Process %d : ",process[i]);
		scanf("%d", &burstArr[i]);
		printf("Enter the Priority for Process %d : ",process[i]);
		scanf("%d", &priority[i]);
	}
	PRIORITY(process, burstArr, priority, noOfProcess);
	getch();
}