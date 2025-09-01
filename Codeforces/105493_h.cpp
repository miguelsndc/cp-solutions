#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n), b(m);
    for (int &x : a) {
        cin >> x;
        x -= d;
    }
    for (int &x : b) cin >> x;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int arrive_a = a[0];
    int arrive_b = a[0] + d;
    char at = 'B';
    int bus = 0;
    int time = -1e9;
    while (1) {
        if (at == 'A') {
            while (a.size() > 1 and a.back() <= time) a.pop_back();
            if (a.size() == 1 or a.back() + d >= arrive_a) {
                cout << 'A' << ' ' << bus << '\n';
                return 0;
            }
            time = a.back() + d;
            a.pop_back();
            bus++;
            at = 'B';
        }
        else {
            while (b.size() > 0 and b.back() <= time) b.pop_back();
            if (b.size() == 0 or b.back() + d >= arrive_a) {
                cout << "B" << ' ' <<  bus << '\n';
                return 0;
            } 
            time = b.back() + d;
            b.pop_back();
            bus++; at = 'A';
        }
    }
}