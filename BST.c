#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(struct node *root,int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node * insertNode(struct node* root,int value)
{
    
  if (root==NULL)
  {
    return createNode(root,value);
  }
  if (root->data==value)
    {
        printf("Alredy in the list\n");
       return 0;
    }
  
  if (value<root->data)
  {
    root->left =insertNode(root->left,value); 
    
  }
  else{
     root->right =insertNode(root->right,value); 
  }
  return root;
}

struct node* minvalue(struct node*root)
{
    if(root==NULL)
    {
        return NULL;
    }
    if (root->left)
    return minvalue(root->left);
    else 
    return root;

}

struct node *deleteNode(struct node* root,int value)
{
   if(root==NULL)
   return root;

   if (value <root->data)
   root->left=deleteNode(root->left,value);
   else if(value>root->data)
   root->right=deleteNode(root->right,value);
   else{
    if(root->left==NULL)
    return root->right;

    else if(root->right==NULL)
    return root ->left;

    root->data = minvalue(root->right);
    //if both the node are not NULL
   
    root->right=deleteNode(root->right,root->data);
    //return root->right;
   }
   
   return root;
}

struct node *postorderTraversal(struct node* root)
{
    if(root!=NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ",root->data);

    }
}

struct node *inorderTraversal(struct node* root)
{ 
    if(root!=NULL)
    {
         inorderTraversal(root->left);
         printf("%d ",root ->data);
         inorderTraversal(root->right);
    }
 
 
}


int main()
{
    struct node *root = NULL;
    int choise, item;
    do
    {
        printf("***Main Menu***");
        printf("\n1) Insert elemet\n2) Delete\n3)Display\n4)Exit\n");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
        {
            printf("Enter the element to insert :\n");
            scanf("%d", &item);
            root = insertNode(root, item);
           
            break;
        }
        case 2:
        {
            printf("Enter the Element to delete: \n");
            scanf("%d", &item);
            root = deleteNode(root, item);
            printf("Node Deleted\n");
            break;
        }
        case 3:
        {
            printf("Inorder Traversal of tree \n");
            inorderTraversal(root);
            printf("\nPost order Traversal of tree \n");
            postorderTraversal(root);
        break;
        }
        case 4:
        {
            exit(0);
        }
        default:
        {
            printf("Enter a valid option\n");

        }
        }
} while(choise !=4);
    


return 0;
}