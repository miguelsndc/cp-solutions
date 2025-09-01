#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    // const int mxn = 9e8;
    // vector<int> v;
    // for (int i = 1; i <= mxn; i++) {
    //     int k = i;
    //     while(k % 2 == 0) k /= 2;  
    //     while(k % 3 == 0) k /= 3;  
    //     while(k % 5 == 0) k /= 5;  
    //     if (k == 1) {
    //         v.push_back(i);
    //     }
    // }
    // cout << v[1499] << '\n';
    int ans = 859963392;
    printf("The 1500'th ugly number is %d.\n", ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}