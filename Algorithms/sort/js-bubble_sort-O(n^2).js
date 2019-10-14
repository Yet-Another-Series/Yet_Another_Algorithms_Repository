const bubbleSort = (array) => {
    let tempArray = array;
    let temp;
    let canSwap = true;

    while (canSwap) {
        canSwap = false;
        for (let i = 0; i < tempArray.length; i++) {
            if (tempArray[i] > tempArray[i + 1]) {
                temp = tempArray[i];
                tempArray[i] = tempArray[i + 1]
                tempArray[i + 1] = temp;
                canSwap = true;
            }
        }
    }
    return tempArray;
}

module.exports = bubbleSort;