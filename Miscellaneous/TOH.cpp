// Towers of Hanoi 

#include <stdio.h>


void TOH(int n,char A,char B,char C){
	if (n>0){
		// To move n-1 disks from A to B using C
		TOH(n-1,A,C,B);
		printf("Move a disk %d from disk %c to %c\n",n,A,C);
		// To move n-1 disks form B to C using A
		TOH(n-1,B,A,C);		
	}
}
int main(){
	
	int n = 4;
	char A,B,C;
	// To move n disks form tower A to C using B
	TOH(n,'A','B','C');
	
	return 0;
}
