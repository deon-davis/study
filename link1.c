#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

int main()
{
 void transverse(struct Node *temp)
 {
  while(temp != NULL)
  {
   printf("%d",temp->data);
   temp = temp->next;
  }
 }
 struct Node* head = NULL;
 struct Node* second = NULL;
 struct Node* third = NULL;

 head = (struct Node*)malloc(sizeof(struct Node));
 second = (struct Node*)malloc(sizeof(struct Node));
 third = (struct Node*)malloc(sizeof(struct Node));
 head->data = 1;
 head->next = second;

 second->data = 2;
 second->next = third;

 third->data =3;
 third->next = NULL;

 transverse(head);
 free(head);
 free(second);
 free(third);
return 0;
}



 
