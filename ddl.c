#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node *next;
struct Node *prev;
};

struct Node *create_newnode(int input)
{
 struct Node *newnode;
 newnode = (struct Node*)malloc(sizeof(struct Node));
 newnode->data = input;
 newnode->next = NULL;
 newnode->prev = NULL;
 return newnode;
}

void push(struct Node **head_ref,int inp_dat)
{
 struct Node *temp;
 temp = create_newnode(inp_dat);
 if( *(head_ref) != NULL)
 {
  temp->next = *(head_ref);
  (*head_ref)->prev = temp;
 }
 *(head_ref) = temp;
}

void insertafter(struct Node *prev_node, int inp_dat)
{
 struct Node *new_node;
 if(prev_node->next)
 {
  new_node = create_newnode(inp_dat);
  new_node->next = prev_node->next;
  prev_node->next->prev = new_node;
  prev_node->next = new_node;
  new_node->prev = prev_node;
 }
 else
 {
  new_node = create_newnode(inp_dat);
  new_node->prev = prev_node;
  prev_node->next = new_node;
 }
}

void append(struct Node **head_ref, int inp_dat)
{
 struct Node *new_node,*temp;
 temp = *head_ref;
 new_node = create_newnode(inp_dat);
 if(temp != NULL)
 {
  while(temp->next != NULL)
   temp = temp->next;
  temp->next = new_node;
  new_node->prev = temp;
 }
 else
 *(head_ref) = new_node;
 }

void print(struct Node **head_ref)
{
 struct Node *temp;
 temp = *(head_ref);
 while(temp != NULL)
 {
  printf("%d ",temp->data);
  temp = temp->next;
 }
}

void revprint(struct Node **head_ref)
{
 struct Node *temp;
 temp = *(head_ref);
 while(temp->next != NULL)
  temp =temp->next;
 while(temp != NULL)
 { 
  printf("%d ",temp->data);
  temp = temp->prev;
 }
}

int main()
{
 struct Node *head = NULL,*temp;
 int opt=1,input,i,pos;
 while(opt)
 {
  printf("\n----------------");
  printf("\n1.push\n2.append\n3.insertafter\n4.print\n5.print reverse");
  printf("\n----------------");
  printf("\nEnter option: ");
  scanf("%d",&opt);
  switch(opt)
  {
   case 1:
   printf("Enter data:");
   scanf("%d",&input);
   push(&head,input);
   break;
   case 2:
   printf("Enter data:");
   scanf("%d",&input);
   append(&head,input);
   break;
   case 3:
   printf("Enter data:");
   scanf("%d",&input);
   printf("Enter position:");
   scanf("%d",&pos);
   temp = head;
   if(temp)
   {
    for(i = 0; ((i< pos) && (temp->next != NULL)); i++)
     temp = temp->next;
    insertafter(temp,input);
   }
   break;
   case 4:
   print(&head);
   break;
   case 5:
   revprint(&head);
   break;
  }
 }
return 0;
}

 
