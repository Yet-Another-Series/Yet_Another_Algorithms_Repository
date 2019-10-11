#include <bits/stdc++.h>

#define ll long long

#define esq(x) 2*(x)
#define dir(x) (2*(x))+1

#define MAX 1000000

using namespace std;

ll segTree[4 * MAX]; // 1 indexed
ll arr[MAX];

/**
 * build the tree based on arr
 *
 * call build(1, 1, n)
 */
ll build(int ind, int l, int r) {
    if(l == r) return segTree[ind] = arr[l-1];
    int mid = (l + r) >> 1;
    return segTree[ind] = build(esq(ind), l, mid) +
            build(dir(ind), mid + 1, r);
}

/**
 * call query(1, 1, n, A, B)
 * 
 * ind: node id
 * l and r: node's range
 * A: left of the query
 * B: right of the query
 */
ll query(int ind, int l, int r, int A, int B) {
    if(l >= A && r <= B) return segTree[ind];
    if(r < A || l > B) return 0;
    int mid = (l + r) >> 1;
    return query(esq(ind), l, mid, A, B) +
            query(dir(ind), mid+1, r, A, B);
}

/**
 * call update(1, 1, n, x, val)
 *
 * ind: node id
 * l and r: node's range
 * x: position to update
 * val: sum val to position x
 */
ll update(int ind, int l, int r, int x, int val) {
    if(l == r) return segTree[ind] += val;
    int mid = (l + r) >> 1;
    if(x <= mid) update(esq(ind), l, mid, x, val);
    else update(dir(ind), mid+1, r, x, val);
    return segTree[ind] = segTree[esq(ind)] + segTree[dir(ind)];
}

int main() {
    int n = 5;
    for(int i = 0; i < n; i++) {
        arr[i] = i;
    }

    build(1, 1, n);
    cout << query(1, 1, n, 2, 3) << endl; // query range 2-3
    update(1, 1, n, 3, 1); // sum 1 to position 3
    cout << query(1, 1, n, 2, 3) << endl;
}
