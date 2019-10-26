#include<bits/stdc++.h>
using namespace std;

void construct(vector<int>v, vector<int> &tree, int low, int high, int pos)
{
    if(high == low)
    {
        tree[pos] = v[low];
        return;
    }
    int mid = (high+low)/2;
    construct(v, tree, low, mid, 2*pos+1);
    construct(v, tree, mid+1, high, 2*pos+2);
    tree[pos] = min(tree[pos*2+1], tree[pos*2+2]);
}

int rangeMinQuery(vector<int> &tree,int x1, int x2, int low, int high, int pos)
{
    if(x2<low or x1>high)               //no overlap
    return INT_MAX;
    else if(x1<=low and x2>=high)       //total overlap
    return tree[pos];
    //Partial overlap
    int mid = (low+high)/2;
    return min(rangeMinQuery(tree, x1, x2, low, mid, 2*pos+1), rangeMinQuery(tree, x1, x2, mid+1, high, 2*pos+2));
}

int main()
{
    int  n;
    cin >> n;
    vector<int> v(n);
    vector<int> tree(4*n);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    for(int i=0; i<4*n; i++)
    {
        tree[i] = INT_MAX;
    }
    construct(v, tree, 0, n-1, 0);
    int m;
    cin >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        cout << rangeMinQuery(tree, a, b, 0, n-1, 0) << endl;
    }
    
    return 0;
}
