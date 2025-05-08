#include <iostream>
#include <string>

using namespace std;

string numberToWords(int n) {
    string ones[] = {"", "один", "два", "три", "чотири", "п’ять", "шість", "сім", "вісім", "дев’ять"};
    string teens[] = {"десять", "одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п’ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев’ятнадцять"};
    string tens[] = {"", "", "двадцять", "тридцять", "сорок", "п’ятдесят", "шістдесят", "сімдесят", "вісімдесят", "дев’яносто"};
    string hundreds[] = {"", "сто", "двісті", "триста", "чотириста", "п’ятсот", "шістсот", "сімсот", "вісімсот", "дев’ятсот"};

    if (n == 1000) return "тисяча";

    string result = "";
    int h = n / 100;
    int t = (n % 100) / 10;
    int o = n % 10;

    result += hundreds[h];

    if (t == 1) {
        result += (result.empty() ? "" : " ") + teens[o];
    } else {
        if (t > 1) result += (result.empty() ? "" : " ") + tens[t];
        if (o > 0) result += (result.empty() ? "" : " ") + ones[o];
    }

    return result;
}

int main() {
    int n;
    cout << "Введіть число від 1 до 1000: ";
    cin >> n;

    if (n < 1 || n > 1000) {
        cout << "Число поза межами діапазону." << endl;
    } else {
        cout << "Словами: " << numberToWords(n) << endl;
    }

    return 0;
}

