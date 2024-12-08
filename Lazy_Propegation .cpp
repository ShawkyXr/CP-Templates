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
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
//    #endif
   ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
   cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Sec; " << nl;
}

template <typename T, bool base> struct Lazy_Segment_tree{
    
private:

    struct Node{
            
            T val, lazy;
    
            Node(T value = 0) : val(value), lazy(0) {}
    
            Node operator = (const T &a){
                val = a;
                return *this;
            }
    };

    int size;
    T ret; 
    vector<Node> tree;

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int mid(int l, int r) { return l + (r-l) / 2; }

    void build(vector<T> &v, int x, int lx, int rx){
        if (lx == rx){
            if (lx < sz(v)) tree[x] = v[lx];
            return;
        }

        int m = mid(lx, rx);

        build(v, left(x), lx, m);
        build(v, right(x), m + 1, rx);
    }

    void propagate(int x, int lx, int rx){
        if (tree[x].lazy == 0) return;
        if (lx != rx){
            tree[left(x)].lazy += tree[x].lazy;
            tree[right(x)].lazy += tree[x].lazy;
        }
        tree[x].val += tree[x].lazy;
        tree[x].lazy = 0;
    }

    void update(int l,int r ,T val, int x,int lx, int rx){
        propagate(x, lx, rx);
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r){
            tree[x].lazy += val;
            propagate(x, lx, rx);
            return;
        }

        int m = mid(lx, rx);

        update(l, r, val, left(x), lx, m);
        update(l, r, val, right(x), m + 1, rx);

        tree[x] = merge(tree[left(x)], tree[right(x)]);
    }

    Node query(int l, int r, int x, int lx, int rx){
        propagate(x, lx, rx);
        if (lx > r || rx < l) return ret;
        if (lx >= l && rx <= r) return tree[x];
        int m = mid(lx, rx);
        return merge(query(l, r, left(x), lx, m), query(l, r, right(x), m + 1, rx));
    }

    Node query(int idx, int x, int lx, int rx){
        propagate(x, lx, rx);
        if (lx == rx) return tree[x];
        int m = mid(lx, rx);
        if (idx <= m) return tree[x].val + query(idx, left(x), lx, m);
        return tree[x].val + query(idx, right(x), m + 1, rx);
    }
   
    
public:

    Lazy_Segment_tree(int n, vector<T> &v, T Default = 0){ 

        ret = Default; // Default value
        size = 1;
        while (size < n) size *= 2; 

        tree.assign(2 * size, ret);

        build(v, 0, 0, size - 1); 
    }

    void update(int l, int r, T val){
        if (base) update(l-1, r-1, val, 0, 0, size - 1);
        else update(l, r, val, 0, 0, size - 1);
    }

    T query(int l, int r){
        if (base) return query(l-1, r-1, 0, 0, size - 1).val;
        return query(l, r, 0, 0, size - 1).val;
    }

    T query(int idx){
        if (base) return query(idx-1, 0, 0, size - 1).val;
        return query(idx, 0, 0, size - 1).val;
    }

    Node merge(Node a, Node b){
        return a.val + b.val; // Change this to operation you want to perform
    }

    T get(int i){
        return query(i, i);
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