#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;                 // next is self referential pointer of struct node type or pointer to itself
}*first=NULL;                           // first is global pointer of type struct node or called head pointer

void display(struct node * p);
int count(struct node * p);
void insert(struct node * p, int index, int x);

int main()
{
    display(first);
    printf("\n");
    insert(first,0,10);
    display(first);

    printf("\n");
    insert(first,1,20);
    display(first);

    printf("\n");
    insert(first,2,30);
    display(first);

    printf("\n");
    insert(first,0,5);
    display(first);
}

void display(struct node * p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
}

int count(struct node * p)
{
    int l=0;
    while(p != NULL)
    {
        l++;
        p = p->next;
    }

    return l;
}

void insert(struct node * p, int index, int x)
{
    struct node * t;
    int i;

    if(index<0 || index>count(p))                          // checking index in valid or not
        return;

    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;

    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(i=0; i<index-1 && p; i++)
        {
            p = p->next;
        }
            if(p)
            {
                t->next = p->next;
                p->next = t;
            }
    }

}

