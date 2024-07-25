//
// Created by HUAWEI on 2024/7/23.
//
#include<iostream>
#include<cstring>

using namespace std;

int main() {
    /*
    int n, a, b;
    cin >> n >> b >> a;
    char *T = new char[n + 1];
    cin >> T;

    int num_of_1 = 0, num_of_0 = 0;
    for (int i = 0; i < n; i++) {
        if (T[i] == '1')num_of_1++;
        else num_of_0++;
    }

    if (a <= n && b <= n) {
        int small_win_a = 0, small_win_b = 0, major_win_a = 0, major_win_b = 0;
        for (int i = 0; i < n; i++) {
            major_win_a = 0;
            major_win_b = 0;
            char *p = T + i;
            int round = 0;
            while (1) {
//            round++;
//            cout << round << endl;
                if (*p == '1') {
                    small_win_a++;
                    if (small_win_a == b) {
                        major_win_a++;
//                    cout << "major_win_a: " << major_win_a << endl;
                        small_win_a = 0;
                        small_win_b = 0;
                        if (major_win_a == a) {
                            cout << 1;
                            break;
                        }
                    }
                } else if (*p == '0') {
                    small_win_b++;
                    if (small_win_b == b) {
                        major_win_b++;
//                    cout << "major_win_b: " << major_win_b << endl;
                        small_win_a = 0;
                        small_win_b = 0;
                        if (major_win_b == a) {
                            cout << 0;
                            break;
                        }
                    }
                }
                p++;
                if (p == T + n) {
                    p = T;
                }
            }
        }
    } else {
        int res = -1, rest_a, rest_b, rest_rest_a, rest_rest_b;
        if (b / num_of_0 > b / num_of_1)res = 1;
        else if (b / num_of_0 < b / num_of_1)res = 0;
        else {
            rest_a = b - (b / num_of_1 - 1) * num_of_1;
            rest_b = b - (b / num_of_0 - 1) * num_of_0;
            if (a / rest_b > a / rest_a)res = 1;
            else if (a / rest_b < a / rest_a)res = 0;
            else {
                rest_rest_a = a - (a / rest_a - 1) * rest_a;
                rest_rest_b = a - (a / rest_b - 1) * rest_b;
            }
        }

        for (int i = 0; i < n; i++) {
            if (res == -1) {
                int small_win_a = 0, small_win_b = 0;
                char *p = T + i;
                for (int j = 0; j < n; j++) {
                    if (*p == '1') {
                        small_win_a++;
                        if (small_win_a == rest_rest_a) {
                            res = 1;
                            break;
                        }
                    } else if (*p == '0') {
                        small_win_b++;
                        if (small_win_b == rest_b) {
                            res = 0;
                            break;
                        }
                    }
                    p++;
                    if (p == T + n) {
                        p = T;
                    }
                }
            }
            cout << res;
            res = -1;
        }
    }

    delete[]T;*/
    cout << (1 << 2 + 1);
    return 0;
}