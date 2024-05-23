#include <stdio.h>
#include <conio.h>
int request[100];
int findMin(int head, int len){
	int result = 0, min = 1000, diff, idx = 0, i;
	for(i = 0;i < len;i++){
		if(head > request[i])
			diff = head - request[i];
		else
			diff = request[i] - head;
		if(min > diff){
			min = diff;
			idx = i;
		}
	}
	result = request[idx];
	request[idx] = 1000;
	return result;

}
void main(){
	int noOfRequest, head, i, diff, seek = 0, rtnMinVal;
	float avgSeek;
	printf("Enter the Number Of Requests : ");
	scanf("%d", &noOfRequest);
	printf("Enter the Requests One by One : ");
	for(i = 0;i < noOfRequest;i++)
		scanf("%d", &request[i]);
	printf("Enter the Head Pointer : ");
	scanf("%d", &head);
	for(i = 0;i < noOfRequest;i++){
		rtnMinVal = findMin(head, noOfRequest);
		if(rtnMinVal > head)
			diff = rtnMinVal - head;
		else
			diff = head - rtnMinVal;
		head = rtnMinVal;
		seek = seek + diff;
	}
	avgSeek = (float)seek / noOfRequest;
	printf("The Average Seek time is %.2f", avgSeek);
	getch();
}