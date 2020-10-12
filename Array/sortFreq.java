/*
Sort elements by frequency 
Print the elements of an array in the decreasing frequency if 2 numbers have same frequency then print the one which came first.

Examples:
Input : arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
Output : arr[] = {8, 8, 8, 2, 2, 5, 5, 6}

Input : arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8}
Output : arr[] = {8, 8, 8, 2, 2, 5, 5, 6, -1, 9999999}
*/

import java.util.*;
import java.lang.*;
import java.io.*;

// Implement Comparator interface to sort the values
	class SortComparator implements Comparator<Integer>{
		private final Map<Integer,Integer> freqMap ;
		
		// constructor for class
		SortComparator(Map<Integer,Integer> tFreqMap){
			this.freqMap = tFreqMap;
		}
		@Override
		public int compare(Integer k1,Integer k2){
			int freqcomp = freqMap.get(k2).compareTo(freqMap.get(k1));
			// compare value if freq is equal
			int valuecomp = k1.compareTo(k2);
			if (freqcomp == 0)
				return valuecomp;
			else
				return freqcomp;
		}
	
	
	}

class sortFreq{
	
	public static void main (String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while(t>0){
		    int n = input.nextInt();
		    int i=0,j=0;
		    int[] a = new int[n];
		    for(i=0;i<n;i++)
		        a[i] = input.nextInt();	
		    Map<Integer,Integer> map = new HashMap<>();
		    List<Integer> outArray = new ArrayList<>();
		    
		    for(int current:a){
		    	int count = map.getOrDefault(current,0);
		    	map.put(current,count+1);
		    	outArray.add(current);
		    }
		    SortComparator comp = new SortComparator(map);
		    Collections.sort(outArray,comp);
		    
		    for(Integer k : outArray){
		    	System.out.print(k+ " ");
		    }	
		    System.out.println();     	
		    
		    
		    t--;		    
		}		
	}
}

