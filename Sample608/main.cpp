#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, int> score{};

	score["Tom"] = 100;
	score["Bob"] = 80;
	score["Mike"] = 76;

	score["Tom"] = 90;//"Tom"に90が上書きされる

	//要素を追加
	score.insert(make_pair("John", 88));
	score.emplace("David", 70);

	auto itr = score.find("John");
	//firstメンバがキー,secondメンバーが値を表す
	cout << itr->first << "の点数は" << itr->second << endl;

	//要素を削除
	score.erase("Mike");

	cout << "Tomの点数:" << score["Tom"] << endl;
	cout << "Bobの点数:" << score["Bob"] << endl;
	
	//count() : Mikeがあれば1,なければ0が返る
	if (score.count("Mike")) {
		cout << "Mikeの点数:" << score["Mike"] << endl;
	}

	return 0;
}