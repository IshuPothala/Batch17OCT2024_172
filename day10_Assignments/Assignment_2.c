/*
A2.Program to find nth number made of given four digits 1, 4,6 and 9 as the only digits..

Input Format:

The First Line Of Input Contains T no of test cases
The Second Line Of Input Contains N as input taken.

Output Format:
Print the number of digits in the nth number .

Constraints:

1<=T<=100
1<=N<=100

Examples:

Input : 6
Output : 14

1,4 6, 9.11,14

Input : 21
Output : 111
DATE:7/11/2024
Author Name:Iswarya Pothala
*/


#include <stdio.h>

int main()
{
    int N;
    printf("\nEnter the number: \n");
    scanf("%d",&N);
    generateNthnum(N);
    return 0;
}
void generateNthnum(int num)
{
    int digits[]={1,4,6,9};
    int number[10];
    int iv=0;
    int i;
    while(num>0)
    {
        number[iv++]=digits[(num-1)%4];
        num=(num-1)/4;
    }
    for(i=iv-1;i>=0;i--)
    {
        printf("%d",number[i]);
    }
    printf("\n");
}
