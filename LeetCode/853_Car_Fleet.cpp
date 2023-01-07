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

// https://leetcode.com/problems/car-fleet/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> p(position.size());
        for(int i=0;i<position.size();i++){
            p[i]=make_pair(position[i],speed[i]);
        }
        sort(p.begin(),p.end(),[](pair<int,int> &left, pair<int,int> &right){
            return left.first > right.first;
        });
        stack<float> s; // stack of unit of times it takes to arrive
        for(int i=0;i<p.size();i++){
            float t=(target - p[i].first) / (float)p[i].second;
            if(s.empty() || s.top() < t){
                s.push(t);
            }
        }
        return s.size();
    }
};

void solve() {
    int tg = 12;
    vi pos = { 10,8,0,5,3 };
    vi sp =  { 2,4,1,1,3 };
    Solution s;
    cout << s.carFleet(tg, pos, sp);
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
