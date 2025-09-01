#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void solve(int n) {
    map<array<int, 5>, int> mp;

    int mx = 0;
    for (int i = 0; i < n; i++) {
        array<int, 5> a;
        for (int i = 0; i < 5; i++) cin >> a[i];
        sort(begin(a), end(a));
        mp[a]++;
        mx = max(mx, mp[a]);
    }

    int count = 0;
    for (const auto &[a, v]: mp) {
        if (v == mx) count += v;
    }

    cout << count << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while((cin >> tt) && tt != 0) {
         solve(tt);
    }
}