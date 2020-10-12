import java.util.*;
import java.lang.*;
import java.io.*;

class commonArray{
	public static void main (String[] args) {
		Scanner input = new Scanner(System.in);
		int i,j,k;
	        int[] a1 = {1, 5, 10, 20, 40, 80};
		int[] a2 = {6, 7, 20, 80, 100};
		int[] a3 = {3, 4, 15, 20, 30, 70, 80, 120};
		int n1 = a1.length;
		int n2 = a2.length;
		int n3 = a3.length;
		
		//finding the common elements in the 3 sorted arrays		
		i=j=k=0;
		while(i<n1 && j<n2 && k<n3){
			if (a1[i] == a2[j] && a2[j] == a3[k]){
				System.out.println(a1[i]);
				i++;
				j++;
				k++;
			}
			else if (a1[i] < a2[j])
				i++;
			
			else if (a2[j] < a3[k])
				j++;
			
			else
				k++;				
		
		}	
		
		    	
	}
}

