const merge = (leftArray, rightArray) => {
  const result = [],
    leftArrayLength = leftArray.length,
    rightArrayLength = rightArray.length;

  let leftIterator = 0,
    rightIterator = 0;

  while (
    leftIterator < leftArrayLength &&
    rightIterator < rightArrayLength
    ) {
    const leftElement = leftArray[leftIterator];
    const rightElement = rightArray[rightIterator];
    if (leftElement < rightElement) {
      result.push(leftElement);
      leftIterator = leftIterator + 1;
    } else {
      result.push(rightElement);
      rightIterator = rightIterator + 1;
    }
  }
  return result
    .concat(leftArray.slice(leftIterator))
    .concat(rightArray.slice(rightIterator));
};

const mergeSort = array => {
  if (array.length < 2) {
    return array;
  }
  const mid = Math.floor(array.length / 2);
  const leftArray = array.slice(0, mid);
  const rightArray = array.slice(mid);
  return merge(mergeSort(leftArray), mergeSort(rightArray));
};

const testArray = [24, 5, 6, 222, 3, 766, 59];
console.log(mergeSort(testArray)); //output - [3, 5, 6, 24, 59, 222, 766]
