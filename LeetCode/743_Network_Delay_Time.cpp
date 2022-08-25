/*Author: vitaliiiiin*/
/*Vitalii Nesterenko*/

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

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return 0;
    }
};

void solve() {
	
}

int main() {
	fastio();
	solve();
	return 0;
}
