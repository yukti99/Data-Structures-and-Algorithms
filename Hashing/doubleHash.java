// Double hashing in java 

import java.util.*;


class hash{
	int[] hashTable;
	int table_size;
	int size;
	int prime;
	hash(int n,int prime){
		this.table_size = n;
		this.prime = prime;
		this.size = 0;
		hashTable = new int[this.table_size];
		for(int i=0;i<table_size;i++){
			hashTable[i] = -1;
		}
	}
	public boolean isFull(){
		return (size == table_size);
	}
	public int hash1(int key){
		return (key%table_size);
	}
	public int hash2(int key){
		return (prime - (key%prime));
	}
	public void insert(int key){
		if (isFull())
			return ;
		int index = hash1(key);
		int i=1;
		if (hashTable[index] != -1){ 
			while(true){
				int index2 = hash2(key);			
				int newIndex = (index+i*index2)%table_size;
				
				if ( hashTable[newIndex] ==-1){
					hashTable[newIndex] = key;
					break;
				}
				i++;
			}
		}
		else{
			// no collision
			hashTable[index] = key;
			
		}
		size++;
			
		
	}
	
	public void displayHash(){
		for(int i=0;i<table_size;i++){
			if (hashTable[i]!=-1)
				System.out.println(i+"-->"+hashTable[i]);
			else
				System.out.println(i);
		}
	}


}

class doubleHash{

		

	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter size of array = ");
		int n = input.nextInt();
		int[] a = new int[n];
		System.out.print("Enter array :\n");
		for(int i=0;i<n;i++){
			a[i] = input.nextInt();
		}
		hash h = new hash(13,7);
		for(int i=0;i<n;i++){
			h.insert(a[i]);
		}
		h.displayHash();
		System.out.println();
		
		
	}
	
}
