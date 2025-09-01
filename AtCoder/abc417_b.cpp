#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N), B(M);
    for (int &i: A) cin >> i;
    for (int &i: B) cin >> i;
    for (int x: B) {
        
        int i = 0, found = false;
        for (;i < A.size(); i++) {
            if (A[i] == x) {
                found = true;
                break;
            }
        }
        if (found)
            A.erase(A.begin() + i);
    }

    for (int x: A) cout << x << ' ';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}