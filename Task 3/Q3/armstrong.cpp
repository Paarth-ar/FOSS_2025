#include <iostream>
#include <cmath> 
#include <limits> 

using namespace std;
bool isArmstrong(long long num) {
    if (num < 0) return false; 

    long long originalNum = num;
    int digits = 0;
    long long temp = num;
    while (temp != 0) {
        temp /= 10;
        digits++;
    }

    long long sum = 0;
    temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum += static_cast<long long>(pow(digit, digits));
        temp /= 10;
    }

    return sum == originalNum;
}

int main() {
    long long number;

    cout << "Enter a non-negative integer: ";
    while (!(cin >> number) || number < 0) {
        cout << "Invalid input. Please enter a non-negative integer: ";
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    if (isArmstrong(number))
        cout << number << " is an Armstrong number.\n";
    else
        cout << number << " is NOT an Armstrong number.\n";

    return 0;
}
