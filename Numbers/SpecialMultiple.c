#include <stdio.h>
#include <math.h>

int last(int n){
    int r;
    while(n!=0){
        r = n%10;
        n = n/10;
        if (r!=9)
            return 0;        
    }
    return 1;
}
int main(){
    int T,i,j,n,N;
    int check;
    //printf("\nEnter the number of test cases = ");
    scanf("%d",&T);
    while(T--){
        N = 9;
        int a[200] = {0,9,90,99},f=0;
        //printf("\nEnter n = ");
        scanf("%d",&n);
        for(i=1;i<4;i++){
            if (a[i]%n==0){
                printf("%d\n",a[i]);
                f=1;
                break;
            }
        }
        if (f==1)
            continue;
        i=2;j=0;
        int k=0,x=1;
        int y=0,size = 4;    
        //for(j=0;j<size;j++){
    	while(j<size){
            //printf("\nNo,j = %d,%d\n",a[j],j);
            check = pow(10,i)*N + a[j];
            a[size++] = check;
            //printf("\nCheck = %d\n",check);
            if (check % n == 0){
                printf("%d\n",check);
                break;
            } 
            if (last(check)){
            	//printf("\nIncreasing no of digits!\n");
                i++;
                j=0;
            }
            else
            	j++;           
        
        }
    }
    
    return 0;
}
