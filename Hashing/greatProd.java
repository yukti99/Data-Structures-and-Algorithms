import java.util.*;

/* 
Find pair with greatest product in array

Given an array of n elements, the task is to find the greatest number such that it is product of two elements of given array. If no such element exists, print -1. Elements are within the range of 1 to 10^5.

Examples :

Input :  arr[] = {10, 3, 5, 30, 35}
Output:  30
Explanation: 30 is the product of 10 and 3.

Input :  arr[] = {2, 5, 7, 8}
Output:  -1
Explanation: Since, no such element exists.

Input :  arr[] = {10, 2, 4, 30, 35}
Output:  -1

Input :  arr[] = {10, 2, 2, 4, 30, 35}
Output:  4

Input  : arr[] = {17, 2, 1, 35, 30}
Output : 35

*/

class greatProd{

	public static int greatestProd(int[] a,int n){		
		HashMap<Integer,Integer> h = new HashMap<>();
		for(int i=0;i<n;i++){
			if (!h.containsKey(a[i]))
				h.put(a[i],h.get(a[i]));
			else
				h.put(a[i],h.get(a[i])+1);
		}
		
		Arrays.sort(a);
		for (int i = n - 1; i > 1; i--){ 
			for (int j = 0; j < i && a[j] <= Math.sqrt(a[i]); j++){ 
				if (a[i] % a[j] == 0){ 
					int result = a[i] / a[j]; 
					if (result != a[j] &&	h.get(result) == null|| h.get(result) > 0) 					
						return a[i]; 
					else if (result == a[j] && h.get(result) > 1) 
						return a[i]; 
					
				} 
			} 
		} 
		
		return -1;	
	
	}
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
		System.out.println(greatestProd(a,n));	
		
	}
}


