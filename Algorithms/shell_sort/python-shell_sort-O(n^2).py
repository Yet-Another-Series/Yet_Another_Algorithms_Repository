#python implementation 
#shell sort


def shellSort(arr):

    n = len(arr);
    window = n/2;

    while window > 0:
        for i in range(window, n):
            temp = arr[i]
            j = i;
            
            while j>=window and arr[j-window] > temp:
                arr[j] = arr[j - window]
                j -= window
            
            arr[j] = temp

        window /= 2

arr = [12, 34, 52, 2, 3]

n = len(arr)

shellSort(arr)

for i in range(n):
    print(arr[i])

