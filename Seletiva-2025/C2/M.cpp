#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    int n; cin >> n;
    int h = sqrt(n);
    while (n % h) h--;
    cout << (h - 1) + (n / h - 1);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; 
    while(tt--) {
         solve();
    }
}