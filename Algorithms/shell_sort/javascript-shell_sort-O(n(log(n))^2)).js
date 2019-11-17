const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout
});

const shellSort = arr => {
  if (arr.length < 2) return arr;

  let gap = parseInt(arr.length / 2);
  while (gap >= 1) {
    for (let i = gap; i < arr.length; i++) {
      let j = i;
      let temp = arr[i];

      while (j >= gap && arr[j - gap] > temp) {
        arr[j] = arr[j - gap];
        j -= gap;
      }
      arr[j] = temp;
    }
    gap = parseInt(gap / 2);
  }
  return arr;
};

readline.question(`Enter comma separated array of numbers:`, input => {
  arr = JSON.parse(input);
  console.log(shellSort(arr));
  readline.close();
});
