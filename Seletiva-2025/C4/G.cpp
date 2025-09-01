#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(k), psum(k + 1), ssum(k + 1);
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) {
        psum[i] = psum[i - 1];
        if (i % 2 == 0) {
            psum[i] += a[i - 1] - a[i - 2];
        }
    }
    
    for (int i = k - 1; i >= 0; i--) {
        ssum[i] = ssum[i + 1];
        if ((k - i) % 2 == 0) {
            ssum[i] += a[i + 1] - a[i];
        }
    }

    int t = INT32_MAX;
    for (int i = 0; i < k + 1; i+= 2) {
        t = min(t, psum[i] + ssum[i]);
    }
    cout << t;
}