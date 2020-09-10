#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *ptr;   
};  
struct node *new_node,*top=NULL,*temp;  
void push(){
    int val;
     printf("\nEnter value\n");    
        scanf("%d",&val); 
    new_node = (struct node *) malloc(sizeof(struct node )); 
      new_node->data = val;  
    if(top== NULL)  
    {  
        new_node->ptr=NULL;
        top=new_node;
    }  
    else  
    {  
        new_node->ptr = top;  
      top= new_node;  
        printf("\nNode inserted at the beggining");  
    }      
}  
void pop()
{  
    if(top == NULL)  
    {  
        printf("stack is empty\n");  
    }  
    else   
    {  
        temp =top;  
        top = temp->ptr;  
        free(temp);  
        printf("\nnode deleted\n");  
    }  
}void display()
{
    temp=top;  
    if(top == NULL)  
    {  
        printf("empty");  
    }  
    else  
        printf("\nvalues in the stack.\n");   
        while (temp!=NULL)  
        {  
            printf("\n%d",temp->data);  
            temp = temp -> ptr;  
        }  
    
}
int main(){
    int choice;
    do{
        printf("\nmenu:\n1.push\n2.pop\n3.display\n4.exit\nenter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    getchar();
                    break;
            case 4: exit(0);
                    break;
            default: printf("wrong choice!");
        }
        printf("\npress enter to continue!");
    } while (choice != 5);
}