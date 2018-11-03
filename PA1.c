//This is the main file.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Tree
{
    int val;
    struct Tree *left_child, *right_child, *parent, *ide_val; //ide_val is pointer list to values identical to it
};
//insert
struct Tree *newLeaf(int x){
        struct Tree *tempy =  malloc(sizeof(struct Tree));
    tempy->val = x;
    tempy->left_child = NULL;
    tempy->right_child = NULL;
    tempy->parent = NULL;
    tempy->ide_val = NULL;
    return tempy;
}
struct Tree* insert(struct Tree *tree, int item){
  struct Tree *temp;
    /* If the tree is empty, return a new Node */
if (tree == NULL){
   temp = malloc(sizeof(tree));
    temp->val = item;
    temp->left_child = NULL;
    temp->right_child = NULL;
    temp->ide_val = NULL;
    tree = temp;
}
    /* Otherwise, recur down the tree */
 else if(item == (tree)->val){
	tree->ide_val = newLeaf(item);
 }
else if (item < tree->val)
    {
    tree->left_child  = insert(tree->left_child, item);
    }
    else if (item > tree->val)
    {
    tree->right_child = insert(tree->right_child, item);
    }

 }

int main() {
     int n; //this is the number that has to be saved into the tree
     char str1[50];
    struct Tree *root = NULL;
     while(scanf("%s %d", str1, &n) !=EOF){ //scans until end of file
            if ((strcmp(str1,"INS")) != 0){
                    if (root == NULL){
                        root = insert(root, 50);
                    }
                    else{
                        insert(root, n);
                    }
                printf("%d", n);
            }
            else if ((strcmp(str1,"DEL")) != 0){}
           else if ((strcmp(str1,"SEA")) != 0){}
           else if ((strcmp(str1,"MIN")) != 0){}
           else if ((strcmp(str1,"MAX")) != 0){}
           else if ((strcmp(str1,"PRE")) != 0){}
           else if ((strcmp(str1,"SUC")) != 0){}
           else if ((strcmp(str1,"HEI")) != 0){}

    }
     return 0;
}

