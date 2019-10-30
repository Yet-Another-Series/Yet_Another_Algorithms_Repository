package main

import "fmt"

func Fibonacci(n int) {
	fibo := make([]int, n)
	fibo[0] = 1
	fibo[1] = 1

	for i := 2; i < n; i++ {
		fibo[i] = fibo[i-2] + fibo[i-1]

	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d ", fibo[i])
	}
	fmt.Print("\n")

}

func main() {
	Fibonacci(10)
}
