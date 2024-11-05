#include<iostream>
#include<map>
#include<random>

using namespace std;

int main() {
	//英単語の和訳と英訳のペアをdicに格納
	map<string, string>dic{ {"活動","activity"},
							{"雰囲気","atmosphere"},
							{"血液","blood"},
							{"環境","environment"},
							{"温度","temperature"}};

	auto itr = dic.begin();//先頭要素のイテレータを取得
	for (const auto& d : dic) {
		cout << d.first << endl;
	}

	return 0;
}