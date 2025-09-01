#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll d; cin >> d;
    ll sum_d = 0;
    ll x = d;
    while(x) {
        sum_d += x % 10;
        x /= 10;
    }
    for (int i = 0; i < sum_d * d; i++) {
        cout << d;
    }
}