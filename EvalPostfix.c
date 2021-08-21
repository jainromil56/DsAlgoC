 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

struct Node{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x){
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    if (t==NULL)
    {
        printf("stack overflowed");
    }else{
        t->data=x;
        t->next=top;
        top=t;
    }
    
}

int pop(){
    struct Node *t;
    int x=-1;
    if (top==NULL)
    {
        printf("stack is empty\n");
    }else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
    
}

void Display(){
    struct Node *p;
    p=top;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


// Infix to postfix conversion
// checks and returns precidency 
int pre(char x){
    if (x=='+' || x=='-')
        return 1;
    else if (x=='*' || x=='/')
        return 2;
    return 0;
}

// checks if its operand or not, operand=*,/,-,+
int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;
}

// function for evaluating postfix
int Eval(char *postfix){
    int i,x1,x2,r;
    for (i = 0; postfix[i]!='\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }else{
            x2=pop();
            x1=pop();
            switch (postfix[i])
            {
            case '+':
                r=x1+x2;
                push(r);
                break;
            
            case '-':
                r=x1-x2;
                push(r);
                break;
            
            case '*':
                r=x1*x2;
                push(r);
                break;
            
            case '/':
                r=x1/x2;
                push(r);
                break;
            
            default:
                break;
            }
        }
    }
    return top->data;
}


 int main(){
    //  Evaluates postfix
    char *postfix="234*+82/-";
    // output would evaluating procedure - 2 3*4 : 2+12 : 14 8 2 : 14 8/2 : 14-4 : 10
    printf("Result is %d\n",Eval(postfix));
     Display();
     pop();
     printf("%d ",pop());
    Display(); 

     return 0;
 }