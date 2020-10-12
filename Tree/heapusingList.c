#include <stdio.h>
#include <stdlib.h>


struct Node{
	int data;
	struct node*left,*right;
};

struct node*root;
int front,rear;
int height=1;
int top;

struct Node**createqueue(){
	struct node**q=(struct node**)malloc(sizeof(struct node*)*100);
	front=-1;
	rear=-1;
	//printf("a\n");
	return(q);

}
struct node**createstack(){
	struct node**s=(struct node**)malloc(sizeof(struct node*)*20);
	top=-1;
	return(s);
}
int emptystack(struct node**s){
	return(top==-1);
}
void push(struct node** s,struct node* new){
	s[++top]=new;


}
struct node* pop(struct node**s){
	if(!emptystack(s)){
		return(s[top--]);
	}
	return NULL;
}
int topofstack(struct node**s){
	return(top);
}

int preordertraverse(struct node*root){
	struct node**s=createstack();
	while(1){
		while(root){
			push(s,root);
			printf("%d ",root->data);
			root=root->left;
		}
		if(emptystack(s))
			break;
		root=pop(s);
		root=root->right;
	}
}
int empty(struct node**q){
	return(front==-1);
}
void enqueue(struct node**q,struct node*new){
	q[++rear]=new;
	if(front==-1){
		front=rear;
	}
}
struct node*dequeue(struct node**q){
	if(!empty(q)){
		front++;
		return(q[front-1]);
	}
	return NULL;
}
/*int levelinsert(int data){
	
	struct node*new=malloc(sizeof(struct node));
	new->data=data;
	new->right=NULL;
	new->left=NULL;
	if(!root){
		root=new;
		printf("%d\n",root->data);
		return(0);
	}

	struct node**q=createqueue();
	struct node*temp;
	enqueue(q,root);
	while(!empty(q)){
		//printf("b\n");
		temp=dequeue(q);
		//printf("c\n");
		if(temp->left){
			enqueue(q,temp->left);
		
			//printf("d\n");
		}
		else{
			temp->left=new;
			printf("%d ",new->data);
			return(0);
		}
		if(temp->right){
			enqueue(q,temp->right);
			//printf("e\n");
		}

		else{
			temp->right=new;
			printf("%d ",new->data);
			return(0);
		}
	}
	return(0);



}
int traverse(struct node*root){

	
	if(root){
		printf("%d ",root->data);
		
		if(root->left){
			
			traverse(root->left);
			
		}
		if(root->right){
			traverse(root->right);
		}
	}
	return(0);

}
//searching by level order traversal
int search(int data){
	struct node**q=createqueue();
	struct node*temp;
	enqueue(q,root);
	while(!empty(q)){
		temp=dequeue(q);
		if(temp->data==data){
			printf("found at height %d",height);
			return(0);
		}
		if(temp->left){
			enqueue(q,temp->left);
			height++;
		}
		if(temp->right){
			enqueue(q,temp->right);

		}

	}
	return(0);

}*/
/*int searchbyrecur(struct node*root,int data){
	if(root==NULL)
		return(0);
	if(root->data==data){
		return(1);
	}
	int temp=searchbyrecur(root->left,data);
	if(temp!=0) return(temp);
	else return(searchbyrecur(root->right,data));
}
int finddiameter(struct node*root){
	if(!root)
		return(0);
	int left,right;
	left=finddiameter(root->left);
	right=finddiameter(root->right);
	if(left>=right)
		return(left+1);
	else
		return(right+1);
}*/
/*void roottoleafpath(struct node*root){
	struct node**s=createstack();
	int j=0;
	int i;
	int a[100];
	while(1){
		while(root){
			push(s,root);
			a[j]=root->data;
			j++;
			root=root->left;

		}
		if(emptystack(s)) break;
		root=pop(s);
		printf("\n");
		if(!root->left && !root->right){

			for(i=0;i<=j;i++){
				printf("%d ",a[i]);

			}
			j=topofstack(s)+1;


			printf("\n");
		}
		root=root->right;
	}

}*/
/*struct node*mirror(struct node*root){
	if(!root) return (NULL);
	struct node*temp;
	mirror(root->left);
	mirror(root->right);
	temp=root->left;
	//printf("%d",temp->data);
	root->left=root->right;
	//printf("%d ",left->data);
	root->right=temp;
	return(root);

}*/
struct node*maxheap(struct node*root,int x){
	struct node*new=malloc(sizeof(struct node));
	new->left=NULL;
	new->right=NULL;
	new->data=x;
	if(root==NULL){
		root=new;
		return(root);
	}
	struct node**q=createqueue();
	struct node*temp=root;
	struct node**s=createstack();
	push(s,temp);
	while(temp){
		if(temp->left) enqueue(q,temp->left);
		else{
			temp->left=new;
			new=temp->left;
			break;
		}
		if(temp->right) enqueue(q,temp->right);
		else{
			temp->right=new;
			new=temp->right;
			break;
		}
		temp=dequeue(q);
		push(s,temp);
	}
	struct node*temp2;
	int y;
	while(!emptystack(s)){
		temp2=pop(s);
		if(temp2->data<new->data){
			y=new->data;
			new->data=temp2->data;
			temp2->data=y;
			new=temp2;

		}
	}
	return(root);
}

void main(){
	int a[]={32,15,20,30,12,25,16};
	int i;
	for(i=0;i<7;i++){
		root=maxheap(root,a[i]);
	}
	//root=mirror(root);
	printf("\n");
	preordertraverse(root);
	//printf("\nsearch of 15=%d\n",searchbyrecur(root,15));
	//printf("the diameter = %d",finddiameter(root));
	//roottoleafpath(root);



}


