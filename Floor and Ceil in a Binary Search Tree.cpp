#include <stdio.h>
#include <malloc.h>
#include <limits.h>


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

void insertRecursive(struct node * &root,int data){
    if(root == NULL) {root =  newNode(data); return ;}
    if(data < root->key) insertRecursive(root->left,data);
    else insertRecursive(root->right,data);

}

void inorder(struct node * root){
    if (root == NULL) return ;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}


void findFloorCeilRecursive(struct node * root, struct node *&floor, struct node *& ceil, int data){
    if(root == NULL) return;
    if(data == root->key){floor = root;ceil = root;}
    else if (data < root->key){ceil = root;
        findFloorCeilRecursive(root->left, floor, ceil, data);}
    else{floor = root;
        findFloorCeilRecursive(root->right, floor, ceil, data);}
}
void findFloorCeilIterative(struct node * root, struct node * &floor, struct node * &ceil, int data)
{
    while (root)
    {
        if (root->key == data)
        {
            floor = root;
            ceil = root;
            break;
        }

        else if (data < root->key)
        {
            ceil = root;
            root = root->left;
        }

        else
        {
            floor = root;
            root = root->right;
        }
    }
}

int main(){

            /* Construct below tree
                           8
                         /   \
                        /     \
                       4       10
                      / \     /  \
                     /   \   /    \
                    2     6 9      12
                */

    int keys[] = { 2, 4, 6, 8, 9, 10, 12 };
    int len1 = (*(&keys +1) - keys);
    struct node * root = NULL;
    for (int i = 0; i < len1; ++i) {
        insertRecursive(root,keys[i]);
    }
    inorder(root);
    printf("\n");
    for (int j = 0; j < 15; ++j) {
        struct node * ceil = NULL;struct node * floor = NULL;
        findFloorCeilRecursive(root, floor, ceil, j);
        printf("%d-->%d and %d\n",j,(floor) ? floor->key:-1,(ceil)? ceil->key:-1);
    }
    printf("\n");
    for (int j = 0; j < 15; ++j) {
        struct node * ceil = NULL;struct node * floor = NULL;
        findFloorCeilIterative(root, floor, ceil, j);
        printf("%d-->%d and %d\n",j,(floor) ? floor->key:-1,(ceil)? ceil->key:-1);
    }
    return 0;
}
