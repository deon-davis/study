#include<stdio.h>
#include<stdlib.h>

struct Node
{
char data;
struct Node *next;
};

struct Node* new_node(char dat_in)
{
struct Node *new;
new = (struct Node*)malloc(sizeof(struct Node));
new->data = dat_in;
new->next = NULL;
return new;
}

void push(struct Node **head_ref,char data_in)
{
struct Node *temp;
temp = new_node(data_in);
temp->next = *(head_ref);
*(head_ref) = temp;
}

char pop(struct Node **head_ref)
{
 struct Node *temp;
 char out;
 temp = *(head_ref);
 if(!temp)
 {
 printf("stack underflow\n");
 return 0;
 }
 out = temp->data;
 *(head_ref) = temp->next;
 free(temp);
 return out;
}

int isEmpty(struct Node **head_ref)
{
 if(!(*head_ref))
  return 1;
 else
  return 0;
}


void print_stack(struct Node **head_ref)
{
 struct Node *temp = *(head_ref);
 while(temp != NULL)
 {
  printf("%c ",temp->data);
  temp = temp->next;
 }
}

int main()
{
 struct Node *head = NULL;
 int i,set;
 char express[20];
 printf("enter the expression:");
 scanf("%s",express);
 for(i =0;express[i] != '\0';i++)
 {
  print_stack(&head);
  printf("\n");
  switch(express[i])
  {
  case '(':
  case '{':
  case '[':
  push(&head,express[i]);
  break;
  case ')':
  if(pop(&head) == '(')
  set = 1;
  else
  set = 0;
  break;
  case '}':
  if(pop(&head) == '{')
  set = 1;
  else
  set = 0;
  break;
  case ']':
  if(pop(&head) == '[')
  set = 1;
  else
  set = 0;
  break;
  }
 }
 if( set && isEmpty(&head))
 printf("balanced expression\n");
 else
 printf("Unbalanced expression\n");
return 0;
}



