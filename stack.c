#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node *next;
};

struct Node* new_node(int dat_in)
{
struct Node *new;
new = (struct Node*)malloc(sizeof(struct Node));
new->data = dat_in;
new->next = NULL;
return new;
}

int push(struct Node **head_ref,int data_in)
{
struct Node *temp;
int status = 0;
temp = new_node(data_in);
if(temp)
status = 1;
temp->next = *(head_ref);
*(head_ref) = temp;
return status;
}

int pop(struct Node **head_ref)
{
 struct Node *temp;
 temp = *(head_ref);
 if(!temp)
 return 0;
 *(head_ref) = temp->next;
 free(temp);
 return 1;
}

int isEmpty(struct Node **head_ref)
{
 if(!(*head_ref))
  return 1;
 else
  return 0;
}

int peek(struct Node **head_ref)
{
 if(*head_ref)
 return (*head_ref)->data;
 else
 {
 printf("Stack underflow");
 return -1;
 }
}

void print_stack(struct Node **head_ref)
{
 struct Node *temp = *(head_ref);
 while(temp != NULL)
 {
  printf("  --------\n");
  printf("     %d \n\r",temp->data);
  printf("  --------\n");
  temp = temp->next;
 }
}

int main()
{
 struct Node *head = NULL;
 int option =1, input_data,topdat;
 while(option)
 {
  printf("------------------\n");
  printf("1.push\n2.pop\n3.peek\n4.print\n");
  printf("------------------\n");
  printf("Enter the option:");
  scanf("%d",&option);
  switch(option)
  {
   case 1:
   printf("Enter data:");
   scanf("%d",&input_data);
   if(!push(&head,input_data))
    printf("stack oerflow\n");
   break;
   case 2:
   if(!pop(&head))
    printf("stack underflow\n");
   break;
   case 3:
   topdat = peek(&head);
   printf("data %d\n",topdat);
   break;
   case 4:
   print_stack(&head);
   break;
  }
 }
return 0;
}



