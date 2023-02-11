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

// https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> c(26);
        int n=s.size();
        int i=0,j=0;
        int maxc=0;
        int res=0;
        while(j<n){
            c[s[j]-'A']++;
            maxc=max(maxc,c[s[j]-'A']);
            if((j-i+1)-maxc>k){
                c[s[i]-'A']--;
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};

void solve() {
    string s;
    int k;
    cin >> s >> k;
    Solution sln;
    cout << sln.characterReplacement(s, k);
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
