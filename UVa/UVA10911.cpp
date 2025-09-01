#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cc = 1;
    while (n != 0) {
        vii students(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            string na;
            int x, y;
            cin >> na >> x >> y;
            students[i] = make_pair(x, y);
        }
        double sum = 0;
        for (int i = 0; i < 2 * n - 1; i++) {
            double minn = INFINITY;
            for (int j = i + 1; j < 2 * n; j++) {
                int xs = (students[i].first - students[j].first) * (students[i].first - students[j].first);
                int ys = (students[i].second - students[j].second) * (students[i].second - students[j].second);
                minn = min(minn, sqrt(xs + ys));
            }
            sum += minn;
            minn = INFINITY;
        }
        cout << "Case " << cc << ": " << setprecision(2) << sum << '\n';
        cin >> n;
    }

    return 0;
}