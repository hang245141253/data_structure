#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int A[N], cnt;

int build(int l, int r) {
    if (l > r) return 0;     
    // if (l == r) return 1;    
    int pos = l;             
    cnt++;                  

    for (int i = l + 1; i <= r; i++) {
        cnt++;                
        if (A[i] > A[pos]) { 
            pos = i;       
        }
    }


    int ls = build(l, pos-1);

    int rs = build(pos+1, r);

    return max(ls, rs) + 1;  
}

int main() {
    int n;
    cin >> n;  
    for(int i = 1; i <= n; ++i) {
        cin >> A[i];  
    }
    cnt = 0;  
    int dep = build(1, n); 
    cout << dep << " " << cnt << endl;  
}
