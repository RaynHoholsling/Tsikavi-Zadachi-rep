#include <iostream>

using namespace std;

bool isPalindrome(int number) {
    int reversed = 0;
    int original = number;
    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number = number / 10;
    }
    return original == reversed;
}

int main() {
    for (int i = 1; i < 100; i++) {
        if (isPalindrome(i)) {
            int square = i * i;
            if (isPalindrome(square)) {
                cout << i << " -> " << square << endl;
            }
        }
    }
    return 0;
}

