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

int checkXYBST(int X[],int Y[],int n){
    if (n == 0) return 1;
    if (X[0] != Y[0])   return 0;
    if (n == 1) return 1;

    int leftX[n-1], rightX[n-1], leftY[n-1], rightY[n-1];
    int k = 0, l = 0, m = 0, o = 0;


    for (int i = 1; i < n; i++)
    {

        if (X[i] < X[0]) leftX[k++] = X[i];
        else rightX[l++] = X[i];
        if (Y[i] < Y[0]) leftY[m++] = Y[i];
        else rightY[o++] = Y[i];
    }


    if (k != m) return 0;
    if (l != o)return 0;

    return checkXYBST(leftX, leftY, k)  &&  checkXYBST(rightX, rightY, l);

}




int main(){

    int X[] = { 15, 25, 20, 22, 30, 18, 10, 8, 9, 12, 6 };
    int Y[] = { 15, 10, 12, 8, 25, 30, 6, 20, 18, 9, 22 };

    int len1 = (*(&X +1) - X);
    int len2 = (*(&Y +1) - Y);
    if(len1 == len2 && checkXYBST(X,Y, len1)) printf("Yes They Are The Same \n");
    else printf("No They Are The Not The Same \n");
    return 0;
}
