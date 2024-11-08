#include<iostream>
#include<map>
#include<random>

using namespace std;

int main() {
	//�p�P��̘a��Ɖp��̃y�A��dic�Ɋi�[
	map<string, string>dic{ {"����","activity"},
							{"���͋C","atmosphere"},
							{"���t","blood"},
							{"��","environment"},
							{"���x","temperature"}};

	auto itr = dic.begin();//�擪�v�f�̃C�e���[�^���擾
	cout << itr->first << endl;

	//�͈�for
	for (const auto d : dic) {
		cout << d.first << endl;
	}

	//������������쐬
	random_device rand_dev{};
	//�����A���S���Y���Ƀ����Z���k�c�C�X�^�[���w��
	mt19937 rand_engine(rand_dev());
	//0�`(map�̗v�f��)-1���ϓ��Ȋm���œ��镪�z��������쐬
	uniform_int_distribution<int> dist(0, dic.size() - 1);

	//cout << dist(rand_engine) << endl;

	itr = dic.begin();
	itr = next(itr, dist(rand_engine));//std::next(�C�e���[�^,�i�߂��)
	cout << itr->first << "�̉p�P���?>" << endl;
	string str;
	cin >> str;
	if (str == itr->second) {
		cout << "����!" << endl;
	}
	else {
		cout << "�s�����c" << endl;
	}


	return 0;
}