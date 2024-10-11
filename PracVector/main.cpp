#include <iostream>
#include <vector>

using namespace std;

void compare(int& max, int& min, int data) {
	if (data > max) {
		max = data;
	}
	if (data < min) {
		min = data;
	}
}

int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;

	//�Y�����̔ԍ����g�������[�v
	max = vec[0];
	min = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		compare(max, min, vec[i]);
	}
	cout << "�ő�l:" << max << " " << "�ŏ��l:" << min << endl;

	vec.push_back(0);

	//�C�e���[�^���g�������[�v
	max = min = vec.at(0);//vec[0]�Ɠ���
	for (auto itr = vec.begin() + 1; itr != vec.end(); ++itr) {
		compare(max, min, *itr);
	}
	cout << "�ő�l:" << max << " " << "�ŏ��l:" << min << endl;

	vec.push_back(100);

	//�͈�for���g�������[�v
	max = min = vec.front();//vec�̐擪�v�f���擾
	for (auto i : vec) {
		compare(max, min, i);
	}
	cout << "�ő�l:" << max << " " << "�ŏ��l:" << min << endl;

	return 0;
}