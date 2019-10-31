import Foundation

print("Factorial: \n")

let n = readLine()

var result = 1


for number in 1...n{

    result *= number
}

print(result)
