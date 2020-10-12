import java.util.*;
import java.lang.*;
import java.io.*;


/*

Find sum of non-repeating (distinct) elements in an array

Given an integer array with repeated elements, the task is to find sum of all distinct elements in array.

Examples:

Input  : arr[] = {12, 10, 9, 45, 2, 10, 10, 45,10};
Output : 78
Here we take 12, 10, 9, 45, 2 for sum
because it's distinct elements 

Input : arr[] = {1, 10, 9, 4, 2, 10, 10, 45 , 4};
Output : 71



*/

class sumNonrep{
	public static void main (String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while(t>0){
		    int n = input.nextInt();
		    int i=0,j=0;
		    int[] a = new int[n];
		    Map<Integer,Integer> h = new HashMap<>();
		    int sum=0;
		    for(i=0;i<n;i++){
		        a[i] = input.nextInt();
		        if (!h.containsKey(a[i])){
		        	h.put(a[i],1);
		        	sum+=a[i];
		        }
		    }
		    System.out.println(sum); 		   
		    t--;		    
		}		
	}
}

