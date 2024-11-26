#include <stdio.h>
  2 #include <string.h>
  3 #define BUFF 1024
  4 int findSubstringPos(char *str, char *sub)
  5 {
  6   char *pos = strstr(str,sub);
  7   if( pos != NULL)
  8   {
  9     return pos-str;
 10   }
 11   else
 12     return -1;
 13 }
 14
 15 int findCharPos(char *str, char *c)
 16 {
 17   char *pos = strstr(str,c);
 18
 19   if( pos != NULL)
 20   {
 21      return pos-str;
 22   }
 23   else
 24     return -1;
 25 }
 26
 27 int main()
 28 {
 29   int n;
 30   char str[BUFF];
 31   scanf("%d",&n);
 32 //  getchar();
 33   int i;
 34   for(i=0;i<n;i++)
 35   {
 36     fgets(str,sizeof(str),stdin);
 37     str[strcspn(str,"\n")]='\0';
 38
 39     int pos_A= findSubstringPos(str,"is");
 40     int pos_IS = findCharPos(str,"a");
 41
 42     int sum = pos_A + pos_IS;
 43     printf("%d\n",sum);
 45     }
 46
 47     return 0;
 48
 49 }
 50
                