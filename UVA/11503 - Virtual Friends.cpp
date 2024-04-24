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
#define SIZE            100005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

map <string, string> par;
map <string, ll> total;
ll ans;

string Find(string x) {
    if(par[x] == x) return x;
    return par[x] = Find(par[x]);
}

void Union(string a, string b) {
    string u = Find(a);
    string v = Find(b);

    if(u == v) {
        ans = total[u];
        return;
    }

    par[u] = v;
    total[v] += total[u];
    ans = total[v];
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, sum = 0, c = 0;
    string s1, s2;

    scl1(t);

    while(t--) {
        scl1(n);

        par.clear();
        total.clear();

        while(n--) {
            cin >> s1 >> s2;

            if(par[s1].size() == 0) {
                par[s1] = s1;
                total[s1] = 1;
            }
            if(par[s2].size() == 0) {
                par[s2] = s2;
                total[s2] = 1;
            }

            Union(s1, s2);

            printl(ans);
        }
    }

    return 0;
}

