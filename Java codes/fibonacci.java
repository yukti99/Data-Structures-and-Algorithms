import java.util.Scanner;

class fibonacci{
	public static void main(String args[]){
		Scanner input = new Scanner(System.in) ;
		System.out.print("Enter n upto which series has to be printed = ");
		int n = input.nextInt();
		System.out.println("You entered "+n);
		
		// fibonacci series without recursion
		int n1 = 0,n2 = 1,n3=0;
		
		System.out.print("The fibonacci series till "+n+" : "+n1+" "+n2);
		for(int i=2;i<n;i++){
			n3 = n1+n2;
			System.out.print(" "+n3);
			n1 = n2;
			n2 = n3;	
		}
		System.out.println("\n");
	
	}

}
