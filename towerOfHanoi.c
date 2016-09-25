#include<stdio.h>
/*
	1.define number of disk 1-6 from smallest to biggest
	2.define peg name "A B C" from left to right
*/
void hanoi(int diskNumber,char sourcePeg[],char destinationPeg[],char auxillaryPeg[])
{
	if(diskNumber==1) //the smallest disk can move from source to destination instantly.
	{
		printf("Move disk number 1 from %s to %s\n",sourcePeg,destinationPeg);
	}
	else
	{
		hanoi(diskNumber-1,sourcePeg,auxillaryPeg,destinationPeg);
		//move smaller disk above this disk to auxillary peg before move this disk to destination disk
		printf("Move disk number %d from %s to %s\n",diskNumber,sourcePeg,destinationPeg);//move this disk
		hanoi(diskNumber-1,auxillaryPeg,destinationPeg,sourcePeg);
		//move smaller disks from auxillary peg to destination (above this disk)
	}
}

int main()
{
	char a[]="peg \"A\"";
	char b[]="peg \"B\"";
	char c[]="peg \"C\"";
	int numberOfDisk;

	printf("input number of disk: ");
	scanf("%d",&numberOfDisk);
	hanoi(numberOfDisk,a,c,b);
}

