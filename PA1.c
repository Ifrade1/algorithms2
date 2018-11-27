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
int deletey(struct Tree *tree, int item){
       struct Tree *temp = tree;
       struct Tree *parent = tree;
       struct Tree *min = tree;//get smallest node in right subtree
       int del_num;
        if(item < tree->val){
            tree = search(tree->left_child, item);//key is in the left subtree
        }
	else if(item > tree->val){
		tree= search(tree->right_child, item);//key is in right subtree
        }
    else if (item == tree->val){//nodes have the same key
        del_num = 1;
        parent = tree->parent;
	    while (temp->ide_val != NULL){
           tree = temp;
            temp= temp->ide_val;
            free(tree);
            del_num++;
	    }
	    if((tree->left_child)== NULL && (tree->right_child == NULL)){
	         if ((parent->left_child)->val == (tree)->val){
                parent->left_child = NULL;
                free(tree);
                }
            else if ((parent->right_child)->val == (tree)->val){
                parent->right_child = NULL;
                free(tree);
            }
	    }
		if((tree->left_child)== NULL && (tree->right_child != NULL)){//node has 0 children or 1 child
                tree->right_child->parent = parent;
            if ((parent->left_child)->val == (tree)->val){
                parent->left_child = tree->right_child;
                free(tree);
                }
            else if ((parent->right_child)->val == (tree)->val){
                parent->right_child = tree->right_child, tree->right_child->parent =tree->parent;
                free(tree);
            }
		}
		if((tree->right_child == NULL) && (tree->left_child != NULL)){
            if ((parent->left_child)->val == (tree)->val){
                parent->left_child = tree->left_child, tree->left_child->parent = tree->parent;
                free(tree);
                }
            else if ((parent->right_child)->val == (tree)->val){
                parent->right_child = tree->left_child, tree->left_child->parent = tree->parent;
                free(tree);
            }
		}
		else if(tree->right_child != NULL && tree->left_child != NULL){
            min = tree->left_child;
		while(min->left_child != NULL){
			min = min->left_child;
		}
		tree->val = min->val;//copies contents to current node
		(min->parent)->left_child = NULL;
		free(min);
		}
		}
		if (tree == NULL) return 0;
		 return del_num;
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
int pred(struct Tree* tree, int item){
    struct Tree *pre = tree;
    struct Tree *parent_pre = tree;
      pre = search(tree, item);
    if(pre == NULL){
        return 0;
    }
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
    if (suc == NULL){
        return 0;
    }
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

	struct Tree *temp= suc->ide_val;
	if (temp !=NULL) {//successor is the node who is the left child of the parent pointer
		suc = temp;
		return suc->val;
	}
	else
    {
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
     int n; //this is the number that has to be saved into the tree
     int min;
     int max;
     char str1[50];
     int heightTree;
     int predecessor;
     int successor;
     int numDeletedLeafs;
    struct Tree *root = NULL;
     int res;
     int err;
    char input[100];
    while(1) {
        err = 0;
        if(fgets(input, sizeof input, stdin) != NULL) {
            res = sscanf(input, "%19s%19d", str1, &n);
            if (res == 2 &&(strcmp(str1,"INS")) == 0){
                    if (root == NULL){
                        root = insert(root, n);
                        printf("%d\n", n);
                    }
                    else if (root!= NULL){
                        insert(root, n);
                        printf("%d\n", n);
                    }
            }
            else if ((res == 2) &&(strcmp(str1,"DEL")) == 0){
                  if(root == NULL){
                    printf("%d\n", 0);
                    }
                else if(root != NULL){
                    numDeletedLeafs = deletey(root->right_child, n);
                    numDeletedLeafs++;//increments number of successful deletes
                    printf("%d\n", numDeletedLeafs);
		    }
	    }
           else if (res == 2 &&(strcmp(str1,"SEA")) == 0){
                if (search(root, n)== NULL){
                   printf("%d\n", 0);
                }
                else if (search(root, n) != NULL){
                     printf("%d\n", 1);
                }
           }
           else if (res == 1 &&(strcmp(str1,"MIN")) == 0){
                if (minimum(root)== NULL){
                    printf("%d\n", 0);
                    }
                else{
                    min = minimum(root)->val;
                    printf("%d\n", min);
                }
           }
           else if (res == 1 &&(strcmp(str1,"MAX")) == 0){
                 if (maximum(root)== NULL){
                    printf("%d\n", 0);
                    }
                else{
                    max = maximum(root)->val;
                    printf("%d\n", max);
                }
           }
            else if (res == 2 &&(strcmp(str1,"PRE")) == 0){
                predecessor = pred(root, n);
                printf("%d\n", predecessor);
           }
           else if (res == 2 &&(strcmp(str1,"SUC")) == 0){
                successor = succ(root, n);
                printf("%d\n", successor);
           }
           else if (res == 1 &&(strcmp(str1,"HEI")) == 0){
                heightTree = height(root);
                printf("%d\n", heightTree);
           }
    }
    }
     return 0;
};
