/* Towers of Hanoi */

#include <stdio.h>

void TowersOfHanoi(int n ,char from_rod,char to_rod,char aux_rod){
	if (n == 1){
		printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
        return ; 
	}
	TowersOfHanoi(n-1,from_rod,aux_rod,to_rod);
	printf("\n Move disk %d from rod %c to rod %c",n, from_rod, to_rod); 
	TowersOfHanoi(n-1,aux_rod,to_rod,from_rod);
}


int main(){
	int n = 5; // Number of disks 
    TowersOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods 
    return 0; 
}
