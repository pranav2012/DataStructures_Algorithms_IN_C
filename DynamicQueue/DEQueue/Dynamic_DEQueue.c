 #include<stdio.h>
 #include<stdlib.h>

 struct node{
     int data;
     struct node *nxt;
 }*front=NULL,*rear=NULL,*tmp,*new_node;

 void enqueue(int data);
 void enqueue_at_front(int data);
 void dequeue();
 void dequeue_at_rear();
 void traversal();

 int data;

 int main(){
    int choice;
    do{
        start:
        printf("Menu\n1.Enqueue\n2.Enqueue at Front\n3.Dequeue\n4.Dequeue at Rear\n5.Traversal\n6.Exit\nEnter Your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
                system("clear");
                printf("Enter Element to be added: ");
                scanf("%d",&data);
                enqueue(data);
                break;
        case 2:
                system("clear");
                printf("Enter Element to be added: ");
                scanf("%d",&data);
                enqueue_at_front(data);
                break;
        case 3:
                system("clear");
                dequeue();
                break;
        case 4:
                system("clear");
                dequeue_at_rear(); 
                break;
        case 5:
                system("clear");
                traversal();
                break;
        case 6:
                exit(0);
                break;
        default:
            printf("wrong choice!!");
            goto start;
            printf("press any key to continue!");
            getchar();
            break;
        }
    }while (choice != 7);
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

 void enqueue_at_front(int data){
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->nxt = NULL;
    if(front == NULL && rear == NULL)
        front = rear = new_node;
    else{
        tmp = front;
        front = new_node;
        front->nxt = tmp;
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

 void dequeue_at_rear(){
    if(front == NULL && rear == NULL)
        printf("Queue Empty!\n");
    else if(front == rear){
        tmp = rear;
        front = rear = NULL;
        free(tmp);
    }
    else{
        tmp = front;
        while(tmp->nxt != rear)
            tmp = tmp->nxt;
        rear = tmp;
        rear->nxt = NULL;
        free(rear->nxt); 
    }
 }

 void traversal(){
    if(front == NULL && rear == NULL)
        printf("Queue empty!\n");
    else{
        tmp = front;
        while(tmp != NULL){
            printf("%d | ", tmp->data);
            tmp = tmp->nxt;
        }
        printf("\n");
    }
 }