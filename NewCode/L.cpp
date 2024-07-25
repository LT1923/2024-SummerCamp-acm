//
// Created by HUAWEI on 2024/7/23.
//
#include <iostream>

using namespace std;

int main() {
    int flag = 0;
    char map[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
            if (map[i][j] == '8' && 0 < i && i < 8 && 0 < j && j < 8 && flag == 0) {
                flag = 1;
            } else {
                map[i][j] = '*';
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}