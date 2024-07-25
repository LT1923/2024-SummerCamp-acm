//
// Created by HUAWEI on 2024/7/25.
//
#include<iostream>
#include<vector>

using namespace std;

struct node {
    int path;
    vector<int> parent;
    vector<int> child;
};
//vector<vector<int>> adjlist;
vector<node> dp;
vector<bool> vis;

int dfs(int i) {
    dp[i].path = 0;
    vis[i] = true;
    for (int child: adjlist[i]) {
        if (!vis[child]) {
            dfs(child);
            dp[i] = max(dp[i], 1 + dp[child]);
        }
    }
    return dp[i];
}

int main() {
    int t;
//    cin >> t;
    scanf("%d", &t);
    while (t--) {
        int n;
//        cin >> n;
        scanf("%d", &n);
//        adjlist.resize(n + 1);
        dp.resize(n + 1);
        vis.resize(n + 1);
        for (int i = 1; i <= n - 1; i++) {
            vis.assign(n + 1, false);
            int u, v, c;
//            cin >> u >> v >> c;
            scanf("%d%d%d", &u, &v, &c);
//            adjlist[u].push_back(v);
            dp[u].child.push_back(v);
            dp[v].parent.push_back(u);
//            cout << dfs(c) << ' ';
            printf("%d ", dfs(c));
        }
//        cout << endl;
        printf("\n");
        adjlist.clear();
    }
    return 0;
}