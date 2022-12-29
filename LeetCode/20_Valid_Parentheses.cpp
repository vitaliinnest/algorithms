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
    map<char,char> om = {
        {'{','}'},
        {'[',']'},
        {'(',')'}
    };

    map<char,char> cm = {
        {'}','{'},
        {']','['},
        {')','('}
    };

    bool isValid(string s) {
        if(s.size()%2==1) return false;
        stack<char> st;
        for(char p:s){
            if(om.count(p)){
                st.push(p);
            }else{
                if(st.empty()) return false;
                if(st.top()!=cm[p]){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

void solve() {
    string str="{[]}";
    // cin >> str;
    Solution s;
    cout << s.isValid(str);
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
