/* Front and back searching algorithm */

#include <iostream>
using namespace std ;

//binary search for sorted array
int Binary_Search(int*a,int n,int item)
{
	int l = 0,u = n-1,mid;
	while(l<=u)
	{
		mid = (l+u)/2;
		if (item>a[mid])
			l  = mid + 1;
		else if (item<a[mid])
			u = mid - 1;
		else
			return mid;		
	}
	return -1;
	
}
int search(int*a,int n,int x)
{
	int front = 0,back  = n-1 ;
	// searching while the two elements do not cross
	while (front<back)
	{
		if (a[front] == x)
			return front;
		else if(a[back] == x)
			return back;
		else
		{
			front++ ;
			back++ ;	
		}
	}
	return -1;
}

// driver program for the program
int main()
{

	int arr[] = { 4, 6, 1, 5, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 1;
    cout << search(arr, n, x);
	return 0;
	
}
