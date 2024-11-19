#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Weapon {
public:

	Weapon() = default;
	Weapon(string name, int atk, int price, int weight) : m_name(name), m_atk(atk), m_price(price), m_weight(weight) {};
	~Weapon() = default;

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

	string text;
	getline(ifs, text);//��s�ڂ�ǂݎ̂Ă�
	while (getline(ifs, text)) {
		istringstream iss(text);
		while (getline(iss, text, ',')) {
			cout << text << " ";
		}
		cout << endl;
	}
	ifs.close();

	return 0;
}