const bubbleSort = (array) => {
    let temp;
    let canSwap = true;

    while (canSwap) {
        canSwap = false;
        for (let i = 0; i < array.length; i++) {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1]
                array[i + 1] = temp;
                canSwap = true;
            }
        }
    }
    return array;
}

module.exports = bubbleSort;