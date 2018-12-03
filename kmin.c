#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct Tree
{
  int val;
  struct Tree *left_child, *right_child,*ide_val, *parent; //ide_val is pointer list to values identical to it                                                                                             
};

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

//successor function                                                                                                       
int succ(struct Tree *tree, int *count, int item){
  if(tree == NULL) return INT_MAX;//base case                                                                              
  int l = succ(tree->left_child, count, item);
  if(l != INT_MAX) return l;// kth smallest integer is in the left subtree                                                 
  if(++*count == item)return tree->val;//kth smallest integer is the current tree's value                                  
  return succ(tree->right_child, count, item);
}

int kmin(struct Tree *root, int k){//finds kmin                                                                            
  int count = 0;
  return succ(root, &count, k);

}

int main() {
  int n; //this is the number that has to be saved into the tree                                                           
  int min = 0;
  int successor;
  int numInsertions = 0;
  struct Tree *root = NULL;
  int res = 0;
  int k;
  FILE *input = fopen("InputMil[2171].txt", "r");
  //fscanf(input, "%d\n", &k);                                                                                             
  scanf("%d", &k);//input a k manually                                                                                     
  while (res < 1000000){
    //while(res < 6){                                                                                                      
    //scanf("%d\n", &n);                                                                                                   
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
    min = minimum(root)->val;
    printf("%d\n", min);
  }
  successor = kmin(root, k);
  min = INT_MAX;
  if(successor != min){
    printf("%d\n", successor);//prints out kth smallest integer
  }
  else{
    printf("Invalid \n");
  }
  //printf("%d\n", min);//print out the the kth smallest integer                                                           
  return 0;
};

