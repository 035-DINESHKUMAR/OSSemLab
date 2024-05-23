#include <stdio.h>
#include <conio.h>
int findIndex(int frames[], int framesLen, int pageString[], int startIndex){
	int result = 0, findPage[100], cnt = 0, i ,j;
	for(i = 0;i < framesLen;i++)
		findPage[i] = 0;
	for(i = startIndex;i >= 0;i--){
		for(j = 0;j < framesLen;j++){
			if(pageString[i] == frames[j]){
				findPage[j] = 1;
				cnt++;
				break;
			}
		}
		if(cnt == framesLen - 1){
			for(j = 0;j < framesLen;j++){
				if(findPage[j] == 0){
					result = j;
					break;
				}
			}
			break;
		}
	}
	return result;
}
void main(){
	int i, j, frames[100], noOfFrames, pageString[100], len, idx = 0, flag, rtnIndex = 0;
	printf("Enter the Number of Frames : ");
	scanf("%d", &noOfFrames);
	for(i = 0;i < noOfFrames;i++)
		frames[i] = -1;
	printf("Enter the Length of the Page String : ");
	scanf("%d", &len);
	printf("Enter the Page String : ");
	for(i = 0;i < len; i++)
		scanf("%d", &pageString[i]);
	for(i = 0;i < len;i++){
		flag = 0;
		for(j = 0;j < noOfFrames;j++){
			printf("%d | ",frames[j]);
			if(pageString[i] == frames[j]){
				flag = 1;
				break;
			}
			printf("\n");
		}
		if(flag == 0){
			if(i == 0 || i == 1 || i == 2){
				frames[idx] = pageString[i];
				idx = (idx + 1) % noOfFrames;
			}else{
				rtnIndex = findIndex(frames, noOfFrames, pageString, i);
				frames[rtnIndex] = pageString[i];
			}
		}
	}
	printf("The Final Page in the Frames is : \n");
	for(i = 0;i < noOfFrames;i++)
		printf("%d | ", frames[i]);
	getch();
}