class SearchMissingNumber{ 
    static int missingNumber(int ar[],int size) { 
        int a = 0, b = size - 1; 
        int mid = 0; 
        while ((b - a) > 1) { 
            mid = (a + b) / 2; 
            if ((ar[a] - a) != (ar[mid] - mid)) 
                b = mid; 
            else if ((ar[b] - b) != (ar[mid] - mid)) 
                a = mid; 
        } 
        return (ar[mid] + 1); 
    } 
    public static void main (String[] args) { 
    int ar[] = { 10,11,12,13,15,16,17,18,19 }; 
    int size = ar.length; 
    System.out.println("Missing number: " +missingNumber(ar, size)); 
    } 
} 