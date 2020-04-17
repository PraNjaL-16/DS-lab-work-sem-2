#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;                 // next is self referential pointer of struct node type or pointer to itself
}*first=NULL;                           // first is global pointer of type struct node or called head pointer

void create(int A[],int n);
void display(struct node * p);
int count(struct node * p);
int Delete(struct node *p, int index);

int main()
{
    int A[]={3,5,7,10,15};

    create(A,5);

    printf("%d\n",Delete(first,4));
    display(first);

    printf("\n");
     printf("%d\n",Delete(first,4));
    display(first);

    printf("\n");
     printf("%d\n",Delete(first,1));
    display(first);
}

void create(int A[],int n)
{
    int i;
    struct node * t;                 //t is temporary pointer which will help in creating new node of linkdlist
    struct node *last;               //last will help to add new node at the end of linkdlist

    first = (struct node *)malloc(sizeof(struct node));              //creating a new node or first node
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;          // connecting new created node to previous node
        last = t;                // incrementing the last pointer to newly created node
    }
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

int Delete(struct node *p, int index)
{
    struct node * q;
    int x,i;

    if(index<1 || index > count(p))                              //validity of index
    {
        return -1;
    }

    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(p);
        return x;
    }
    else
    {
        for(i=0; i<index-1;i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);                                      //de-allocating the memory
        return x;
    }
}
