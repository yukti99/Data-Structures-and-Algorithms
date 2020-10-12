import java.util.*;

// Minimum operation to make all elements equal in array

class equalArray{
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
		
		
		
		// using hash maps to find the highest duplication in an array
		
		HashMap<Integer,Integer> h = new HashMap<>(); // maps array element with its frequency
		int max=1,c=0;
		for(i=0;i<n;i++){
			if (h.containsKey(a[i])){
				
				c = h.get(a[i]);
				c++;
				
				if (max<c){	
					max = c;
				}
				h.put(a[i],c); 				
			}
			else{
				h.put(a[i],1);
			}			
		}
		int ans=0;		
		ans = n-max;		
		System.out.println("Minimun Operations required to make all elements equal in the array = "+ans);
	}

}
//{1, 5, 2, 1, 3, 2, 1};
