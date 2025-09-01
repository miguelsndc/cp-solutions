#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr i64 inf = 1E18;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    vector<int> v(100);
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int x; cin >> x;
            v.push_back(x);
        } else {
            cout << v.back() << '\n';
            v.pop_back();
        }
    }
}