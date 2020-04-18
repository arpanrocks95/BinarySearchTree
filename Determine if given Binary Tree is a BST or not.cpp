#include <stdio.h>
#include <malloc.h>



/* nodes for queue and tree node*/
struct node {
    int key;
    struct node * left;
    struct node * right;
};

/* function for creating new node of tree*/
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}


void checkBstOrNot(node *root,node * parent,int & condition)
{
    if (root == NULL)
        return;
    if(root->left) {
        if(root->left->key > root->key || (root->left->key < root->key && root->left->key < parent->key) ){
            condition = 0;
            if(parent == root) condition = 1;
        }
    }
    if(root->right) if(  root->right->key < root->key) condition = 0;
    checkBstOrNot(root->left,root,condition);
    checkBstOrNot(root->right,root,condition);
}





void check(node* root)
{
    int condition = 1;
    checkBstOrNot(root,root,condition);
    if(condition) printf("yes its a bst ");
    else printf("no its not a binary tree");
}

int main(){


    /* Construct below Tree
                 20
                /  \
              10    30
                   /  \
                  5    40
    */

    struct node *root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(5);
    root->right->right = newNode(40);  //replace 5 by 35 and 25
    check(root);



    return 0;
}
