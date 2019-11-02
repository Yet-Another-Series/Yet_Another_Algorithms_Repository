// Iterative approach
const fibonacci = (n) => {
    let fib = [0, 1];
    for (let i = 2; i < n + 1; i++) {
      fib.push(fib[i - 2] + fib[i -1])
    }
   return fib[n];
}
