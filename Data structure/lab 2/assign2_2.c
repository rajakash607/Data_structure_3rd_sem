#include<stdio.h>
#include<stdlib.h>
void non_zero(int *arr[],int size) {
    int count=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j]!=0)
            {
                count++;
            }
        }
    }
printf("Total no of non zero elements in this array is %d\n",count);
}
void sum_above_lead_diagonal(int *arr[],int size){
    int count=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            count=count + arr[i][j];
        }
        
    }
    printf("Sum of elements above leading diagonal is %d\n",count);
}
void below_minor_diagonal(int *arr[],int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
        
    }



}
void product_lead_diagonal(int *arr[],int size){
    int count=1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i+j==size-1)
            {
                count=count*arr[i][j];
            }
        }
    }
    printf("Product of leading diagonal elements is %d\n",count);

};
int main()
{
    int n,choice;
    printf("Enter the size of 2-D array to create\n");
    scanf("%d",&n);
    int **array=malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        array[i] =malloc(n*sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter value at index %d %d\n",i,j);
            scanf(" %d",&array[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");
        
    }
    printf("Enter 1 for no of all non zero elements\n 2 for sum of elements above the leading diagonal\n3 for displaying no below minor diagonal\n4 for product of the leading diagonal elements\n");
    scanf(" %d",&choice);
    do
    {
        switch (choice)
    {
    case 1:
        non_zero(array,n);
        break;
    case 2:
        sum_above_lead_diagonal(array,n);
    break;
    case 3:
        below_minor_diagonal(array,n);
    break;
    case 4:
        product_lead_diagonal(array,n);
    break;
    default:
        break;
    }
    } while (choice != 0);
    
    
    
return 0;
}