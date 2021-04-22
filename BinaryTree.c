#include<stdio.h>
#include "queue.h"
#include<stdlib.h>

struct node *root=NULL;

void TreeCreate()
{
    struct node *p, *t;
    int x;
    struct queue q;
    create(&q, 100);

    printf("Enter the root value: ");
    scanf("%d", &x);
    root=(struct node* )malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q, root);
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("Enter the left child of %d: ", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t=(struct node* )malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q, t);}
        printf("Enter the right child %d: ", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t=(struct node* )malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q, t);}
    }
}

void preorder(struct node *p){
    if(p){
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(struct node *p){
    if(p){
        preorder(p->lchild);
        preorder(p->rchild);
        printf("%d ", p->data);
    }
}

void inorder(struct node *p){
    if(p){
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);  
    }
}

int main(){
    TreeCreate();
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}

