import java.util.*;

/* 

First element occurring k times in an array

Given an array of n integers. The task is to find the first element that occurs k number of times. If no element occurs k times the print -1. The distribution of integer elements could be in any range.

Examples:

Input : {1, 7, 4, 3, 4, 8, 7}, 
        k = 2
Output : 7
Both 7 and 4 occur 2 times.
But 7 is the first that occurs 2 times. 

Input : {4, 1, 6, 1, 6, 4}, 
        k = 1
Output : -1


*/

class ktimes{
	public static void main(String[] args){	
		// Taking an array as input
		Scanner input = new Scanner(System.in);
		System.out.print("Enter n = ");
		int n = input.nextInt();
		int[] a = new int[n];
		int i;
		System.out.println("Enter array : ");
		for(i=0;i<n;i++)
			a[i] = input.nextInt();
		
		System.out.print("Enter k = ");
		int k = input.nextInt();
		
		HashMap<Integer,Integer> h = new HashMap<>();
		int f=0;
		for(i=0;i<n;i++){
			if (h.containsKey(a[i])){
				int c = h.get(a[i]);
				h.put(a[i],c+1);
			}
			else{
				h.put(a[i],1);
			}
		}
		for(i=0;i<n;i++){
			if (h.get(a[i]) == k){
				f=1;
				System.out.println(a[i]+" has "+k+" occurences in the array");
				break;
			}
		}
		if (f==0)
			System.out.println("No such element!");
			
			
		
	}

}

//1 2 3 4 1 2 3 4 and k = 3

// false


