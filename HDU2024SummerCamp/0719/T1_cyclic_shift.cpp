//
// Created by HUAWEI on 2024/7/19.
//
#include<iostream>
#include<cstring>

using namespace std;

#define LIM 1048580

int main() {
    int T;
    cin >> T;

    char *a = new char[LIM];
    char *b = new char[LIM];
    memset(a, 0, sizeof a);//N2:sizeof a?
    memset(b, 0, sizeof b);

    while (T--) {
        cin >> a >> b;

        int count = 0;
        char *p_find;
        while ((p_find = strstr(a, b)) != nullptr) {
            count++;
        }
        //todo:shift
    }
    delete[]a;//N1： delete []a
    delete[]b;
    return 0;
}