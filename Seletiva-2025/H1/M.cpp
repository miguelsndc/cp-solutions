#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n, m, L; cin >> n >> m >> L;
        vector<array<int, 3>> hurdles(n);
        vector<array<int, 3>> power_ups(m);

        for (int i = 0; i < n; i++) {
            cin >> hurdles[i][0] >> hurdles[i][1];
            hurdles[i][2] = 0;
        }
        
        for (int i = 0; i < m; i++) {
            cin >> power_ups[i][0] >> power_ups[i][1];
            power_ups[i][2] = 1;
        }

        vector<array<int, 3>> kojima(n + m);

        auto comp = [](const array<int,3> &a, const array<int,3>&b) {
            return a[0] < b[0];
        };

        merge(hurdles.begin(), hurdles.end(), power_ups.begin(), power_ups.end(), kojima.begin(), comp);

        priority_queue<int> feijao;
        int power = 1, used = 0, fail = 0;
        for (auto [a, b, type]: kojima) {
            if (type == 1) {
                feijao.push(b);
            } else {
                int pos = a - 1;
                int power_need = b - pos + 1;
                if (power < power_need) {
                    while(!feijao.empty() && power < power_need) {
                        power += feijao.top();
                        used++;
                        feijao.pop();
                    }

                    if (power < power_need) {
                        fail = true;
                        break;
                    }
                }
            }
        }

        cout << (fail ? -1 : used) << '\n';
    }
}