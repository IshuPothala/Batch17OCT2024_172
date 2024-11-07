/*
. rotate array every kth element

1 2 3 4 5 6 7 8 9

k= 3

3 2 1 6 5 4 9 8 7
*/
#include <stdio.h>

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int i;
    rotate_k_element(arr,n,k);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
void rev(int arr[],int start,int end)
{
    while (start<end)
    {
        int temp;
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
        
    }
}
void rotate_k_element(int arr[],int n,int k)
{
    int i,end;
    for(i=0;i<n;i=i+k)
    {
        end=(i+k-1<n)?(i+k-1):(n-1);
        rev(arr,i,end);
    }
}