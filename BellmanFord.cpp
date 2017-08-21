#include<iostream>
using namespace std;
typedef struct EDGE
{
    int from;
    int to;
    int value;
};
int main()
{
    int i,j,k,n,m,u,min,t1,t2,t3;
    EDGE a[50];
    int dis[50];//shortest distance from src to dst
    int flag[50];//whether this dst have joined shortest path
    int inf=999;//can't reach this dst distance
    int path[50];//storage the last node path to destination
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a[i].from>>a[i].to>>a[i].value;
    }
    for(i=0;i<n;i++)
    {
        dis[i]=inf;
    }
    dis[0]=0;

    //bellman ford core algorithm
    for(j=0;j<n;j++)
        for(i=0;i<m;i++)
        if(dis[a[i].from] < inf && dis[a[i].to] > dis[a[i].from] + a[i].value )
    {
        dis[a[i].to] = dis[a[i].from] + a[i].value;
    }
    for(i=0;i<n;i++)
        cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}
