#include <stdio.h>
#include <stdlib.h>

struct Node {
	
	int data;
	struct Node* next;
	struct Node* prev;
};

void push(struct Node **head_ref,int item){
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = item;
	new_node->next = *head_ref;	
	new_node->prev = NULL;
	// change previous of head to new node
	if (*head_ref != NULL)
		(*head_ref)->prev = new_node;
	*head_ref = new_node;
}
void append(struct Node **head_ref,int item){
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = *head_ref;
	new_node->data = item;
	new_node->next = NULL;
	
	// if list is empty make the new node as the head node
	if (*head_ref == NULL){
		new_node->prev = NULL;
		*head_ref = new_node;
		return ;		
	}
	// else travserse till the end
	while(last->next != NULL){
		last = last->next;
	}
	last->next = new_node;
	new_node->prev = last;
}
void insertAfter(struct Node**head_ref,int key,int item){
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *temp = *head_ref;
	new_node->data = item;
	while(temp->next != NULL && temp->data != key){
		temp = temp->next;
	}
	// we have found the previous node
	new_node->next = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	// if insertion is not happening as the end
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	
}

void insertAt(struct Node** head,int pos,int item){
	
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = item;
	int c=0;
	struct Node* t = *head;
	// empty list
	if (*head == NULL){
		n->prev = NULL;
		*head = n;
		return ;
	}
	// insertion at beginning
	if (pos == 0){
		n->prev = NULL;
		n->next = *head;
		*head = n;
		return ;
	}
	
	while(c!= pos && t->next!= NULL){
		t = t->next;
		c++;
	}
	t = t->prev;
	n->next = t->next;
	n->prev = t;
	t->next = n;
	// insertion not happening at the end
	if (n->next != NULL){
		n->next->prev = n;		
	}	
	
}

struct Node* CreateList(int size){
	printf("Enter the Elements for the doubly linked list : ");
	struct Node *head = NULL;
	int x;
	for(int i=0;i<size;i++){
		scanf("%d",&x);
		append(&head,x);
	}
	//printf("Created successfully!\n");
	return head;		
	
}
// deletes the item passed as a parameter
void DeleteNode(struct Node** head_ref,int item){
	
	struct Node *temp = *head_ref;
	if (*head_ref == NULL)
		return ;
	while(temp != NULL && temp->data != item)
		temp = temp->next;
		
	// if node to be deleted is head node
	if (*head_ref == temp)
		*head_ref = temp->next;
		
	// if node to be deleted is NOT last node
	if (temp->next != NULL)
		temp->next->prev = temp->prev;
		
	// if node to be deleted is NOT first node
	if (temp->prev != NULL)
		temp->prev->next = temp->next;
	// free memory occupied by temp
	free(temp);
	return;	
}

int length(struct Node* head){
	
	struct Node* node = head;
	int l=0;
	while(node!= NULL){
		l++;
		node = node->next;
	}
	return l;
}
void middle(struct Node* head){
	
	int f=0;
	struct Node* slow = head, *fast = head ,*prev = head;
	if (head == NULL)
		return ;
	while(fast && fast->next){		
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
		if (fast == NULL){
		    f=1;
			break;
		}
	}
	if (f==1)
		printf("\nThe middle elements are [%d],[%d]\n",prev->data,slow->data);
	else
        printf("\nThe middle element is [%d]\n\n",slow->data);
	
}
void ReverseList(struct Node** head){
	
	struct Node *prev =NULL,*current = *head,*next;
	if (*head == NULL)
		return ;
	while(current != NULL){
		// swapping next and prev
		next = current->next; 
		current->next = current->prev;
		current->prev = next;
		// forward current
		prev = current;
		current = next;
	}
	// after all links are reversed make last node as head
	*head = prev;	
}

// for unsorted list
void remove_duplicates(struct Node **head){
	
	struct Node *p1 = *head, *p2, *temp;
	while(p1 != NULL && p1->next != NULL){
		
		p2 = p1;
		while(p2->next != NULL){
			
			if (p1->data == p2->next->data){
				temp = p2->next;
				p2->next = p2->next->next;
				free(temp);
			}
			else
				p2 = p2->next;
		}
		p1 = p1->next;
	}	
}
// for sorted lists
void dup_sorted(struct Node**head){
	
	struct Node *p1 = *head, *p2, *temp;
	while(p1 != NULL && p1->next != NULL){
		
		p2 = p1;
		while(p2->next != NULL){
			
			if (p1->data == p2->next->data){
				temp = p2->next;
				p2->next = p2->next->next;
				free(temp);
			}
			else
				break;
		}
		p1 = p1->next;
	}	
	
}
// for sorted lists
struct Node* Intersection(struct Node* a, struct Node* b)
{
  // same process as what we do when we create a linked list
  // create a node then create a double pointer to point at the node
  struct Node* c = NULL;
  struct Node** head = &c; // pointer to a pointer  
  
