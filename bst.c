//This is the main file.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Tree
{
    int val;
    struct Tree *left_child, *right_child,*ide_val, *parent; //ide_val is pointer list to values identical to it
};
//insert
struct Tree *search(struct Tree *leaf, int item) {
    if (leaf == NULL) {
        return NULL;
    }
    else if (leaf->val == item) {
        return leaf;
    }
    else if (leaf->val > item) {
        return search(leaf->left_child, item);
    }
    else if (leaf->val > item){
    return search(leaf->right_child, item);
    }
}
struct Tree *newLeaf(int x){
        struct Tree *tempy =  malloc(sizeof(struct Tree));
    tempy->val = x;
    tempy->left_child = NULL;
    tempy->right_child = NULL;
    tempy->ide_val = NULL;
    tempy->parent = NULL;
    return tempy;
}
int height(struct Tree* root){
    if (root == NULL) return -1;
    else {
        int Lheight = height(root->left_child);
        int Rheight = height(root->right_child);
        if (Lheight > Rheight) return(Lheight+1);
        else return(Rheight+1);
    }
}
struct Tree* insert(struct Tree *tree, int item){
    struct Tree *lchild = tree;
    struct Tree *rchild = tree;
    /* If the tree is empty, return a new Node */
if (tree == NULL){
  return newLeaf(item);
 }
    /* Otherwise, recur down the tree */
  else if(item == (tree->val)){
            while (tree->ide_val != NULL) {
            tree = tree->ide_val;
            }
             tree->ide_val = newLeaf(item);
  }
else if (item < tree->val)
    {
      tree->left_child = insert(tree->left_child,item);
    }
    else if (item > tree->val)
    {
    tree->right_child = insert(tree->right_child, item);
    }
return tree;
}
//delete

 struct Tree *minimum(struct Tree *tree){
    struct Tree *min = tree;
    if (min == NULL) return NULL;
    while(min->left_child != NULL){
        min = min->left_child;
    }
    return min;
}
 struct Tree *maximum(struct Tree *tree){
    struct Tree *max = tree;
    if (max == NULL) return NULL;
    while(max->right_child != NULL){
        max = max->right_child;
    }
    return max;
}
int pred(struct Tree* tree, int item){
    struct Tree *pre = tree;
    struct Tree *parent_pre = tree;
      pre = search(tree, item);
    if(pre == NULL) return 0;
   if (item > parent_pre->val){
        while (item > parent_pre->val){
            parent_pre = parent_pre->right_child;
            } return parent_pre->parent->val;}
    if (minimum(tree)->val == item){
        return 0;}
    if((pre->left_child != NULL)&& (pre->left_child)->right_child != NULL){
        return maximum(pre)->val; }
    else if (pre->left_child != NULL&& (pre->left_child)->right_child == NULL){
        return (pre->left_child)->val;
    }
    return (pre)->val;
}

//successor function
int succ(struct Tree *tree, int item){
       struct Tree *suc = tree;
    suc = search(tree, item);
    if (suc == NULL) return 0;
    if (maximum(tree)->val == item){
        return 0;
        }
	if(suc->right_child != NULL && (suc->right_child)->left_child != NULL){
            suc= suc->right_child; //successor is the node with the minimum key value in right subtree
		return (minimum(suc->left_child))->val;
	}
	else if(suc->right_child != NULL && (suc->right_child)->left_child == NULL){
            suc = suc->right_child; //successor is the node with the minimum key value in right subtree
            return suc->val;
	}
	if (suc->ide_val != NULL){
	  struct Tree* temp = suc->ide_val;
	while (temp->ide_val !=NULL) {//successor is the node who is the left child of the parent pointer
	  temp = temp->ide_val;
		  }
		return suc->val;
	}
	else
    {
        struct Tree* parent_suc = suc->parent;// find the predecessor of the item
	if (suc == parent_suc->left_child){
	  return parent_suc->val;
	}
	while((parent_suc !=NULL) && (suc == parent_suc->right_child)){
            suc = parent_suc;
            parent_suc = parent_suc->parent;
        }
        suc = parent_suc;
    }
	return suc->val;
}

//predecessor function
int main() {
     int n; //this is the number that has to be saved into the tree
     long min = 0;
     long successor;
     int numInsertions = 0;
    struct Tree *root = NULL;
    int res = 0;
     int k;
      FILE *input = fopen("InputMil[2171].txt", "r");
      fscanf(input, "%d\n", &k);
      while (res < 1000000){
	fscanf(input, "%d\n", &n);
             numInsertions++;
                    if (root == NULL){
                        root = insert(root, n);
                    }
                    else if (root!= NULL){
                        insert(root, n);
                    }
		    res++;
      }
           printf("The number of insertions is %d\n", numInsertions);
	   if (minimum(root)== NULL){
                    printf("%d\n", 0);
		           }
		  else{
                    min =maximum(root)->val;
		    printf("%d\n", min);
		     for (int i = 0; i < k; i++){
		       successor = succ(root, min);
		       min = successor;
		    }
		    }
            printf("%d\n", min);
     return 0;
    };
