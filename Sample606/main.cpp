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
	li.sort();//�����ɕ��ёւ�
	li.unique();//�d�������f�[�^���폜
	li.remove(3);//�l��3�̃f�[�^�����X�g����폜
	li.reverse();//�f�[�^����t�]
	for (auto d : li) {
		cout << d << " ";
	}
	cout << endl;
	return 0;
}