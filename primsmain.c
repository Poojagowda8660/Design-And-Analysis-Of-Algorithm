#include <stdio.h>
#include <stdlib.h>
void Prims(int cost[10][10],int n)
{
    int i,j,visited[10],u,v,ne=1,min,mincost=0;
    for(i=1;i<=n;i++)
        visited[i]=0;
    visited[1]=1;
    while(ne<n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]==1)
                        continue;
                    else
                    {
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if(visited[u]==0||visited[v]==0)
        {
            printf("\n %d Edge(%d,%d)=%d",ne++,u,v,min);
            mincost=mincost+min;
            visited[v]=1;
        }
        cost[u][v]=cost[v][u]=999;
    }
    printf("\nCost of spanning tree is %d",mincost);
}

int main()
{
    int i,j,n,cost[10][10];
    printf("\nRead number of nodes:");
    scanf("%d",&n);
    printf("\nRead cost matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    Prims(cost,n);
    return 0;
}
