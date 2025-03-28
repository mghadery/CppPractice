// Part01Core.cpp : Defines the entry point for the application.
//

#include "Part01Core.h"
using namespace std;

template <typename T>
constexpr int int_square(T num)
{
	return (int)(num * num);
}


int main()
{
	const auto lang = "Cpp";

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(1, 10000);
	auto rnd = dis(gen);

	constexpr int offset = int_square(5.5);
	auto luck = offset + (int)ceil(rnd);

	printf("Give me your name please:");

	char name[100];
	scanf("%99s", name);

	printf("Hello %s. Welcome to %s World!. Your number is %d! Good luck!\n", name, lang, luck);
	
	return 0;
}
