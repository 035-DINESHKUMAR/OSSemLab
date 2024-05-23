#include <stdio.h>
#include <conio.h>
void main(){
	int i, j, noOfMemorySpaces, memSpaces[100], reqMemory[100];
	int remSpaces = 0, noOfReqMemory, finished[100], cnt = 0, idx = 0;
	printf("\nEnter the Number of Spaces Available : ");
	scanf("%d", &noOfMemorySpaces);
	printf("Enter the Memory Spaces Available : ");
	for(i = 0;i < noOfMemorySpaces;i++)
		scanf("%d", &memSpaces[i]);
	printf("Enter the Number of Request Memory Spaces : ");
	scanf("%d", &noOfReqMemory);
	printf("Enter the Request Memory Spaces : ");
	for(i = 0;i < noOfReqMemory;i++){
		scanf("%d", &reqMemory[i]);
		finished[i] = 0;
	}
	for(i = 0;i < noOfReqMemory;i++){
		for(j = 0;j < noOfMemorySpaces;j++){
			if(reqMemory[i] < memSpaces[j] && finished[i] != 1){
				finished[i] = 1;
				memSpaces[j] = memSpaces[j] - reqMemory[i];
			}
		}
	}
	for(i = 0;i < noOfReqMemory;i++){
		if(finished[i] == 1)
			cnt++;
	}
	if(cnt != noOfReqMemory){
		for(i = 0;i < noOfReqMemory;i++){
			if(finished[i] == 0)
				idx = i;
		}
		printf("The Memory for the process %d is can't be allocated due to insufficient Memory", idx);
		for(i = 0;i < noOfMemorySpaces;i++){
			remSpaces = remSpaces + memSpaces[i];
		}
		printf("The Total of Remaining Space is %d", remSpaces);
	}
	else{
		for(i = 0;i < noOfMemorySpaces;i++){
			remSpaces = remSpaces + memSpaces[i];
		}
		printf("The Total of Remaining Space is %d", remSpaces);
	}
	getch();
}