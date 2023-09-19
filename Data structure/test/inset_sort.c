#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
}*head;

void add_at_end(int data){
    struct node*ptr=head;
    struct node*temp=malloc(sizeof(struct node));
    while (ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    temp->data=data;
    temp->link=NULL;
}

void insert_sorted(int data){
    struct node*ptr=head;
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    if (data<ptr->data)
    {
        temp->link=head;
        head=temp;
        
    }
    else
    {
        while (ptr->link!=NULL && data>ptr->link->data) 
    {
        ptr=ptr->link;
    }
    
    temp->link=ptr->link;
    ptr->link=temp;
    }
};

void display(){
    struct node* temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
};
int main(){
    head=malloc(sizeof(struct node));
    head->data=2;
    head->link=NULL;
    add_at_end(5);
    add_at_end(7);
    add_at_end(15);
    add_at_end(25);
    add_at_end(87);
    insert_sorted(1);
    display();



};