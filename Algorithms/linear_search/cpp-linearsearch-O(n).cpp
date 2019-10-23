#include <iostream>                                                                    
using namespace std;

int main(){
     int array[] = {1,2,13,4,5,6};
     int target = 3;
     bool found = false;
     unsigned int i;
      
     for(i = 0; i < (sizeof(array) / sizeof(array[0])); i++){
         if(array[i] == target){
               cout << i << endl;
               found = true;
         }
     }
     if(!found) cout << -1 << endl;
            
     return 0;
}
