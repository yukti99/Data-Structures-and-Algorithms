/* Insertion Sort implementation in C */

#include <stdio.h>

int main()
{
	int i,temp,pos,n=8;
	int a[] = {9,3,1,5,8,2,6,7};
    for(i=1; i<n; i++)
    {
    	// element to be inserted 
		temp = a[i];  //  this temp variable is put into its right position according to order by comparing with left-hand elements
    	pos = i-1;
    	while(pos>=0 && a[pos] > temp)
    	{
    		a[i+1] = a[i];
    		pos = pos - 1;
		}
		// insert he number at hole  position
		a[i+1] = temp;
	}
	for(i=0;i<n;i++){printf("%d ",a[i]);
	}	
	return 0;
}



/*
procedure insertionSort( A : array of items )
   int holePosition
   int valueToInsert
	
   for i = 1 to length(A) inclusive do:
	
      // select value to be inserted 
      valueToInsert = A[i]
      holePosition = i
      
      //locate hole position for the element to be inserted 
		
      while holePosition > 0 and A[holePosition-1] > valueToInsert do:
         A[holePosition] = A[holePosition-1]
         holePosition = holePosition -1
      end while
		
      // insert the number at hole position 
      A[holePosition] = valueToInsert
      
   end for
	
end procedure
*/

