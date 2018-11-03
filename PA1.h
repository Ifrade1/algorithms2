#ifndef PA1_H_INCLUDED
#define PA1_H_INCLUDED
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
}

struct tree* insert(struct Tree **tree, int item, struct Tree *parent){
 }
//delete

//search

//min

//max

//predecessor

//successor



#endif // PA1_H_INCLUDED
