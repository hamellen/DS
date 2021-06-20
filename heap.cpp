// heap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<queue>
#include<vector>
using namespace std;
class median {
public:
    priority_queue<int>maxheap;//기본 내림차순
    priority_queue<int, vector<int>, greater<int>>minheap;//오름차순 설정,les는 내림차순

    void insert(int data) {
        if (maxheap.size() == 0) {
            maxheap.push(data);
            return;
        }
        else if (maxheap.size() == minheap.size()) {
            if (data <= get())
                maxheap.push(data);
            else
                minheap.push(data);
            return;
        }
        else if (maxheap.size() < minheap.size()) {
            if (data > get()) {
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(data);
            }
            else
                maxheap.push(data);
            return;
        }
        else if (data < get())
        {
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(data);
        }
        else
            minheap.push(data);
    }
    double get() {
        if (maxheap.size() == minheap.size())
            return (maxheap.top() + minheap.top()) / 2.0;
        else if (maxheap.size() < minheap.size())
            return minheap.top();
        return maxheap.top();
    }
};
int main()
{
    median med;

    med.insert(1);
    med.insert(2);
    med.insert(7);
    med.insert(6);
    med.insert(9);
    med.insert(5);
    cout << "중앙값" << med.get() << endl;
}

