/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Shawky_XR <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
#define add_mod(a, b, m) (((a   % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define cin(vec) for(auto& i : vec) cin >> i
#define fix_mod(a,b)  ((a % b + b) % b)
#define sz(x) int(x.size())
#define fori(i, n) for (int i = 0; i < n; i++)
#define forll(i,n) for (ll i = 0; i < n; i++)
#define forab(i, a, b) for (int i = a; i <= b; i++)
#define fixed(n) cout << fixed << setprecision(n)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define Pi 3.141592653589793
#define nl "\n"
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

template <typename T, bool base> struct Segment_tree{

private:

    struct Node{

        T val;

        Node(T value = 0) : val(value) {}

        Node operator = (const T &a){
            val = a;
            return *this;
        }
        

    };

    int size;
    vector<Node> tree;
    Node ret; // Default value

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int mid(int l, int r) { return l + (r-l) / 2; }

    void build(vector<T> &v, int x, int lx, int rx){

        if (lx == rx){
            if (lx < sz(v)) tree[x] = v[lx]; // 0 based indexing tree
            return;
        }

        int m = mid(lx, rx);

        build (v, left(x), lx, m);
        build (v, right(x), m + 1, rx);

        tree[x] = merge(tree[left(x)], tree[right(x)]);
    }

    void update(int i, T val, int x, int lx, int rx){

        if (lx == rx){
            tree[x] = val;
            return;
        }

        int m = mid(lx, rx);

        if (i <= m) update(i, val, left(x), lx, m);
        else update(i, val, right(x), m + 1, rx);

        tree[x] = merge(tree[left(x)], tree[right(x)]);
    }

    Node query(int l, int r, int x, int lx, int rx){

        if (l > rx || r < lx) return ret;
        if (l <= lx && rx <= r) return tree[x];

        int m = mid(lx, rx);

        return merge(query(l, r, left(x), lx, m), query(l, r, right(x), m + 1, rx));
    }

public:

    Segment_tree(int n, vector<T> &v, T Default = 0){ 

        ret = Default;
        size = 1;
        while (size < n) size *= 2; 

        tree.assign(2 * size, ret);

        build(v, 0, 0, size - 1); // 0 based indexing tree
    }

    void update(int i, T val){
        if (base) update(i-1, val, 0, 0, size - 1);
        else update(i, val, 0, 0, size - 1);
    }

    T query(int l, int r){
        if (base) return query(l-1 , r-1, 0, 0, size - 1).val;
        return query(l, r, 0, 0, size - 1).val;
    }

    Node merge(Node a, Node b){
        return a.val + b.val; // Change this to operation you want to perform
    }

    T get(int i){
        if (base) return query(i-1, i-1);
        return query(i, i);
    }

    void print(){
        for (int level = 1 ; level <= size ; level *= 2){
            for (int i = 0 ; i < level ; i++){
                cout << tree[level + i -1].val << " ";
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