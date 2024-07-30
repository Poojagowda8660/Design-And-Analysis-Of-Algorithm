#include <stdio.h>
#include <stdlib.h>
#define size 100
int count=0;
void insertionsort(int A[size],int n)
{
    int i,j,temp,item;
    for(i=0;i<=n-1;i++)
    {
        item=A[i];
        j=i-1;
      while(j>=0 && A[j]>item)
      {
          A[j+1]=A[j];
          j=j-1;
          A[j+1]=item;
      }
    }
}
int main()
{
int i,A[size],n;
printf("\nRead array size:");
scanf("%d",&n);
printf("\nRead array elements\n");
for(i=0;i<=n-1;i++)
    scanf("%d",&A[i]);
insertionsort(A,n);
printf("\nSorted elements are\n");
for(i=0;i<=n-1;i++)
    printf("%d\t",A[i]);
printf("\nCount=%d",count);
return 0;
}
