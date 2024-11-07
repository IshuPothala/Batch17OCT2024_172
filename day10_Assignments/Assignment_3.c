/*A3. Write a program to find the  n-th number made of prime digits

Input Format:
First Line Of Input Contains T Number Of Test Cases
Second Line Of Input Contains an input Number N.

Output Format:
Print the Nth number of sequence and it should be only prime.

Constraints:
1<=T<=100
1<=N<=10000

Examples :
Input  :
10
Output :
 33

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