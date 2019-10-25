#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    int arr[V][V];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            arr[i][j]=0;
    for(int i=0;i<V;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        arr[v1][v2]=arr[v2][v1]=1;
        
    }
    bool visit[V]={0};
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x=q.front();
        
        q.pop();
        for(int i=0;i<V;i++){
            if(arr[x][i]==1&&visit[i]==0)
            { q.push(i);
             cout<<x<<" ";
            visit[i]=1;}
            }
    }
    
    

  return 0;
}
