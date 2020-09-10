#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *nxt;
}*rear = NULL,*front = NULL,*new_node,*tmp;

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
        tmp = rear;
        rear = new_node;
        tmp->nxt = rear;
        rear->nxt = front;
    }
}

void dequeue(){
    if(front == NULL && rear == NULL)
        printf("Empty Queue!");
    else if(front == rear){
        front = rear = NULL;
        free(front);
    }
    else{
        tmp = front;
        front = tmp->nxt;
        free(tmp);
        rear->nxt = front;
    }
}

void traversal(){   
    if(front == NULL && rear == NULL)
        printf("Queue Empty!!\n");
    else if(front == rear)
        printf("%d \n",rear->data);
    else{
        tmp = front;
        printf("%d |",tmp->data);
        while(tmp->nxt != rear->nxt){
            tmp = tmp->nxt;
            printf("%d |",tmp->data);
        }
        printf("\n");
    }
}