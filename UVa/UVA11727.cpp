#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// -----------

int main() {
    int tc, x;
    int s[3];
    scanf("%d", &tc);
    int case_no = 1;
    while (tc--) {
        scanf("%d %d %d", &s[0], &s[1], &s[2]);
        sort(s, s + 3);
        printf("Case %d: %d\n", case_no, s[1]);
        case_no++;
    }
    return 0;
}