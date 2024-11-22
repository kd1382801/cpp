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
	//ファイルストリームを生成
	ifstream ifs("weapon_list.csv");
	
	//エラーチェック
	if (ifs.fail()) {
		cout << "ファイルオープンエラー" << endl;
		return -1;
	}

	vector<Weapon*> vWpn{};//Weaponクラスの配列
	vector<string> vec{};//CSVの各項目を一時的に格納する配列
	string text;
	getline(ifs, text);//一行目を読み捨てる
	while (getline(ifs, text)) {
		istringstream iss(text);
		while (getline(iss, text, ',')) {
			//分割した項目をvecに格納
			vec.push_back(text);
		}
		//CSVを分割した項目(vec)をWeaponクラスの引数としてコンストラクタを呼び出し、インスタンスを生成
		//VWpnには生成されたインスタンスのアドレスが格納される
		vWpn.push_back(new Weapon(vec[0], stoi(vec[1]), stoi(vec[2]), stoi(vec[3])));
		//一時的に保存していた内容を削除(要素数は0)
		vec.clear();
	}
	ifs.close();

	//武器一覧の表示
	for (int i = 0; i < vWpn.size(); i++) {
		cout << i << ":" << left << setw(10) << vWpn[i]->GetName();
		if (vWpn[i]->GetPrice() >= 0) {
			cout << right << setw(8) << vWpn[i]->GetPrice() << "G" << endl;
		}
		else {
			cout << right << setw(9) << "-非売品-" << endl;
		}
	}

	//武器購入
	int d;
	cout << "どの武器を購入しますか?>";
	cin >> d;
	//入力された値が武器リストの選択肢内にあるかどうか
	if (d >= 0 && d < vWpn.size()) {
		//非売品か否かのチェック
		if (vWpn[d]->GetPrice() < 0) {
			cout << "非売品のため購入できません!" << endl;
		}
		else {
			cout << vWpn[d]->GetName() << "を購入した" << endl;
			cout << "攻撃力が" << vWpn[d]->GetAtk() << "アップした" << endl;
			cout << "重量が" << vWpn[d]->GetWeight() << "増えた" << endl;
		}
	}
	else {
		cout << "正しい番号を入力してください" << endl;
	}
	return 0;
}