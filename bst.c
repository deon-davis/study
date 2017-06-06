#include<stdio.h>
#include<stdlib.h>

struct Node
{
 int data;
 struct Node *left;
 struct Node *right;
};

struct Node *new_node(int input)
{
 struct Node *temp;
 temp = (struct Node*)malloc(sizeof(struct Node));
 temp->data = input;
 temp->left = temp->right = NULL;
 return temp;
}

/* inorder trversal   left--root--right*/
void inorder(struct Node *root)
{
 if(root != NULL)
 {
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
 }
}

/*preorder traversal  root--left--right*/
void preorder(struct Node *root)
{
 if(root != NULL)
 {
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
 }
}

/*postorder traversal left--right--root*/
void postorder(struct Node *root)
{
 if(root != NULL)
 {
  postorder(root->left);
  postorder(root->right);
  printf("%d ",root->data);
 }
}

/*insert new node in BST*/
struct Node *insert(struct Node *node, int key)
{
 if(node == NULL)
 return new_node(key);
 if(key < node->data)
 node->left = insert(node->left,key);
 else if( key > node->data)
 node->right = insert(node->right,key);
 return node;
}

int main()
{
 struct Node *root = NULL;
 struct Node *now = NULL;
 root = insert(root,50);
 now = insert(root,30);
 now = insert(root,20);
 now = insert(root,40);
 now = insert(root,70);
 now = insert(root,60);
 now = insert(root,80);
printf("\ninorder print ");
inorder(root);
printf("\npostorder print ");
postorder(root);
printf("\npreorder print ");
preorder(root);
return 0;
}

