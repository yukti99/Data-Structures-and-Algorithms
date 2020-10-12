import java.util.Scanner;

class fibrec{
	static int n1=0,n2=1,n3=0;
	static int fib(int n){
		if (n==0 || n==1)
			return n;
		return fib(n-1)+fib(n-2);
	}
	public static void main(String args[]){
		Scanner input  = new Scanner(System.in);
		System.out.print("Enter n = ");
		int n = input.nextInt();
		System.out.println("You entered "+n);
		System.out.println("The fibonacci series till : ");
		for(int i=0;i<n;i++){
			System.out.print(fib(i)+" ");		}
				
		System.out.print("\n");
	
	}

}
	
