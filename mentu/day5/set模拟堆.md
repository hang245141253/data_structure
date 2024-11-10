```c++
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

void test1() {
    cout << "set base usage : " << endl;
    set<int> s;
    cout << s.size() << endl;
    s.insert(3); // 3
    cout << s.size() << endl;
    s.insert(4); // 3, 4
    cout << s.size() << endl;
    s.insert(2); // 3, 4, 2
    cout << s.size() << endl;
    return ;
}

// set自带去重
void test2() {
    cout << "set item unique feature: " << endl;
    set<int> s;
    cout << s.size() << endl;
    s.insert(3);
    cout << s.size() << endl;
    s.insert(4);
    cout << "insert 4 : " << s.size() << endl;
    s.insert(4);
    cout << "insert 4 : " << s.size() << endl;
    return ;
}

// 不想去重，构建PII
void test3() {
    cout << "set item unique feature 2: " << endl;
    typedef pair<int, int> PII;
    set<PII> s;
    int tot = 0;
    cout << s.size() << endl;
    s.insert(PII(3, tot++));
    cout << s.size() << endl;
    s.insert(PII(4, tot++));
    cout << "insert 4 : " << s.size() << endl;
    s.insert(PII(4, tot++));
    cout << "insert 4 : " << s.size() << endl;
    return ;
}

// 遍历PII，默认顺序是以PII.first为序，如果相同再以second为序
void test4() {
    cout << "foreach set item : " << endl;
    typedef pair<int, int> PII;
    set<PII> s;
    int tot = 0;
    s.insert(PII(4, tot++));
    s.insert(PII(3, tot++));
    s.insert(PII(4, tot++));
    for (auto x : s) {
        cout << "(" << x.first << ", " << x.second << ")" << endl;
    }
    return ;
}

// set模拟堆
void test5() {
    cout << "set replace heap : " << endl;
    typedef pair<int, int> PII;
    int tot = 0;
    set<PII> s;
    for (int i = 0; i < 10; i++) {
        s.insert(PII(rand() % 20, tot++)); // push
    }
    for (int i = 0; i < 4; i++) {
        cout << "s.begin() = " << s.begin()->first << endl;  // 查看堆顶元素
        s.erase(s.begin()); // pop
        cout << "pop heap" << endl;
    }
    return ;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

```


* Leetcode 23 

把所有链表最小的节点全成一个集合。

构建新链表的时候，每次从这个小顶堆取元素。

取走一个之后立刻往set中从刚刚取走元素的链表继续补位

直到set没有元素，所有链表也合并完了。

    每次从所有剩余链表中，第一个节点中选出一个最小值 

    加入到结果链表中。

    维护的是所有的链表的第一个元素


```C++
/**
 * 传入的是链表数组指针
 * 
 * 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        typedef pair<int, int> PII;
        int n = lists.size();
        set<PII> s;

        // 构建集合
        for (int i = 0; i < n; i++) {
            if (lists[i] == nullptr) continue;
            s.insert(PII(lists[i]->val, i));
        }

        // 新建链表
        ListNode new_head, *p = &new_head, *q;
        new_head.next = nullptr;

        while (s.size()) {
            PII a = *s.begin(); // 拿出最小值准备插入到新链表
            s.erase(s.begin());
            // a.second是某链表的头节点
            q = lists[a.second];  // 当前节点（即最小节点）赋值给 q，方便后面将 q 插入到合并链表中
            lists[a.second] = lists[a.second]->next; // 该链表的当前节点推进到下一个节点，以便下次 set 插入时可以处理下一个节点。
            p->next = q; // 头插
            q->next = nullptr;
            p = q;
            // 如果这个链表还有元素，扔到set中
            if (lists[a.second]) {
                s.insert(PII(lists[a.second]->val, a.second));
            }
        }
        return new_head.next;
    }
};

```