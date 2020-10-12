/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class sumPairs{
	public static void main (String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while(t>0){
		    int n = input.nextInt();
		    int i=0,j=0;
		    int[] a = new int[n];
		    for(i=0;i<n;i++){
		        a[i] = input.nextInt();
		    }
		    int max=Integer.MIN_VALUE;
		    int cn=0;
		    for(i=0;i<n;i++){
		        for(j=i+1;j<n;j++){
		        	if (a[i]+a[j] > max){
		        		max = a[i]+a[j];
		        	}      	
		            
		            
		        }
		    }
		    for(i=0;i<n;i++){
		        for(j=i+1;j<n;j++){
		        	if (a[i]+a[j] == max){
		        		cn++;
		        	}
		        	
		            
		            
		        }
		    }
		    System.out.println(cn);
		    t--;
		    
		}
		
	}
}
//System.out.println("i & j = "+i+" & "+j);
//System.out.println("sum = "+c);
