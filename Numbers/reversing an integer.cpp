/* Reversing an integer */

#include <iostream>
using namespace std ;

int main()
{
	int n,i,c=0,t,reverse = 0 ,d;
    cout<<"Enter any integer = " ;
	p :  cin>>n ;
	if (!(n/2))
	{
		cout<<"Invalid Input!" ;
		exit(1);		
	}	  
	t = n ;	
	while(n)
	{
	   reverse *= 10 ;
	   d = n % 10 ;
	   n /= 10 ;	
	   reverse += d ;	
	}
	n = t ;
	cout<<"The original number  = "<<n<<endl ;
	cout<<"Reversed number  = "<<reverse<<endl ;	
	return 0;
}



