#include <stdio.h>
#include <stdlib.h>
 
struct node
{
     int data;
     struct node* left;
     struct node* right;
};
 
struct node* newNode(int data)
{
     struct node* node = (struct node*)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     return(node);
}

void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data); 
     printInorder(node->right);
}

 
void swapTree(struct node*node)
{
    if(node==NULL) return;
    struct node*temp=node->left;
    node->left=node->right;
    node->right=temp;
    swapTree(node->left);
    swapTree(node->right);
}
int main()
{
     struct node *root  = newNode(8);
     root->left             = newNode(5);
     root->right           = newNode(4);
     root->right->right     = newNode(11);
     root->right->right->left     = newNode(3);
     root->left->left     = newNode(9);
     root->left->right   = newNode(7);
     root->left->right->left   = newNode(1);
     root->left->right->right   = newNode(12);
     root->left->right->right->left   = newNode(2);
     printf("\n Inorder traversal of binary tree is \n");
     printInorder(root); 
     swapTree(root);
     printf("\n After swap Inorder traversal of binary tree is \n");
     printInorder(root); 

      return 0;
}
/*
        1                ==>                1
      /   \                               /   \  
     2     3                             3     2
   /   \                                      / \ 
  4     5                                    5   4
Inorder: 4,2,5,1,3                       3,1,5,2,4
*/  

// code source: https://gist.github.com/shankernaik/8488012
