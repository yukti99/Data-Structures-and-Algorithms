#include <stdio.h> 
#include <conio.h> 
void create();
void display();
void insert();
void clean();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
 
typedef struct node
{
 int data;
 struct node *link;
}node;
node *init=NULL, *ptr, *temp;
int ch;
 
int main()
{
 clrscr();
 while(1){
  printf("\n***SINGLE LINKED LIST OPERATIONS:****");
  printf("\n                MENU                             ");
  printf("\n---------------------------------------");
  printf("\n 1.Create     ");
  printf("\n 2.Display   ");
  printf("\n 3.Insert ");
  printf("\n 4. Delete");
  printf("\n 5.Exit       ");
  printf("\n--------------------------------------\n");
  printf("Enter your choice:\t");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
     create();
     break;
   case 2:
     display();
     break;
   case 3:
     insert();
     break;
   case 4:
     clean();
     break;
   case 5:
     exit(0);
   default:
     printf("\n Wrong Choice:\n");
     break;
  }
  
 }
 return 0;
 
}
 
void create()
{
 struct node *temp,*ptr;
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
 {
  printf("\nOut of Memory Space:\n");
  exit(0);
 }
 printf("\nEnter the data value for the node:\t");
 scanf("%d",&temp->data);
 temp->link=NULL;
 if(init==NULL)
 {
  init=temp;
 }
 else
 {
  ptr=init;
  while(ptr->link!=NULL)
  {
   ptr=ptr->link;
  }
  ptr->link=temp;
 }
}
 
void display()
{
 struct node *ptr;
 if(init==NULL)
 {
  printf("\nList is empty:\n");
  return;
 }
 else
 {
  ptr=init;
  printf("\nThe List elements are:\n");
  while(ptr!=NULL)
  {
   printf("%d\t",ptr->data );
   ptr=ptr->link;
  }
 }
}
 
void insert()
{
 int ch;
 printf("\n1. Insert at beginning \n2. Insert at last \n3. Insert at specific location");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
   insert_begin();
   break;
  case 2:
   insert_end();
   break;
  case 3:
   insert_pos();
   break;
  default:
   printf("Invalid choice");
 }
}
 
void insert_begin()
{
 struct node *temp;
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
 {
  printf("\nOut of Memory Space:\n");
  return;
 }
 printf("\nEnter the data value for the node:\t" );
 scanf("%d",&temp->data);
 temp->link =NULL;
 if(init==NULL)
 {
  init=temp;
 }
 else
 {
  temp->link=init;
  init=temp;
 }
}
 
void insert_end()
{
 struct node *temp,*ptr;
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
 {
  printf("\nOut of Memory Space:\n");
  return;
 }
 printf("\nEnter the data value for the node:\t" );
 scanf("%d",&temp->data);
 temp->link =NULL;
 if(init==NULL)
 {
  init=temp;
 }
 else
 {
  ptr=init;
  while(ptr->link!=NULL)
  {
   ptr=ptr->link ;
  }
  ptr->link =temp;
 }
}
 
void insert_pos()
{
 struct node *ptr,*temp;
 int i,pos;
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
 {
  printf("\nOut of Memory Space:\n");
  return;
 }
 printf("\nEnter the position for the new node to be inserted:\t");
 scanf("%d",&pos);
 printf("\nEnter the data value of the node:\t");
 scanf("%d",&temp->data) ;
 
 temp->link=NULL;
 if(pos==0)
 {
  temp->link=init;
  init=temp;
 }
 else
 {
  for(i=0,ptr=init;ilink;
   if(ptr==NULL)
   {
    printf("\nPosition not found:[Handle with care]\n");
    return;
   }
  }
  temp->link =ptr->link ;
  ptr->link=temp;
 }
}
 
void delete_begin()
{
 struct node *ptr;
 if(ptr==NULL)
 {
  printf("\nList is Empty:\n");
  return;
 }
 else
 {
  ptr=init;
  init=init->link ;
  printf("\nThe deleted element is :%d\t",ptr->data);
  free(ptr);
 }
}
 
void delete_end()
{
 struct node *temp,*ptr;
 if(init==NULL)
 {
  printf("\nList is Empty:");
  exit(0);
 }
 else if(init->link ==NULL)
 {
  ptr=init;
  init=NULL;
  printf("\nThe deleted element is:%d\t",ptr->data);
  free(ptr);
 }
 else
 {
  ptr=init;
  while(ptr->link!=NULL)
  {
   temp=ptr;
   ptr=ptr->link;
  }
  temp->link=NULL;
  printf("\nThe deleted element is:%d\t",ptr->data);
  free(ptr);
 }
}
 
void delete_pos()
{
 int i,pos;
 struct node *temp,*ptr;
 if(init==NULL)
 {
  printf("\nThe List is Empty:\n");
  exit(0);
 }
 else
 {
  printf("\nEnter the position of the node to be deleted:\t");
  scanf("%d",&pos);
  if(pos==0)
  {
   ptr=init;
   init=init->link ;
   printf("\nThe deleted element is:%d\t",ptr->data );
   free(ptr);
  }
  else
  {
   ptr=init;
   for(i=0;ilink ;
    if(ptr==NULL)
    {
     printf("\nPosition not Found:\n");
     return;
    }
   }
   temp->link =ptr->link ;
   printf("\nThe deleted element is:%d\t",ptr->data);
   free(ptr);
  }
 }
}
 
void clean()
{
 int choice;
 printf("\n1. Delete from beginning \n2. Delete from last \n3. Delete specific location");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
   delete_begin();
   break;
  case 2:
   delete_end();
   break;
  case 3:
   delete_pos();
   break;
  default:
   printf("Invalid choice");
 }
 
}
 
