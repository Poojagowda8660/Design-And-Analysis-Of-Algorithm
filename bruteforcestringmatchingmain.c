#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int count=0;
int bfsm(char T[20],char P[10])
{
    int m,n,i,j;
    n=strlen(T);
    m=strlen(P);
    for(i=0;i<=n-m;i++)
    {
        j=0;
        while(j<m&&P[j]==T[i+j])
        {
            count++;
            j=j+1;
        }
        count++;
        if(j==m)
            return i+1;
    }
    return -1;
}
int main()
{
    char T[20],P[10];
    int flag;
    printf("\nEnter the text\n");
    scanf("%s",&T);
    printf("\nEnter the pattern to be matched\n");
    scanf("%s",&P);
    flag=bfsm(T,P);
    if (flag==-1)
        printf("\nPattern not found");
    else
        printf("\nPattern found at %d location",flag);
        printf("\nCount=%d",count-1);
    return 0;

}
