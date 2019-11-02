#include <iostream>
#include <vector>
int n;
std::vector<int> arr;
std::vector<int> tree;
std::vector<int> lazy;
void build(int node = 0, int start = 0, int end = n-1){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    build(2*node+1,start,(start+end)/2);
    build(2*node+2,(start+end)/2+1,end);
    tree[node] = tree[2*node+1] + tree[2*node+2];
}

int query(int l, int r, int node = 0, int start = 0, int end = n-1){
    if(lazy[node] != 0){
        tree[node] += (lazy[node]*(end-start+1));
        if(start != end){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > r || end < l)return 0;
    if(l<=start && end <= r)return tree[node];
    int p1 = query(l,r,2*node+1,start,(start+end)/2);
    int p2 = query(l,r,2*node+2,(start+end)/2+1,end);
    return p1+p2;
}

void update(int l, int r, int val, int node = 0, int start = 0, int end = n-1){
    if(lazy[node] != 0){
        tree[node] += (lazy[node]*(end-start+1));
        if(start != end){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > r || end < l)return;
    if(start == end){
        arr[start] += val;
        tree[node] += arr[start];
        if(tree[node] == 1)lazy[node] = true;
        return;
    }
    if(l<=start && end <= r){
        tree[node] += (val*(end-start+1));
        if(start != end){
            lazy[2*node+1]+=val;
            lazy[2*node+2]+=val;
        }
        lazy[node] = 0;
    }
    update(l,r,2*node+1,start,(start+end)/2);
    update(l,r,2*node+2,(start+end)/2+1,end);
    tree[node] = tree[2*node+1] + tree[2*node+2];
    return;
}

int main(){
    printf("Enter number of array elements (n) : ");
    scanf("%d",&n);
    arr = std::vector<int> (n);
    tree = std::vector<int> (4*n,0);
    lazy = std::vector<int> (4*n,0);
    for(int iterator = 0; iterator < n; ++i){
        scanf("%d",&arr[iterator]);
    }
    build();
    return 0;
}