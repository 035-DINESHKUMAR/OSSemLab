#include <stdio.h>
#include <conio.h>

void main(){
	int request[100], noOfRequest, head, seek = 0, diff, i;
	float avgSeek;
	printf("Enter the Number of Request : ");
	scanf("%d", &noOfRequest);
	printf("Enter the Request One by One : ");
	for(i = 0;i < noOfRequest;i++)
		scanf("%d", &request[i]);
	printf("Enter the head pointer : ");
	scanf("%d", &head);
	for(i = 0;i < noOfRequest;i++){
		if(head > request[i])
			diff = head - request[i];
		else
			diff = request[i] - head;
		head = request[i];
		seek = seek + diff;
	}
	avgSeek = (float)seek / noOfRequest;
	printf("The Average Seek Time is %.2f", avgSeek);
	getch();
}