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

// https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        if(n==0)return 0;
        int l=0,r=n-1;
        int ml=h[l],mr=h[r];
        int ans=0;
        while(l<r){
            if(ml<=mr){
                l++;
                ml=max(ml, h[l]);
                ans += ml-h[l];
            }else {
                r--;
                mr=max(mr, h[r]);
                ans += mr-h[r];
            }
        }
        return ans;
    }
};

void solve() {
    vi h={0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(h);
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
