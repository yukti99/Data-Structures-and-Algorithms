import java.util.*;

class OddsAndEvens{
	public static void print(int no){
		for(int i=0;i<no;i++){
			System.out.print("-");
		}
		System.out.println();
	
	}
	public static void main(String[] args){
		int i,j;
		Scanner input = new Scanner(System.in);
		System.out.println("Let’s play a game called \"Odds and Evens\"");
		System.out.print("What is your name? ");
		String name = input.nextLine();
		System.out.print("Hi "+name+", which do you choose? (O)dds or (E)vens? ");
		char c = input.next().charAt(0);
		if (c == 'O')
			System.out.println(name+" has picked odds! The computer will be evens.");
		else
			System.out.println(name+" has picked evens! The computer will be odds.");
			
		print(50);
		System.out.println();
		System.out.print("How many \"fingers\" do you put out? ");
		int f = input.nextInt();
		Random rand = new Random();
		int computer = rand.nextInt(6); // to generate random nos from 0 to 5
		System.out.println("The computer plays "+computer+" fingers.");
		print(50);
		int sum = computer+f;
		System.out.println(f+" + "+computer+" = "+sum);
		boolean oddOrEven = (sum % 2 == 0);
		int e=0;
		if (oddOrEven){
			e=1;
			System.out.println(sum+" is ...even!");
		}
			
		else
			System.out.println(sum+" is ...odd!");
		print(50);
		if ((e==1 && c=='E')||(e==0 && c == 'O'))
			System.out.println("That means "+name+"  wins! :)");
		else
			System.out.println("That means computer  wins! :)");
			
		System.out.println("Thank you, "+name+" for playing!");		 
		

	}

}
