#include <list>
#include <iostream>

using namespace std;

int main() {
	list<int> li1{ 2,3,11,17 };
	list<int> li2{ 5,7,13,19 };

	//li1の末尾にli2のデータを順に追加
	for (auto d : li2) {
		li1.push_back(d);
	}
	li1.sort();
	cout << "連結結果：";
	for (auto d : li1) {
		cout << d << " ";
	}
	cout << endl;
}