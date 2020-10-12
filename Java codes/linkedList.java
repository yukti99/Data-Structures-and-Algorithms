import java.util.Scanner;

class linkedList{
	class Node{
		int data;
		Node next;
			
			// Constructer of this class
		public Node(int data){
			this.data = data;
			this.next = null;
		}
	}	
	
	public Node head = null;
	
	// adds elements in front
	public void push(int data){
		// creates a new node
		Node n = new Node(data);
		// checks if list is empty
		if (head == null){
			head = n;		
		}
		else{
			n.next = head;
			head = n;			
		}
	
	}
	// adds elements at back
	public void append(int data){
		Node n = new Node(data);
		if (head == null){
			head = n;
			n.next = null;
			return ;		
		}
		Node p = head;
		while(p.next!=null){
			p = p.next;		
		}
		p.next = n;
		n.next = null;
	
	
	}
	public void display(){
		System.out.println("The Singly Linked List : ");
		if (head == null){
			System.out.println("The list is Empty");
			return ;		
		}
		Node n = head;
		while(n!=null){
			System.out.print(n.data + " ");
			n = n.next;		
		}
		System.out.print("\n");
	
	}
	
	
	public static void main(String args[]){
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the no of elemnets in linked list = ");
		int n = input.nextInt();
		System.out.println("Enter the elements for list : ");
		
		linkedList l = new linkedList();
		for(int i=0;i<n;i++){
			l.append(input.nextInt());
		}
		l.display();
		
		
	}

}
