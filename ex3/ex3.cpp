#include <iostream>

using namespace std;

int main() {
    const int N = 1000;
    bool isPrime[1001];

    for (int i = 2; i <= N; i++) {
        isPrime[i] = true;
    }

    for (int current = 2; current * current <= N; current++) {
        if (isPrime[current]) {
            for (int multiple = current * 2; multiple <= N; multiple += current) {
                isPrime[multiple] = false;
            }
        }
    }

    cout << "Prime numbers from 2 to " << N << ":\n";
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}

