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



void findPredecessor(struct node * root,struct node * &preced,int data){
    if (root == NULL){
        preced = NULL;
        return;
    }
    if(data == root->key){
        if(root->left){
            struct node * temp = root->left;
            while(temp->right != NULL) temp = temp->right;
            preced = temp;
        }
    }
    else if(data < root->key) findPredecessor(root->left,preced,data);
    else findPredecessor(root->right,preced,data);
}

void findPredecessorIterative(struct node * root,struct node * &preced,int data){
    if (root == NULL){
        preced = NULL;
        return;
    }
    while(1){
        if(data < root->key) root = root->left;
        else if (data > root->key)root = root->right;
        if(data == root->key){
            if(root->left){
                struct node * temp = root->left;
                while(temp->right != NULL) temp = temp->right;
                preced = temp;
            }
            break;
        }

    }

}

int main(){

/* Construct below tree
               15
             /    \
            /      \
           10       20
          / \      /  \
         /   \    /    \
        8    12  16    25
	*/

    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
    struct node * root = NULL;
    int len = (*(&keys+1) - keys);
    for (int i = 0; i < len; ++i) {
        insertRecursive(root,keys[i]);
    }
    // find in-order predecessor for each key
    for (int j = 0; j < len; ++j) {
        struct node * prec = nullptr;
        findPredecessorIterative(root, prec, keys[j]);   /*change it  by finpredecessor*/

        if (prec != nullptr)
            printf("Predecessor of node %d is : %d\n",keys[j],prec->key) ;
        else
            printf( "Predecessor doesn't exists for %d\n",keys[j]);
    }


    return 0;
}
