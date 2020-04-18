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

void  LCARecursive(struct node * root,int data1,int data2,struct node * &lca){
    if(root == NULL) return ;
    if(root->key > (data1 > data2)? data1:data2) LCARecursive(root->left,data1,data2,lca);
    else if(root->key < (data1 < data2)? data1:data2) LCARecursive(root->right,data1,data2,lca);
    if((root->key >data1 && root->key < data2) || (root->key < data1 && root->key >data2)){
        if(lca == NULL) lca = root;
        else if(lca->key > root->key) lca = root;

    }
}

void  LCAIterative(struct node * root,int data1,int data2,struct node * &lca){
    if(root == NULL) return ;
    int cond = 1;
    while(cond){

        if((root->key > (data1 > data2)? data1:data2) ) if(root->left)root = root->left; else cond = 0;
        else if((root->key < (data1 < data2)? data1:data2) ) if(root->right)root = root->right; else cond = 0;
        if((root->key >data1 && root->key < data2) || (root->key < data1 && root->key >data2)){
            if(lca == NULL) lca = root;
            else if(lca->key > root->key) lca = root;
        }
    }
}
void LCA(struct node * root,int data1,int data2){
    if(root == NULL) return;
    struct  node * lca =NULL;
    LCAIterative(root,data1,data2,lca);
    if(lca != NULL) printf("%d is LCA\n",lca->key);
    else printf("No LCA\n");
    LCARecursive(root,data1,data2,lca);
    if(lca != NULL) printf("%d is LCA\n",lca->key);
    else printf("No LCA\n");
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
    LCA(root,8,12);
    return 0;
}
