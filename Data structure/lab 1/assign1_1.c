//Write a program that will merge the contents of two sorted (ascending order) arrays of type double values. Store the result in an output array (still in ascending order). The program should not assume that both its input arrays are of same length but can assume that one array does not contain duplicate values. The result array should also contain no duplicate values.  
#include<stdio.h>
int main()
{
    double array1[5] = {1.0, 3.0, 5.0, 7.0, 9.0};
    double array2[4] = {2.0, 4.0, 6.0, 8.0};
    double array3[9];
    int i = 0, j = 0, k = 0;
    while (i<5 && j<4)
    { 
        if (array1[i]<array2[j])
        {
            array3[k]=array1[i];
            k++;
            i++;
        }
        else
        {
            array3[k]=array2[j];
            k++;
            j++;
        } 
    }
    while (i < 5) {
        array3[k] = array1[i];
        i++;
        k++;
    }

    while (j < 4) {
        array3[k] = array2[j];
        j++;
        k++;
    }
    
for (int i=0; i<9; i++){
    printf("%.1f ",array3[i]);
}
return 0;
}