#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    int start, n1, n2, n3, ans;
    while (scanf("%d %d %d %d", &start, &n1, &n2, &n3), start || n1 || n2 || n3) {
        ans = 1080;  // start rotation; ->
        ans += (start - n1) > 0 ? (start - n1) * 9 : (start - n1 + 40) * 9;
        ans += (n2 - n1) > 0 ? (n2 - n1) * 9 : (n2 - n1 + 40) * 9;
        ans += (n2 - n3) > 0 ? (n2 - n3) * 9 : (n2 - n3 + 40) * 9;
        printf("%d\n", ans);
    }
    return 0;
}