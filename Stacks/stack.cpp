#include<iostream>
#include<stdlib.h>
#define size 100

using namespace std;

class Stack{
    private:
        int stack[size];
        int element;
        int top;
    public:
        Stack(){
            top=-1;
        }
        void push(int value){
            element = value;
            if(top==size-1)
                cout<<"stack overflow!";
            else{
                top++;
                stack[top]=element;
            }
        }
        void pop(){
            if(top==-1)
                cout<<"stack underflow!";
            else
                top--;
        }
        void traversal(){
            if(top==-1)
                cout<<"no elements in stack!";
            else{
                for(int i=top;i>=0;i--)
                    cout<<stack[i]<<"\n";
            }
        }
        int ret_top(){
            return top;
        }
        bool empty(){
            if(top==-1)
                return true;
            return false;
        }
        bool full(){
            if(top==size-1)
                return true;
            return false;
        }
};

int main(){
    int element,choice;
    Stack obj;
    do{
        start:
        cout<<"\n\nPress enter to continue...";
        system("cls");
        printf("\n 1.push \n 2.pop \n 3.display \n 4.exit \n 5.clear screen \n");
		printf("enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element: ");
				scanf("%d",&element);
				obj.push(element);
				break;
			case 2:
				obj.pop();
				break;
			case 3:
				obj.traversal();
				break;
			case 4:
				exit(0);
			case 5:
				system("cls");
				break;
			default:
				printf("wrong choice!!");
                goto start;
		}
    }while(choice!=6);
}