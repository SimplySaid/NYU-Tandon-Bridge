#include <iostream>
#include <cmath>
using namespace std;


int func(long long int n);

int main() {
    long long int n = 9000000000001LL;

    cout << func(n); //Returns 31
    cout << "\n";
    cout << log(n);

    return 0;
}

int func(long long int n) {
    long long int i, j, count;
    count = 0;
    for (i = 1; i <= log(n); i *= 2)
        for (j = 1; j <= i; j++)
            count += 1;
    return count;
}