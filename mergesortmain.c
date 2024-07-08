#include <stdio.h>
#include <stdlib.h>
#define size 100
int count;
void merge(int A[size],int l,int m,int r)
{
    int i,j,k,B[size];
    i=l;
    j=m+1;
    k=l;
    while(i<=m && j<=r)
    {
        count++;
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    while(i<=m)
        B[k++]=A[i++];
    while(j<=r)
        B[k++]=A[j++];
    for(i=l;i<=r;i++)
        A[i]=B[i];
}
void mergesort(int A[size],int l,int r)
{
    int m;
    if(l<r)
    {
        m=(l+r)/2;
        mergesort(A,l,m);
        mergesort(A,m+1,r);
        merge(A,l,m,r);
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
    mergesort(A,0,n-1);
    printf("\nSorted elements are\n");
    for(i=0;i<=n-1;i++)
        printf("%d\t",A[i]);
    printf("\nCount=%d",count);
    return 0;
}
