#include <iostream>
#include <vector>
using namespace std;

// struct Stack {
//     vector<int> data;
//     Stack() {}
//     void push(int x) {
//         data.push_back(x);
//     }
//     void pop() {
//         if (empty()) return;
//         data.pop_back();
//     }
//     bool empty() {
//         return (data.size() == 0 && cout << "stack empty\n");
//     }
//     int size() {
//         return data.size();
//     }
//     void output() {
//         cout << "==========\n";
//         for (int i = data.size() - 1; i >= 0; i--) {
//             cout << " " << data[i] << endl;
//         }
//         cout << "==========\n";
//     }
// };

struct Stack {
    int *data, top;
    Stack(int n = 100) {
        top = -1; // empty
        data = new int[n];
    }
    void push(int x) {
        top += 1;
        data[top] = x;
    }
    void pop() {
        if (empty()) return;
        top--;
    }
    bool empty() {
        return (top == -1 && cout << "stack empty\n");
    }
    int size() {
        return top + 1;
    }
    void output() {
        cout << "==========\n";
        for (int i = top; i >= 0; i--) {
            cout << " " << data[i] << endl;
        }
        cout << "==========\n";
    }
};

int main() {
    Stack s;
    string op;
    int val;
    while (cin >> op) {
        if (op == "push") {
            cin >> val;
            s.push(val);
        } else if (op == "pop") {
            s.pop();
        } else if (op == "size") {
            cout << "size : " << s.size() << endl;
        } else if (op == "output") {
            s.output();
        }

    }
    return 0;
}