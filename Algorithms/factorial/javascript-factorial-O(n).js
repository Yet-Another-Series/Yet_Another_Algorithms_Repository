const factorial = input => {
    let result = 1
    for (let i=1; i<=input; i++) {
        result *= i
    }
    return result
}

console.log(factorial(6))
