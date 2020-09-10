#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *nxt;
};

struct Node *top = NULL, *New_node, *tmp;

void push(int data);
void pop();
void traversal();

int main(){
    int choice, data;
    do{
        start:
        printf("\n\nmenu:\n1.push\n2.pop\n3.traverse\n4.exit\nenter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("clear");
            printf("Enter element to push: ");
            scanf("%d",&data);
            push(data);
            break;
        case 2: 
            system("clear");
            pop();
            break;
        case 3:
            system("clear");
            traversal();
            break;
        case 4:
            exit(0);
            break;
        default: 
            printf("wrong choice!!");
            goto start;
        }
    }while(choice != 5);
}

void push(int data){
    New_node = (struct Node *) malloc(sizeof(struct Node));
    New_node->data = data;
    New_node->nxt = NULL;
    if(top == NULL)
        top = New_node;
    else{
        New_node->nxt = top;
        top = New_node;  
    }  
    printf("\n%d is pushed to Stack", data);
}

void pop(){
    if(top == NULL){
        printf("stack Underflow!!");
    }
    else{
        tmp = top;
        top =  tmp->nxt;
        printf("%d poped out of the Stack!", tmp->data);
        free(tmp);
    }
}

void traversal(){
    tmp = top;
    if(tmp == NULL)
        printf("Stack Empty!!");
    else{
        while(tmp != NULL){
            printf("------------\n");
            printf("|    %d     |\n",tmp->data);
            tmp = tmp->nxt;
        } 
        printf("------------\n");
    }
}