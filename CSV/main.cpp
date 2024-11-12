#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

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

	string text;
	getline(ifs, text);//ファイルから一行読み込む
		istringstream iss(text);//文字列ストリームissを生成(初期値text)
		getline(iss, text, ',');
		cout << text << endl;

	return 0;
}