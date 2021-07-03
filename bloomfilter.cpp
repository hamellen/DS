

#include <iostream>
#include <vector>
using namespace std;

class bloom 
{
	vector<bool> bloom1;
	int bits;

	int hash(int num, int key) {
		switch (num)
		{
		case 0:
			return key % bits;
		case 1:
			return (key / 7) % bits;
		case 2:
			return (key / 11) % bits;
		}
		return 0;
	}

public:
	bloom(int n):bits(n) 
	{
		bloom1 = vector<bool>(n,false);
	}
	void lookup(int key) 
	{
		bool result = bloom1[hash(0, key)] & bloom1[hash(1, key)] & bloom1[hash(2, key)];

		if (result) {
			cout << "값이 존재할수 있음" << endl;

		}
		else
			cout << "값이 존재하지 않음" << endl;
	}
	
	void insert(int key) 
	{
		bloom1[hash(0, key)] = true;
		bloom1[hash(1, key)] = true;
		bloom1[hash(2, key)] = true;

		for (const auto& a : bloom1) {
			cout << a << " ";
		}
	}
};




int main()
{
   
}

