#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void count_node(struct node* head){
    int count = 0;
    struct node* ptr=NULL;
    ptr = head;
    while(ptr!=NULL){
        count++;
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n%d",count);
};
struct node* add_at_end(struct node* ptr,int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
};
struct node* add_beg(struct node* head,int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    temp->link = head;
    head =temp;
    return head;

};
struct node* add_at_pos(struct node* head,int data,int pos){
    struct node *ptr=head;
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    pos--;
    while (pos!=1)
    {
        ptr=ptr->link;
        pos--;
    }
    temp->link=ptr->link;
    ptr->link=temp;
    
    

};
struct node* del_first(struct node* head){
    struct node* ptr=head;
    if (head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        head=head->link;
        free(ptr);
        ptr=NULL;
    }
    return head;
};
void del_last(struct node* head){
    
    if (head==NULL)
    {
        printf("List is empty");
    }
    else if (head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node* ptr=head;
        while (ptr->link->link!=NULL)
        {
            ptr=ptr->link;
        }
        free(ptr->link);
        ptr->link=NULL; 
    }
}
struct node* del_at_pos(struct node* head,int pos){
    struct node* current=head;
    struct node* previous=current;
    if (pos==0)
    {
        head=head->link;
        free(current);
        current=NULL;
        free(previous);
        previous=NULL;
        return head;
    }
    else
    {
        while (pos!=0)
        {
            previous=current;
            current=current->link;
            pos--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
        return head;
    }

};
struct node* reverse(struct node*head){
    struct node* next=NULL;
    struct node* prev=NULL;
    while (head!=NULL)
    {
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
    
};

int main(){
    int count;
    struct node* head=malloc(sizeof(struct node));
    head->data=11;
    head->link=NULL;
    struct node* ptr=head;
    ptr=add_at_end(ptr,23);
    ptr=add_at_end(ptr,12);
    ptr=add_at_end(ptr,90);
    head=add_beg(head,8);
    
    
    head=del_first(head);
    del_last(head);
    ptr=head;
    add_at_pos(head,222,3);
    
    // head=del_at_pos(head,0); 
    // head=reverse(head);
    count_node(head);

}