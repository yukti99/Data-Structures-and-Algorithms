import java.util.*;

//  Maximum distance between two occurrences of same element in array
// Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.

class maxDist{
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
		
		HashMap<Integer,Integer> h  = new HashMap<>();
		int max=0,dist=0;
		for(i=0;i<n;i++){
			if (h.containsKey(a[i]))
				max = Math.max(max,i-h.get(a[i]));
			
			else
				h.put(a[i],i);
			
		}
		System.out.println("Maximum distance between two occurrences of same element in the array = "+max);
		
		
	}

}
// 3 2 1 2 1 4 5 8 6 7 4 2
// ans  =  2;


