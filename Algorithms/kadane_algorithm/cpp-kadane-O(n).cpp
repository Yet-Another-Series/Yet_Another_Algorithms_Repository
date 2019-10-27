#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int max_ending_here=a[0];
        int max_so_far=a[0];
        for(int i=1;i<n;i++)
        {
        max_ending_here = max(a[i], max_ending_here+a[i]); 
            
            if(a[i] >0 && max_so_far < max_ending_here)
            max_so_far=max_ending_here;
        }
        cout<<max_so_far<<endl;
    }
	return 0;
}
