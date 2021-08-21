 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

struct Node{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x){
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

char pop(){
    struct Node *t;
    char x=-1;
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

// check no. of paranthesis is balanced or not ()
int isBalanced(char *exp){
    int i;

    for ( i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(exp[i]);
        }else if (exp[i]==')')
        {
            if (top==NULL)
            {
                // returns 0 if not balanced
                return 0;
            }
            pop();
            printf("bal value is: %d \n",pop());
        }
    }
    if (top==NULL)
    {
        return 1;
    }else{
                // returns 0 if not balanced
        return 0;
    }   
}

// checks for other types of brackets if balanced or not
int isBalancedForAll(char *exp){
    int i;
    int x;

    for ( i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
        }else if (exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if (top==NULL)
            {
                // returns 0 if not balanced
                return 0;
            }

            x=pop();
            // ASCII code = (=41 )=40 [=91 ]=93 {=123 }=125
            if (x!=40 && exp[i]==')')
            {
                return 0;
            }
            if (x!=91 && exp[i]==']')
            {
                return 0;
            }
            if (x!=123 && exp[i]=='}')
            {
                return 0;
            }
            printf("\nvalue = %d \n",x);
            
        }
    }
    if (top==NULL)
    {
        return 1;
    }else{
        // returns 0 if not balanced
        while(top)   //making stack empty changes
        {
                struct Node *t=top;
                top=top->next;
                free(t);
        }
        return 0;
    }
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

char* InToPost(char *infix){
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));

    while (infix[i]!='\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }else{
            if (pre(infix[i])>pre(top->data))
            {
                push(infix[i++]);
            }else{
                postfix[j++]=pop();
            }
            
        }
        
    }

    while (top!=NULL)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

 int main(){

    //infix to postfix conversion
    char *infix="a+b*c-d/e";
    push('#');
    char *postfix=InToPost(infix);
    printf("converted to postfix: %s \n",postfix);

     //for paranthesis is balanced or not 1-true-balanced 0-false-notbalanced
     char *exp = "((a+b)*(c-d))";
    printf("balanced paranthesis: %d \n",isBalanced(exp));
    
    //checks for all type of brackets 
    char *exp1 = "{([a+b]*[c-d])/e}";
    printf("balanced paranthesis for all: %d \n",isBalancedForAll(exp1));

    //----------------------------------------------------------------// 
     push(10);
     push(11);
     push(12);


     Display();
     pop();
     printf("%d ",pop());
    Display(); 

     return 0;
 }