#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main() {
	string filename = "enemy_list.csv";
	//�t�@�C�����͗p�X�g���[��ifs�𐶐�
	ifstream ifs(filename);
	
	//�G���[�`�F�b�N
	if (ifs.fail()) {
		//�t�@�C���̓ǂݍ��݂����s�����Ƃ�
		cout << "�t�@�C���I�[�v���G���[" << endl;
		return -1;	//�G���[�R�[�h:-1
	}

	string text;
	getline(ifs, text);//�t�@�C�������s�ǂݍ���
		istringstream iss(text);//������X�g���[��iss�𐶐�(�����ltext)
		getline(iss, text, ',');
		cout << text << endl;

	return 0;
}