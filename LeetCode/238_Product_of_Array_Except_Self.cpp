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

// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> r(nums.size());
        // prefix
        r[0]=1;
        for(int i=1;i<nums.size();i++){
            r[i]=r[i-1]*nums[i-1];
        }
        // postfix
        int p=1;
        for(int i=r.size()-2;i>=0;i--){
            p*=nums[i+1];
            r[i]=r[i]*p;
        }
        return r;
    }
};

void solve() {
    int n;
    vi nums;
    while (cin >> n) nums.pb(n);
    Solution s;
    vi res = s.productExceptSelf(nums);
    for(auto i:res) cout << i << " ";
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
