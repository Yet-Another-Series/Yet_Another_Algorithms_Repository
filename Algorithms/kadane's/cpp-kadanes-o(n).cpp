#include <iostream>
using namespace std;

int main (int argc,  char** argv) {

// no of elements in array
  int n;
  cin >> n;
  
  int a[n];
 // input array elements
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  int current_sum = a[0], max_sum_till_now = a[0];
  
  for (int i = 1; i < n; ++i) {
  
// if current sum (including current array element) is smaller than previous sum
    if (current_sum > current_sum + a[i]) {
      curren_sum = 0;
    }
    
// add current array element to current sum
    else {
      current_sum += a[i];
    }
    
// if current sum is greater than max sum till now, then update the value of max sum
    max_sum_till_now = max_sum_till_now > current_sum? max_sum_till_now : current_sum;
  }
  
  return 0;
}
