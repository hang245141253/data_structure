#include <iostream>
using namespace std;

struct Data {
    int x, y;
};

Data a[2], *p = a;

int main() {
    a[0].x = 111, a[0].y = 222;
    a[1].x = 333, a[1].y = 444;

    cout << a[1].x << endl;                 // 直接访问数组元素
    cout << p[1].x << endl;                 // 使用指针数组下标访问

    cout << (&a[1])->x << endl;             // 数组下标和指针偏移的结合
    cout << (&p[1])->x << endl;             // 通过指针偏移访问
    
    cout << (p + 1)->x << endl;             // 使用指针算术结合结构体指针访问
    cout << (*(p + 1)).x << endl;           // 使用指针算术结合解引用操作访问

    cout << (a + 1)->x << endl;             // 使用数组指针算术访问
    cout << (*(a + 1)).x << endl;           // 使用数组指针解引用访问

    cout << *(&a[0].x + 2) << endl;         // 通过偏移结构体成员的地址
    cout << *(&p[0].x + 2) << endl;         // 通过偏移结构体成员的地址

    cout << (&a[0] + 1)->x << endl;         // 使用地址运算符和指针算术访问
    cout << (*(&a[0] + 1)).x << endl;       // 使用地址运算符和解引用访问

    cout << (&p[0] + 1)->x << endl;         // 使用地址运算符和指针算术访问
    cout << (*(&p[0] + 1)).x << endl;       // 使用地址运算符和解引用访问

    cout << *((int *)a + 2) << endl;        // 强制转换类型并进行指针算术访问
    cout << ((int *)a + 2)[0] << endl;      // 强制转换类型并当成数组访问
    cout << ((int *)a)[2] << endl;

    cout << *((int *)p + 2) << endl;        // 使用强制类型转换和指针算术访问
    cout << ((int *)p + 2)[0] << endl;
    cout << ((int *)p)[2] << endl;
  
    // 新的方法，使用char*进行偏移然后转换为Data*
    cout << ((Data*)((char*)a + sizeof(Data)))->x << endl;  // 套娃写法
    cout << ((Data*)((char*)p + sizeof(Data)))->x << endl;

    return 0;
}
