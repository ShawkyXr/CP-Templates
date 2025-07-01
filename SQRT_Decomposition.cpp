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


template <typename T> struct Sqrt_Decom{

    int n,Sq;
    vector <T> vec, blk;
    vector <vector <T>> blocks;
    
    Sqrt_Decom (int N,vector <T> arr){
        n = N, Sq = sqrt(n)+1;
        vec = arr;
        blk.assign(Sq);
        blocks.assign(Sq,vector <T> ());

        for (int i=0 ; i<n ; i++){
            blocks[i/Sq].push_back(vec[i]);
            blk[i] += vec[i];
        }

    }

    void update(int idx, T val){
        
        int blk_idx = idx/Sq;

        blk[blk_idx] -= vec[idx]; 
        vec[idx] = val;
        blk[blk_idx] += val; 

        int b_idx = idx%Sq;

        blocks[blk_idx][b_idx] = val;
    }


    T query(int l, int r){
        T ret = 0;

        while(l <= r){

            if (l%Sq==0 && l+Sq-1 <= r){
                ret += blk[l/Sq];
                l += Sq;
            }else{
                ret += vec[l];
                l++;
            }
        }

        return ret;
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