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

// Trie 
struct Trie {
    struct Node {
        vector<Node*> child;
        int cnt;
        int end;

        Node() {
            child.assign(26, NULL);
            cnt = 0;
            end = 0;
        }

        ~Node() {
            for (auto childNode : child) {
                if (childNode) {
                    delete childNode; 
                }
            }
        }

    };

    Node* root;

    Trie() { 
        root = new Node();
    }

    ~Trie() {
        delete root;  
    }

    void insert(string s) {
        Node* cur = root;
        for (char c : s) {
            if (cur->child[c - 'a'] == NULL) {
                Node* newNode = new Node();
                cur->child[c - 'a'] = newNode;
            }
            cur = cur->child[c - 'a'];
            cur->cnt++;
        }
        cur->end++;
    }

    int isExist(string s) {  // check if whole string exists in the trie
        Node* cur = root;
        for (char c : s) {
            if (cur->child[c - 'a'] == NULL) return 0;
            cur = cur->child[c - 'a'];
        }
        return cur->end;
    }

    int isPrefix(string s) {  // check if the prefix exists in the trie
        Node* cur = root;
        for (char c : s) {
            if (cur->child[c - 'a'] == NULL) return 0;
            cur = cur->child[c - 'a'];
        }
        return cur->cnt;
    }

    void remove(string s) {
        Node* cur = root;
        for (char c : s) {
            if (cur->child[c - 'a'] == NULL) return;
            cur = cur->child[c - 'a'];
            cur->cnt--;
        }
        cur->end--;
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