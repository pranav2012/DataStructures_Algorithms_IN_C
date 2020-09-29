#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL, *new_node, *temp;

void insert(int data){
    if(root == NULL){
        root->data = data;
        root->left = root->right = NULL;
    }
    else{
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        temp = root;
        while(temp->right!=NULL){
            if(temp->left == NULL)
                temp->left = new_node;
            else
                temp->right = new_node;
        }
    }
}