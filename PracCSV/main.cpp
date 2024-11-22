#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Weapon {
public:

	Weapon() = default;
	Weapon(string name, int atk, int price, int weight) : m_name(name), m_atk(atk), m_price(price), m_weight(weight) {};
	~Weapon() = default;

	string GetName() { return m_name; }
	int GetAtk() { return m_atk; }
	int GetPrice() { return m_price; }
	int GetWeight() { return m_weight; }
private:

	string m_name;
	int m_atk, m_price, m_weight;
};

int main() {
	//�t�@�C���X�g���[���𐶐�
	ifstream ifs("weapon_list.csv");
	
	//�G���[�`�F�b�N
	if (ifs.fail()) {
		cout << "�t�@�C���I�[�v���G���[" << endl;
		return -1;
	}

	vector<Weapon*> vWpn{};//Weapon�N���X�̔z��
	vector<string> vec{};//CSV�̊e���ڂ��ꎞ�I�Ɋi�[����z��
	string text;
	getline(ifs, text);//��s�ڂ�ǂݎ̂Ă�
	while (getline(ifs, text)) {
		istringstream iss(text);
		while (getline(iss, text, ',')) {
			//�����������ڂ�vec�Ɋi�[
			vec.push_back(text);
		}
		//CSV�𕪊���������(vec)��Weapon�N���X�̈����Ƃ��ăR���X�g���N�^���Ăяo���A�C���X�^���X�𐶐�
		//VWpn�ɂ͐������ꂽ�C���X�^���X�̃A�h���X���i�[�����
		vWpn.push_back(new Weapon(vec[0], stoi(vec[1]), stoi(vec[2]), stoi(vec[3])));
		//�ꎞ�I�ɕۑ����Ă������e���폜(�v�f����0)
		vec.clear();
	}
	ifs.close();

	//����ꗗ�̕\��
	for (int i = 0; i < vWpn.size(); i++) {
		cout << i << ":" << left << setw(10) << vWpn[i]->GetName();
		if (vWpn[i]->GetPrice() >= 0) {
			cout << right << setw(8) << vWpn[i]->GetPrice() << "G" << endl;
		}
		else {
			cout << right << setw(9) << "-�񔄕i-" << endl;
		}
	}

	//����w��
	int d;
	cout << "�ǂ̕�����w�����܂���?>";
	cin >> d;
	//���͂��ꂽ�l�����탊�X�g�̑I�������ɂ��邩�ǂ���
	if (d >= 0 && d < vWpn.size()) {
		//�񔄕i���ۂ��̃`�F�b�N
		if (vWpn[d]->GetPrice() < 0) {
			cout << "�񔄕i�̂��ߍw���ł��܂���!" << endl;
		}
		else {
			cout << vWpn[d]->GetName() << "���w������" << endl;
			cout << "�U���͂�" << vWpn[d]->GetAtk() << "�A�b�v����" << endl;
			cout << "�d�ʂ�" << vWpn[d]->GetWeight() << "������" << endl;
		}
	}
	else {
		cout << "�������ԍ�����͂��Ă�������" << endl;
	}
	return 0;
}