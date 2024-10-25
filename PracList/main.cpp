#include <list>
#include <iostream>

using namespace std;

int main() {
	//�u���b�N(�u���b�N���̕ϐ��̓u���b�N���ł����g���Ȃ�)
	//li1�̖�����li2�̃f�[�^�����ɒǉ�������@
	{
		list<int> li1{ 2,3,11,17 };
		list<int> li2{ 5,7,13,19 };

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
	//li2�̐擪��li1�̖����f�[�^���珇�ɒǉ�������@
	{
		list<int> li1{ 2,3,11,17 };
		list<int> li2{ 5,7,13,19 };

		/*//�t���ɂ���
		li1.reverse();//li1���t���ɂ���
		for (auto d:li1) {
			li2.push_front(d);
		}*/

		//�t�C�e���[�^�[���g��(����rbegin()����擪rend()�܂ł̃��[�v)
		for (auto itr = li1.rbegin(); itr != li1.rend(); itr++) {
			li2.push_front(*itr);
		}

		li2.sort();
		cout << "�A�����ʁF";
		for (auto d : li2) {
			cout << d << " ";
		}
		cout << endl;
	}
	//merge�֐����g�������@
	{
		list<int> li1{ 2,3,11,17 };
		list<int> li2{ 5,7,13,19 };

		//li1��li2�𓝍�����(li2�̓��e�͏�����)
		li1.merge(li2);//merge()���g���Ǝ����I�ɏ����\�[�g�����
		cout << "�A�����ʁF";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << "li2�̗v�f��:" << li2.size() << endl;
	}
	//insert�֐����g�������@
	{
		list<int> li1{ 2,3,11,17 };
		list<int> li2{ 5,7,13,19 };

		//li1�̖�����li2�̐擪���疖���܂ł�}������(li2�̓��e�͂��̂܂܎c��)
		li1.insert(li1.end(), li2.begin(), li2.end());//�����\�[�g�͂���Ȃ�
		li1.sort();
		cout << "�A�����ʁF";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << "li2�̗v�f��:" << li2.size() << endl;
	}
	//splice�֐����g�������@
	{
		list<int> li1{ 2,3,11,17 };
		list<int> li2{ 5,7,13,19 };

		//li1�̖�����li2��}������(li2�̓��e�͏�����)
		li1.splice(li1.end(), li2);//�����\�[�g�͂���Ȃ�
		li1.sort();
		cout << "�A�����ʁF";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << "li2�̗v�f��:" << li2.size() << endl;
	}
}