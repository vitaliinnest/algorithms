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

class MinStack {
private:
    vector<int> m;
    vector<int> v;
public:
    MinStack() {
    }
    
    void push(int val) {
        v.push_back(val);
        if(m.empty()){
            m.push_back(val);
        }else{
            int mt=min(m.back(),val);
            m.push_back(mt);
        }
    }
    
    void pop() {
        v.pop_back();
        m.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return m.back();
    }
};

void solve() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-1);
    cout << "getMin " << minStack.getMin() << endl; // return -3
    minStack.pop();
    cout << "top " << minStack.top() << endl;    // return 0
    cout << "getMin " << minStack.getMin() << endl; // return -2
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
