#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    int cnt = 0;
    while(a != c or b != d) {
        if (b < n) b++;
        else {
            a++; b= 0;
        }
        cnt++;
    }
    cout << cnt << '\n';
}