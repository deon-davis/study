#include<stdio.h>
#include<stdlib.h>

struct Node
{
 int data;
 struct Node* next;
};

/*insert at the begining of the linked list*/

void push(struct Node **head_ref, int new_dat)
{
 struct Node* new_node;
 new_node = (struct Node*)malloc(sizeof(struct Node));
 new_node->data = new_dat;
 new_node->next = *(head_ref);
 *(head_ref) = new_node;
}

/*insert at the end of linked list*/

void append(struct Node **head_ref, int new_dat)
{
 struct Node* new_node;
 new_node = (struct Node*) malloc(sizeof(struct Node));
 new_node->data = new_dat;
 new_node->next = NULL;
 struct Node* last;
 last = *(head_ref);
 if(last == NULL)
 {
  *(head_ref) = new_node;
 }
 else
 {
  while(last->next != NULL)
   last = last->next;
  last->next = new_node;
 }
}

void insertafter(struct Node* prev_node, int new_dat)
{
 if(prev_node == NULL)
 {
  printf("the given node is invalid");
 }
 else
 {
  struct Node* new_node;
  new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_dat;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
 }
}

void transverse(struct Node* node)
{
 while(node != NULL)
 {
  if(node->next != NULL)
  printf("|| %d ||==>",node->data);
  else
  printf("|| %d ||\n",node->data);
  node = node->next;
 }
}


int main()
{
 struct Node* head = NULL;
 struct Node* temp;
 int inp_dat,option=1,locate,i;
 while(option)
 {
 printf("1.push\n2.append\n3.insertafter\n4.print\n");
 printf("Enter option:");
 scanf("%d",&option);
 switch(option)
 {
  case 1:
  printf("Enter data:");
  scanf("%d",&inp_dat);
  push(&head,inp_dat);
  break;
  case 2:
  printf("Enter data:");
  scanf("%d",&inp_dat);
  append(&head,inp_dat);
  break;
  case 3:
  printf("Enter data:");
  scanf("%d",&inp_dat);
  printf("Enter the location after which to insert:");
  scanf("%d",&locate);
  temp = head;
  for(i=0;(i<locate && temp->next != NULL);i++)
  temp=temp->next;
  insertafter(temp,inp_dat);
  break;
  case 4:
  transverse(head);
  break;
 }
}
return 0;
}



