#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *nxt;
};

struct node *start = NULL, *new_node, *temp;

void insertion(int data);
void deletion();
void traversal();
void insert_at_beginning(int data);
void insert_at_end(int data);
void insert_at_pos(int data, int pos);
void delete_at_beginning();
void delete_at_end();
void delete_at_pos();

int main()
{
    int choice,element;
    do{
        start:
        printf("\n\nPress enter to continue...");
        getchar();
        system("clear");
        printf("\n 1.add node \n 2.delete node \n 3.display \n 4.exit \n 5.clear screen \n");
		printf("enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element to be added: ");
				scanf("%d",&element);
				insertion(element);
				break;
			case 2:
				deletion();
				break;
			case 3:
                printf("your linked list is: \n\n");
				traversal();
                getchar();
				break;
			case 4:
				exit(0);
			case 5:
				system("clear");
				break;
			default:
				printf("wrong choice!!");
                goto start;
		}
    }while(choice!=6);
    return 0;
}

void insertion(int element){
    int choice;
    new_node = (struct node *) malloc(sizeof(struct node)); 
    int pos = 0;
    do{
        start:
        printf("\n\nPress enter to continue...");
        getchar();
        system("clear");
        printf("\n 1.add node at beginning \n 2.add node at the end \n 3.add node at a specific place \n 4.go back to previous menu \n 5.exit \n 6.clear screen \n");
		printf("enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_at_beginning(element);
                getchar();
                return;
				break;
			case 2:
				insert_at_end(element);
                getchar();
                return;
				break;
			case 3:
                printf("enter position at which you want to add: ");
                scanf("%d",&pos);
				insert_at_pos(element,pos);
                getchar();
                return;
				break;
            case 4:
                return;
                system("clear");
                break;
			case 5:
				exit(0);
                break;
			case 6:
				system("clear");
				break;
			default:
				printf("wrong choice!!");
                goto start;
		}
    }while(choice!=7);
}

void deletion(){
    int choice, pos;
    do{
        start:
        printf("\n\nPress enter to continue...");
        getchar();
        system("clear");
        printf("\n 1.delete node at beginning \n 2.delete node at the end \n 3.delete node at a specific position \n 4.go back to previous menu \n 5.exit \n 6.clear screen \n");
		printf("enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				delete_at_beginning();
                return;
				break;
			case 2:
				delete_at_end();
                return;
				break;
			case 3:
                printf("enter position at which you want to delete: ");
                scanf("%d",&pos);
				delete_at_pos(pos);
                return;
				break;
            case 4:
                return;
                system("clear");
                break;
			case 5:
				exit(0);
                break;
			case 6:
				system("clear");
				break;
			default:
				printf("wrong choice!!");
                goto start;
		}
    }while(choice!=7);
}

void traversal(){
    struct node *temp;
    if(start == NULL)
        printf("empty!");
    else{
        temp = start;
        while(temp != NULL){
            printf("%d --> ", temp->data);
            temp = temp->nxt;
        }
        printf(" Null");
    }
}

void insert_at_beginning(int data){
    new_node->data = data;
    if(start == NULL){
        new_node->nxt = NULL;
        start = new_node;
    }
    else{
        new_node->nxt = start;
        start = new_node;
    }
    printf("inserted value at beginning");
}

void insert_at_end(int data){
    new_node->data = data;
    new_node->nxt = NULL;
    if(start == NULL){
        start = new_node;
    }
    else{
        temp = start;
        while(temp->nxt != NULL)
            temp = temp->nxt;
        temp->nxt = new_node;
    }
    printf("inserted value at the end");
}

void insert_at_pos(int data,int pos){
    new_node->data = data;
    new_node->nxt = NULL;
    if(start == NULL){
        start = new_node;
        printf("list empty adding at 1st position");
    }
    else{
        int count = 1,flag=0;
        temp = start;
        while(temp != NULL){
            if(pos == count){
                flag=1;
                new_node->nxt = temp->nxt;
                temp = new_node;
                break;
            }
            count++;
            temp = temp->nxt;
        }
        flag?printf("inserted value at %d", pos):printf("no such postion!");
    }
}

void delete_at_beginning(){
    temp = start;
    if(start == NULL)
        printf("Empty List can't delete!");
    else{
        start = temp->nxt;
        free(temp);
        printf("deleted from beginning");
        getchar();
    }
}

void delete_at_end(){
    temp = start;
    if(start == NULL)
        printf("Empty List can't delete!");
    else{
        while (temp->nxt != NULL)
            temp = temp->nxt;
        temp = NULL;
        free(temp);
        printf("deleted from the end!");
        getchar();
    }
}

void delete_at_pos(int pos){
    temp = start;
    int count = 1,flag = 0;
    struct node *del;
    if(start == NULL)
        printf("Empty List can't delete!");
    else{
        while (temp != NULL){
            if(pos == count){
                flag = 1;
                del = temp;
                temp = temp->nxt;
                free(del);
                break;
            }
            temp = temp->nxt;
            count++;
        }
        flag?printf("deleted at position %d",pos):printf("can't delete no such position!");
        getchar();
    }
}

