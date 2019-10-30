const array = [2, 3, 5, 6, 1, 90, 6];

console.log(`Array disordered [${array}]`);

bubbleSort = (array) => {
    for (let i = 0; i < array.length - 1; i++) {
        for (let j = i + 1; j < array.length; j++) {
            if (array[i] > array[j]) {
                let tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }

        }
    }
}

bubbleSort(array)

console.log(`Array Sorted [${array}]`);
