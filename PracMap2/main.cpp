#include<iostream>
#include<map>
#include<random>

using namespace std;

int main() {
	//�p�P��̘a��Ɖp��̃y�A��dic�Ɋi�[
	map<string, string>dic{ {"����","activity"},
							{"���͋C","atmosphere"},
							{"���t","blood"},
							{"��","environment"},
							{"���x","temperature"}};

	auto itr = dic.begin();//�擪�v�f�̃C�e���[�^���擾
	for (const auto& d : dic) {
		cout << d.first << endl;
	}

	return 0;
}