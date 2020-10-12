/*

Given two unsorted arrays, find all pairs whose sum is x
Given two unsorted arrays of distinct elements, the task is to find all pairs from both arrays whose sum is equal to x.

Examples:

Input :  arr1[] = {-1, -2, 4, -6, 5, 7}
         arr2[] = {6, 3, 4, 0}  
         x = 8
Output : 4 4
         5 3

Input : arr1[] = {1, 2, 4, 5, 7} 
        arr2[] = {5, 6, 3, 4, 8}  
        x = 9
Output : 1 8
         4 5
         5 4


*/
import java.util.*;
import java.lang.*;
import java.io.*;

class sumX{
	public static void main (String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while(t>0){
		    int n1 = input.nextInt();
		   
		    int i=0,j=0;
		    int[] a1 = new int[n1];
		    HashMap<Integer,Integer> h = new HashMap<Integer,Integer>();
		    for(i=0;i<n1;i++){
		        a1[i] = input.nextInt();
		        if (h.containsKey(a1[i])){
		        	h.put(a1[i],h.get(a1[i])+1);		        
		        }else{
		        	h.put(a1[i],1);
		        }
		        
		    }
		    int n2 = input.nextInt();
		    int[] a2 = new int[n2];   
		    for(i=0;i<n2;i++){
		        a2[i] = input.nextInt();		        
		    }
		    int X = input.nextInt();
		    for(i=0;i<n2;i++){
		    	int c = Math.abs(a2[i]-X);
		    	if (h.containsKey(c)){
		    		System.out.println(c+" & "+a2[i]);
		    	}		    	
		    }
		    
		 
		   
		    t--;		    
		}		
	}
}
/*
1
6
-1 -2 4 -6 5 7
4
6 3 4 0
8

4,4
5,3


*/



