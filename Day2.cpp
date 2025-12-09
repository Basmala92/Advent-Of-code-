#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define allr(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define ld long double
#define INF (int)(1e18)
#define MOD 1000000007
using namespace std;
vector<pair<int,int> > ranges;

void getranges(string s) {
    string p1 = "", p2 = "";
    int l = 0, r = 0;
    for (int i = 0; i < s.size(); i++) {
        while (i < s.size() && s[i] != '-') {
            p1 += s[i];
            i++;
        }
        l = stoll(p1);
        i++;
        while (i < s.size() && s[i] != ',') {
            p2 += s[i];
            i++;
        }
        r = stoll(p2);
        ranges.push_back({l, r});

        l = 0, r = 0;
        p1.clear();
        p2.clear();
    }
}

void Part1() {
    string s;
    cin >> s;
    getranges(s);
    int sum = 0;
    for (auto [l,r]: ranges) {
        for (int num = l; num <= r; num++) {
            string x = to_string(num);
            int n = x.size();
            if (x.substr(0, n / 2) == x.substr(n / 2))
                sum += num;
        }
    }
    cout << sum << "\n";
}

int getall(int l,int r) {
    int sum = 0;
    for (int i = l; i <= r; i++) {
        int num = i;

        string s = to_string(num);
        int n = s.size();

        for (int j = 0; j < n; j++) {
            string sub = s.substr(0, j + 1);

            int sz = sub.size();
            if (s.size() % sz != 0 || sz == s.size())continue;
            int k = j + 1;
            bool f = false;
            while (k < s.size()) {
                //  cout << sub << " " << s.substr(k, sz) << " ";
                if (s.substr(k, sz) != sub) {
                    f = true;
                    break;
                }
                k += sz;
            }

            if (!f) {
                //cout << num << "\n";
                sum += num;
                break;
            }
        }
    }
    return sum;
}


void Part2() {
    string s;
    cin >> s;
    getranges(s);
    int sum = 0;
    for (auto [l,r]: ranges) {
        int x = getall(l, r);
        sum += x;
    }
    cout << sum << "\n";
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
        // Part1();
        Part2();
    }
}
