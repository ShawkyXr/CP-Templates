/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Shawky_XR <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define nl "\n"
#define cin(vec) for(auto& i : vec) cin >> i
#define cin_2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
#define cout_2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
#define sz(x) int(x.size())
#define fix_mod(a,b)  ((a % b + b) % b)
#define add_mod(a, b, m) (((a   % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define fori(i, n) for (int i = 0; i < n; i++)
#define forll(i,n) for (ll i = 0; i < n; i++)
#define forab(i, a, b) for (int i = a; i <= b; i++)
#define fixed(n) cout << fixed << setprecision(n)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define mod 1000000007
#define Pi 3.141592653589793
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
const ll oo = 0x3f3f3f3f3f3f3f3f;
constexpr int Mod =  1e9 + 7;


void IO(){
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
//    #endif
   ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Sec; " << nl;
}

// Merge Sort Tree
template <typename T, bool base> struct Merge_Sort_Tree{

private:

    int size;
    vector<vector<T>> tree;


    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int mid(int l, int r) { return l + (r-l) / 2; }


    void build(int n,vector < T > &v, int x, int lx, int rx){
        if (lx == rx){
            tree[x] = {v[lx]};
            return;
        }
        int m = (lx + rx) / 2;
        build(n, v, left(x), lx, m);
        build(n, v, right(x), m + 1, rx);

        vector <T> merged;
        // merge two arrays
        merge(all(tree[left(x)]), all(tree[right(x)]), back_inserter(merged));

        tree[x] = merged;
    }

    void update(int i, T val, int x, int lx, int rx){
        if (lx == rx){
            tree[x] = {val};
            return;
        }
        int m = (lx + rx) / 2;
        if (i <= m) update(i, val, left(x), lx, m);
        else update(i, val, right(x), m + 1, rx);

        vector <T> merged;
        // merge two arrays
        merge(all(tree[left(x)]), all(tree[right(x)]), back_inserter(merged));

        tree[x] = merged;
    }

    // return sorted interval [l, r] 
    vector<T> query(int l, int r, int x, int lx, int rx){
        if (l > rx || r < lx) return {};
        if (l <= lx && rx <= r) return tree[x];

        int m = (lx + rx) / 2;
        
        vector <T> to_lift = query(l, r, left(x), lx, m);
        vector <T> to_right = query(l, r, right(x), m + 1, rx);

        vector <T> merged;
        // merge two arrays
        merge(all(to_lift), all(to_right), back_inserter(merged));

        return merged;
    }

public:

    Merge_Sort_Tree(int n, vector<T> &v){ 

        size = sz(v);

        tree.assign(4 * size, vector<T>());

        build(n, v, 0, 0, size - 1);
    }

    vector<T> query(int l, int r, T val){
        if (base) return query(l-1, r-1 , 0, 0, size - 1);
        return query(l, r, 0, 0, size - 1);
    }

    void update(int i, T val){
        if (base) update(i-1, val, 0, 0, size - 1);
        else update(i, val, 0, 0, size - 1);
    }

    void print(){
        for (int level = 1 ; level <= size ; level *= 2){
            for (int i = 0 ; i < level ; i++){
                for (int space = 0 ; space < size / level ; space++) cout << " ";
                for (auto j : tree[level + i -1]) cout << j << " ";
            }
            cout << nl;
        }
    }

};

void solve(){
   
}


int main(){
    IO();
    int testcase=1 ;
    // cin >> testcase;
    for (int t=1 ; t<=testcase ; t++) {
        // cout << "Case #" << testcase << ": ";
        solve();
    }
    return 0;
}