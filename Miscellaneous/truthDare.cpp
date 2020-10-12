#include <stdio.h>
#include <stdlib.h>


void print(int a[],int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(){
	
	int T,i=0,x,y,j=0,flag=0;
	scanf("%d",&T);
	while(T--){
		int tr,dr,ts,ds,t=0,d=0;
		scanf("%d",&tr);
		int TR[tr];
		for(i=0;i<tr;i++){
			scanf("%d",&TR[i]);
		}
		scanf("%d",&dr);
		int DR[dr];
		for(i=0;i<dr;i++){
			scanf("%d",&DR[i]);
		}
		scanf("%d",&ts);
		int TS[ts];
		for(i=0;i<ts;i++){
			scanf("%d",&TS[i]);			
		}
		scanf("%d",&ds);
		int DS[ds];
		for(i=0;i<ds;i++){
			scanf("%d",&DS[i]);			
		}
		for(i=0;i<ts;i++){
			flag=0;
			for(j=0;j<tr;j++){
				if  (TS[i] == TR[j]){
					flag=1;
				}					
			}
			if (flag == 0)
				break;
		}
		for(i=0;i<ds;i++){
			if (flag==0)
				break;
			flag=0;
			for(j=0;j<dr;j++){
				if  (DS[i] == DR[j]){
					flag=1;
				}
				
			}
		}
	
		if (flag!=0)
			printf("yes\n");
		else
			printf("no\n");
		
	}
	
	
	return 0;
}
