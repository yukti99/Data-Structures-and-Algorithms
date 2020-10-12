import java.util.*;
import java.lang.*;
import java.io.*;

class equal01{

	public static int subarr(int[] a,int n,int i,int X,int Y){
		int count=0;
		for(int j=i;j<n;j++){
			if (a[j] == 1)
				X++;
			else
				Y++;
			if (X==Y)
				count++;
		}
		return count;
	}
	public static int ans(int[] a,int n){
		int sum=0;
		for(int i=0;i<n;i++){
			sum+= subarr(a,n,i,0,0);
			
		}
		return sum;
	}
	public static void main (String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while(t>0){
		    int n = input.nextInt();
		    int i=0,j=0;
		    int[] a = new int[n];
		    for(i=0;i<n;i++){
		        a[i] = input.nextInt();
		    }
		    System.out.println(ans(a,n));
		 
		   
		    t--;		    
		}		
	}
}

