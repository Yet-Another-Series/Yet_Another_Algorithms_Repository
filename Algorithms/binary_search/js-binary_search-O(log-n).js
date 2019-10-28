// Sorted array
const array = [1, 2, 3, 5, 7, 8, 9, 11, 14, 15, 16, 18];

// Random value
const value = Math.round(Math.random() * 20);

console.log(`Searching ${value} in array [${array}]`);

const binarySearch = (array, value, start, end) => {

  // Base condition
  if (start > end) {
    return -1;
  }

  // Find the middle value
  const middle = Math.floor((start + end) / 2);

  // Compare with number
  if (array[middle] === value) {
    return middle;
  }

  // If element at middle is greater than value, search in the firts half of array
  if (array[middle] > value) {
    console.log(`Search in sub-array [${array.slice(start, middle - 1)}]`);
    return binarySearch(array, value, start, middle - 1);
  }
  else {
    // If element at midddle is smaller than value, search in the right half of array
    console.log(`Search in sub-array [${array.slice(middle + 1, end)}]`);
    return binarySearch(array, value, middle + 1, end);
  }

}

const position = binarySearch(array, value, 0, array.length - 1);

if (position >= 0) {
  console.log(`${value} found at index ${position}`);
} else {
  console.log('Element not found');
}
