/**
 * Get maximum subarray sum using Kadane's Algorithm
 * 
 * inspired by: https://www.youtube.com/watch?v=86CQq3pKSUw
 * 
 * @example
 * maxSequence([-2, 1, -3, 3, -1, 2, 1, -5, 4])
 * 5
 * 
 * maxSequence([-1, -2])
 * 0 // returns 0 when array is empty or if all of the array is negative numbers
 * 
 * @param arr
 * @returns {Number} maximumSum
 */
const maxSequence = (arr = []) => {
  let currentMax = globalMax = 0
  
  for (let currentNumber of arr) {
    currentMax = Math.max(currentNumber, currentNumber + currentMax)
    
    globalMax = currentMax > globalMax ? currentMax : globalMax
  }
  
  return globalMax
}