

#include <iostream>
#include <vector>
using namespace std;
class hash_map 
{
    vector<int>data1;
    vector<int>data2;
    int size;
public:
    hash_map(int n) {
        size = n;
        data1 = vector<int>(n, -1);//첫번째 컨테이너 정의
        data2 = vector<int>(n, -1);//두번째 컨테이너 정의
    }
    int hash1(int key) const {//첫번째 해싱함수 
        return key % size;
    }
    int hash2(int key)const {//두번째 해싱함수
        return (key / size) % size;
    }
    vector<int>::iterator find(int key) {//컨테이너상에서 값이 존재하는 반복자 반환
        auto hashvalue1 = hash1(key);
        if (data1[hashvalue1] == key) {
            return data1.begin() + hashvalue1;
        }
        auto hashvalue2 = hash2(key);
        if (data2[hashvalue2] == key) {
            return data2.begin() + hashvalue2;
        }
        return data2.end();
    }
    void erase(int key) {//원소삭제 함수
        auto it = find(key);
        if (it != data2.end()) {
            *it = -1;
        }
        else {
            cout << "탐지에 실패하였습니다." << endl;
        }
    }
    void insert(int key) {
        insert_impl(key, 0, 1);
    }
    void insert_impl(int key, int cnt, int table) {//원소삽입 함수
        if (cnt >= size) {
            cout << "재해싱이 필요합니다." << endl;
            return;
        }
        else if (table == 1) 
        {
            int hashvalue1 = hash1(key);
            if (data1[hashvalue1] == -1) {//첫번째 컨테이너에 원소 삽입
                data1[hashvalue1] = key;
            }
            else {
                int oldvalue = data1[hashvalue1];//두번째 컨테이너로 원소 옮기기
                data1[hashvalue1] = key;
                insert_impl(oldvalue, cnt + 1, 2);
            }
        }
        else if (table == 2) 
        {
            int hashvalue2 = hash2(key);
            if (data2[hashvalue2] == -1) {//두번째 컨테이너에 원소 삽입
                data2[hashvalue2] = key;
            }
            else {
                int oldvalue2 = data2[hashvalue2];//첫번째 컨테이너로 원소 옮기기
                data2[hashvalue2] = key;
                insert_impl(oldvalue2, cnt + 1, 1);
            }
        }
    }
};

int main()
{
    
}

