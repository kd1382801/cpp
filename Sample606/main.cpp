#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> li{ 5,8,2 };

	li.push_back(1);
	li.push_back(2);
	li.push_front(3);
	
	list<int>::iterator itr;
	itr = li.begin();
	itr++;
	li.insert(itr, 4);
	li.sort();//昇順に並び替え
	li.unique();//重複したデータを削除
	li.remove(3);//値が3のデータをリストから削除
	li.reverse();//データ列を逆転
	for (auto d : li) {
		cout << d << " ";
	}
	cout << endl;
	return 0;
}