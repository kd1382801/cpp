#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

class Enemy {
private:
	string m_name;
	int m_hp, m_atk, m_def;

public:
	Enemy() = default;
	Enemy(string name, int hp, int atk, int def) :m_name(name), m_hp(hp), m_atk(atk), m_def(def) {};
	~Enemy() = default;

	string GetName() { return m_name; }
	int	GetHp() { return m_hp; }
	int	GetAtk() { return m_atk; }
	int	GetDef() { return m_def; }
};

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

	//Vector�̓񎟌��z����g�p
	/*vector<vector<string>> vEne{};
	int j = 0;				//�s�ԍ����Ǘ�����ϐ�
	string text;

	while (getline(ifs, text)) {		//�t�@�C�������s�ǂݍ���
		istringstream iss(text);		//������X�g���[��iss�𐶐�(�����ltext)
		vEne.resize(j + 1);				//vEne��1�s���̃f�[�^�̈���m��
		while (getline(iss, text, ',')) {
			vEne[j].push_back(text);	//�z��Ɋe���ڂ��i�[
		}
		j++;
	}
	//�t�@�C���N���[�Y
	ifs.close();

	for (int i = 0; i < vEne.size(); i++) {
		for (int j = 0; j < vEne[0].size(); j++) {
			cout << vEne[i][j] << "\t";
		}
		cout << endl;
	}
	*/

	//Enemy�N���X���g�p
	vector<Enemy*> vEne{};	//Enemy�N���X�̔z��
	vector<string> v{};		//CSV�̊e���ڂ��ꎞ�I�ۑ�����z��
	string text;

	while (getline(ifs, text)) {		//�t�@�C�������s�ǂݍ���
		istringstream iss(text);		//������X�g���[��iss�𐶐�(�����ltext)
		while (getline(iss, text, ',')) {
			v.push_back(text);	//�z��Ɋe���ڂ��ꎞ�I�Ɋi�[
		}
		//�z��v�̊e�v�f��Enemy�̃R���X�g���N�^�̈����ɂ��ăC���X�^���X�𐶐� *stoi()�͕�����𐮐��ɕϊ�
		vEne.push_back(new Enemy(v[0], stoi(v[1]), stoi(v[2]), stoi(v[3])));
		//�z��v�̑S�v�f���폜(v�̗v�f��:0)
		v.clear();
	}
	//�t�@�C���N���[�Y
	ifs.close();

	for (auto p : vEne) {
		cout << p->GetName() << "\t" 
			 << p->GetHp() << "\t" 
			 << p->GetAtk() << "\t" 
			 << p->GetDef() << endl;
	}

	//�o�̓t�@�C���X�g���[���̐���
	ofstream ofs("enemy_list2.csv", ios::out);

	//�G���[�`�F�b�N
	if (!ofs) {
		cout << "�t�@�C���I�[�v���G���[" << endl;
		return -1;
	}
	//�t�@�C����������
	ofs << "test" << "," << 100 << "," << 20 << endl;
	//�t�@�C���N���[�Y
	ofs.close();

	ofs.open("enemy_list.csv", ios::app);
	ofs << "Rat,50,5,2" << endl;
	ofs.close();

	return 0;
}