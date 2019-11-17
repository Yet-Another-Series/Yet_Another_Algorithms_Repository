// O(n) solution for finding maximum sum of 
// a subarray of size k 

// Returns maximum sum in a subarray of size k. 
function findHighestSpending(input, n, k) {
    if (n < k) {
        console.error("Error: n must be greater than k");
        return -1;
    }

    // Find sum of first subarray of size k 
    var highestSpending = 0;
    for (var i = 0; i < k; i++) {
        highestSpending += input[i];
    }

    // Create temporary variable to store total number on each slide 
    var window_sum = highestSpending;
    // Slide along the array by adding the next value, while removing the last value
    for (var i = k; i < input.length; i++) {
        window_sum += input[i] - input[i - k];
        highestSpending = Math.max(highestSpending, window_sum);
    }
    return highestSpending;
}


// example: spendings = your total spending per day for a week
var spendings = [13, 70, 14, 18, 37, 33, 35];
var n = spendings.length;
var k = 3;
document.write("Highest Spending: $" + findHighestSpending(spendings, n, k));




