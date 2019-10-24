#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int BIT[MAX]={0};
 
int sum(int idx) {         //returns the sum from [0,idx] in O(logn) time
	int ans = 0;
	while(idx > 0) {
		ans += BIT[idx];
		idx -= idx & (-idx);
	}
	return ans;
}

void add(int idx,int val) {   //adds the value in the tree in O(logn) time
	while(idx < MAX) {
		BIT[idx] += val;
		idx += idx & (-idx);
	}
}

int sum_range(int l, int r) {   //returns sum from index l to r both inclusive.
	return sum(r) - sum(l-1);
}

int main() {

	int n; cin>>n;
	for(int i=1;i<=n;i++) {
		int x; cin>>x;   
		add(1,x);    //keep adding the value in the tree.
	}

	cout<<sum_range(1,n);   //return the same from [1,n], feel free to change according to your needs

}
