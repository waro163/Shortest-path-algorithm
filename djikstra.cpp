#include<iostream>
using namespace std;
int main()
{
    int i,j,k,n,m,u,min,t1,t2,t3;
    int a[50][50];
    int dis[50];//shortest distance from src to dst
    int flag[50];//whether this dst have joined shortest path
    int inf=999;//can't reach this dst distance
    int path[50];//storage the last node path to destination
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(i==j)a[i][j]=0;
        else a[i][j]=inf;
    }
    for(i=0;i<m;i++)
    {
        cin>>t1>>t2>>t3;
        a[t1][t2]=t3;
    }
    //print the graph
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=0;i<n;i++)
    {
        flag[i]=0;
        dis[i]=a[0][i];
        if(dis[i]<inf){
                path[i]=i;
        } else path[i]=inf;
    }
    flag[0]=1;
    //djikstra core algorithm
    for(i=0;i<n-1;i++)
    {
        min=inf;
        //u=-1;
        for(j=1;j<n;j++)
        {
            if(flag[j]==0 && dis[j] < min)
            {
                min=dis[j];
                u=j;
            }
        }
        //if can't find u, break branch should be added
        //if(u==-1)break;
        flag[u]=1;
        for(j=1;j<n;j++)
        {
            if(a[u][j]<inf)
            {
                if(dis[j]>dis[u] + a[u][j]){
                    dis[j]=dis[u] + a[u][j];
                    path[j]=u;
                }

            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<dis[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<path[i]<<" ";
    }
    return 0;
}
