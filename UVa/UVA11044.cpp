#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    int tc, w, h;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &w, &h);
        printf("%d\n", ((w / 3) * (h / 3)));
    }
    return 0;
}