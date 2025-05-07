/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Shawky_XR <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

// #include <bits/stdc++.h> 
#include <cassert>
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

typedef long long ll;
#define nl "\n"
#define fixed(n) cout << fixed << setprecision(n)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)



// point update and range query (BIT) 0-based
template <typename T > struct FenwickTree{ 
    vector <T> tree;
    int n;

    FenwickTree(vector <T> &vec){ 
        n = vec.size();
        tree.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            tree[i] += vec[i];
            int nxt = i | (i + 1);
            if (nxt < n)
                tree[nxt] += tree[i];
        }
    }

    FenwickTree(int n){
        this->n = n;
        tree.assign(n, 0);
    }


    void update(int idx, T val){
        for (; idx < n; idx |= (idx + 1)){
            tree[idx] += val;
        }
    }



    T query(int idx){ //from 0 to idx
        T res {};
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1){
            res += tree[idx];
        }
        return res;
    }


    T query(int l, int r){ // from l to r
        if (l > r) return 0;
        return query(r) - (l > 0 ? query(l-1) : 0);
    }

};




// range update and point query (BIT) 0-based
template <typename T> struct FenwickTree2{
    vector <T> tree;
    int n;

    FenwickTree2(vector <T> &vec){
        n = vec.size();
        tree.assign(n, 0);
        for (int i = 0; i < n ; i++){
           update(i, vec[i]);
        }
    }

    FenwickTree2(int n){
        this->n = n;
        tree.assign(n, 0);
    }


    void update(int idx, T val){
        for (int i = idx ; i < n; i |= (i+1)){
            tree[i] += val;
        }
    }

    void range_update(int l, int r, T val){ // range update from l to r
        update(l, val);
        if (r + 1 < n)
            update(r + 1, -val);
    }

    T query(int idx){ // value at idx
        T res {};
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1){
            res += tree[idx];
        }
        return res;
    }

};

void solve(){
    
}


int main(){
    fast;
    int testcase=1 ;
    // cin >> testcase;
    for (int t=1 ; t<=testcase ; t++) {
        // cout << "Case #" << testcase << ": ";
        solve();
    }
    return 0;
}