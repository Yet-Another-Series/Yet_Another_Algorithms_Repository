#include <iostream>
#include<climits>
using namespace std;
int findminVertex(int * weights, int V, bool* visited){
    int min=INT_MAX;
    int pos=-1;
    for(int i=0; i<V; i++){
        if(weights[i]<min && visited[i]==false){
            min=weights[i];
            pos=i;
        }
    }

    return pos;

}

void dijkstra(int ** arr, int V, int E){
    bool * visited=new bool[V];
    int * weights=new int[V];
    for(int i=0; i<V; i++){
        visited[i]=false;
    }

    weights[0]=0;

    for(int i=1; i<V; i++){
        weights[i]=INT_MAX;
    }
    int count=1;
    while(count<=(V-1)){
        int minVertex=findminVertex(weights, V, visited);
        visited[minVertex]=true;
        for(int i=0; i<V; i++){
            if(arr[minVertex][i]!=0 && visited[i]==false){
                if(arr[minVertex][i]+weights[minVertex]<weights[i]){
                    weights[i]=arr[minVertex][i]+weights[minVertex];
                }
            }
        }

        count++;

    }


    //print
    for(int i=0; i<V; i++){
        cout<<i<<" "<<weights[i];
        cout<<endl;
    }





}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;

    int ** arr=new int*[V];

    for(int i=0; i<V; i++){
        arr[i]=new int[V];
    }

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            arr[i][j]=0;
        }
    }

    for(int i=0; i<E; i++){
        int sv;
        int ev;
        int w;
        cin>>sv>>ev>>w;
        arr[sv][ev]=w;
        arr[ev][sv]=w;
    }

    dijkstra(arr, V, E);


    return 0;
}
