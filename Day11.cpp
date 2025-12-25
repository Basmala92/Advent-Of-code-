#include <bits/stdc++.h>
#define int long long
#define allr(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define ld long double
#define INF (int)(1e18)
#define MOD 1000000007
using namespace std;
int cnt_pathpart1(string src, string dest, map<string, vector<string> > &adj) {
    if (src == dest) return 1;


    int ans = 0;
    for (auto v: adj[src]) {
        ans += cnt_pathpart1(v, dest, adj);
    }
    return ans;
}

map<pair<string, pair<bool, bool> >,int> memo;
int cnt_pathpart2(string src, bool f1, bool f2, map<string, vector<string> > &adj) {
    if (src == "fft")f1 = true;
    if (src == "dac")f2 = true;
    if (src == "out") {
        if (f1 & f2)return 1;
        return 0;
    }


    if (memo.count({src, {f1, f2}}))
        return memo[{src, {f1, f2}}];

    int ans = 0;

    if (adj.count(src)) {
        for (auto v: adj[src]) {
            ans += cnt_pathpart2(v, f1, f2, adj);
        }
    }
    return memo[{src, {f1, f2}}] = ans;
}

void solve() {
    string s;
    map<string, vector<string> > adj;

    while (getline(cin, s) && s != "?") {
        stringstream ss(s);
        string s1, s2;
        ss >> s1;
        s1.pop_back();
        while (ss >> s2) {
            adj[s1].push_back(s2);
        }
    }
    cout << cnt_pathpart1("you", "out", adj) << "\n";

    cout << cnt_pathpart2("svr", false, false, adj) << "\n";
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
        solve();
    }
}
