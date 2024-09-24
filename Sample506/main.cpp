#include<iostream>
#include<string>
#include"bird.h"
#include"chicken.h"
#include"crow.h"

using namespace std;

int main() {
	Bird* pBird1{}, * pBird2{};	//•Ï”{} : ‰Šú’lnullptr
	
	pBird1 = new Crow();
	pBird2 = new Chicken();

	pBird1->fly();
	pBird2->fly();

	pBird1->sing();
	pBird2->sing();

	delete pBird1;
	delete pBird2;
	return 0;
}