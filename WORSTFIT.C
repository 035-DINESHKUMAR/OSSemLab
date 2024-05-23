#include <stdio.h>
#include <conio.h>
int memSpaces[100], finished[100];
void findMax(int memLen, int value, int idx){
	int i, j, max = 0, index;
	for(i = 0;i < memLen;i++){
		if(max < memSpaces[i]){
			max = memSpaces[i];
			index = i;
		}
	}
	if(value < max){
		finished[idx] = 1;
		memSpaces[index] = memSpaces[index] - value;
	}else{
		printf("The Memory for the process %d is can't be allocated due to insufficient Memory", idx);
	}
}
void main(){
	int i, j, noOfMemorySpaces, reqMemory[100];
	int remSpaces = 0, noOfReqMemory;
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
		findMax(noOfMemorySpaces, reqMemory[i], i);
	}
	for(i = 0;i < noOfMemorySpaces;i++){
		remSpaces = remSpaces + memSpaces[i];
	}
	printf("The Total of Remaining Space is %d", remSpaces);
   getch();
}