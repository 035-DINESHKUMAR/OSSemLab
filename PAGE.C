#include <stdio.h>
#include <conio.h>
void main(){
	int noOfPages, frames[100], page, offset, i;
	printf("\nEnter the Number of Frames : ");
	scanf("%d", &noOfPages);
	printf("Enter the Page Number and Frame Number(If Frame is not present mention as -1) : ");
	for(i = 0;i < noOfPages;i++){
		printf("%d\t", i);
		scanf("%d", &frames[i]);
	}
	printf("Enter the Logical Address(Page Number and Offset) : ");
	scanf("%d %d", &page, &offset);
	if(page >= noOfPages || frames[page] == -1){
		printf("Page Fault : Page is not found");
	}else{
		printf("Physical Address : %d %d", frames[page], offset);
	}
	getch();
}