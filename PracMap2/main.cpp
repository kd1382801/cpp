#include<iostream>
#include<map>
#include<random>

using namespace std;

int main() {
	//pP๊ฬa๓ฦp๓ฬyA๐dicษi[
	map<string, string>dic{ {"ฎ","activity"},
							{"ตอC","atmosphere"},
							{"t","blood"},
							{"ยซ","environment"},
							{"ทx","temperature"}};

	auto itr = dic.begin();//ๆชvfฬCe[^๐ๆพ
	for (const auto& d : dic) {
		cout << d.first << endl;
	}

	return 0;
}