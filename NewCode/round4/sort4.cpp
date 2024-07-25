//
// Created by HUAWEI on 2024/7/25.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int map[n + 1];
        for (int i = 0; i < n; i++) {
            cin >> map[i + 1];
        }
        vector<int> arr;

        int sum = 0;
        while (sum < n) {
            int i = 1;
            for (; i <= n; i++) {
                if (map[i] != 0) break;
            }
            int j = map[i];
            map[i] = 0;
            int num = 1;
            sum++;
            while (map[j] != 0) {
                int k = j;
                j = map[j];
                map[k] = 0;
                sum++;
                num++;
            }
            arr.push_back(num);
        }

        int ans = 0;

        int two = 0;
        vector<int> twoNum;
        for (int &k: arr) {
            if (k > 4) {
                int add = (k - 4) / 3;
                if ((k - 4) % 3 != 0) add++;
                ans += add;
                if (k - add * 3 != 2) ans += 1;
                else {
                    twoNum.push_back(2);
                }
            } else if (k == 4 || k == 3) ans++;
            else if (k == 2) two++;
        }
        two = two + twoNum.size();
        int c = two / 2;
        if (two % 2 != 0) c++;
        ans += c;
        cout << ans << endl;
    }
    return 0;
}
