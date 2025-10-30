#include<stdio.h>
#include<stdlib.h>
#define size 15
int s[size];
int top=-1;
void push(int value);
void pop();
void display();
void main(){
int value,choice;
printf("---program to push pop or display stack---");
while(1){
printf("Enter what toperation to made");
printf("\n1. push ");
printf("\n2. pop");
printf("\n3. display");
printf("\n4.exiting the program");
printf("\nEnter your choice");
scanf("%d",&choice);
switch (choice){
    case 1:
    printf("\nEnter the value to be entered: ");
    scanf("%d",&value);
    push(value);
    break;
    case 2:
    printf("\nThe stack is popped");
    pop();
    break;

    case 3:
    printf("\nThe stack is displayed");
    display();
    break;

    case 4:
    printf("Exiting the program]\n");
    exit(0);

    default:
    printf("Invalid choice");
    break;
}
}
}

void push(int value){
    if(top==size-1)
    {
        printf("stack overflow");
    }
    else
    {
        top++;
        s[top]=value;
        printf("the value is pushed");
    }

}

void pop(){
    if(top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        printf("the popped element is %d",s[top]);
        top--;
    }


}
void display(){
    if(top==-1)
    {
        printf("stack is empty");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",s[i]);
        }
    }

}

