import java.util.*;

/* 
Check if a given array contains duplicate elements within k distance from each other
Given an unsorted array that may contain duplicates. Also given a number k which is smaller than size of array.
 Write a function that returns true if array contains duplicates within k distance.
*/

class duplicate{
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
		boolean ans=false;
		int v=0;
		for(i=0;i<n;i++){
			if (h.containsKey(a[i])){
				v=1;
				int c = h.get(a[i]);
				if (i-c <= k){
					int p = i-c;
					System.out.println(a[i]+" is repeated at distance "+p);
					ans = true;
					break;
				}
			}
			else{
				h.put(a[i],i);
			}
		}
		if (v==1 && !ans)
			System.out.println("All duplicates are more than k distance away");
		else if (v==0 && !ans)
			System.out.println("No Duplicates!");
		System.out.println(ans);		
		
	}

}

//1 2 3 4 1 2 3 4 and k = 3

// false


