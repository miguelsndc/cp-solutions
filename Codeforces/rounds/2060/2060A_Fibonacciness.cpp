#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    vector<int> v = {a1, a2, -1, a4, a5};

    int maxfib = 0; 
    for (int i = -100000; i < 100000; i++) {
        v[2] = i;

        int fib = 0;
        for (int i = 2; i < 5; i++) {
            if (v[i] == v[i - 1] + v[i - 2]) {
                fib++;
            }
        }
        maxfib = max(maxfib, fib);
    }

    cout << maxfib << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}