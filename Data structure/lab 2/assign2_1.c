#include<stdio.h>
#include<stdlib.h>
void display(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
int sum(int arr[],int size) {
    int sum =0;
    for (int i = 0; i < size; i++)
    {
        sum=sum + arr[i];
    }
    return(sum);
}
void odd_even(int arr[],int size)
{
    int even = 0,odd=0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]%2==0)
        {
           even++;
        }
        else
        {
            odd++;
        }
    }
    printf("even %d odd %d\n",even,odd);
}
void insert(int arr[],int size,int loc,int element){
    for (int i = 0; i < loc; i++)
    {
        arr[i]=arr[i-1];
    }
    arr[loc]=element;
    display(arr,size+1);
}
void delete(int arr[],int size,int loc){
    for (int i = loc; i < size; i++)
    {
        arr[i]=arr[i+1];
    }
    display(arr,size-1);

}
int search(int arr[],int size,int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element)
        {
            return (i);
        }
        return -1;
    }
}
void sort(int arr[],int size){
    int i,j,temp;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if (arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            
        }
    }
    display(arr,size);
}

void reverse(int arr[],int size){
    int *temp;
    temp=(int *)malloc(size*4);
    for (int i = 0; i < size; i++)
    {
        temp[size-1-i]=arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i]=temp[i];
    }
    display(arr,size);

    
}

int main()
{
    int* ptr;
    int n, i,choice,loc,element;
 
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter elements: \n");
 
    ptr = (int*)malloc(n * 4);
 
        for (i = 0; i < n; ++i) {
            scanf("%d",&ptr[i]);
        }

        printf("Enter 1 for sum\n 2 for total no of odds and evens\n 3 for inserting an element\n 4 for deleting an element\n 5 for serching an element\n 6 for sorting the array \n 7 for reversing the array \n and 8 for displaying the array\n");
        do
        {
        scanf(" %d",&choice);
        int add;
        switch (choice)
        {
        case 1:
            add = sum(ptr,n);
            printf("%d is the sum",add);
            break;
        case 2:
            odd_even(ptr,n);
            break;
        case 3:
            printf("To insert give location and element");
            scanf(" %d %d",&loc,&element);
            insert(ptr,n,loc,element);
            break;
        case 4:
            printf("To deletr give location");
            scanf(" %d",&loc);
            delete(ptr,n,loc);
            break;
        case 5:
            printf("To search give element");
            scanf(" %d",&element);
            search(ptr,n,element);
            break;
        case 6:
            sort(ptr,n);
            break;
        case 7:
            reverse(ptr,n);
            break;
        case 8:
            display(ptr,n);
            break;
        }
        } while (choice!=0);
        
   
return 0;
}