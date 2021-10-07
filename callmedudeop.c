#include <stdio.h>
#include <string.h>
int AWM(int n, int i, int k);
int primechk(int a);
int sum=0;
int AWM(int n, int i, int k)
{    int c=0;
    
    if (i <= n) {
        if (n % i == 0) {
            if(i%k!=0)
            {c=1;sum=sum+i;return i;}
        }
 
        // Calling the function recursively
        // for the next number
        if(c==0)
        AWM(n, i - 1,k);
    }
}
int primechk(int a)
{
   int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
     return 0;
   }
   return 1;
}
 
int main()
{
int N,K;
printf("Enter n : ");
scanf("%d",&N);
printf("Enter k : ");
scanf("%d",&K);

if(primechk(K)==0)
{printf("ERROR k is not a prime number");
return 0;}


int arr[N];
 for(int i=1,j=0;i<N+1,j<N;i++,j++)
   arr[j]=AWM(i,i,K);

printf("\narray is [");
 for(int j=0;j<N;j++)
 {
   printf("%d",arr[j]);
   if(j<N-1)
   printf(",");
   else printf("]");

 }  
 printf("\nSum is %d",sum);   
    return 0;
}
