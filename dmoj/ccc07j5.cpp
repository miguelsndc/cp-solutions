#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    /*
    
        tenho n paradas
        ele pode andar entre A e B km por dia
        quantas formas tem de chegar se ele obrigatoriamente tme q ficar em uma das N paradas

        a cada dia tenho q saber o hotel onde estou e pra onde posso ir

        de N + A até N + B adiciono 1 a partir de N
    */

    int A, B; cin >> A >> B;
    int N; cin >> N;
    vector<int> locations = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        locations.push_back(x);
    }
    int M = locations.size();
    sort(all(locations));
    vector<ll> dp(M);
    dp[0] = 1;
    for (int i = 1; i < M; i++) {
        for (int j = 0; j < i; j++) {
            int dist = abs(locations[j] - locations[i]);
            if (dist >= A and dist <= B) {
                dp[i] += dp[j];
            }
        }
    }
    cout << dp[M - 1] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}