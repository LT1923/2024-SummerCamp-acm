//
// Created by HUAWEI on 2024/7/25.
//
#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    long long int x_G, y_G, x_T, y_T;
    while (T--) {
        cin >> x_G >> y_G >> x_T >> y_T;

        long long int res_1 = pow(x_T - x_G, 2) + pow(y_T + y_G, 2);
        long long int res_2 = pow(x_T + x_G, 2) + pow(y_T - y_G, 2);
        printf("%.11lf\n", (double) min(sqrt(res_1), sqrt(res_2)));
    }
    return 0;

}