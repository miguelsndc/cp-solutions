#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void solve() {
    ll pw[6];
    pw[0] = 1;
    for (int i = 1; i <= 5; i++) pw[i] = pw[i - 1] * 10;

    int K; cin >> K;
    string  S, T; cin>> S >> T;
    vector<int> freq(10, K);
    freq[0] = 0;

    vector<int> Sv, Tv;
    for (int i = 0; i < 4; i++) Sv.push_back((int)(S[i] - '0')), freq[Sv[i]]--;
    for (int i = 0; i < 4; i++) Tv.push_back((int)(T[i] - '0')), freq[Tv[i]]--;

    ll s = accumulate(all(freq), 0);

    long double prob = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            Sv.push_back(i);
            Tv.push_back(j);

            ll score_s = 0, score_t = 0, total_freq[10] = {0}, cur_freq[10] = {0};
            bool ok = true;

            for (int x: Sv) {
                cur_freq[x]++;
                total_freq[x]++;
            }
            for (int x = 1; x <= 9; x++) score_s += x * pw[cur_freq[x]];
            memset(cur_freq, 0, sizeof cur_freq);
            for (int x: Tv) {
                cur_freq[x]++;
                total_freq[x]++;
            }
            for (int x = 1; x <= 9; x++) score_t += x * pw[cur_freq[x]];

            for (int x = 1; x <= 9; x++) {
                ok &= (total_freq[x] <= K);
            }

            Sv.pop_back();
            Tv.pop_back();

            if (!ok) continue;

            long double curprob = 1;
            if (score_s > score_t) {
                curprob *= (1.0*freq[i] / (s + 0.0));
                curprob *= (1.0*(freq[j] - (i == j)) / (s - 1 + 0.0));
                prob += curprob;
            }
        }
    }

    cout << fixed << setprecision(20) << prob << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}