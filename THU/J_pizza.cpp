//
// Created by HUAWEI on 2024/7/21.
//
#include<iostream>
#include<vector>

#define mod 998244353

using namespace std;

int main() {
    //n种佐料，m个朋友
    int n = 0, m = 0;
    cin >> n >> m;

    //初始化想要和不想要的需求矩阵
    int **wanted = new int *[m + 1], **not_wanted = new int *[m + 1];
    for (int i = 1; i <= m; i++) {
        wanted[i] = new int[n + 1];
        not_wanted[i] = new int[n + 1];

        for (int j = 1; j <= n; j++) {
            wanted[i][j] = 0, not_wanted[i][j] = 0;
        }

        //读取需求
        int num_of_wish = 0;
        cin >> num_of_wish;

        int ingredient = 0;
        for (int k = 1; k <= num_of_wish; k++) {
            cin >> ingredient;

            if (ingredient > 0) {
                wanted[i][ingredient] = 1;
            } else {
                not_wanted[i][-ingredient] = 1;
            }
        }
    }

    //枚举pizza
    int *pizza = new int[n + 2];
    for (int i = 1; i <= n + 1; i++) {
        pizza[i] = 0;
    }
    int *last_pizza = new int[n + 2];
    int cnt = 0;

    int digit = 0;
    int *friend_happy = new int[m + 1];
    while (pizza[n + 1] != 1) {
//        bool wanted_flag = true;
//        bool not_wanted_flag = true;
        bool satisfied = true;
        for (int i = 1; i <= m; i++) {
            friend_happy[i] = 0;

            bool wanted_flag_i = false;
            bool not_wanted_flag_i = false;

            for (int j = 1; j <= n; j++) {
                if ((pizza[j] & wanted[i][j]) == 1) {
                    wanted_flag_i = true;
                }
                if (not_wanted[i][j] == 1 && (pizza[j] & not_wanted[i][j]) == 0) {
                    not_wanted_flag_i = true;
                }
            }

            if (wanted_flag_i || not_wanted_flag_i)friend_happy[i] = 1;
            if (!friend_happy[i])satisfied = false;
        }
        if (satisfied) {
            cnt = (cnt + 1) % mod;
            cout << "digit: " << digit << "\ncnt: " << cnt << endl;

        }

        //递增
        for (int j = 1; j <= n + 1; j++) {
            last_pizza[j] = pizza[j];
        }
        for (int i = 1; i <= n + 1; i++) {
            if (i == 1)pizza[i] = (pizza[i] + 1) % 2;
            else if (last_pizza[i - 1] == 1 && pizza[i - 1] == 0)pizza[i] = (pizza[i] + 1) % 2;
//            cout << pizza[i];
        }
        digit++;
//        cout << '\n';
    }

    cout << cnt;

    delete[]last_pizza;
    delete[]not_wanted;
    delete[]wanted;
    delete[]pizza;
    return 0;
}