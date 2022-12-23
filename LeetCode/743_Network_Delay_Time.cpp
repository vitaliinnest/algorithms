#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

#define fastio() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)

#define vt vector
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define nl "\n"
#define all(x) (x).begin(), (x).end() 
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

typedef long long 			ll;
typedef long double 		ld;
typedef pair<int,int> 		pi;
typedef pair<ll,ll> 		pll;
typedef pair<double,double> pd;
typedef pair<ld,ld> 		pld;
typedef vt<int> 			vi;
typedef vt<ll> 				vl;
typedef vt<bool> 			vb;
typedef vt<vi> 				vvi;
typedef vt<vl> 				vvl;
typedef vt<string> 			vs;
typedef vt<vs> 				vvs;
typedef vt<pi> 				vpi;
typedef vt<pll> 			vpll;
typedef map<int,int>		mi;
typedef map<ll,ll>			mll;

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(array<A,S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(ld& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}

string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b ? "true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
		res+=char('0'+v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
  string res;
	FOR(S)
		res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}

template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}

// https://leetcode.com/problems/network-delay-time/
class Solution {
private:
	// set<int>
	priority_queue<int,vi,greater<int> > pq;
	map<int,vt<pi>> buildAdjacencyList(const vvi& times) {
		map<int,vt<pi>> adjList;
		for (auto edge : times) {
			// [u] = [(v,w)]
			adjList[edge[0]].pb(mp(edge[1], edge[2]));
		}
		return adjList;
	}
	void djikstra(const map<int,vpi>& adjList) {
		pq.push(2);
		pq.push(3);
		cout << pq.top() << " ";
	}
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    	map<int,vpi> adjList = buildAdjacencyList(times);
    	return 0;
    }
};

void solve() {
	int v, n, k;
	// v - vertices
	// n - edges
	// k - starting vertex
	cin >> v;
	//times[i] = vector(3) (u,v,w)
	vvi times(v);
	for (int i = 0; i < v; ++i) {
		vi path(3);
		for (int j = 0; j < 3; ++j) {
			cin >> path[j];
		}
		times.pb(path);
	}
	cin >> n >> k;
	Solution sol;
	cout << sol.networkDelayTime(times, n, k);
}

int main() {
	fastio();
	solve();
	return 0;
}
