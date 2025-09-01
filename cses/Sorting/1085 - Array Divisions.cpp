#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

ll n, k;
int f(ll s, ll* A) {
    ll curr_seg_sum = 0;
    ll req_seg = 0;
    for (ll i = 0; i < n; i++) {
        if (A[i] > s) {
            return false;
        }
        if (A[i] + curr_seg_sum > s) {
            curr_seg_sum = 0;
            req_seg++;
        }
        curr_seg_sum += A[i];
    }
    req_seg++;
    return req_seg <= k;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    ll sum = 0;
    ll A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }

    ll l = 0, r = sum;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (f(mid, A)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r;

    return 0;
}