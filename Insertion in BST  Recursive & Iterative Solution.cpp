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
void insertIterative(struct node * &root,int data){
    if(root == NULL) {root = newNode(data);return;}
    else{
        struct node * temp = root;
        struct node * parent = NULL;
        while(temp != NULL){
            parent = temp;
            if(data < temp->key) temp = temp->left;
            else temp = temp->right;
        }
        if(data < parent->key) parent->left = newNode(data);
        else parent->right = newNode(data);
    }

}
void inorder(struct node * root){
    if (root == NULL) return ;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}




int main(){
    node* root = NULL;
    node * root1 = NULL;
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
    int len = (*(&keys +1) - keys);
    for (int i = 0; i < len ; ++i) {
         insertRecursive(root,keys[i]);
    }
    for (int i = 0; i < len ; ++i) {
        insertIterative(root1,keys[i]);
    }
    inorder(root);
    printf("\n");
    inorder(root1);
    return 0;

}
