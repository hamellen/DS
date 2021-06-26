
#include <iostream>
#include <unordered_map>//key,value 저장
#include<unordered_set>//key 저장
using namespace std;

void print(const unordered_set<int>& container) {
	for (const auto& element : container)
		cout << element << ' ';
}
void print(const unordered_map<int,int>& container) {

	for (const auto& element : container)
		cout << element.second<<" "<< element.first << ' ';
}
void find(const unordered_set<int>& container, int value) {
	if (container.find(value) != container.end())
		cout << "검색 성공" << endl;
	else
		cout << "검색실패" << endl;
}
void find(const unordered_map<int,int>& container, int value) {
	if (container.find(value) != container.end())
		cout << "검색 성공" << endl;
	else
		cout << "검색실패" << endl;
}
int main()
{
   
}

