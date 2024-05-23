//no of files, startAddress, capacity array, no of blocks, fileblock array= {1}
#include <stdio.h>
#include <conio.h>
void main(){
	int noOfFiles, startAdd[100], capacity[100], noOfBlocks;
	int fileBlock[100], i, j, cnt, totSize;
	clrscr();
	printf("\nEnter the Number of Files : ");
	scanf("%d", &noOfFiles);
	for(i = 0;i < noOfFiles;i++){
		printf("Enter the Starting Address of the File %d : ", i);
		scanf("%d", &startAdd[i]);
		printf("Enter the Capacity of the File %d : ", i);
		scanf("%d", &capacity[i]);
	}
	printf("Enter the Number Of Blocks : ");
	scanf("%d", &noOfBlocks);
	for(i = 0;i < noOfBlocks;i++)
		fileBlock[i] = 1;
	for(i = 0;i < noOfFiles;i++){
		cnt = 0;
		totSize = startAdd[i] + capacity[i];
		for(j = startAdd[i];j < totSize && j < noOfBlocks;j++){
			if(fileBlock[j] != 0){
				fileBlock[j] = 0;
				cnt++;
			}
		}
		if(cnt != capacity[i]){
			printf("\nThe File %d can't be allocated because the blocks are already occupied\n", i);
		}
		else{
			printf("\nThe File %d is allocated in the blocks in the following blocks\n", i);
			for(j = startAdd[i];j < totSize;j++)
				printf("%d ", j);
		}
	}
	getch();
}