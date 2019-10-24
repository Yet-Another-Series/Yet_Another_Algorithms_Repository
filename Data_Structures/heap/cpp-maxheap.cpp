#include<cstdio>

int heap[1024];
int ptr;
void add(int num){
    heap[ptr] = num;
    int nowPtr = ptr;
    while(nowPtr != 0){
        if(heap[nowPtr] <= heap[(nowPtr-1)/2]){
            break;
        }
        else{
            int x = heap[nowPtr];
            heap[nowPtr] = heap[(nowPtr-1)/2];
            heap[(nowPtr-1)/2] = x;
            nowPtr = (nowPtr-1)/2;
        }
    }
    ptr++;
}
int pop(){
    int output = heap[0];
    heap[0] = heap[ptr-1];
    int nowptr = 0;
    while(true){
        if(nowptr*2+1 >= ptr){
            break;
        }
        else if(nowptr*2+2 == ptr){
            if(heap[nowptr] > heap[nowptr*2+1])break;
            else{
                int temp = heap[nowptr];
                heap[nowptr] = heap[nowptr*2+1];
                heap[nowptr*2+1] = temp;
                break;
            }
        }
        else{
            if(heap[nowptr] >= heap[nowptr*2+1] && heap[nowptr] >= heap[nowptr*2+2]){
                break;
            }
            else if(heap[nowptr*2+1] > heap[nowptr*2+2]){
                int temp = heap[nowptr];
                heap[nowptr] = heap[nowptr*2+1];
                heap[nowptr*2+1] = temp;
                nowptr = nowptr*2+1;
            }
            else{
                int temp = heap[nowptr];
                heap[nowptr] = heap[nowptr*2+2];
                heap[nowptr*2+2] = temp;
                nowptr = nowptr*2 +2;
            }
            
        }

    }

    ptr--;
    return output;
}

void print(){
    for(int i=0;i<ptr;i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}



int main(){
    ptr = 0;
    
    //example

    add(10);
    add(8);
    add(5);
    add(3);
    add(7);
    add(12);
    add(9);
    add(3);
    add(7);
    add(12);
    print();
    printf("%d\n", pop());
    print();
    printf("%d\n", pop());
    print();


}
