/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Shawky_XR <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

// #include <bits/stdc++.h> 
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

// -------------------------------------------------- Number Theory -------------------------------------------------- //


// Logarithm for any base
double LOG(double val, double base){
    return log2(val) / log2(base);
}

// Greatest Common Divisor (GCD) of two numbers in O(log(min(a,b))) using Euclid’s algorithm
ll GCD(ll n ,ll m){ 
    if (!m) return n;
    return GCD(m,n%m);
}



// Least Common Multiple (LCM) of two numbers in O(log(min(a,b)))
ll LCM(ll n, ll m){ 
    return (n / GCD(n,m))*m;
}



// prime factorization of n in O(sqrt(n))
vector <ll> prime_factors(ll n){ 
    vector <ll> ans;
    for (ll i=2 ; i*i<=n ; i++){
        while (n%i==0){
            n/=i;
            ans.push_back(i);
        }
    }
    if (n>1) ans.push_back(n);
    return ans;
}



// power of a to the power of b in O(log(b))
ll power(ll a, ll b){ 
    if (b==0) return 1;
    ll res=power(a,b/2);
    if (b&1) return res*res*a;
    return res*res;
}



// modular exponentiation of a to the power of b modulo m in O(log(b))
ll mod_power(ll a, ll b, ll m = 1e9+7){
    ll res = 1;
    a = a % m;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}


// Euler's Totient Function in O(sqrt(n)) : number of integers from 1 to n that are coprime to n
ll phi(ll n){ 
    ll result = n;
    for (ll i=2 ; i*i<=n ; i++){
        if (n%i==0){
            while (n%i==0) n/=i;
            result -= result/i;
        }
    }
    if (n>1) result -= result/n;
    return result;  
}


// Euler's Totient Function in O(nloglogn) : number of integers from 1 to n that are coprime to phi[i]
vector <ll> phi_nums (ll max_n){
    vector <ll> phi(max_n+1);
    for (ll i=1 ; i<=max_n ; i++){
        phi[i]=i;
    }
    for (ll i=2 ; i<=max_n ; i++){
        if (phi[i]==i){
            for (ll j=i ; j<=max_n ; j+=i){
                phi[j]-=phi[j]/i;
            }
        }
    }
    return phi;
}



// get all divisors of n in O(sqrt(n))
vector <ll> get_divisors(ll n){ 
    vector <ll> ans;
    for (ll i=1 ; i*i<=n ; i++){
        if (n%i==0){
            ans.push_back(i);
            if (i*i!=n) ans.push_back(n/i);
        }
    }
    return ans;
}



// sieve of eratosthenes in O(nloglogn)
vector <bool> sieve(ll n){ 
    vector <bool> is_prime(n+1,1);
    is_prime[0]=is_prime[1]=0;
    for (ll i=2 ; i*i<=n ; i++){
        if (is_prime[i]){
            for (ll j=i*i ; j<=n ; j+=i){
                is_prime[j]=0;
            }
        }
    }
    return is_prime;
}



// sum of all divisors of n in O(sqrt(n))
ll sum_of_divisors(ll n) {

    if (n == 1) return 1;

    ll result = 1 + n; 

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) result += i;
            else result += i + n / i;
        }
    }

    return result;
}




// number of divisors of n in O(sqrt(n))
ll num_of_divisors(ll n){
    ll cnt = 0;
    for (ll i=1 ; i*i<=n ; i++){
        if (n%i==0){
            cnt++;
            if (i*i!=n) cnt++;
        }
    }
    return cnt;
}




// number of divisors of n in O(sqrt(n)) optimized with factorization
ll num_of_divisors_optimized(ll n){ 
    ll cnt = 1;
    for (ll i=2 ; i*i<=n ; i++){
        ll power = 0;
        while (n%i==0){
            n/=i;
            power++;
        }
        cnt *= power+1;
    }
    if (n!=1) cnt *= 2;
    return cnt;
}


// check if n is prime in O(sqrt(n))
bool is_prime(ll n){ 
    if (n<2 || (n%2==0 && n!=2)) return false;
    for (int i=3 ; i<=sqrt(n) ; i+=2){
      if (n%i==0) return false;
    }
    return true;
}



// get all primes numbers till n in O(nloglogn)
vector <ll> get_primes(ll n){
    vector <bool> is_prime = sieve(n);
    vector <ll> primes;
    for (ll i=2 ; i<=n ; i++){
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}



// Summation of all primes numbers till n in O(nloglogn)
ll sum_primes(ll n){ 
    vector <bool> is_prime = sieve(n);
    ll sum=0;
    for (ll i=0 ; i<=n ; i++){
        if (is_prime[i]) sum+=i;
    }
    return sum;
}



// Summation of all divisors of n optimized with sieve and factorization in O(sqrt(n))
ll sum_of_divisors_optimized(ll n){ 

    ll sqrt_n = sqrt(n);
    vector <ll> primes = get_primes(sqrt_n);

    ll sum = 1;

    for (int i=0 ; i<primes.size() && primes[i]*primes[i]<=n ; i++){
        if (n%primes[i]==0){
            ll cnt = 0;
            while (n%primes[i]==0){
                n/=primes[i];
                cnt++;
            }
            sum *= (mod_power(primes[i],cnt+1) -1) / (primes[i]-1);
        }
    }
    
    if (n!=1) sum *= n+1;
    return sum;
}


// permutation of nPr in O(r)
ll nPr (ll n, ll r){
    ll ans = 1;
    for (ll i=n ; i>n-r ; i--){
        ans *= i;
    }
    return ans;
}


// combination of nCr in O(r)
ll nCr (ll n, ll r){
    if (r > n-r) r = n-r;
    ll ans = 1;
    for (ll i=0 ; i<r ; i++){
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}


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