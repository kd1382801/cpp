#include <iostream>
#include <vector>

using namespace std;

//�Q�Ɠn��
void compare(int& max, int& min, const int& data) {
	/*if (data > max) {
		max = data;
	}
	if (data < min) {
		min = data;
	}*/

	//�������Z�q���g����������
	max = data > max ? data : max;
	min = data < min ? data : min;
	
}

int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;

	//���[�v���g��Ȃ�
	cout << "max_element,min_element" << endl;
	max = *max_element(vec.begin(), vec.end());//�߂�l:�ő�l�̃C�e���[�^
	min = *min_element(vec.begin(), vec.end());
	cout << "�ő�l:" << max << " " << "�ŏ��l:" << min << endl;

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