从leetcode 20 有效的括号

引入：
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。


解题：先问题简化成只有⼀种括号 ( )，怎么做?

结论：

1、在任意一个位置上，左括号数量 >= 右括号数量

2、在最后一个位置上，左括号数量 == 右括号数量

3、程序中只需要记录左括号数量和右括号数量即可

```C++
bool isValid(string s) {
    int lnum = 0, rnum = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case '(' : lnum++; break;
            case ')' : rnum++; break;
            default : return false;
        }
        if (lnum >= rnum) continue;
        return false;
    }
    return lnum == rnum;
}
```

思考：rnum 变量⼀定是需要的么？

```C++
bool isValid(string s) {
    int lnum = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case '(' : lnum++; break;
            case ')' : lnum--; break;
            default : return false;
        }
        if (lnum >= 0) continue;
        return false;
    }
    return lnum == 0;
}
```

引出重点思考的结论：

1、我们获得了怎样新的思维⽅式？

2、+1 可以等价为『进』，-1可以等价为『出』

3、⼀对()可以等价为⼀个完整的事件

4、( () )可以看做事件与事件之间的完全包含关系

5、由括号的等价变换，得到了⼀个新的数据结构


## 03.04 化栈为队

```C++
class MyQueue {
public:
    stack<int> s1, s2;
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s2.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        transfer();
        int ret = s1.top();
        s1.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        transfer();
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
    void transfer() {
        if (!s1.empty()) return;
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }               
    }
};
```

