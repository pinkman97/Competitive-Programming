#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define pi              3.1415926536
#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define printl(n)       printf("%lld\n", n)
#define scd1(n)         scanf("%lf", &n)
#define scd2(a, b)      scanf("%lf %lf", &a, &b)
#define printd(n)       printf("%lf\n", n)
#define printcase       printf("Case %lld: ", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define SIZE            50005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)

ll a[SIZE];
struct info {
    ll sum, max_sum, prefix, suffix;
} tree[SIZE*4];

void calculate(ll node, ll bam, ll dan) {
    tree[node].sum = tree[bam].sum + tree[dan].sum;
    tree[node].prefix = max(tree[bam].prefix, tree[bam].sum+tree[dan].prefix);
    tree[node].suffix = max(tree[dan].suffix, tree[dan].sum+tree[bam].suffix);
    tree[node].max_sum = max( max(tree[bam].max_sum, tree[dan].max_sum), tree[bam].suffix+tree[dan].prefix );
}

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        tree[node].sum = a[r1];
        tree[node].max_sum = a[r1];
        tree[node].prefix = a[r1];
        tree[node].suffix = a[r1];
        return;
    }

    ll bam = node*2;
    ll dan = node*2 + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    calculate(node, bam, dan);
}

void update(ll node, ll r1, ll r2, ll in, ll val) {
    if(in > r2 || in < r1) return;
    if(r1 == in && r2 == in) {
        tree[node].sum = val;
        tree[node].max_sum = val;
        tree[node].prefix = val;
        tree[node].suffix = val;
        return;
    }

    ll bam = node*2;
    ll dan = node*2 + 1;

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, in, val);
    update(dan, mid+1, r2, in, val);

    calculate(node, bam, dan);
}

info query(ll node, ll r1, ll r2, ll i, ll j) {
    if(i > r2 || j < r1) {
        info p;
        p.sum = -1e9, p.max_sum = -1e9, p.prefix = -1e9, p.suffix = -1e9;
        return p;
    }
    if(r1 >= i && r2 <= j) return tree[node];

    ll bam = node*2;
    ll dan = node*2 + 1;

    ll mid = (r1 + r2) / 2;

    info p, p1, p2;

    p1 = query(bam, r1, mid, i, j);
    p2 = query(dan, mid+1, r2, i, j);

    p.sum = p1.sum + p2.sum;
    p.prefix = max(p1.prefix, p1.sum+p2.prefix);
    p.suffix = max(p2.suffix, p2.sum+p1.suffix);
    p.max_sum = max( max(p1.max_sum, p2.max_sum), p1.suffix+p2.prefix );
    return p;
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(n);

    for1(i, n) scl1(a[i]);

    build(1, 1, n);

    scl1(q);

    while(q--) {
        scl1(k);
        scl2(x, y);

        if(k) {
            ans = query(1, 1, n, x, y).max_sum;
            printl(ans);
        }
        else update(1, 1, n, x, y);
    }

    return 0;
}

