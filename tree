#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) arr[i][j]=0;
    }

    vector<vector<int> >v(n);
    int start,end;
    for(int i=0;i<e;i++)
    {
        cin>>start>>end;
        arr[start-1][end-1]=1;
        arr[end-1][start-1]=1;
        v[start-1].push_back(end-1);
        v[end-1].push_back(start-1);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" : ";
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]+1<<" ";
        }
        cout<<endl;
    }



}
