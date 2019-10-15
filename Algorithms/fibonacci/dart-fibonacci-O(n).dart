import 'dart:io';

int fibonacci(int number, Map<int, int> calculated) {
  if (number > 1) {
    if (calculated[number - 2] == null) {
      calculated[number - 2] = fibonacci(number - 2, calculated);
    }
    if (calculated[number - 1] == null) {
      calculated[number - 1] = fibonacci(number - 1, calculated);
    }
    return calculated[number - 2] + calculated[number - 1];
  } else {
    return number;
  }
}

void main() {
  print("Enter a number");
  var line = stdin.readLineSync();
  var input = int.tryParse(line.toString());

  if (input != null) {
    print("Output");
    print(fibonacci(input, {}));
  } else {
    print("Invalid input");
  }
}
