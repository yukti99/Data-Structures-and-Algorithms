import java.util.*;

class Crypto{
	static int spaces[] = new int[100];
	static int v=0,size=0;
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the string to be encrypted : ");
		String s = input.nextLine();
		size = s.length();
		System.out.print("Enter the integer shift value : ");
		int n = input.nextInt();
		System.out.print("Enter code group size : ");
		int g = input.nextInt();
		
		System.out.println("Encrypting the string... ");
		String encrypted = encryptString(s,n,g);
		System.out.println("The encrypted string : "+encrypted);
		System.out.println();
		
		System.out.println("Decrypting the string... ");
		String ungrp = ungroupify(encrypted);
		String decrypt = decryptString(ungrp,n);
		String deob = deObify(decrypt);	
		System.out.println("After decryption : "+deob);
		denormalize(deob);
	
	}
	// Normalize Text
	public static String normalizeText(String s){
		s = s.toUpperCase();
		String s1="";
		int i=0;
		for(char c:s.toCharArray()){
			//if (c == ' ')
			//	spaces[v++] = i;
			if (Character.isDigit(c) || Character.isLetter(c))
				s1+=c;
			else
				spaces[v++] = i;
			i++;	
				
		}
		System.out.println("After normalize : "+s1);
		return s1;
	}
	// Caesar Cipher
	public static String caesarify(String s,int n){
		String s1 = "";
		int shift=0;
		n = n%26;
		for(char c:s.toCharArray()){
			int i = (int)c;
			// case 1: n>0
			if (n>0){
				// case 1.1 i+n <= Z
				if (i+n <= (int)'Z')
					shift = i+n;
				// case 1.2 i+n > Z
				else 
					shift = i+n-26;			
			
			}
			// case 2: n<0
			else{
				// case 2.1 i+n >= A
				if (i+n >= (int)'A')
					shift = i+n;
				// case 2.2 i+n < A
				else
					shift = i+n+26;			
			
			}
			s1+=(char)shift;
		
		}
		System.out.println("After caesarify : "+s1);
		return s1;		
	
	}
	// Code Groups
	public static String groupify(String s,int n){
		int l = s.length(),i=0,k=0;
		String grp = "";
		String s1 = "";
		while(i<l){
			if (k==n){
				k=0;
				s1+=grp+" ";
				grp = "";
				i+=n;
			}
			
			if (i+k<l)	
				grp += s.charAt(i+k);
			else
				grp += 'x';		
			k++;
		}	
		System.out.println("After groupify : "+s1);
		return s1;	
		
	}
	// to obfuscate the string 
	public static String obify(String s){
		String s1 = "";
		for(char i:s.toCharArray()){
			if (i=='A'||i=='E'||i=='I'||i=='O'||i=='U'||i=='Y')
				s1+="OB";
			s1+=i;		
		
		}
		System.out.println("After Obify : "+s1);
		return s1;
	
	}
		
		
	public static String encryptString(String s,int shift,int grp){
		String n = normalizeText(s);
		String o = obify(n);
		String c = caesarify(o,shift);
		String g = groupify(c,grp);
		return g;
	
	}
	public static String ungroupify(String s){
		String s1 = "";
		for(char i:s.toCharArray()){
			if (i=='x')
				break;
			if (i==' ')
				continue;
			s1+=i;		
		}
		System.out.println("After ungroupify : "+s1);
		return s1;
	
	}
	public static String deObify(String s){
		String s1 = "";
		int l = s.length(),i=0;
		while(i<l){				
			if (s.charAt(i)=='O' && s.charAt(i+1)=='B'){				
					char c = s.charAt(i+2);
					if (c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y')
						i+=2;				
			}
			if (i<s.length())
				s1+=s.charAt(i);
			else
				break;
			i++;
		
		}
		System.out.println("After DeObify : "+s1);
		return s1;
		
		
	
	}
	public static String decryptString(String s,int n){
		String s1 = "";
		int shift=0;
		n = (-1)*n; //  the only change in the code of encrypt
		n = n%26;
		for(char c:s.toCharArray()){
			int i = (int)c;
			// case 1: n>0
			if (n>0){
				// case 1.1 i+n <= Z
				if (i+n <= (int)'Z')
					shift = i+n;
				// case 1.2 i+n > Z
				else 
					shift = i+n-26;			
			
			}
			// case 2: n<0
			else{
				// case 2.1 i+n >= A
				if (i+n >= (int)'A')
					shift = i+n;
				// case 2.2 i+n < A
				else
					shift = i+n+26;			
			
			}
			s1+=(char)shift;
		
		}
		System.out.println("After caesarify : "+s1);
		return s1;		
	
	}
	public static String denormalize(String s){
		String s1 = "";
		int i=0,k=0,j=0,l=spaces[v-1];
		for(i=0;i<v;i++){
			if (i>s.length())
				break;
			s = s.substring(0,spaces[i])+' '+s.substring(spaces[i],s.length());	
		}
		System.out.println("After denormalizing : "+s);
		return s1;	
	
	}
		
		
	
}
// Hi! I am Yukti :) Lol!


