#include <iostream>
#include <algorithm>
using namespace std;

int B;
string num1;
string num2;
string sum;

void s_i(string &num) {
    for (int i = 0; i < num.size(); i++) {
        if (num[i] <= '9')
            num[i] -= '0';
        else
            num[i] -= 'A' - 10;
    }
}

void i_s(string &num) {
    for (int i = 0; i < num.size(); i++) {
        if (num[i] <= 9)
            num[i] += '0';
        else
            num[i] += 'A' - 10;
    }
}

void carry(string &sum) {
    for (int i = 0; i < sum.size(); i++) {
        if (sum[i] >= B) {
            if (i == sum.size() - 1) sum.push_back('\0');
            sum[i] = sum[i] % B;
            sum[i + 1]++;
        }
    }
}

int main() {
    cin >> B >> num1 >> num2;
    reverse(num1.begin(), num1.end()); // 保证低位对齐
    reverse(num2.begin(), num2.end());
    s_i(num1);
    s_i(num2);
    for (int i = 0; i < max(num1.size(), num2.size()); i++) {
        if (i < num1.size() && i < num2.size())
            sum.push_back((num1[i] + num2[i]));
        else if (i >= num1.size() && i < num2.size()) {
            sum.push_back((num2[i]));
        } else if (i < num1.size() && i >= num2.size()) {
            sum.push_back((num1[i]));
        }
    }

    carry(sum);
    i_s(sum);
    reverse(sum.begin(), sum.end());
    cout << sum << endl;

    '#';
    '$';

    return 0;
}