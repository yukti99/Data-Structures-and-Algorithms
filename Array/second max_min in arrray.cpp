/*Second largest and Smallest number in an array */

#include <iostream>
#include <limits.h>
#include <cstdio>
using namespace std ;

void swapp(int x, int y);
int s_max(int a[],int n);
int s_min(int a[],int n);

int main()
{
	int n,i ;
	char m1,m2;
	cout<<"Enter the length of array = " ;
	cin>> n ;
	if (n < 2)
    {
        printf(" Invalid Input... ");
        exit(1);
    }
	int a[n] ;
	for(i=0 ; i<n ; i++)
	{
		cout<<"Enter element of the array = ";
		cin>>a[i];		
	}
	cout<<"Array : ";
	for(i=0 ; i<n ; i++)	
		cout<<a[i]<<" ";	
	// menu
	cout<<"\nDo you want the second largest (y/exit-e) ? ";
	cin>>m1 ;
	if (m1 == 'y')	
		cout<<"Second Largest number in the array = "<<s_max(a,n)<<endl ;  
	else if (m1 == 'e')
	{
		cout<<"Program ended...\n" ;
		exit(1);
	}
	cout<<"\nDo you want the second smallest (y/exit-e) ? " ;
	cin>>m2 ;
	if (m2 == 'y')
		cout<<"Second Smallest number in the array = "<<s_min(a,n)<<endl ;
    else if (m2 == 'e')
    	exit(1);   	 	
	
	return 0;
}
void swapp(int &x, int &y) // call by reference
{
	int t ;
	t = x ;
	x = y ;
	y = t ;
}
int s_max(int a[],int n)
{
	int i,max1,max2 ;
	max1 = max2 =  a[0];
	for(i=1 ; i<n ; i++)
	{
		if (a[i] > max1)
			swapp(max1,a[i]) ;
			
		if ( a[i] > max2 && a[i] < max1)		
			max2 = a[i] ;		
	}
	return max2 ;
}
int s_min(int a[],int n)
{
	int i,min1,min2 ;
	min1 = min2 = INT_MAX ;
	for(i=1 ; i<n ; i++)
	{
		if (a[i] < min1)		
			swapp(min1,a[i]) ;	    	
	    	
	    if (a[i] < min2 && a[i] > min1)
	    	min2 = a[i] ;
	}
	return min2;
}
