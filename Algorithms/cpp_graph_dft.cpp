#include <iostream>

using namespace std;

void dft(int** arr, int size, int sv, bool* visited){


    visited[sv]=true;
    cout<<sv<<" ";
    for(int i=0; i<size; i++){
        if(arr[sv][i]==1 && visited[i]==false){
            dft(arr, size, i, visited);
        }
    }




}


int main()
{
    int numofvertices;
    cin>>numofvertices;
    int numberofEdges;
    cin>>numberofEdges;
    int** arr=new int*[numofvertices];
    for(int i=0; i<numofvertices; i++){
        arr[i]=new int[numofvertices];
    }
    for(int i=0; i<numofvertices; i++){
        for(int j=0; j<numofvertices; j++){
            arr[i][j]=0;
        }
    }
    for(int i=0; i<numberofEdges; i++){
        int v1, v2;
        cin>>v1>>v2;
        arr[v1][v2]=1;
        arr[v2][v1]=1;

    }
    bool * visited=new bool[numofvertices];
    for(int i=0; i<numofvertices; i++){
        visited[i]=false;
    }
    dft(arr, numofvertices, 0,visited);
}