  while (a!=NULL && b!=NULL)
  {
    if (a->data == b->data)     // for common elements
    {      
		append(head, a->data);
	    head = &( (*head)->next );   
	    a = a->next;
	    b = b->next;
    }
    else if (a->data < b->data)
    	a=a->next;       
    else   
    	b=b->next;    
  }
  return(c);
}
bool isPresent (struct Node *head, int data){
    struct Node *t = head;
    while (t != NULL)
    {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}

struct Node *Union(struct Node *a, struct Node *b){
	
	struct Node *result = NULL;
	struct Node *p1 = a, *p2 = b;
	// insert all the elements of 1st list into result list
	while(p1 != NULL){
		
		append(&result,p1->data);
		p1 = p1->next;
	}
	// insert those elements from 2nd list into result list which are not present in 1st list
	while(p2 != NULL){
		if (!isPresent(result,p2->data))
			append(&result,p2->data);
		p2 = p2->next;
	}
	return result;
}
// for unsorted list
struct Node *getIntersection(struct Node *a,struct Node *b)
{
    struct Node *result = NULL; // creating new list
    struct Node *p1 = a;
 
    // Traverse list1 and search each element of it in
    // list2. If the element is present in list 2, then
    // insert the element to result
    while (p1 != NULL)    {
        if (isPresent(b, p1->data))
            append(&result, p1->data);
        p1 = p1->next;
    } 
    return result;
}
void pairwise_swap(struct Node* head){
	
	struct Node *p1 = head;
	struct Node *p2 = p1->next ;
	while(p2 != NULL){
		
		// swapping adjacent elements in linked list
		int t = p1->data;
		p1->data = p2->data;
		p2->data = t;
		
		p1 = p2->next;
		if (p2->next == NULL)
			break;  // otherwise segmentation fault will occur 
		p2 = p1->next;
	}
	
}

int isPalindrome(struct Node *head){
	
	struct Node *left = head;
	struct Node *right = left;
	if (left == NULL)
		return 1;
	while(right->next!= NULL)
		right = right->next;
		
	while(left!= right){
		
		if (left->data != right->data)
			return 0;
		
		left = left->next;
		right = right->prev;
	}
	return 1;
	
}
void printList(struct Node *head){
	
	printf("\nDoubly Linked List : ");
	struct Node* node = head;
	while(node!= NULL){
		printf("%d ",node->data);
		node = node->next;
	}
	printf("\n");
}


int main(){
	
	int i,n1,n2,p,e;
	printf("\nEnter the size of linked  list 1 and 2 = ");
	scanf("%d %d",&n1,&n2);
	struct Node *l1 = CreateList(n1);
	printList(l1);
	printf("\nPosition to insert : \n");
	scanf("%d",&p);
	printf("\nItem to insert : \n");
	scanf("%d",&e);
	insertAt(&l1,p,e);
	printList(l1);
	remove_duplicates(&l1);
	printList(l1);
	
	/*
	struct Node *l2 = CreateList(n2);
	pairwise_swap(l1);
	printList(l1);
	printf("\nAfter removing duplicates :\n");
	remove_duplicates(&l1);
	printList(l1);
	dup_sorted(&l2);
	printList(l2);
	struct Node *l3 = Union(l1,l2);
	printf("After Union : ");
	printList(l3);	
	printf("Length = %d\n",length(l1));
	push(&l1,0);
	insertAfter(&l1,6,9);
	printf("Length = %d\n",length(l1));
	DeleteNode(&l1,1);	
	middle(l2);
	printf("\nAfter Reversing the doubly linked list : ");
	ReverseList(&l1);
	printList(l1);
	if (isPalindrome(l1))
		printf("Yes, list is a Palindrome!\n");
	else
		printf("No, list is NOT a Palindrome!\n");
	return 0;*/
}
