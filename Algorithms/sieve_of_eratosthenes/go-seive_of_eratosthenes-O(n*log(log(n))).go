package main

import "fmt"

func SieveOfEratosthenes(n int) {
	prime := make([]bool, n+1)

	for i := 2; i*i < n; i++ {
		if prime[i] == true {
			continue
		}
		for j := i * i; j < n; j += i {
			prime[j] = true
		}
	}

	for i := 2; i < n; i++ {
		if prime[i] == false {
			fmt.Printf("%d ", i)
		}
	}
	fmt.Print("\n")

}

func main() {
	SieveOfEratosthenes(200)
}
