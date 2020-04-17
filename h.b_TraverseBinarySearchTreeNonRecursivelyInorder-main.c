#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    struct node ** s;                                    //use to create array dynamically
};

void stackcreate(struct stack * st,int size);                             //call by reference
void push(struct stack * st, struct node * x);
int isfull(struct stack st);
int isemptystack(struct stack st);

void stackcreate(struct stack * st,int size)
{
    st->size = size;
    st->top = -1;

    st->s = (struct node **)malloc(st->size*sizeof(struct node *));
}

void push(struct stack * st, struct node * x)
{
    if(st->top == st->size-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

 struct node * pop(struct stack * st)
{
    struct node * x = NULL;
    if(st->top == -1)
    {
        printf("stack underflow");
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return(x);
}

int isemptystack(struct stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}

int isfull(struct stack st)
{
    return st.top == st.size-1;
}

struct node
{
    struct node * lchild;
    int data;
    struct node * rchild;
}*root=NULL;

void insert(int key)
{
    struct node * t;
    t = root;
    struct node *r=NULL,*p;

    if(root == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while(t != NULL)
    {
        r = t;
        if(key < t->data)
        {
            t = t->lchild;
        }
        else if(key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;

        if(key < r->data)
        {
            r->lchild = p;
        }
        else
        {
            r->rchild = p;
        }
}

void inorder(struct node * p)
{
    struct stack stk;
    stackcreate(&stk,100);

    while(p || !isemptystack(stk))
    {
        if(p)
        {
            push(&stk,p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d\t",p->data);
            p = p->rchild;
        }
    }
}

int main()
{
    struct node * temp;

    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);

    inorder(root);


    return 0;
}
