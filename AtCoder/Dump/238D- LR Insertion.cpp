#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vi A = {0};
    int n;
    string S;
    cin >> n;
    cin >> S;
    deque<int> dq = {n};
    for (int i = n - 1; i >= 0; i--) {
        if (S[i] == 'L') {
            dq.push_back(i);
        } else {
            dq.push_front(i);
        }
    }
    for (const auto it : dq) {
        cout << it << " ";
    }
    return 0;
}