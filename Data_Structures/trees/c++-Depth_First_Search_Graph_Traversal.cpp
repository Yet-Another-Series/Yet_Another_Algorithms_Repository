//Depth First Search
#include<iostream.h>
#include<conio.h>
class Graph
{
int a[10][10],n,s;
public:
void getdata();
void dfs_traverse();
};
void Graph::getdata()
{
cout<<"\n Enter the number of vertices in the graph: ";
cin>>n;
cout<<"\n Enter the adjacency matrix of graph: "<<endl;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
cin>>a[i][j];
cout<<"\n Enter the vertex from which you want to traverse: ";
cin>>s;
}
void Graph::dfs_traverse()
{
int *visited= new int[n];
int stack[10],top=-1,i;
for(int j=0;j<n;j++)
visited[j]=0;
cout<<"\n The Depth First Search Traversal : "<<endl;
i=stack[++top]=s;
visited[s]=1;
while(top>=0)
{
i=stack[top];
cout<<stack[top--]<<endl;
for(int j=n-1;j>=0;j--)
if(a[i][j]!=0&&visited[j]!=1)
{
stack[++top]=j;
visited[j]=1;
}
}
}
int main()
{
Graph DFS;
clrscr();
DFS.getdata();
DFS.dfs_traverse();
getch();
return 0;
}