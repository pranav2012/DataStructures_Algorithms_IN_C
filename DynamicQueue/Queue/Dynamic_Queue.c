#include <stdio.h>
#include <stdlib.h> 

struct node{
   int data;
   struct node *nxt;
}*front=NULL,*rear=NULL,*new_node,*tmp;

void enqueue(int data);
void dequeue();
void traversal();

int main(){
    int choice;
    do{
        start:
        printf("Menu\n1.Enqueue\n2.Dequeue\n3.Traversal\n4.Exit\nEnter Your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
                system("clear");
                int data;
                printf("Enter Element to be added: ");
                scanf("%d",&data);
                enqueue(data);
                break;
        case 2:
                system("clear");
                dequeue();
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
            printf("press any key to continue!");
            getchar();
            break;
        }
    }while (choice != 5);
    return 0;
}

void enqueue(int data){
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->nxt = NULL;
    if(front == NULL && rear == NULL)
        front = rear = new_node;
    else{
        rear = new_node;
        tmp = front;
        while(tmp->nxt != NULL)
            tmp =tmp->nxt;
        tmp->nxt = rear;
    }
}

void dequeue(){
    if(front == NULL && rear == NULL)
        printf("Queue Empty!\n");
    else if(front == rear){
        tmp = rear;
        front = rear = NULL;
        free(tmp);
    }
    else{
        tmp = front;
        front = front->nxt;
        free(tmp);
    }
}

void traversal(){
    if(front == NULL && rear == NULL)
        printf("Queue empty!");
    else{
        tmp = front;
        while(tmp != NULL){
            printf("%d | ", tmp->data);
            tmp = tmp->nxt;
        }
        printf("\n");
    }
}