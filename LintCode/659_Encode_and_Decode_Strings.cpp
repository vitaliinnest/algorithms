#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

class Solution {
public:
    const char ds='#';
    const char de='@';
    string encode(vector<string> &strs) {
        string e="";
        for(string s:strs)
            // example #4@word
            e += ds + to_string(s.size()) + de + s;
        return e;
    }

    vector<string> decode(string &str) {
        vector<string> r;
        int i=0;
        while(i<str.size()){
            int j=i;
            if(str[i]!=ds){
                i++;
                continue;
            }
            while(str[j]!=de){
                j++;
            }
            int len = stoi(str.substr(i+1, j-i-1));
            string w = str.substr(j+1, len);
            r.push_back(w);
            i=j+1+len;
        }
        return r;
    }
};

void solve() {
    string str;
    vector<string> strs;
    while(cin >> str) strs.pb(str);
    Solution s;
    string e=s.encode(strs);
    vector<string> d=s.decode(e);
    cout << e << endl;
    for (string sr:d) cout << sr << " ";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
