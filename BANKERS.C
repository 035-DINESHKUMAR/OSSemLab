#include <stdio.h>
#include <conio.h>

void main(){
	int alloc[100][100], max[100][100], need[100][100], avail[100];
	int finished[100], p, r, res[100], flag, i, j, k, cnt = 0;
	int terminate = 0, val, safe[100];
	printf("\nEnter the Number of process : ");
	scanf("%d", &p);
	printf("Enter the Number of Resources : ");
	scanf("%d", &r);
	printf("Enter the Resuorce Copies\n");
	for(i = 0;i < r;i++){
		printf("Resuorce[%d] : ", i + 1);
		scanf("%d", &res[i]);
	}
	printf("\nEnter the Allocation Matrix\n");
	for(i = 0;i < p;i++){
		for(j = 0;j < r;j++){
			printf("Enter the Alloc[%d][%d] : ", i + 1, j + 1);
			scanf("%d", &alloc[i][j]);
		}
		finished[i] = 0;
		safe[i] = 0;
	}
	printf("\nEnter the Maximum Matrix\n");
	for(i = 0;i < p;i++){
		for(j = 0;j < r;j++){
			printf("Enter the Max[%d][%d] : ", i + 1, j + 1);
			scanf("%d", &max[i][j]);
		}
	}
	printf("\nNeed Matrix\n");
	for(i = 0;i < p;i++){
		for(j = 0;j < r;j++){
			need[i][j] = max[i][j] - alloc[i][j];
			printf("Need[%d][%d] : %d", i + 1, j + 1, need[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	printf("\nAvailable Matrix\n");
	for(i = 0;i < r;i++){
		val = 0;
		for(j = 0;j < p;j++){
			val += alloc[j][i];
		}
		avail[i] = res[i] - val;
		printf("%d | ", avail[i]);
	}
	while(cnt < p){
		for(i = 0;i < p;i++){
			if(finished[i] != 1){
				flag = 1;
				for(j = 0;j < r;j++){
					if(need[i][j] > avail[j]){
						flag = 0;
						break;
					}
				}
				if(flag == 1){
					finished[i] = 1;
					safe[cnt] = i + 1;
					for(j = 0;j < r;j++)
						avail[j] = avail[j] + alloc[i][j];
					cnt++;
					terminate = 0;
				}
				else{
					terminate++;
				}
			}
		}
		if(terminate == p - 1){
			printf("Processes can't be executed in safe sequence\n");
			break;
		}
	}
	if(terminate != p - 1){
		printf("\nSafe Sequence\n");
		for(i = 0;i < p;i++)
			printf("%d-> ", safe[i]);
	}
	getch();
}