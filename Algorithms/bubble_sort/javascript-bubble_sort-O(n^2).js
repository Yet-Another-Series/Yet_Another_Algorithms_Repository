const bubbleSort = (numbers) => {
    let i, j
    const count = numbers.length

    for(i = 0; i < count-1; i++) {

        for(j = 0; j < count-i-1; j++) {
            if(numbers[j] > numbers[j+1]) swap(numbers[j], numbers[j+1], numbers, j) 
        }

    }
    
    return numbers
}

const swap = (current, last, numbers, index) => {
    numbers[index] = last
    numbers[index + 1] = current
}

console.log(
    bubbleSort([4,1,6,3,9,2])
)
