/*

Find distinct elements common to all rows of a matrix
Given a n x n matrix. The problem is to find all the distinct elements common to all rows of the matrix. The elements can be printed in any order.

Examples:
Input : mat[][] = {  {2, 1, 4, 3},
                     {1, 2, 3, 2},  
                     {3, 6, 2, 3},  
                     {5, 2, 5, 3}  }
Output : 2 3

Input : mat[][] = {  {12, 1, 14, 3, 16},
                     {14, 2, 1, 3, 35},  
                     {14, 1, 14, 3, 11},  
                     {14, 25, 3, 2, 1},
                     {1, 18, 3, 21, 14}  }
Output : 1 3 14

*/
import java.util.*;
import java.lang.*;
import java.io.*;

class distinctMatrix{
	public static void main (String[] args) {
		Scanner input = new Scanner(System.in);
		int i,j;
		int n = input.nextInt();
		int[][] m = new int[n][n];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				m[i][j] = input.nextInt();
		
		// finding the distinct element
		HashMap<Integer,Integer> h = new HashMap<>();
		int[][] a = new int[n][n];
		for(i=0;i<n;i++){
			if (!h.containsKey(m[0][i]))
				h.put(m[0][i],1);	
				
		}
		
		for(i=1;i<n;i++){
			HashMap<Integer,Integer> temp = new HashMap<>();
			for(j=0;j<n;j++){
				if (!temp.containsKey(m[i][j])){
					temp.put(m[i][j],1);
				}
			}
			for(j=0;j<n;j++){
				if (!temp.containsKey(m[0][j])){
					h.remove(m[0][j]);
				}
			}
			if (h.size()==0)
				break;
				
		}
		System.out.println("The distinct elements common to each row : ");
		for(Integer key:h.keySet()){
			System.out.print(key+" ");
		}
		System.out.println();
		
		
		
				
	}
}
/*
5
12 1 14 3 16
14 2 1 3 35
14 1 14  3 11
14 25 3 2 1
1 18 3 21  14
*/

