#include <bits/stdc++.h>
using namespace std;
  
typedef long long int ll;
  
ll find(ll parent[], ll x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent, parent[x]);
}
  
void merge(ll parent[], ll size[],
           ll x, ll y)
{
    ll r1 = find(parent, x);
    ll r2 = find(parent, y);
  
    if (size[r1] < size[r2]) {
        parent[r1] = r2;
        size[r2] += size[r1];
    }
    else {
        parent[r2] = r1;
        size[r1] += size[r2];
    }
}
  
void generate(int n)
{
    ll i;
    cout << n << '\n';
    ll parent[n + 1];
    ll size[n + 1];
  
    for (i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
  
    vector<pair<ll, ll> > edges;
  
    for (i = 1; i <= n - 1; i++) {
        ll x = 1 + rand() % n;
        ll y = 1 + rand() % n;
  
        while (find(parent, x)
               == find(parent, y)) {
  
            x = 1 + rand() % n;
            y = 1 + rand() % n;
        }
        merge(parent, size, x, y);
        edges.push_back(make_pair(x, y));
    }

    int m[100005];
    for (int i = 1; i <= n; i++) {
        m[i - 1] = i;
    }
    shuffle(m, m + n, default_random_engine(time(NULL)));

    for (i = 0; i < edges.size(); i++) {
        cout << m[edges[i].first - 1] << ' '
             << m[edges[i].second - 1] << '\n';
    }
}
  
int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));
    generate(atoi(argv[1]));
}
