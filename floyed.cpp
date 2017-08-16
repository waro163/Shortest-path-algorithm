#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int i,j,k,n,m,t1,t2,t3;
    int a[50][50],inf=999,b[50][50];
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
        b[t1][t2]=t2;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(a[i][k] <= inf && a[k][j] <= inf && a[i][j] > a[i][k] + a[k][j])
        {
           a[i][j] = a[i][k] + a[k][j];
            b[i][j] = k;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<i<<" "<<j<<" "<<b[i][j]<<"|";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
