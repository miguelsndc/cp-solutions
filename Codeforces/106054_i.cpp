#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N, M; cin >> N >> M;
    vector<int> players(N + 1);
    while(M--) {
        int X, Y; cin >> X >> Y;
        // pega X / k se 1 e Y se 2
        // simular cada jogador a partir da escolha de ines
        vector<int> play(N);
        for (int &i: play) cin >> i;

        int cnt1 = count(play.begin(), play.end(), 1);
        int cnt2 = N - cnt1;
        if (X / (cnt1 + 1) >= Y) {
            int r = (X / (cnt1 + 1));
            players[N] += r;
            for (int j = 0; j < N; j++) {
                players[j] += (play[j] == 1 ? r : Y);
            } 
        } else {
            players[N] += Y;
            int r = cnt1 > 0 ? (X / cnt1) : 0;
            for (int j = 0; j < N; j++) {
                players[j] += (play[j] == 1 ? r : Y);
            } 
        }
    }

    for (int x: players) {
        cout << x << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}