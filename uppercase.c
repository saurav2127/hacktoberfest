#include <stdio.h>                            //header files
#include <string.h>
#include <math.h>
int main()                             //main function
{
    char S[1000];                 //declaring variables and string
    int test; 
    int i=1;                    
    printf("Enter the no. of test cases = ");   //taking no. of test case as input
    scanf("%d",&test);
    start:  printf("Enter a string (Uppercase) = ");   //taking string as input and string must be those whose integer form lies in range of long long
    scanf("%s",S);
    int len=strlen(S);
    for(int j=0; j<len; j++)     //to check string is lower case or not
    {
        if(S[j]>=97 && S[j]<=122)
        {
            printf("String must be in uppercase.\n");
            i++;
            goto start;   
        }
    }
    int temp=len;
    long long sum=0;
    while(len--)           //loop to calculate integer form of string
    {
        char c=S[len];
        sum=sum+(pow(26,temp-(len+1))*(c-64));
    }
    printf("%lld\n",sum);
    if(i!=test)          //when test case is not equal to counter i, then it goes to start statment
    {
        i++;
        goto start;
    }
    return 0;
}
