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

struct node * maxInleftSubtree(struct node * root){
    while(root->right != NULL) root = root->right;
    return root;
}


void deleteNodeInBSTRecursive(struct node *&root, int data){
    if(root == NULL) return ;
    if(data < root->key)deleteNodeInBSTRecursive(root->left, data);
    else if(data > root->key)deleteNodeInBSTRecursive(root->right, data);
    else  {
        if(root->left  == NULL && root->right == NULL) root = NULL;
        else if(root->left  && root->right) {
            struct node * maxleft =  maxInleftSubtree(root->left);
            root->key = maxleft->key;
            deleteNodeInBSTRecursive(root->left, maxleft->key);
        }
        else{
            struct node * child  = (root->left) ? root->left : root->right;
            struct node * parent = returnParentOFNodewithData(root->data,this->root);
            if(parent->right == root) parent->right = child;
            else parent->left = child;
            free(root);
        }
    }

}



void inorder(struct node * root){
    if (root == NULL) return ;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}




int main(){
    node* root1 = NULL;
    int keys[] = { 15, 10, 20, 8, 12, 25 };
    int len = (*(&keys +1) - keys);
    for (int i = 0; i < len ; ++i) {
        insertRecursive(root1,keys[i]);
    }
    inorder(root1);
    printf("\n");
    deleteNodeInBSTRecursive(root1, 25);
    inorder(root1);
    printf("\n");

    return 0;

}
