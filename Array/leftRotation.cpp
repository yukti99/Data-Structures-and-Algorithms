/* LEFT ROTATION OF AN ARRAY  in c*/

#include <stdio.h>
#include <stdlib.h> 

void Rotate_Left(int a[],int n,int d){
    int i;
    int temp = a[0];
    for(i=0;i<n-1;i++){
        a[i] = a[i+1];
    }
    a[n-1] = temp;        
}

int main(){
    
    int i,n,d;
    scanf("%d",&n);
    scanf("%d",&d);
	if (d>n)
		d = d%n;    
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);        
        
    
    for(i=0;i<d;i++)
        Rotate_Left(a,n,d);
        
    for(i=0;i<n;i++)
        printf("%d ",a[i]);        
    return 0;
}
