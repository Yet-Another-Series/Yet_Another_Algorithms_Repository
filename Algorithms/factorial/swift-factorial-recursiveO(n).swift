
import Foundation



func recursiveFactorial(number: Int) -> Int {

  if number==0
  {
    return 1
  }
  else
  {
    return recursiveFactorial(number: number-1)*number
  }
    
}

print("Factorial: \n")
let n = readLine()

let result = recursiveFactorial(number: n)


print(result)

