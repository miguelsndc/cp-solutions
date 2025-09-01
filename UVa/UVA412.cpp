#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void solve(int n) {
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    int top = 0;
    int bottom = n * (n - 1) >> 1; // n choose 2
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gcd(numbers[i], numbers[j]) == 1)
                top++;
        }
    }

    if (top == 0) {
        cout << "No estimate for this data set." << '\n';
    } else {
        cout << fixed << setprecision(6) << sqrt(1.0 * 6 * bottom / top) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n && n)
        solve(n);

    return 0;
}