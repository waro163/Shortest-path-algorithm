#include<iostream>
using namespace std;
int main()
{
    int i,j,k,n,m,u,min,t1,t2,t3;
    int a[50][50],dis[50],flag[50],inf=999;
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
    }
    flag[0]=1;
    for(i=0;i<n;i++)
    {
        min=inf;
        for(j=1;j<n;j++)
        {
            if(flag[j]==0 && dis[j] < min)
            {
                min=dis[j];
                u=j;
            }
        }
        flag[u]=1;
        for(j=1;j<n;j++)
        {
            if(a[u][j]<inf)
            {
                if(dis[j]>dis[u] + a[u][j])
                    dis[j]=dis[u] + a[u][j];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}
