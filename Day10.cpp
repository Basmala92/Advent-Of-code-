#include <bits/stdc++.h>
#define int long long
#define allr(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define ld long double
#define INF (int)(1e18)
#define MOD 1000000007
using namespace std;

int bitmask(vector<vector<int> > &sets, string &x) {
    bitset<10> num;
    vector<int> button;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == '#') {
            num[i] = 1;
        } else {
            num[i] = 0;
        }
    }
    int tar = num.to_ulong();
    for (int i = 0; i < sets.size(); i++) {
        bitset<10> num2 = 0;
        for (int j = 0; j < sets[i].size(); j++) {
            num2[sets[i][j]] = 1;
        }
        button.push_back(num2.to_ulong());
    }
    int sz = button.size();

    int ans = INF;
    for (int i = 0; i < (1 << sz); i++) {
        int mask = 0, cnt = 0;
        for (int j = 0; j < sz; j++) {
            if (i & (1 << j)) {
                mask ^= button[j];
                cnt++;
            }
        }
        if (mask == tar) {
            if (cnt < ans) {
                ans = cnt;
            }
        }
    }
    return ans;
}


void Part1() {
    string s;
    int ans = 0;
    while (getline(cin, s) && s != "*") {
        vector<int> tar;

        vector<vector<int> > sets;
        string x = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#' || s[i] == '.') {
                x += s[i];
            }
            if (s[i] == '{') {
                i++;
                while (i < s.size() && s[i] != '}') {
                    if (s[i] >= '0' && s[i] <= '9') {
                        string c = "";
                        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                            c += s[i];
                            i++;
                        }
                        if (!c.empty()) {
                            int cc = stoi(c);
                            tar.push_back(cc);
                        }
                    }
                    i++;
                }
            }
            if (s[i] == '(') {
                vector<int> v;
                i++;
                while (i < s.size() && s[i] != ')') {
                    if (s[i] >= '0' && s[i] <= '9') {
                        int num = s[i] - '0';
                        v.push_back(num);
                    }
                    i++;
                }
                sets.push_back(v);
            }
        }
        ans += bitmask(sets, x);
    }
    cout << ans << "\n";
}

void Part2() {
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
        //Part2();
    }
}
