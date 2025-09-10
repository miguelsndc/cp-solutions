#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> grid[N][N];
    int freq[N][N][26];
    memset(freq, 0, sizeof freq);
    while(Q--) {
        int type; cin >> type;
        if (type == 0) {
            char letter;  cin >> letter;
            int x, y; cin >> x >> y;
            int v = (int)(letter - 'a');
            grid[x][y].push_back(v);
            freq[x][y][v]++;
        }
        if (type == 1){
            int x, y; cin >> x >> y;
            if (grid[x][y].size() > 0) {
                int top = grid[x][y].back();
                freq[x][y][top]--;
                grid[x][y].pop_back();
            }
        }
        if (type == 2) {
            char pivot; cin >> pivot; 
            int x, y; cin >> x >> y;
            int v = (int)(pivot - 'a');
            int v_freq = freq[x][y][v];
            int s = 0;
            for (int i = 0; i < 26; i++) s += freq[x][y][i];
            if (v_freq * 2 > s) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}