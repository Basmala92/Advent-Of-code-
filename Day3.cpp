#include <bits/stdc++.h>
#define int long long
#define allr(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define ld long double
#define INF (int)(1e18)
#define MOD 1000000007
using namespace std;
int getMaxInd(string s) {
    char mx = '0';
    int ind = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] > mx) {
            mx = s[i];
            ind = i;
        }
    }
    return ind;
}

void Part1() {
    string s;
    int ans = 0;
    while (cin >> s && s != "?") {
        int ind = getMaxInd(s), sind = ind + 1;
        string x = "";
        x += s[ind];
        char mx = '0';

        for (int i = ind + 1; i < s.size(); i++) {
            if (s[i] > mx) {
                mx = s[i];
                sind = i;
            }
        }
        x += s[sind];
        ans += stoll(x);
    }
    cout << ans << endl;
}

void Part2() {
    int ans = 0;
    string s;
    while (cin >> s && s != "?") {
        int n = s.size();
        int nextind = -1;
        string x = "";
        for (int i = 0; i < 12; i++) {
            char mx = '0';
            int ind = 0;
            int rem = 11 - i;
            int l = n - rem;
            for (int j = nextind + 1; j < l; j++) {
                if (s[j] > mx) {
                    mx = s[j];
                    ind = j;
                }
            }
            x += s[ind];
            nextind = ind;
        }
        ans += stoll(x);
    }
    cout << ans << "\n";
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
        //Part1();
        // Part2();
    }
}
