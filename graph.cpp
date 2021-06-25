// graph.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
enum class city :int {
    moscow, london, seoul, seattle, dubai, sydney//도시명에 따른  enum class  정의
};

ostream& operator<<(ostream& os, const city c)//출력연산자 정의 
{
    switch (c) 
    {
    case city::moscow:
        os << "모스크바";
        return os;
    case city::london:
        os << "런던";
        return os;
    case city::seoul:
        os << "서울";
        return os;
    case city::seattle:
        os << "시애틀";
        return os;
    case city::dubai:
        os << "두바이";
        return os;
    case city::sydney:
        os << "시드니";
        return os;
    default:
        return os;
    }
}

class graph 
{
    vector<vector<pair<int, int>>> data;//가중치 저장 자료구조 선언

    graph(int n) {
        data = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());//생성자 선언
    }
    void addedge(const city c1, const city c2, int g) {//인접리스트 노드 더하기 함수 
        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);
        data[n1].push_back({ n2,g });
        data[n2].push_back({ n1,g });
    }
    void removeedge(const city c1, const city c2) 
    {
        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);
        remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair) {return pair.first == n2});//알고리즘을 이용하여 인접리스트 제거함수 
        remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair) {return pair.first == n1});
    }
};
int main()
{
    
}

