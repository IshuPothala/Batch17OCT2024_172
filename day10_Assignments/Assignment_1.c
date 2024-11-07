/*Description:  A1. Check whether a given number can be expressed as the sum of two prime number 

i/p
Enter a positive integer: 34
Output
34 = 3 + 31

34 = 5 + 29
34 = 11 + 23
34 = 17 + 17
NoofWays = 4

NoofWays=-1


DATE:7/11/2024
Author Name:Iswarya Pothala


*/



#include <stdio.h>

int is_prime(int number)
{
    int i;
    if(number<=1)
        return 0;
    for(i=2;i*i <= number;i++)
    {
        if (number%i==0)
          return 0;
    }
    return 1;
}
// pair of primes which can sum up
void find_pair(int number)
{
    int counter=0;
    for (int i=2;i<number;i++)
    {
        if(is_prime(i) && is_prime(number-i))
        {
            printf("%d=%d+%d\n",number,i,number-i);
            counter++;
        }
    }
    if (counter==0)
    {
        printf("NoofWays=-1\n");
    }
    else
    {
        printf("NoofWays=%d\n",counter);
    }
}
int main()
{
    int number;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    if (number<2)
       printf("NoofWays=-1\n");
    else
      find_pair(number);
      return 0;
}