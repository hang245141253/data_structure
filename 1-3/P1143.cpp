#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    string num;

    cin >> n >> num >> m;
    reverse(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        if (num[i] <= '9') num[i] -= 48;
        else num[i] -= 55;
    }

    int d = 0;  // 存n进制转10进制 
    for (int i = 0; i < num.size(); i++) {
        d += num[i] % n * pow(n, i);
    }

    string ans;
    while (d) {
        if (d % m <= 9) ans += d % m + '0';
        else ans += d % m + 55;
        d /= m;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    

    return 0;
}