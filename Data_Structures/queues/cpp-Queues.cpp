#include<iostream>
using namespace std;
int main(){
	
	
	
	int n,f=-1,r=-1; // f will be pointing to first element of queue and r to last element
	int a[n]; //a[n] is the queue 
	cin >> n; // size of queue
	
	
	
	while(1){ 
		int x;
		cin >> x; 
		switch(x){
			case 1: //for x==1 insertion will take place 
				if(r==n-1) cout << "Queue is full" << endl;
				else{
					int p;
					cin >> p;
					f=0;
					r++;
					a[r]=p;
				}
				break;
				
				
				
				
			case 2: // x==2 deletion will take place
			    if(f==r) cout << "Queue is empty" << endl;
				else{
					int q;
					q=a[f];
					f++;
				}
				break;
				
				
				
				
			case 3: // x==3 queue will be displayed
			    for(int j=f;j<=r;j++){
			    	cout << a[j] << " ";
				}
				break;
				
				
				
			case 4: //x==4  queue will be displayed and the whole program will be stopped
				for(int j=f;j<=r;j++){
					cout << a[j] << " ";
				}
				cout << endl;
			    exit(0);// this command will stop the program
			    
			    
			    
			default: cout << "ERROR" << endl;				
		}
	}
}
