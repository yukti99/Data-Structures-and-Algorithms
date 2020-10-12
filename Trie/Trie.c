// TRIE DATA STRUCTURE
// Representation of English Words
//  Insertion and Search

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 

#define A_size(a) sizeof(a)/sizeof(a[0]) 
#define Alpha_size (26) 
#define CharToIndex(c) ((int)c - (int)'a') 

 
struct TrieNode{ 
	struct TrieNode *children[Alpha_size]; 
	bool isEndOfWord; 
}; 

// Returns new trie node (initialized to NULLs) 
struct TrieNode *CreateNode(void){ 
	struct TrieNode *t = (struct TrieNode *)malloc(sizeof(struct TrieNode)); 	
	int i;
	t->isEndOfWord = false;
	for (i = 0; i < Alpha_size; i++) 
		t->children[i] = NULL; 
	return t; 
} 


void insert(struct TrieNode *root,char key[]){ 
	int level,index; 
	int length = strlen(key); 
	struct TrieNode *p = root; 

	for (level = 0; level < length; level++){		
		index = CharToIndex(key[level]); 		
		if (!p->children[index]) 
			p->children[index] = CreateNode(); 			
		p = p->children[index]; 
	} 
	p->isEndOfWord = true; 
} 

bool search(struct TrieNode *root,char key[]){ 
	int level,index; 
	int length = strlen(key); 
	struct TrieNode *p = root; 

	for (level = 0; level < length; level++){ 
		index = CharToIndex(key[level]); 
		if (!p->children[index]) 
			return false; 
		p = p->children[index]; 
	} 
	return (p != NULL && p->isEndOfWord); 
} 
int j=0;
// To  display the content of the trie
void DisplayTrie(struct TrieNode* root,char str[],int level){
	
	if (root->isEndOfWord){
		j++;
		str[level] = '\0';
		printf("%d.\t%s\n",j,str);
	}
	int i;
	for(i=0;i<Alpha_size;i++){
		if (root->children[i]){
			str[level] = i+'a';
			DisplayTrie(root->children[i],str,level+1);			
		}
	}
}
bool isLastNode(struct TrieNode* root){
	int i=0;
	for(i=0;i<Alpha_size;i++){
		if (root->children[i])
			return false;
	}
	return true;
}

// Auto-complete feature using Trie
void suggestions(struct TrieNode* root,char prefix[],int level){
	if (root->isEndOfWord){
		prefix[level] = '\0';
		printf("%s\n",prefix);
	}
	if (isLastNode(root))
		return;
	int i=0;
	for(i=0;i<Alpha_size;i++){
	
		if (root->children[i]){
			prefix[level] = i+'a';
			suggestions(root->children[i],prefix,level+1);
		}			
	}	
}
int AutoSuggestions(struct TrieNode* root,char query[]){
	struct TrieNode* p = root;
	int level;
	int n = strlen(query);
	for(level=0;level<n;level++){
		int index = CharToIndex(query[level]);
		if (!p->children[index])
			return 0;
		p = p->children[index];
	}
	bool isPrefix = (p->isEndOfWord == true);
	bool isLast = isLastNode(p);
	
	if (isPrefix && isLast){
		printf("%s\n",query);
		return -1;
	}
	if (!isLast){
		int level=strlen(query);
		suggestions(p,query,level);
		return 1;
	}
} 
int main(){	
	char words[][20] = {"the","yukti", "there", "answer", "any","by", "bye", "their","amazing","love","happiness","amaze","difficult","cat"};
	struct TrieNode *root = CreateNode(); 
	int i; 
	for (i = 0; i < A_size(words); i++) 
		insert(root, words[i]); 		
	char key[] = "answer";	
	if (search(root,key))
		printf("\n\"%s\" is Present in the Trie!!\n",key);
	else
		printf("\n\"%s\" is Not Present in the Trie!!\n",key);
	char str[30];
	int level = 0;
	printf("\nThe Words in Trie in Alphabetical Order : \n");
	DisplayTrie(root,str,level);
	printf("\n");
	printf("\nThe total number of word in Trie = %d\n",j);
	char query[30] = "an";
	printf("\nThe suggestions for \"%s\" are : \n",query);
	int a = AutoSuggestions(root,query);
	if (a == -1)
		printf("\nNo other strings found with this prefix !\n");
	else if (a == 0)
		printf("\nNo string found with this prefix!!\n");
	return 0; 
} 

