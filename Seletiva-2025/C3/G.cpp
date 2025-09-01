#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

bool f(int n, int c, vector<int>& stalls, int amount) {
    int fitted = 1, prevloc = 1;
    for (int i = 1; i < n; i++) {
        if (stalls[i] - prevloc >= amount) {
            fitted++; prevloc = stalls[i];
        }
    }
    return fitted >= c;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n, c; cin >> n >> c;
        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }

        sort(begin(stalls), end(stalls));

        int l = 0, r = stalls[n - 1] - stalls[0];
        while(r - l > 1) {
            int mid = (l + r) / 2;
            if (f(n, c, stalls, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        cout << l << '\n';
    }
}