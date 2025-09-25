/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Shawky_XR <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

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
   ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
   cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Sec; " << nl;
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
//    #endif
}


template <typename T, bool base> struct Sparse_Table{

private:

    int size;
    int Log;
    vector<vector<T>> table;

    void build(vector<T> &v){
        size = sz(v);
        Log = 32 - __builtin_clz(size);

        table.assign(Log + 1, vector<T>(size));

        for (int i=0 ; i<size ; i++) table[0][i] = v[i];

        for (int i=1 ; i <= Log ; i++){
            for (int j=0 ; j + (1 << i) <= size ; j++){
                table[i][j] = merge(table[i-1][j], table[i-1][j + (1 << (i-1))]);
            }
        }
    }

    T merge(T a, T b){
        return min(a, b);
    }

public:

    Sparse_Table(int n, vector<T> &v){
        build(v);
    }

    T query1(int l, int r){ // Min, Max, GCD, LCM in O(1) -> overlapping
        if (base) l--, r--;
        int j = 31 - __builtin_clz(r - l + 1);
        return merge(table[j][l], table[j][r - (1 << j) + 1]);
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