/*
Count subsets having distinct even numbers

Given a sequence of n numbers. The task is to count all the subsets of the given set which only have even numbers and all are distinct.
Note: By the property of sets, if two subsets have the same set of elements then they are considered as one. 
For example: [2, 4, 8] and [4, 2, 8] are considered to be the same.

Examples:

Input : {4, 2, 1, 9, 2, 6, 5, 3} 
Output : 7
The subsets are:
[4], [2], [6], [4, 2], 
[2, 6], [4, 6], [4, 2, 6]

Input : {10, 3, 4, 2, 4, 20, 10, 6, 8, 14, 2, 6, 9}
Output : 127

*/

import java.util.*;
import java.lang.*;
import java.io.*;

class distinctEvens{
	public static void main (String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while(t>0){
		    int n = input.nextInt();
		    int i=0,j=0;
		    int[] a = new int[n];
		    HashMap<Integer,Integer> h = new HashMap<>();
		    for(i=0;i<n;i++){
		        a[i] = input.nextInt();
		        if (!h.containsKey(a[i])){
		        	if (a[i]%2 == 0)
		        		h.put(a[i],1);	       
		        	
		    	}
		    }
		    int c = (int)Math.pow(2,h.size());
		    System.out.println(c-1);	   
		    t--;		    
		}		
	}
}



