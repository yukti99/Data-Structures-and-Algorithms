import java.util.*;
import java.lang.*;
import java.io.*;

class sortMatrix{

	public static void sort(int[][] m,int n){
		int i=0,j=0,k=0;
		int[] a = new int[n*n];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				a[k++] = m[i][j];

		Arrays.sort(a);
		k=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				m[i][j] = a[k++];
		
	}
	public static void main (String[] args) {
		Scanner input = new Scanner(System.in);
		int i,j;
		int n = input.nextInt();
		int[][] m = new int[n][n];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				m[i][j] = input.nextInt();
		System.out.print("\nBefore sorting : \n");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				System.out.print(m[i][j]+" ");
			System.out.print("\n");
		}
		System.out.print("\n");
		// sorting the matrix
		sort(m,n);
		
		System.out.print("\nAfter sorting : \n");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				System.out.print(m[i][j]+" ");
			System.out.print("\n");
		}
		System.out.print("\n");
	}
}

