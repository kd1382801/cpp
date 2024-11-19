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
	//ファイルストリームを生成
	ifstream ifs("weapon_list.csv");
	
	//エラーチェック
	if (ifs.fail()) {
		cout << "ファイルオープンエラー" << endl;
		return -1;
	}

	string text;
	getline(ifs, text);//一行目を読み捨てる
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