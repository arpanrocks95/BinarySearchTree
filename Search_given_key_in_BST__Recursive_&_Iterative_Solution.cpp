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


void searchBSTRecursive(struct node * root,int data){
    if(root == NULL) {printf("Not found\n"); return;}
    if (root->key == data) {printf("Found\n"); return;}
    if(data < root->key) searchBSTRecursive(root->left,data);
    else searchBSTRecursive(root->right,data);

}
void searchBSTIterative(struct node * root ,int data){
    if(root == NULL) {printf("Not found\n"); return;}
    struct node * parent = NULL;
    struct node * temp = root;
    int cond =1;
    while(temp != NULL){
        parent =  temp;
        if(parent->key == data) {printf("Found\n");cond = 0;return;}
        if(data < temp->key) temp = temp->left;
        else temp = temp->right;
    }
    if(cond) printf("Not Found\n");

}


void inorder(struct node * root){
    if (root == NULL) return ;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}




int main(){
    node* root = NULL;
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
    int len = (*(&keys +1) - keys);
    for (int i = 0; i < len ; ++i) {
         insertRecursive(root,keys[i]);
    }
    searchBSTRecursive(root,2);
    searchBSTIterative(root,10);
    return 0;

}
