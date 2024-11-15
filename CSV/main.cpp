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
	//ファイル入力用ストリームifsを生成
	ifstream ifs(filename);
	
	//エラーチェック
	if (ifs.fail()) {
		//ファイルの読み込みが失敗したとき
		cout << "ファイルオープンエラー" << endl;
		return -1;	//エラーコード:-1
	}

	//Vectorの二次元配列を使用
	/*vector<vector<string>> vEne{};
	int j = 0;				//行番号を管理する変数
	string text;

	while (getline(ifs, text)) {		//ファイルから一行読み込む
		istringstream iss(text);		//文字列ストリームissを生成(初期値text)
		vEne.resize(j + 1);				//vEneに1行分のデータ領域を確保
		while (getline(iss, text, ',')) {
			vEne[j].push_back(text);	//配列に各項目を格納
		}
		j++;
	}
	//ファイルクローズ
	ifs.close();

	for (int i = 0; i < vEne.size(); i++) {
		for (int j = 0; j < vEne[0].size(); j++) {
			cout << vEne[i][j] << "\t";
		}
		cout << endl;
	}
	*/

	//Enemyクラスを使用
	vector<Enemy*> vEne{};	//Enemyクラスの配列
	vector<string> v{};		//CSVの各項目を一時的保存する配列
	string text;

	while (getline(ifs, text)) {		//ファイルから一行読み込む
		istringstream iss(text);		//文字列ストリームissを生成(初期値text)
		while (getline(iss, text, ',')) {
			v.push_back(text);	//配列に各項目を一時的に格納
		}
		//配列vの各要素をEnemyのコンストラクタの引数にしてインスタンスを生成 *stoi()は文字列を整数に変換
		vEne.push_back(new Enemy(v[0], stoi(v[1]), stoi(v[2]), stoi(v[3])));
		//配列vの全要素を削除(vの要素数:0)
		v.clear();
	}
	//ファイルクローズ
	ifs.close();

	for (auto p : vEne) {
		cout << p->GetName() << "\t" 
			 << p->GetHp() << "\t" 
			 << p->GetAtk() << "\t" 
			 << p->GetDef() << endl;
	}

	//出力ファイルストリームの生成
	ofstream ofs("enemy_list2.csv", ios::out);

	//エラーチェック
	if (!ofs) {
		cout << "ファイルオープンエラー" << endl;
		return -1;
	}
	//ファイル書き込み
	ofs << "test" << "," << 100 << "," << 20 << endl;
	//ファイルクローズ
	ofs.close();

	ofs.open("enemy_list.csv", ios::app);
	ofs << "Rat,50,5,2" << endl;
	ofs.close();

	return 0;
}