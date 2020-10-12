// SELECTION SORT

import java.util.Scanner;

class SelectionSort{

	static void Sort(int[] a,int n){
		int i=0,j=0,pos;
		for(i=0;i<n;i++){
			pos = i;
			for(j=i+1;j<n;j++){
				if (a[j]<a[pos])
					pos = j;
					
				
	
			}
			int t = a[i];
			a[i] = a[pos];
			a[pos] = t;
		
		}
	
	}
	public static void main(String args[]){
		System.out.print("Enter n = ");
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int i=0;
		int a[] = new int[n];	
		System.out.println("Enter the array : ");	
		for(i=0;i<n;i++){
			a[i] = input.nextInt();			
		}
		System.out.println("The array Entered : ");	
		for(int x:a){
			System.out.print(x+" ");		
		}		
		Sort(a,n);		
		System.out.println("\nArray after Sorting  : ");	
		for(int x:a){
			System.out.print(x+" ");		
		}		
	
	}

}
