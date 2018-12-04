//This is the main file.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
struct Tree
{
  int val, ide_val;
    struct Tree *left_child, *right_child, *parent; //ide_val is pointer list to values identical to it
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
    else if (leaf->val < item){
        return search(leaf->right_child, item);
    }
}
struct Tree *newLeaf(int x){
        struct Tree *tempy =  malloc(sizeof(struct Tree));
    tempy->val = x;
    tempy->left_child = NULL;
    tempy->right_child = NULL;
    tempy->ide_val = 1;
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
 else  if(item == (tree->val)){
   tree->ide_val = tree->ide_val+1;
   return tree;
      }
else if (item < tree->val)
    {
      lchild = insert(tree->left_child, item);
     tree->left_child = lchild;
    lchild->parent = tree;
    }
    else if (item > tree->val)
    {
   rchild = insert(tree->right_child, item);
    tree->right_child = rchild;
    rchild->parent = tree;
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
/*
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
    } return 0;                                                                
    //   } 
    return (pre)->val;
}
*/
//successor function
int succ(struct Tree *tree, int item){
  struct Tree *suc = search(tree, item);
     if (tree == NULL) return 0;
     if ((maximum(tree)->val == item)){
       return 0;
     }
     if (suc->ide_val > 1) {//successor is the node who is the left child  of the parent pointer;                                                         
       suc->ide_val = suc->ide_val-1;
       //  free(temp);                                                      
       return suc->val;
     }
	if(suc->right_child != NULL){
            suc= suc->right_child; //successor is the node with the minimum key value in right subtree
            if (suc->left_child != NULL){
                return minimum(suc)->val;
            }
            else {
                return suc->val;
            }
	}
	
	else {
        struct Tree* parent_suc = suc->parent;// find the predecessor of the item
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
clock_t starttime, endtime;
  double execution_time;
     int n; //this is the number that has to be saved into the tree
     //     int min = 0;
     // int max = 0;
     int successor =0;
    struct Tree *root = NULL;
     int k;
     int i;
     starttime = clock();
    scanf("%d/n",&k);//scans size of the array and k
     while(scanf("%d", &n) !=EOF){
            
                    if (root == NULL){
                        root = insert(root, n);
                    }
                    else if (root!= NULL){
                        insert(root, n);
                    }}
     //  printf("The number of insertions is %d\n", numInsertions);
           if (minimum(root)== NULL){
                    printf("%d\n", 0);
                    }
                else{            
		    successor = minimum(root)->val;
		    // max = maximum(root)->val;
		    // printf("min is %d\n", successor);
		    // printf("max is %d\n", max);
                    for (i = 2; i < k; i++){		      		
                         successor = succ(root, successor);
			 //  min = successor;
			 // 	 printf("testy %d\n", successor);
			 // 	 printf("k %d\n", i);
			 // if (successor == 0){
			 //  i = k-1;
			 //  }
                   }
                     printf("kmin is %d\n", successor);
                      endtime = clock();
  execution_time = ((double)(endtime - starttime))/ CLOCKS_PER_SEC;
  printf("BST execution time: %lf seconds \n", execution_time);
                }
     return 0;
};
