
class strings{
	public static void main(String args[]){
		String[] s = new String[10];
		s[0] = "yukti";
		s[1] = "is";
		s[2] = "amazing";
		s[3] = "and cool";
		for(int i=0;s[i]!=null;i++){
			System.out.print(s[i]+" ");		
		}
		System.out.print("\n");
		String[] fruits = {"apple","orange","grapes","melon","strawberry"};
		for(String f:fruits)
			System.out.print(f+", ");	
	}

}
