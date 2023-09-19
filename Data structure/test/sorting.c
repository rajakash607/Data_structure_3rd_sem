#include<stdio.h>
void sort(int arr[], int n){
    int temp,i,j;
    for (i=0;i<n-1;i++){
        for (j = i+1; j <n; j++)
        {
            if (arr[i]>arr[j])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
    
        }

        
    }

};
int main()
{
    int arr[]={
        34,11,90,1,6,778,34,67,42,78,98,12,98,54
    };
    sort(arr,14);
    for (int i = 0; i < 14; i++)
    {
        printf("%d ",arr[i]);
    }
    
    
return 0;
}