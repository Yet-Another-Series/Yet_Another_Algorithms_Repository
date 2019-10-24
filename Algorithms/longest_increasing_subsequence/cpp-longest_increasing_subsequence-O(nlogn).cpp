// O(nlogn) solution for longest increasing subsequence using dynamic programming
#include <bits/stdc++.h>
using namespace std; 

const int INF = 1001001001;

int LIS(int arr[],int n) {
  int dp[n];
  fill(dp,dp+n,INF);
  for (int i = 0; i < n; i++) {
    *lower_bound(dp,dp+n, arr[i]) = arr[i];
  }
  return lower_bound(dp, dp+n, INF) - dp;
}


int main() {
  int n;
  cout << "Please input the number of elements in the array ";
  cin >> n;
  int arr[n];
  cout << "Please input array ";
  for (int i = 0; i < n;i++) {
    cin >> arr[i];
  }
  cout << LIS(arr,n);
  return 0;
}