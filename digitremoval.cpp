#include <cmath>
#include <iostream>

using namespace std;

int check(int n, int d) {
    int c = 0, place_vl = 0;
    int temp = n, temp1 = n;
    while (temp > 0) {
        c++;
        if (temp % 10 == d) {
            place_vl = c;
        }
        temp /= 10;
    }
    if (place_vl == 0) {
        return 0;
    }
    int newn = 0, tens = 1;
    tens = int(pow(10, place_vl - 1));
    newn = temp1 - (temp1 / tens) * tens;

    int p = place_vl;
    if (d == 0) {
        tens = 0;

        while (p--) {
            tens = tens * 10 + 1;
        }
    }

    int t = tens - newn;

    if (d == 9 && place_vl != 0) {
        return t + check(n + t, d);
    } else {
        return t;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        cout << check(n, d)<<endl;
    }
    return 0;
}
