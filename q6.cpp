#include <bits/stdc++.h>
using namespace std;

struct MaxHeap {
    vector<int> a;
    void heapifyUp(int i) {
        while (i>0) {
            int p=(i-1)/2;
            if (a[p]<a[i]) {
                swap(a[p],a[i]);
                i=p;
            } else break;
        }
    }
    void heapifyDown(int i) {
        int n=a.size();
        while (true) {
            int l=2*i+1,r=2*i+2,largest=i;
            if (l<n && a[l]>a[largest]) largest=l;
            if (r<n && a[r]>a[largest]) largest=r;
            if (largest!=i) {
                swap(a[i],a[largest]);
                i=largest;
            } else break;
        }
    }
    void push(int x) {
        a.push_back(x);
        heapifyUp(a.size()-1);
    }
    void pop() {
        if (a.empty()) return;
        a[0]=a.back();
        a.pop_back();
        if (!a.empty()) heapifyDown(0);
    }
    int top() {
        if (a.empty()) return -1;
        return a[0];
    }
    bool empty() {
        return a.empty();
    }
};

int main() {
    MaxHeap h;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        h.push(x);
    }
    while (!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }
    return 0;
}
