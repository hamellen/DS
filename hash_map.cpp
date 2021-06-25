

#include <iostream>
#include <vector>
using namespace std;
class hash_map {
    
    vector<int>data;
public:
    hash_map(int n) {
        data = vector<int>(n, -1);
    }
    void insert(int value) {
        int n = data.size();
        data[value % n] = value;

    }
    bool find(int value) {
        int n = data.size();
        return (data[value % n] == value);
     }
    void erase(int value) {
        int n = data.size();
        if (data[value % n] == value) {
            data[value % n] = -1;
        }
    }
};
int main()
{
    hash_map map(7);

    auto find = [&](int value) {
        if (map.find(value))
            cout << "성공" << endl;
        else
            cout << "실패" << endl;
    };
    map.insert(6);
    map.insert(5);
    map.insert(3);
    map.erase(6);
    find(4);
    return 0;
}
