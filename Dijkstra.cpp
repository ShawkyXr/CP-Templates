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

template <typename T=int> struct Dijkstra{

    struct edge{
        T u, v, w;
        edge(T u, T v, T w): u(u), v(v), w(w) {}
        bool operator < (const edge& e) const{
            return w > e.w;
        }
    };

    vector<vector<edge>> adj;
    vector<T> dist;
    vector<T> parent;

    Dijkstra(int n): adj(n), dist(n, LLONG_MAX), parent(n, -1) {}

    void AddE(T u, T v, T w, bool directed = false){
        adj[u].emplace_back(edge(u, v, w));
        if (!directed) adj[v].emplace_back(edge(v, u, w));
    }

    void get_dist(T src,T target = -1){
        dist.assign(sz(adj), LLONG_MAX);
        parent.assign(sz(adj), -1);
        // create pq with edges sorted by lowest weight
        priority_queue<edge> pq;
        pq.emplace(edge(-1, src, 0));
        // initialize the distance of the source node to 0
        dist[src] = 0;
        parent[src] = -1;

        while (!pq.empty()){
            edge e = pq.top();
            pq.pop();
            if (e.v == target) return;
            if (dist[e.v] < e.w) continue;
            // relax all the edges that are going out of the current node
            for (auto& road : adj[e.v]){
                if (dist[road.v] > e.w + road.w){
                    dist[road.v] = e.w + road.w;  // relaxtion
                    parent[road.v] = e.v;
                    pq.emplace(edge(road.u, road.v, dist[road.v]));
                }
            }
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