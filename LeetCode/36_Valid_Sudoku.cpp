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

void print(unordered_set<char> const &s) {
    if(s.size()==0) cout << "empty";
    else copy(s.begin(), s.end(), ostream_iterator<char>(cout, " "));
    cout << endl;
}

//https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size=9;
        int bsize=3;
        char emp='.';
        int boxn=0;
        vector<unordered_set<char>> bs(bsize); //3x3
        for(int i=0;i<size;i++){
            unordered_set<char> rs(size);
            unordered_set<char> cs(size);
            for(int j=0;j<size;j++){
                //row
                char c=board[i][j];
                if(c!=emp){
                    if(rs.count(c)) return false;
                    else rs.insert(c);
                }
                // sub-box
                if(c!=emp){
                    int boxn=j/3;
                    if(bs[boxn].count(c)) return false;
                    else bs[boxn].insert(c);
                }
                if(j==size-1 && (i+1)%3==0){
                    for(int b=0;b<bsize;b++){
                        bs[b].clear();
                    }
                }
                //column
                char col=board[j][i];
                if(col!=emp){
                    if(cs.count(col)) return false;
                    else cs.insert(col);
                }
            }
        }
        return true;
    }
};

void solve() {
    // vector<vector<char>> b;
    // for(int i=0;i<9;i++){
    //     vector<char> r;
    //     for(int j=0;j<9;j++){
    //         char k;
    //         cin >> k;
    //         r.push_back(k);
    //     }
    //     b.push_back(r);
    // }

    // vector<vector<char>> b1 // true
    //     = { { '5','3','.','.','7','.','.','.','.' },
    //         { '6','.','.','1','9','5','.','.','.' },
    //         { '.','9','8','.','.','.','.','6','.' },
    //         { '8','.','.','.','6','.','.','.','3' },
    //         { '4','.','.','8','.','3','.','.','1' },
    //         { '7','.','.','.','2','.','.','.','6' },
    //         { '.','6','.','.','.','.','2','8','.' },
    //         { '.','.','.','4','1','9','.','.','5' },
    //         { '.','.','.','.','8','.','.','7','9' } };

    vector<vector<char>> b2 // false
        = { {'.','.','.','.','5','.','.','1','.'},
            {'.','4','.','3','.','.','.','.','.'},
            {'.','.','.','.','.','3','.','.','1'},
            {'8','.','.','.','.','.','.','2','.'},
            {'.','.','2','.','7','.','.','.','.'},
            {'.','1','5','.','.','.','.','.','.'},
            {'.','.','.','.','.','2','.','.','.'},
            {'.','2','.','9','.','.','.','.','.'},
            {'.','.','4','.','.','.','.','.','.'} };
    
    Solution s;
    cout << s.isValidSudoku(b2);
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
