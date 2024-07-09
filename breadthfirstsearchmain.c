#include <stdio.h>
#include <stdlib.h>
void bfs(int A[10][10],int n,int visited[10],int source)
{
    int Queue[10],rear=-1,front=0,i,delnode;
    visited[source]=1;
    Queue[++rear]=source;
    while (front<=rear)
    {
        delnode=Queue[front++];
        for(i=1;i<=n;i++)
        {
            if (A[delnode][i]==1 && visited[i]==0)
            {
                Queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}


int main()
{
    int n,A[10][10],i,j;
    int visited[10],count=0;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    printf("\nRead the adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
               scanf("%d",&A[i][j]);
        }
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
    for(i=1;i<=n;i++)
    {
        if (visited[i]==0)
        {
            bfs(A,n,visited,i);
                count++;
        }
    }

    if (count==1)
        printf("\nGraph is connected,one component");
    else
        printf("\nGraph is not connected,%d component",count);
    return 0;
}
