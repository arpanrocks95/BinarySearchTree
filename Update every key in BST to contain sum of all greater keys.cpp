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

void convert(struct node * root,int &totalsum){
    if(root ==NULL) return;
    convert(root->left,totalsum);
    totalsum = totalsum - root->key;
    root->key += totalsum;
    convert(root->right,totalsum);
}


int findtotalsum(struct node * root){
    if(root == NULL) return 0;
    return root->key + findtotalsum(root->left) + findtotalsum(root->right);
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
    int totalsum = findtotalsum(root);
    convert(root,totalsum);
    inorder(root);
    return 0;
}
