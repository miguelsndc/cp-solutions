#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;
    vector<int> a{a1,a2,a3,a4};
    sort(all(a));
    int area = a[0] * a[2];
    cout << area << '\n';
}