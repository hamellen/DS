// iterator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<string>winner = { "해밀턴","해밀턴","루즈버그","베텔","해밀턴","베텔","베텔","알로소" };//벡터 초기화
    auto it = winner.begin();//반복자 생성
    cout << "최근우승자:" << *it << endl;
    it += 3;
    cout << "3년전 우승자" << *it << endl;
    return 0;
}

