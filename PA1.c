//This is the main file.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Tree
{
    int val;
    struct Tree *left_child, *right_child,*ide_val; //ide_val is pointer list to values identical to it
};
//insert
struct Tree *newLeaf(int x){
        struct Tree *tempy =  malloc(sizeof(struct Tree));
    tempy->val = x;
    tempy->left_child = NULL;
    tempy->right_child = NULL;
    tempy->ide_val = NULL;
    return tempy;
}
struct Tree* insert(struct Tree *tree, int item){
  struct Tree *temp;
    /* If the tree is empty, return a new Node */
if (tree == NULL){
   return newLeaf(item);
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
return tree;
 };
//delete
struct Tree* remove(struct Tree *tree, int item){
	if (tree == NULL) return tree;//if the root is empty, return the root
	if(item < tree->val){
		tree->left_child = remove(tree->left_child, item);//key is in the left subtree
	}
	else if(item > tree->val){
		tree->right_child = remove(tree->right_child, item);//key is in right subtree	
	}
	else{//nodes have the same key
		if(root->left_child == NULL){//node has 0 children or 1 child
			struct Tree *temp = tree->right_child;
			free(tree);
			return temp;	
		}
		else if(root->right_child == NULL){
		struct Tree *temp = tree->left_child;
			free(tree);
			return temp;
		}
		struct Tree *temp = minimum(tree->right_child);//get smallest node in right subtree
		tree->val = temp->val;//copies contents to current node
		tree->right = remove(tree->right_child, temp->val);//deletes node
	}
 return tree;
}//end of delete
 int minimum(struct Tree *tree){
    struct Tree *min = tree;
    if (min == NULL) return -1;
    while(min->left_child != NULL){
        min = min->left_child;
    }
    return (min->val);
}
 int maximum(struct Tree *tree){
    struct Tree *max = tree;
    if (max == NULL) return -1;
    while(max->right_child != NULL){
        max = max->right_child;
    }
    return (max->val);
}

struct Tree * search(struct Tree * leaf, int item) {
    if (leaf == NULL) {
        return NULL;
    }
    else if (leaf->val == item) {
        return leaf;
    }
    else if (leaf->val > item) {
        return search(leaf->left_child, item);
    }
    return search(leaf->right_child, item);
}

int main() {
     int n; //this is the number that has to be saved into the tree
     int min;
     int max;
     char str1[50];
    struct Tree *root = NULL;
     int res;
     int err;
    char input[100];
    while(1) {
        err = 0;
        if(fgets(input, sizeof input, stdin) != NULL) {
            res = sscanf(input, "%19s%d%d%d", str1, &n);
            if (res == 2 &&(strcmp(str1,"INS")) == 0){
                    if (root == NULL){
                        root = insert(root, n);
                        printf("%d", n, "/n");
                    }
                    else if (root!= NULL){
                        insert(root, n);
                        printf("%d", n, "/n");
                    }
            }
            else if ((res == 2) &&(strcmp(str1,"DEL")) == 0){}
           else if (res == 2 &&(strcmp(str1,"SEA")) == 0){
                if (search(root, n)== NULL){
                   printf("%d", 0, "/n");
                }
                else if (search(root, n) != NULL){
                     printf("%d", 1, "/n");
                }
           }
           else if (res == 1 &&(strcmp(str1,"MIN")) == 0){
               min = minimum(root);
                printf("%d", min);
           }
           else if (res == 1 &&(strcmp(str1,"MAX")) == 0){
                max = maximum(root);
                printf("%d", max, "/n");
           }
           else if (res == 2 &&(strcmp(str1,"PRE")) == 0){}
           else if (res == 2 &&(strcmp(str1,"SUC")) == 0){}
           else if (res == 1 &(strcmp(str1,"HEI")) == 0){}
    }
    }
     return 0;
}

