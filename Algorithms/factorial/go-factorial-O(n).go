package main

import "fmt"

func factorial(n int) {

	number := 1
	for i := 1; i <= n; i++ {
		number = number * i

	}

	fmt.Println(number)

}

func main() {
	factorial(5)
}
