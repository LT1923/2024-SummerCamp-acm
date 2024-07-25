//
// Created by HUAWEI on 2024/7/25.
//
#include <iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int *>> map(n + 1, vector<int *>());

    for (int i = 1; i <= n; i++) {
        map[i].push_back(new int(i));
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(new int(b));
        map[b].push_back(new int(a));
//        map[a][b] = 1;
//        map[b][a] = 1;
    }
    int num = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
//            if (map[i][j] == 1) num++;
            bool find = false;
            for (auto neighbor: map[i]) {
                if (*neighbor == j)find = true;
            }
            if (find)num++;
            else {
                for (int k = 1; k < i; k++) {
                    map[k][j] = 0;
                }
                break;
            }
        }
    }
    cout << num;
    for (int i = 1; i < n + 1; i++) {
        delete map[i];
    }
    delete[]map;
    return 0;
}
