class switches{
	public enum day {mon,tue,wed,thurs,fri,sat,sun};
	public static void main(String args[]){
		String y = "yukti";
		switch(y){
			case "shruti":
				System.out.println("No!!We want Yukti!");
				break;
			case "yukti":
				System.out.println("hello yoko!");
				break;
			// executed when none of above cases are true
			default:
				System.out.println("chal be!!");
				
		
		}
		
		
		day[] d = day.values();
		for(day x : d){
			switch(x){
				case mon:
					System.out.println("Monday");
					break;
				case sun:
					System.out.println("Sunday");
					break;
				case wed:
					System.out.println("Wednesday");
					break;				
				default:
					System.out.println("Other");
					break;				
			
			}
		
		}
		
		
	}
}
