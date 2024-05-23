#include <stdio.h>
#include <conio.h>

void main(){
	int pageString[100], frames[100], noOfFrames, i, idx = 0, len, flag, j;
	printf("Enter the Number of frames : ");
	scanf("%d", &noOfFrames);
	for(i = 0;i < noOfFrames;i++){
		frames[i] = -1;
	}
	printf("Enter the length of the Page String : ");
	scanf("%d", &len);
	printf("Enter the Page String : ");
	for(i = 0;i < len;i++){
		scanf("%d", &pageString[i]);
	}
	for(i = 0;i < len;i++){
		flag = 0;
		for(j = 0;j < noOfFrames;j++){
			printf("%d | ",frames[j]);
			if(pageString[i] == frames[j]){
				flag = 1;
				break;
			}
		}
		printf("\n");
		if(flag == 0){
			frames[idx] = pageString[i];
			idx = (idx + 1) % noOfFrames;
		}
	}
	for(i = 0;i < noOfFrames;i++)
		printf("%d | ",frames[i]);
	getch();
}