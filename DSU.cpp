/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Shawky_XR <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

// #include <bits/stdc++.h> 
#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <bitset>

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

template <typename T> struct DSU{

    public:

        int n;
        vector <T> parent;
        vector <T> size;


        DSU(int n) : n(n) , parent(n+2), size(n+2) {

            for (int i=1 ; i<=n ; i++){
                parent[i] = i;
                size[i] = 1;
            }

        }
        

        T get_parent(T u){
            return parent[u] = (parent[u] == u ? u : get_parent(parent[u])); // path compression
        }


        bool connected(T u, T v){
            return get_parent(u) == get_parent(v);
        }


        void unoin(T u ,T v){
            
            if (connected(u,v)) return;

            int Pu = get_parent(u), Pv = get_parent(v);
            
            if (size[Pu] < size[Pv])
                swap(Pu,Pv);

            size[Pu]+=size[Pv];
            parent[Pv] = Pu;
           
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