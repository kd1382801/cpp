#include <list>
#include <iostream>

using namespace std;

int main() {
	list<int> li1{ 2,3,11,17 };
	list<int> li2{ 5,7,13,19 };

	//li1�̖�����li2�̃f�[�^�����ɒǉ�
	for (auto d : li2) {
		li1.push_back(d);
	}
	li1.sort();
	cout << "�A�����ʁF";
	for (auto d : li1) {
		cout << d << " ";
	}
	cout << endl;
}