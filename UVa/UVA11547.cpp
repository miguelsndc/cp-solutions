#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// -----------

int main() {
    int tc;
    int x;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &x);
        int ans = abs(((((((x * 567) / 9) + 7492) * 235) / 47) - 498)) % 100;
        printf("%d\n", int(ans * 1.0 / 10));
    }
    return 0;
}