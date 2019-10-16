#include<iostream>

using namespace std;


int shellSort(int arr[], int n){

  for (int x = n/2; x > 0; x /= 2) 
    { 
        
        for (int i = x; i < n; i += 1) 
        { 
            
            
            int temp = arr[i]; 
  
            
            
            int j;             
            for (j = i; j >= x && arr[j - x] > temp; j -= x) 
                arr[j] = arr[j - x]; 
              
            
            arr[j] = temp; 
        } 
    } 
    return 0; 
}

int main(){

    int arr[] = {12, 34, 54, 2, 3};

    int n = 5;

    shellSort(arr, n);

    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;

}