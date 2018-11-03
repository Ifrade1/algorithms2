//This is the file with ALL functions
//set the tree up
#include<stdio.h>
#include<stdlib.h>
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
struct tree* insert(struct Tree **tree, int item, struct Tree *parent){
  struct Tree *temp;
    /* If the tree is empty, return a new Node */
if (*tree == NULL){
   temp = malloc(sizeof(tree));
    temp->val = item;
    temp->left_child = NULL;
    temp->right_child = NULL;
    temp->parent = parent;
    temp->ide_val = NULL;
    *tree = temp;
}
    /* Otherwise, recur down the tree */
 else if(item == (*tree)->val){
	(*tree)->ide_val = newLeaf(item);
 }
else if (item < (*tree)->val)
    {
        insert(&((*tree)->left_child), item, *tree);
    }
    else if (item > (*tree)->val)
    {
        insert(&((*tree)->right_child), item, *tree);
    }
 }
//delete

//search

//min

//max

//predecessor

//successor
