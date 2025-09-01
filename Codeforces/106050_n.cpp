#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N; cin >> N;
    int A = 0, B = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A += (x == 1);
        B += (x == 2);
    }
    if (A > B) {
        cout << "Cataratas do Pinhao";
    } else if (A < B) {
        cout << "Pinhao das Cataratas";
    } else {
        cout << "Cascatiba?";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}