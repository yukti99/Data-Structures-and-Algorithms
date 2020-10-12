#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    int n;
    int **myArray;

    n = 10;
    myArray = (int**)malloc(n*sizeof(int*));

    //Usage example
    int myIntArray[] = {1,2,3,4,5};

    myArray[0] = myIntArray;
    int a[] = {8,9,0};
    myArray[1] = a;

    //This call should print "4"
    printf("%d\n",myArray[1][2]);

    return 0;
}   
