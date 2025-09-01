#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    ll sum = 0;
    vector<int> first(7, -1);
    int max_c = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum = (sum + x) % 7;
        if (first[sum] == -1) {
            first[sum] = i + 1;
        } else {
            max_c = max(max_c, i - first[sum] + 1);
        }
    }
    cout << max_c;
}