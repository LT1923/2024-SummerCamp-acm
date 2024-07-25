/*
#include <iostream>
#include <vector>

#define MAX 100005

using namespace std;

int gcd(int a, int b) {
    int temp;
    while (a != 0) {
        temp = b % a;
        b = a;
        a = temp;
    }
    return b;
}

class Frac {
public:
    int top;
    int bottom;

    Frac();

    Frac operator+(const Frac &other);

    Frac operator*(const Frac &other);

    void simplify();
};

Frac::Frac() {
    this->top = 0;
    this->bottom = 1;
}

Frac Frac::operator+(const Frac &other) {
    Frac res;
    res.top = this->top * other.bottom + other.top * this->bottom;
    res.bottom = this->bottom * other.bottom;
    return res;
}

Frac Frac::operator*(const Frac &other) {
    Frac res;
    res.top = this->top * other.top;
    res.bottom = this->bottom * other.bottom;
    return res;
}

Frac max(const Frac &a, const Frac &b) {
    return (a.top * b.bottom > b.top * a.bottom) ? a : b;
}

void Frac::simplify() {
    int g = gcd(this->bottom, this->top);
    this->top /= g;
    this->bottom /= g;
}

vector<vector<int>> A;//邻接表
vector<Frac> dp;
vector<Frac> e;//在每个顶点的期望停留时间
vector<bool> vis;//是否访问过某顶点

void dfs(int i, int n) {
    vis[i] = true;
    for (int child: A[i]) {
        if (!vis[child]) {
            dfs(child, n);
            dp[i] = max(dp[i], e[i] + dp[child]);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    A.reserve(MAX);
    e.reserve(MAX);
    dp.reserve(MAX);
    vis.reserve(MAX);

    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            A[i].clear();
        }

        for (int i = 1; i <= n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            A[u].push_back(v);
            A[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            e[i].top = 15;
            scanf("%d", &e[i].bottom);
            dp[i] = e[i];
            vis[i] = false;
        }

        dfs(1, n);

        dp[1].simplify();
        cout << dp[1].top << '/' << dp[1].bottom << endl;
    }
    return 0;
}
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> adj[500005];
long long k[500005];
long long dp[500005];

void value(int now, int parent) {
    long long max = 0;
    if (adj[now].size() == 1 && now != 0) {
        dp[now] = k[now];
        return;
    }
    for (int v: adj[now]) {
        if (v != parent) {
            value(v, now);
            if (dp[v] > max) max = dp[v];
        }
    }
    dp[now] = k[now] + max;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            adj[a - 1].push_back(b - 1);
            adj[b - 1].push_back(a - 1);
        }
        for (int i = 0; i < n; i++) {
            long long h;
            cin >> h;
            k[i] = 360360 / h;
        }
        value(0, -1);
        long long g = gcd((long long) 360360, dp[0] * 15);
        cout << dp[0] * 15 / g << '/' << 360360 / g << endl;
    }
    return 0;
}