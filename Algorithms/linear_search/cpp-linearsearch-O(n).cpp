#ifndef LINEAR_H
#define LINEAR_H
    
    // Function searches for an int in an array and returns its position, or -1 if it's not found.
    
    int get_pos(int array[], int target){
         for(unsigned int i = 0; i < (sizeof(array) / sizeof(*array)); i++){
              if(array[i] == target) return i;
         }
         return -1;
    }
    
#endif
