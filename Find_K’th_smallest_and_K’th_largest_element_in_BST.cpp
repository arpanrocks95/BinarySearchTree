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


int  kthLargest(struct node * root,int k,int *  i){
    if(root == NULL) return INT_MAX;
    int left = kthLargest(root->right,k,i);
    if(left != INT_MAX) return left;
    if(++*i == k) return root->key;
    return kthLargest(root->left,k,i);
}
int  kthMinimum(struct node * root,int k,int *  i){
    if(root == NULL) return INT_MAX;
    int left = kthMinimum(root->left,k,i);
    if(left != INT_MAX) return left;
    if(++*i == k) return root->key;
    return kthMinimum(root->right,k,i);
}


int main(){

                    /* Construct below tree
                      15
                     /   \
                    /	  \
                   10	  20
                  / \	  / \
                 /   \   /   \
                8	 12 16   25
                */
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
    int len1 = (*(&keys +1) - keys);
    struct node * root = NULL;
    for (int i = 0; i < len1; ++i) {
        insertRecursive(root,keys[i]);
    }
    inorder(root);
    printf("\n");
    int  i = 0;
    int res = kthLargest(root,2,&i);
    int j = 0;
    int res1 = kthMinimum(root,2,&j);
    if(res != INT_MAX) printf("%d is k th largest and %d is k th minimum\n",res,res1);
    return 0;
}
