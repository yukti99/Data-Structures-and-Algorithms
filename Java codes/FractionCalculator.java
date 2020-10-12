import java.util.*;
import java.io.*;

class Fraction{
	private int num;
	private int den;
	
	public Fraction(int num,int den){
		if (den == 0)
			throw new IllegalArgumentException();
		else if (num<0 && den<0){
			num = num+Math.abs(num)*2;
			den = den+Math.abs(den)*2;
		}
		else if (den<0){
			num = num - 2*num ;
			den = den + Math.abs(den)*2 ;
		}
			
		this.num = num;
		this.den = den;
	}
	//  to eliminate redundancy
	public Fraction(int num){
		this(num,1);
	}
	public Fraction(){
		this(0,1);
	}
	public int getNumerator(){
		return this.num;
	}
	public int getDenominator(){
		return this.den;
	}
	public String toString(){
		String s = this.num+"/"+this.den ;
		return s;
	}
	public double toDouble(){
		double d = this.num/this.den;
		return d;
	}
	public Fraction add(Fraction other){
		int fn = this.num*other.den + this.den*other.num;
		int fd = this.den * other.den;
		Fraction f = new Fraction(fn,fd);
		return f;
	}
	public Fraction subtract(Fraction other){
		int fn = this.num*other.den - this.den*other.num;
		int fd = this.den * other.den;
		Fraction f = new Fraction(fn,fd);
		return f;
	}
	public Fraction multiply(Fraction other){
		int fn = this.num * other.num;
		int fd = this.den * other.den;
		Fraction f = new Fraction(fn,fd);
		return f;
	}
	public Fraction divide(Fraction other){
		int fn = this.num * other.den;
		int fd = this.den * other.num;
		Fraction f = new Fraction(fn,fd);
		return f;
	}
	public boolean equals(Object other){
		if (other == this)
			return true;
		else if (other instanceof Fraction){
			Fraction o = (Fraction)other;
			if (o.num == this.num && o.den == this.den)
				return true;
			else
				return false;
		}
		else
			return false;
		
	}
	public static int gcd(int a,int b){
		if (b==0)
			return a;
		return gcd(b,a%b);
	}
	public void toLowestTerms(){
		int g = gcd(this.num,this.den);
		this.num /= g;
		this.den /= g;		
	}
	

}
class FractionCalculator{
	public static void intro(){
		System.out.print("This program is a fraction calculator\nIt will add, subtract, multiply and divide fractions until you type Q to 						quit.\nPlease enter your fractions int the form a/b, where a and b are integers");
	}
	
	public static char getOperation(Scanner input){
		while(true){
				
				System.out.print("Please enter an operation(+,-,/,* = or Q to quit): ");
				char op = input.next().charAt(0);
				if (op=='+'||op=='-'||op=='*'||op=='/' || op=='=')
					return op;
				else if (op == 'Q' || op == 'q'){
					System.out.println("Good Bye!");
					System.exit(0);
				}
				else{
					
					System.out.println("Invalid input!!");
				}			
		
		}
		
	}
	public static boolean checkInt(String s){
		
		int l = s.length();
		
		for(int i=0;i<l;i++){
			
			if (i==0 && s.charAt(i) == '-' ){
				if (s.length() == 1)
					return false;	
				else continue;			
			}
			
			if (Character.digit(s.charAt(i),10) < 0) 
				return false;
		}
		return true;
	}
	// check if string is of the form a/b	
	public static boolean validFraction(String input){
		
		
		int f=0;
		for(int i=0;i<input.length();i++){
			if (input.charAt(i) == '/')
				f+=1;
		}
		
		if (input.contains("/") == false && checkInt(input)){
				return true;
				
		}	
		else if (input.contains("/") == true){
			
			String[] s = input.split("/");
			try{
				checkInt(s[1]);
				checkInt(s[0]);
			}
			catch(Exception e){
				System.out.println("Invalid fraction!");
				return false;
			}
			
			if (checkInt(s[0]) && checkInt(s[1]) && Integer.parseInt(s[1]) != 0 ){
				return true;
			}		
		}			
		return false;	
	
	}
	public static Fraction getFraction(){
		// ! Scanner not working properly when taken as parameter
		Scanner input = new Scanner(System.in);
		while(true){
			System.out.print("Please enter a fraction (a/b) or integer (a): ");
			String s = null;
			try{			
				s =  input.nextLine();
				
			} 	
			catch(Exception e){
				System.out.println("Invalid fraction!");
				continue;
			}
			
			//System.out.println("string = "+ s);
			if (s.length()==1){
				int n=0;
				try{
					n = Integer.parseInt(s);
				}
				catch(Exception e){
					System.out.println("Invalid fraction!");
					continue;
				}
			}
				
			// Checking the validity of the input fraction entered
			if (validFraction(s)){
				String[] s1 = s.split("/");
				Fraction f = null;
				if (!s.contains("/")){
					
					f = new Fraction(Integer.parseInt(s));
					return f;			
				}			
				f = new Fraction(Integer.parseInt(s1[0]),Integer.parseInt(s1[1]));
				return f;		
				
			}
			else{
				System.out.print("Invalid fraction. ");
				continue;
			}
			
				
		
		}
	}
	public static void result(Fraction f1,Fraction f2,char op){
	
		String fr1 = f1.getNumerator()+"/"+f1.getDenominator();
		String fr2 = f2.getNumerator()+"/"+f2.getDenominator();
		String res = fr1+" "+op+" "+fr2;
		f1.toLowestTerms();
		f2.toLowestTerms();
		
		Fraction ans = null;
		if (op == '='){
			if(f1.equals(f2))
				System.out.println(res+" is True!");				
				
			else
				System.out.println(res+" is False!");	
			return ;				
		
		}
		
		switch(op){
			case '+':
				ans = f1.add(f2);
				break;
			case '-':
				ans = f1.subtract(f2);
				break;
			case '*':
				ans = f1.multiply(f2);
				break;
			case '/':
				ans = f1.divide(f2);
				break;
			
			
		}
		ans.toLowestTerms();
		System.out.println(res+" = "+ans);
		
	}
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);	
		while(true){
			char op =  getOperation(input);
			Fraction frac1 = getFraction();
			Fraction frac2 = getFraction();
			System.out.println("Fraction 1 : "+frac1.getNumerator() +"/"+frac1.getDenominator());
			System.out.println("Fraction 2 : "+frac2.getNumerator() +"/"+frac2.getDenominator());	
			System.out.println("Operation : "+op);
			result(frac1,frac2,op);
			System.out.println("--------------------------------------------------------------------------------");
		
		}
		
		
	}

}

