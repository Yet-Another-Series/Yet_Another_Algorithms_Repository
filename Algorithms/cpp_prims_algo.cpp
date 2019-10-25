#include <iostream>
#include<climits>
using namespace std;
int findmin(int * arr,int V,bool *visit){
    int min=INT_MAX,index;
    for(int i=0;i<V;i++){
        if(arr[i]<min&&visit[i]==0){
            min=arr[i];
            index=i;
        }
    }
    return index;
}


int main()
{
    int V, E;
    cin >> V >> E;
    int arr[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
        {
            arr[i][j]=0;
        }
    }
    int w[V],p[V];
    bool v[V];
    w[0]=0;
    p[0]=-1;
    for(int i=0;i<E;i++){

        int s,e,ww;
        cin>>s>>e>>ww;
        arr[s][e]=ww;
        arr[e][s]=ww;



    }
    for(int i=1;i<V;i++){
        p[i]=w[i]=INT_MAX;
        v[i]=0;
    }

    int count =0;
    while(count!=V-1){
        int pos=findmin(w,V,v);
        v[pos]=1;
        for(int i=0;i<V;i++){
            if(arr[pos][i]!=0&&v[i]==0){
                if(arr[pos][i]<w[i]){
                    w[i]=arr[pos][i];
                    p[i]=pos;
                }
            }
        
        }
        count++;

    }
    for(int i=1;i<V;i++)
    {
        if(i<p[i]){
            cout<<i<<" "<<p[i]<<" "<<arr[i][p[i]]<<endl;

        }
        else
            cout<<p[i]<<" "<<i<<" "<<arr[i][p[i]]<<endl;


    }



    return 0;
}
