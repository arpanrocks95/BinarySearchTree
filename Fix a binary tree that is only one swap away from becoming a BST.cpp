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

void fix(struct node * root){
    if(root == NULL) return;
    if(root->left && root->left->key > root->key && root->right && root->right->key < root->key){
        int temp = root->left->key;
        root->left->key = root->right->key;
        root->right->key = temp;
    }
    fix(root->left);
    fix(root->right);
}




int main(){

/* Construct below tree
		   5
		 /   \
		/	 \
	   3	   8
	  / \	 / \
	 /   \   /   \
	2	 4 6	10   */

    int keys[] = { 5, 3, 2, 4, 6, 8, 10 };
    int len1 = (*(&keys +1) - keys);
    struct node * root = NULL;
    for (int i = 0; i < len1; ++i) {
        insertRecursive(root,keys[i]);
    }
    inorder(root);
    printf("\n");
    int temp = root->left->left->key;
    root->left->left->key = root->left->right->key;
    root->left->right->key = temp;
    inorder(root);
    printf("\n");
    fix(root);
    inorder(root);
    return 0;
}
