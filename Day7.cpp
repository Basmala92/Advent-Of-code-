#include <bits/stdc++.h>
#define int long long
#define allr(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define ld long double
#define INF (int)(1e18)
#define MOD 1000000007
using namespace std;
vector<string> v;

void Part1() {
    string s;

    while (cin >> s && s != "*") {
        v.push_back(s);
    }
    int n = v.size(), m = v[0].size();
    int cnt = 0;
    vector<bool> split(n + 1, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'S') {
                split[j] = true;
                if (v[i + 1][j] != '^')
                    v[i + 1][j] = '|';
            } else {
                if (v[i][j] == '^' && split[j] == true) {
                    split[j] = false;
                    if (j + 1 < m) {
                        split[j + 1] = true;
                        v[i][j + 1] = '|';
                    }
                    if (j - 1 >= 0) {
                        split[j - 1] = true;
                        v[i][j - 1] = '|';
                    }
                    cnt++;
                }
            }
        }
    }

    cout << cnt << "\n";
}


void Part2() {
    int n = v.size(), m = v[0].size();
    vector<vector<int> > memo(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < m; i++) {
        if (v[0][i] == 'S') {
            memo[0][i] = 1;
            break;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] != '^') {
                memo[i + 1][j] += memo[i][j];
            } else {
                if (j - 1 >= 0) {
                    memo[i + 1][j - 1] += memo[i][j];
                }
                if (j + 1 < m) {
                    memo[i + 1][j + 1] += memo[i][j];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans += memo[n - 1][i];
    }
    cout << ans << "\n";
    v.clear();
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("promote.in","r",stdin);
    // freopen("promote.out","w",stdout);


    int tests = 1;
    //  cin >> tests;
    while (tests--) {
        Part1();
        Part2();
    }
}
