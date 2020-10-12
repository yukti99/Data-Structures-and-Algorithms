import java.util.Scanner;

class palindrome{
	public static boolean isPalindrome(String s){
		boolean flag = true;
		s = s.toLowerCase();
		int l = s.length();
		for(int i=0;i<l;i++){
			if (s.charAt(i) != s.charAt(l-i-1)){
				flag = false;
				break;
			}				
		
		}
		return flag;
	
	}
	public static void main(String args[]){
		int i=0;
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the string to check : ");
		String s = input.nextLine();
		
		
		if (isPalindrome(s))
			System.out.println("Yes! The String is a Palindrome\n");
		else
			System.out.println("No! The String is NOT a Palindrome\n");
				
	
	}



}
