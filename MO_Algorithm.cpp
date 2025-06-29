/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Shawky_XR <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <numeric>
#include <iomanip>
#include <algorithm>

using namespace std;

#define nl "\n"
#define cin(vec) for(auto& i : vec) cin >> i
#define sz(x) int(x.size())
#define fixed(n) cout << fixed << setprecision(n)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define Pi 3.141592653589793
typedef long long ll;
typedef pair<int, int> pii;

const ll oo = 0x3f3f3f3f3f3f3f3f;
constexpr int Mod =  1e9 + 7;


void IO(){
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
//    #endif
   ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int Sq;

template <typename T> struct Mo{
    
    struct Query{
        
        int l,r,block_idx,query_idx;

        Query(int l,int r,int Qi): l(l), r(r), query_idx(Qi) , block_idx(l/Sq) {}

        bool operator < (const Query &other) const{      
            if (block_idx == other.block_idx){
                return r < other.r;
            }
            return block_idx < other.block_idx;
        }
    };

    int Q , N;
    T res = 0;
    vector <Query> queries;
    vector <T> vec,ans;

    Mo(int n, vector <T> arr,int q){
        N = n;
        Sq = sqrt(N)+2;
        vec = arr;
        Q = q;
        ans.resize(Q);
    }

    void Add_Query(int l, int r, int i){
        queries.push_back(Query(l,r,i));
    }

    void Add(int idx){

    }

    void Remove(int idx){

    }

    void Process(){

        sort(all(queries));

        int l = 1,r = 0;
        for (int i=0 ; i<Q ; i++){
            
            while(l < queries[i].l) Remove(l++);
            while(l > queries[i].l) Add(--l);
            while(r < queries[i].r) Add(++r);
            while(r > queries[i].r) Remove(r--);

            ans[queries[i].query_idx] =  res;
        }

    }


};


void solve(){
    int n;
    cin >> n;

    vector <int> vec(n);
    for (int i=0 ; i<n ; i++){
        cin >> vec[i];
    }

    int q;
    cin >> q;

    Mo <int> mo(n,vec,q);
    for (int i=0 ; i<q ; i++){
        int l,r;
        cin >> l >> r;
        mo.Add_Query(l,r,i);
    }

    mo.Process();
    for (int i=0 ; i<q ; i++){
        cout << mo.ans[i] << nl;
    }
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