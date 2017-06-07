#include <iostream>

using namespace std;

int shift_left(int* input_array, int input_array_length, int* output_array, int shift_left){
  int output_array_length = input_array_length + shift_left;
  int output_array[output_array_length];
  for (int i = 0; i < input_array_length; i++) {
    output_array[i] = input_array[i];
  }
  for(int j = 0; j < shift_left; j++) {
    output_array[input_array_length + j] = 0;
  }
  return 0;

}
int addition(int* input_array1, int input_array1_length, int* input_array2, int input_array2_length, int* output_array) {
  int i = 0;
  int carry = 0;
  int output_array[input_array1_length+1];
  int first_digit, temp;
  while(i < input_array1) {
    temp = input_array1[i] + input_array2[i] + carry;
    if (temp > 9) {
      first_digit = temp % 10;
      carry = temp / 10;
    }
    else {
      first_digit = temp;
      carry = 0;
    }
    output_array[i] = first_digit;
    i++;
  }
  if(carry > 0) {
    output_array[i] = carry;
  }
  return 0;
}

int multiplication(int* input_array1, int input_array1_length, int* input_array2, int input_array2_length, int* output_array) {
  int carry = 0;
  int first_digit, temp_array[input_array1_length*2];
  for(int k = 0; k < input_array1_length*2; k++){
    output_array[k] = 0;
  }
  for(int i = 0; i < input_array1_length * 2; i++) {
    for(int j = 0; j < input_array1_length; j++) {
      int temp = (input_array1[i] * input_array2[j]) + carry;
      if (temp > 9) {
        first_digit = temp % 10;
        carry = temp / 10;
      }
      else {
        first_digit = temp;
        carry = 0;
      }
      temp_array[i] = first_digit;
    }
    if(carry > 0) {
      temp_array[i] = 0;
    }
    temp_array[i] += 0;
    output_array[i] += temp_array[i];
  }
  return 0;
}



// This function parses a number as a string, saves each digit
// in the num_array that is passed in, low-digits first, and
// returns the number of digits in that number.
// If we can't parse the number, returns -1.
// Example: If num_as_string = "1234",
//          then num_array[] = {4, 3, 2, 1} and
//          the return value is 4.
int readNumberAsArrayFromString(const string& num_as_string,
                                int* num_array) {
  for (int i = 0; i < num_as_string.length(); ++i) {
    if (num_as_string[i] >= '0' &&
        num_as_string[i] <= '9') {
      num_array[i] = static_cast<int>(num_as_string[i] - '0');
    } else {
      return -1;
    }
  }
  return num_as_string.length();
}

// Takes a number represented as an array with its digits,
// low to heigh, as well as its length (i.e. number of digits)
// and return a string representation of that number.
string numberAsArrayToString(int* num_array, int length) {
  if (length <= 0 ) {
    return "NaN";
  }
  string num_string;
  for (int i = 0; i < length; ++i) {
    num_string += static_cast<char>(num_array[i] + '0');
  }
  return num_string;
}

int main() {
  int first_number[10000];
  int second_number[10000];
  int first_number_length, second_number_length;
  cout << "Let's multiply two numbers." << endl;
  {
    cout << "Please enter the first number: ";
    string first_number_as_string;
    cin >> first_number_as_string;
    first_number_length = readNumberAsArrayFromString(
        first_number_as_string,
        first_number);
  }
  {
    cout << "Please enter the second number: ";
    string second_number_as_string;
    cin >> second_number_as_string;
    second_number_length = readNumberAsArrayFromString(
        second_number_as_string,
        second_number);
  }

  cout << "First number is : " << numberAsArrayToString(first_number, first_number_length) << endl;
  cout << "Second number is : " << numberAsArrayToString(second_number, second_number_length) << endl;

  int result[20000];
  int result_length =
      multiplyLargeNumbers(first_number, first_number_length,
                           second_number, second_number_length,
                           result);

  cout << "Result: " << numberAsArrayToString(result, result_length) << endl;
  return 0;
}