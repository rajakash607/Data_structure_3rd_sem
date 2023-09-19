#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct node{
    int data;
    struct node*link;
};
struct node*create_list(){
    
    int data,len;
    printf("Enter no of elements in list: ");
    scanf("%d",&len);
    struct node*head=malloc(sizeof(struct node));
    struct node*ptr=head;
    for (int i = 0; i < len; i++)
    {
        printf("Enter element for %d position ",i+1);
        scanf("%d",&data);
        
        if (i==0)
        {
            head->data =data;
            head->link =NULL;
        }
        else
        {
           struct node*temp=malloc(sizeof(struct node));
           ptr->link=temp;
           temp->data = data;
           temp->link=NULL;
           ptr=temp;
        }
    }
    return head;
};
void traverse_display(struct node*head){
    struct node *ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
};
void empty_check(struct node*head){
    if (head==NULL)
    {
        printf("Checked the list and its empty.\n");
    }
    else
    {
        printf("Checked the list and its not empty.\n");
    }   
};
struct node* add_beg(struct node* head){
    int data;
    printf("Enter element to add at beggining ");
    scanf("%d",&data);
    struct node* temp=malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    temp->link = head;
    head =temp;
    return head;
};
void add_at_end(struct node* head){
    int data;
    printf("Enter element for end position ");
    scanf("%d",&data);
    struct node*ptr=head;
    struct node* temp=malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while (ptr!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
};
struct node* add_at_pos(struct node*head){
    int data,pos;
    printf("Enter position to insert ");
    scanf("%d",&pos);
    struct node*ptr=head;
    struct node*temp=malloc(sizeof(struct node));
    printf("Enter data for node at %d position ",pos);
    scanf("%d",&data);
    temp->data=data;
    temp->link=NULL;
    if (pos==1)
    {
        temp->link=head;
        head=temp;
        return head;
    }
    else
    {
        for (int i = 1; i < pos-1; i++)
    {
        ptr=ptr->link;
    }
    temp->link=ptr->link;
    ptr->link=temp;
    return head;
    }
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
};
struct node* del_at_pos(struct node* head){
    int pos;
    printf("Enter position for deletion ");
    scanf("%d",&pos);
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
void search(struct node* head){
    int ele,count=0;
    bool found=false;
    printf("Enter node to search for: ");
    scanf("%d",&ele);
    struct node*temp=head;
    
    while (temp!=NULL)
    {
        count++;
        if (temp->link==ele)
        {
            found=true;
            printf("We found %d element at %d position.",ele,count);
        }
        temp=temp->link;
    }
    if (found==false)
    {
        printf("We didnt find element %d ",ele);
    }
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
struct node* del_ele(struct node* head){
    int pos,ele,count=0;
    printf("Enter element for deletion ");
    scanf("%d",&ele);
    struct node* current=head;
    struct node* previous=current;
    struct node*temp=head;
    
    while (temp!=NULL)
    {
        count++;
        if (temp->link==ele)
        {
            break;
        }
        temp=temp->link;
    }
    pos=count;
    
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


int main()
{
    int choice;
    struct node*head;
    head=create_list();
    printf("The menu choice:\n1: Traversal\n2: Empty checking\n3: Insert the node at beginning\n4: Insert the node at end\n5: Insert the node at a position\n6: Delete the node from beginning\n7: Delete the node from end\n8: Delete the node at a position\n9: Delete the node for the key\n10: Total number of nodes\n11: Search the element\n12: Quit");
    do
    {
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Traversed list is :\n");
        traverse_display(head);
        break;
    case 2:
        empty_check(head);
        break;
    case 3:
        head=add_beg(head);
        traverse_display(head);
        break;
    case 4:
        add_at_end(head);
        break;
    case 5:
        add_at_pos(head);
        break;
    case 6:
        del_first(head);
        break;
    case 7:
        del_last(head);
        break;
    case 8:
        del_at_pos(head);
        break;
    case 9:
        del_ele(head);
        break;
    case 10:
        count_node(head);
        break;
    case 11:
        search(head);
        break;
    case 12:
        printf("Quit");
        break;
    }
    } while (choice!=12);
return 0;
}