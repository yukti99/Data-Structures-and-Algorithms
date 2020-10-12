import java.util.*;
import java.lang.*;
import java.io.*;

class union{
	public static void main (String[] args) {
		Scanner input = new Scanner(System.in);
		int i,j,k;
	        int[] a1 = {2,5,6,7,2,9,5,3};
        	int[] a2 = {4,6,8,10,5,8,1,9} ;
		int n1 = a1.length;
		int n2 = a2.length;
		// Union of the array
		System.out.println("Union of the array : ");
		HashMap<Integer,Integer> h  = new HashMap<>();
		for(i=0;i<n1;i++){
			if (!h.containsKey(a1[i]))
				h.put(a1[i],1);
		}
		for(i=0;i<n2;i++){
			if (!h.containsKey(a2[i]))
				h.put(a2[i],1);
		}
		for(Integer key :h.keySet()){
			System.out.print(key+" ");
		}
		System.out.println();
		// Intersection of the array
		
		HashMap<Integer,Integer> h2  = new HashMap<>();
		for(i=0;i<n2;i++){
			if (!h2.containsKey(a2[i]))
				h2.put(a2[i],1);
		}
		System.out.println("Intersection of the array : ");
		for(i=0;i<n1;i++){
			if (h2.containsKey(a1[i])){
				System.out.print(a1[i]+" ");
			}
		}
		System.out.println();
		
		
		
		    	
	}
}

