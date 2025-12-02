#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node* NODE;

NODE insertRear(NODE first);
NODE concat(NODE first, NODE second);
void display(NODE first);


int main()
{
    NODE first = NULL;
    NODE second = NULL;
    int choice;
    while(1)
    {
        printf("\n1.Insert to 1\n2.Insert to 2\n3.display 1\n4.Display 2\n5.concatinate\n6.exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: first = insertRear(first); break;
            case 2: second = insertRear(second); break;
            case 3: display(first); break;
            case 4: display(second); break;
            case 5: printf("Concatenating lists...\n");
                    first = concat(first, second);   // store result back in 'first'
                    display(first);                  // print concatenated list
                    break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

NODE insertRear(NODE first)
{
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Insufficient memory\n");
        return first;
    }
    printf("\nEnter element to be inserted: ");
    scanf("%d",&temp->info);
    temp->next = NULL;
    if(first == NULL)
        first = temp;
    else
    {
        cur = first;
        while(cur->next != NULL)
            cur = cur->next;
        cur->next = temp;
    }
    return first;
}

void display(NODE first) {
    NODE cur = first;
    printf("\nList: ");
    while (cur != NULL) {
        printf("%d -> ", cur->info);
        cur = cur->next;
    }
    printf("NULL\n");
}

NODE concat(NODE first, NODE second)
{
    NODE cur;
    cur=first;
    if(first==NULL)
    {
        if(second==NULL)
            return first;
        else
            return second;
    }
    while(cur->next!=NULL)
        cur=cur->next;
    cur->next=second;
    return first;
}
