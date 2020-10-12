/* Class containing left and right child of current 
node and key value*/
class Node 
{ 
	int key; 
	Node left, right; 

	public Node(int item){ 
		key = item; 
		left = right = null; 
	} 
	
} 




class heightbt{
    
    public static int max(int a,int b){
    	if (a>=b)
    		return a;
    	return b;
    }
    public static int findHeight(Node node){
        if (node == null){
            return 0;
        }        
       	return max(findHeight(node.left)+1, findHeight(node.right)+1);
          
        
    }
    public static int height(Node node){
        return findHeight(node);
        
         
    } 
    public static void main(String[] args){
    		Node root = new Node(10); 
		root.left = new Node(20); 
		root.right = new Node(30); 
		root.left.left = new Node(40);
		root.left.right = new Node(50);
		//root.right.left = new Node(60);
		//root.left.left.left = new Node(70);
		
		System.out.println(height(root));
		//height(root);
    }  
}

