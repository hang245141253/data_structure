/*************************************************************************
	> File Name: test.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    long long sum = 0;
    for (int i = 1; i <= 10000; i++) {
        sum += i * i;
    }
    cout << sum << endl;
    return 0;
}
