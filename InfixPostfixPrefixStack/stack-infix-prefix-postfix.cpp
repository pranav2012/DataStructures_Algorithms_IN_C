#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define size 100

using namespace std;

class Stack{
    private:
        char stack[size];
        char element;
        int top;
    public:
        Stack(){
            top=-1;
        }
        void push(char value){
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
                cout<<"\nno elements in stack!";
            else{
                for(int i=top;i>=0;i--)
                    cout<<stack[i]<<"\n";
            }
        }
        char ret_top(){
            return stack[top];
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

void postfix(char ar[]);
void prefix(char ar[]);
Stack obj;

int main(){
    char expression[50];
    int choice;
    cout<<"enter your expression: ";
    gets(expression);
    do{
        start:
        cout<<"your expression is: "<<expression;
        cout<<"\nyou can perform following actions:\n";
        cout<<"1.Convert to Postfix\n";
        cout<<"2.Convert to Prefix\n";
        cout<<"3.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
                postfix(expression);
                break;
            case 2:
                prefix(expression);
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"wrong choice!!";
                goto start;
        }
    }while(choice!=4);
}

bool check_opp(char var){
    if(var == '+' || var == '*' || var == '-' || var == '/' || var == '%' || var == '^')
        return true;
    return false;
}

bool check_var(char var){
    if('a' <= var && var <= 'z' || 'A' <= var && var <= 'z' )
        return true;
    return false;
}

int preced(char opp){
    if(opp='^')
        return 3;
    else if(opp == '*' || opp == '/')
        return 2;
    else if(opp == '+' || opp == '-')
        return 1;
    else
        return -1;
}

void postfix(char ar[]){
    char post[50];
    int pos=0;
    for(int i=0;i<strlen(ar);i++){
        if(check_var(ar[i])){
            post[pos]=ar[i];
            pos++;
        }
        else if(ar[i] == '(') {
            obj.push(ar[i]);
        }
        else if(ar[i] == ')'){
            while((obj.ret_top() != '(') && (!obj.empty())){
                post[pos] = obj.ret_top();
                pos++;  
                obj.pop();
            }
            if(obj.ret_top() == '(')
                obj.pop(); 
        }
        else{
          if(obj.empty())
            obj.push(ar[i]);
          else{
              if(preced(ar[i])>preced(obj.ret_top()))
                obj.push(ar[i]);
              else if(preced(ar[i]) == preced(obj.ret_top()) && ar[i] == '^')
                obj.push(ar[i]);  
              else{
                  while(!obj.empty() && ((preced(ar[i])) <= (preced(obj.ret_top())))){
                      post[pos]=obj.ret_top();
                      pos++;
                      obj.pop();
                    }
                }  
            }  
        }
    }
    while(!obj.empty()){
        obj.traversal();
        post[pos] = obj.ret_top();
        pos++;
        obj.pop();
    }
    //system("cls");
    cout<<"postfix is: ";
    for(int i=0;i<strlen(post);i++)
        cout<<post[i];
    getch();
}
void prefix(char ar[]){
    cout<<"not working!!";
}