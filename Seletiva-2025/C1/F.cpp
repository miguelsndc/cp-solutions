#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) (a.begin(), a.end())
#define pii pair<int, int>
#define vi vector<int>

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k; cin >> n >> k;
    vi s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    ll r = 0, sum = 0, count = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && sum < k) {
            sum += s[r++];
        }
        if (sum >= k) count += n - r + 1;
        sum -= s[l];
    }
    cout << count;
}