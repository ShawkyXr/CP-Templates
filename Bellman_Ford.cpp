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

template <typename T=int> struct Bellman{

    struct Edge{

        int from, to;
        T cost;

        Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    };

    int n;
    bool inv;
    vector<Edge> edges;
    vector<T> dist;
    vector<int> parent;


    Bellman(int n,bool inv) : n(n), inv(inv) ,dist(n, oo), parent(n, -1) {}


    void addEdge(int from, int to, T cost){
        
        if (inv) 
            edges.emplace_back(from, to, -1LL*cost);
        else 
            edges.emplace_back(from, to, cost);

    }


    ll bellmanFord(int src){

        dist[src] = 0;

        for(int i = 0; i < n-1 ; i++){
            for(auto &e : edges){
                if(dist[e.from] + e.cost < dist[e.to]){
                    dist[e.to] = dist[e.from] + e.cost;
                    parent[e.to] = e.from;
                }
            }
        }

        return (inv? dist[n]*-1LL : dist[n]);
    }


    bool NegCycle(){

         for (int i=0 ; i<= n-1 ; i++){
            for(auto &e : edges){
                if (dist[e.from] + e.cost < dist[e.to])
                    return false; // Negative cycle 
            }
        }

        return true;
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