#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define x first
#define y second
#define ndl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define up_b upper_bound
#define low_b lower_bound
#define sz(x) (int)x.size()
#define bit __builtin_popcount
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

template<typename T> using indexed_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<int, ull> piu;
typedef vector<vector<int>> matrix;

const ll INF = 1e18 + 123;
const ld EPS = 1e-9;
const int inf = 1e9 + 123;
const int MOD = 1e9 + 7;
const int N = 5e5 + 123;
const int M = 1e6 + 123;
const double pi = acos(-1.0);
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct point {
    ld x, y;
    void read(){
        cin >> x >> y;
    }
    point operator+(point p){
        return point{x + p.x, y + p.y};
    }
    point operator-(point p){
        return point{x - p.x, y - p.y};
    }
    ld operator%(point p){
        return x * p.y - y * p.x;
    }
    ld operator*(point p){
        return x * p.x + y * p.y;
    }
    point operator*(long long k){
        return point{x * k, y * k};
    }
};

struct line {
    ld a, b, c;
    line(point p, point q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    point q;
    cin >> n;
    q.read();
    vector<point> p(n);
    for (int i = 0; i < n; i++){
        p[i].read();
    }
    ld res = 0;
    for (int i = 0; i < n; i++){
        point a = p[(i+1)%n];
        point b = p[i];
        line l = line(a, b);
        if (fabsl(q.x * l.a + q.y * l.b + l.c) < EPS && min(a.x, b.x) <= q.x && q.x <= max(a.x, b.x) && min(a.y, b.y) <= q.y && q.y <= max(a.y, b.y)){
            cout << "YES";
            return 0;
        }
        a = a - q;
        b = b - q;
        res += atan2(b%a, b*a);
    }
    if (fabsl(res) > EPS){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
