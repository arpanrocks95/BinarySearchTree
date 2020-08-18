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

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void createBalancedBST(struct node * &root,int arr[],int max,int min){
    if(min > max) return;
    int mid = (min + max) / 2;
    root = newNode(arr[mid]);
    createBalancedBST(root->left,arr,mid-1,min);
    createBalancedBST(root->right,arr,max,mid+1);
}

void inorder(struct node * root){
    if (root == NULL) return ;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

void create(struct node * & root,int arr[],int len){
    selectionSort(arr,len);
    createBalancedBST(root,arr,len-1,0);
    inorder(root);
}




int main(){
    node* root1 = NULL;
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
    int len = (*(&keys +1) - keys);
    create(root1,keys, len);
    return 0;
}
