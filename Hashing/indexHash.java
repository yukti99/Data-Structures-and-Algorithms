//  Index Maping  - Trivial hashing in Java

import java.util.*;




class indexHash{
	public static void insert(int[][] hash,int item){
		if (item>=0)
			hash[item][0] = 1;
		else
			hash[Math.abs(item)][1] = 1;
	}
	public static boolean search(int[][] hash,int item){
		if (item>=0)
			if(hash[item][0] == 1)
				return true;
			else
				return false;
		else{
			item = Math.abs(item);
			if (hash[item][1]==1)
				return true;
			return false;
		}
		
			
	}

	public static void main(String[] args){
		//hash matrix
		Scanner input = new Scanner(System.in);
		System.out.print("Enter size of array = ");
		int n = input.nextInt();
		//hash table
		int[][] hash = new int[1000][2];
		int[] a = new int[n];
		System.out.print("Enter array :\n");
		for(int i=0;i<n;i++){
			a[i] = input.nextInt();
		}
		// array is 
		for(int i=0;i<n;i++){
			insert(hash,a[i]);
		}
		int p = 6;
		System.out.println(search(hash,p));
		
		
	}
}
