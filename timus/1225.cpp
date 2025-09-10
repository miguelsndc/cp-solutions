#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    ll fib2[50];
    fib2[0] = 0;
    fib2[1] = 2; 
    for (int i = 2; i < 50; i++) fib2[i] = fib2[i - 1] + fib2[i - 2];
    int n; cin >> n;
    cout << fib2[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}