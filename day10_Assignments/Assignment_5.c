/*
Write a c program to print alphabet triangle.
Input: 5
Output:

     A
    ABA
   ABCBA
  ABCDCBA
 ABCDEDCBA
*/


#include <stdio.h>
int main()
{
    int num,i,j,k;
    printf("Enter the number of rows: ");
    scanf("%d",&num);
    
    for(i=1;i<=num;i++)
    {
        for(j=1;j<num-i;j++)
        {
            printf(" "); //For spacing 
        }
        for(j=1;j<=i;j++)
        {
            printf("%c",'A'+j-1); // Increasing alphabets
        }
        for (k=i-1;k>=1;k--)
        {
            printf("%c",'A'+k-1); //Decreasing alphabets
        }
        printf("\n");
    }
    return 0;
}
