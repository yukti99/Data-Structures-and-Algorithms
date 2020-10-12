#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define Char_size 36
#define CharToIndex(c) ((int)c - (int)'a')
#define NumToIndex(c) ((int)c - (int)'0')

struct additional{
	bool isEndofWord ;
	int count;
};


struct TrieNode{
	
	struct TrieNode* character[Char_size];
	struct TrieNode* number[10];
	struct additional *a;
};

struct TrieNode* CreateNode(void){
	struct TrieNode* t = (struct TrieNode*)malloc(sizeof(struct TrieNode));
	t->a->isEndofWord = false;
	t->a->count = -1;
	int i=0;
	for(i=0;i<Char_size;i++){
		t->character[i] = NULL;
	}
	for(i=0;i<10;i++){
		t->number[i] = NULL;
	}
	return t;
}
void insert(struct TrieNode* root,char key[]){
	struct TrieNode* temp = root;
	int i=0,l = strlen(key);
	for(i=0;i<l;i++){
		// the char of the key is a number
		if (key[i] - 'a'){
			if (temp->number[key[i]-'0'] == NULL)
				temp->number[key[i]-'0'] = CreateNode();				
			
			temp = temp->number[key[i]-'0'];
		}
		// the char of the key is an alphabet
		else{
			if (temp->character[key[i] - 'a'] == NULL)
				temp->character[key[i] - 'a'] = CreateNode();
			temp = temp->character[key[i] - 'a'];			
		}
	}
	temp->a->isEndofWord = true;
		
}

struct additional* search(struct TrieNode* root,char key[]){
	struct additional* x;
	x->count = -1;
	x->isEndofWord = false;
	
	if (root == NULL){
		return x;		
	}
	struct TrieNode* t = root;
	int i=0;
	for(i=0;i<strlen(key);i++){
		if (key[i]-'a'<0){
			t = t->number[key[i]-'0'];
		}
		else{
			t = t->character[key[i]-'a'];			
		}
		if (t == NULL)
			return x;
	}
	x.count = t->a.count;
	x.isEndofWord = t->a.isEndofWord;
	return x;
	
	
}
void update(struct TrieNode* root,char key[],int y){
	struct TrieNode* t = root;
	int i=0;
	for(i=0;i<strlen(key);i++){
		if (key[i]-'a' < 0){
			t = t->number[key[i]-'0'];
		}
		else{
			t = t->character[key[i]-'a'];
		}
	}
	t->a->count = y;
	
	
}
void Usernames(char username[][30],int n){
	struct TrieNode* root = CreateNode();
	int i=0;
	for(i=0;i<n;i++){
		char p[100] = username[i];
		struct additional* x = search(root,p);
		if (x.isEndofWord == false){
			printf("%s\n",p);
			insert(root,p);
			return ;
		}
		int y = x.count+1;
		while(1){
			if (search(root,p))
		}
		 
	}
	
}

int main(){
	
	char name[][30] = { "geek", "geek0", "geek1", "geek" }; 
    int n = sizeof(name) / sizeof(name[0]); 
    Usernames(name, n); 
    return 0; 
}
