import java.util.*;
// To find if array2 a subset of array 1

class subset{
	public static void main(String[] args){
	
		// Taking two arrays as input
		Scanner input = new Scanner(System.in);
		System.out.print("Enter n1 = ");
		int n1 = input.nextInt();
		int[] a1 = new int[n1];
		int i;
		System.out.println("Enter array-1 : ");
		for(i=0;i<n1;i++)
			a1[i] = input.nextInt();
		System.out.print("Enter n2 = ");
		int n2 = input.nextInt();
		int[] a2 = new int[n2];
		System.out.println("Enter array-2 : ");
		for(i=0;i<n2;i++)
			a2[i] = input.nextInt();
		HashMap<Integer,Boolean> h = new HashMap<Integer,Boolean>();
		
		for(i=0;i<n1;i++){
			if (!h.containsKey(a1[i]))
				h.put(a1[i],true);
		}
		int f=1;
		for(i=0;i<n2;i++){
			if (! h.containsKey(a2[i]) )
				f=0;
		}
		if (f==1)
			System.out.println("Yes! It's a subset");
		else
			System.out.println("No! It's NOT a subset");
			
		
	
	}

}
