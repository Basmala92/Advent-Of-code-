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


void Part1() {
    int num = 50, cnt = 0;
    string s;
    while (cin >> s && s != "?") {
        if (s[0] == 'R') {
            string x = s.substr(1);
            int rot = 0;
            if (!x.empty())
                rot = stoll(x);
            num += rot;
            num %= 100;
            if (num == 0)cnt++;
        } else if (s[0] == 'L') {
            string x = s.substr(1);
            int rot = 0;
            if (!x.empty())
                rot = stoll(x);

            num -= rot;
            num %= 100;
            num += 100;
            num %= 100;

            if (num == 0)cnt++;
        }
    }
    // ? at the condition to break the loop add it to input
    cout << cnt << endl;
}

void Part2() {
    int num = 50, cnt = 0;
    string s;
    while (cin >> s && s != "?") {
        if (s[0] == 'R') {
            string x = s.substr(1);
            int rot = 0;
            if (!x.empty())
                rot = stoll(x);
            while (rot--) {
                num++;
                if (num > 99) {
                    num %= 100;
                }
                if (num == 0)cnt++;
            }
        } else if (s[0] == 'L') {
            string x = s.substr(1);
            int rot = 0;
            if (!x.empty())
                rot = stoll(x);
            while (rot--) {
                num--;
                if (num < 0) {
                    num += 100;
                    num %= 100;
                }
                if (num == 0)cnt++;
            }
        }
    }

    cout << cnt << endl;
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
        //Part2();
    }
}
