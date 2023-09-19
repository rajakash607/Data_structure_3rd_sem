#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node * add_first_node(int data){
    struct node*temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    return temp;
};
struct node* add_at_pos(struct node* head, int data, int pos){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    if (pos == 0) {
        temp->next = head;
        if (head != NULL) {
            head->prev = temp;
        }
        return temp;
    }

    struct node* p = head;
    for (int i = 0; i < pos - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL) {
        printf("Error: Position out of range\n");
        free(temp);
        return head;
    }

    temp->prev = p;
    temp->next = p->next;
    if (p->next != NULL) {
        p->next->prev = temp;
    }
    p->next = temp;

    return head;
};
struct node* add_at_end(struct node *head, int data){
    struct node *temp=head;
    struct node*p=malloc(sizeof(struct node));
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=p;
    p->data=data;
    p->prev=temp;
    p->next=NULL;
    return head;
};
struct node*create_full_list(struct node* head){
    int size,data;
    printf("Enter no of nodes for the linked list to create ");
    scanf("%d",&size);
    if (size==0)
        return head;
    for (int i = 0; i < size; i++)
    {
        printf("Enter data for %d position ",i+1);
        scanf("%d",&data);
        if (i==0)
        {
            head=add_first_node(data);
        }
        else
        {
            head=add_at_end(head,data);
        }
        
        
    }
    return head;

};
struct node *reverse(struct node *head){
    struct node * temp=head->next,*ptr=NULL;
    while (temp!= NULL)
    {
        head->prev=temp;
        head->next=ptr;
        ptr=head;
        head=temp;
        temp=temp->next;
    }
    head->prev=temp;
    head->next=ptr;
    return head;
};
void display(struct node*head){
    struct node* temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
};

int main()
{
    struct node*head;
    // head=add_first_node(145);
    // head=add_at_end(head,12);
    // head=add_at_end(head,156);
    // head=add_at_end(head,129);
    // head=add_at_pos(head,999,3);
    // head=add_at_end(head,112);
    // head=add_at_end(head,192);
    head=create_full_list(head);
    head=reverse(head);
    display(head);
return 0;
}