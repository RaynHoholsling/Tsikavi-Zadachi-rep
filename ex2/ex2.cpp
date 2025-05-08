#include <iostream>


int main() {
    bool resheto[1001];

    for (int i = 0; i <= 1000; i++)
    {
        resheto[i] = true;
    }

    for (int p = 2; p * p <= 1000; p++)
    {
        if (resheto[p]) {
            for (int i = p * p; i <= 1000; i += p)
            {
                resheto[i] = false;
            }
        }
    }

    for (int i = 2; i <= 1000; i++)
    {
        if (resheto[i])
        {
            std::cout << " " << i ;
        }
    }
    return 0;
}
