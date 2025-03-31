#include "chap2_types.h"
#include <inttypes.h>
#include <cstdio>
#include <iostream>
#include <cstddef>

namespace chap2_types
{
	void run()
	{
		printf("This is chapter 2: Types\n");

		//integers
		auto x{ 1000llu };
		printf("%llu\n", x);

		int8_t y = 23;
		printf("%d\n", y);

		double z = 2.34e-22;
		printf("%lg\n", z);


		//characters
		char str1[]{'T', 'e', 's', 't', '1', '\n', '\0'};
		printf(str1);

		std::u8string str2 = u8"تست 2";

		char str3[] = "Test3\n";
		printf(str3);

		wchar_t str4[] = L"Test4\n";
		std::wcout << str4;

		char16_t str5[] = u"Test5\n";

		char c1 = 'ش'; //Wrong!
		char16_t c2 = u'ش';
		char32_t c3 = U'ش';
		wchar_t c4 = L'ش';

		char pi1 = '\u03C0'; // Wrong! Unicode for π (U+03C0)
		char16_t pi2 = u'\u03C0'; // Unicode for π (U+03C0)
		char32_t pi3 = U'\U000003C0'; // Unicode for π (U+03C0)
		wchar_t pi4 = L'\U000003C0'; // Unicode for π (U+03C0)

		wchar_t str6[]{ L'ت' , L'س' ,L'ت' ,L'\n', L'\0' };
		wchar_t str7[]{ L"تست" };
		wchar_t str8[] = L"تست";
		char str9[] = "تست";  //wrong!
		char32_t str10[] = U"تست";
		wchar_t str11[]{ L"Test_WCOUT" };

		std::wcout << str6;  //does not print anything!
		std::wcout << str7;  //does not print anything!
		std::wcout << str11;
		std::wcout << "...\n" << std::endl;


		//boolean
		bool b1 = 3 > 4 ? false : true && 3 == 3;
		//printf("%d", b1);

		//byte
		std::byte sb{ 23 };
		printf("%x\n", std::to_integer<int>(sb));


		//size
		printf("size of short: %zd\n", sizeof(short));
		printf("size of float: %zx\n", sizeof(float));
		printf("size of int: %hu\n", sizeof(int));
		printf("size of long: %hd\n", sizeof(long));
		printf("size of long long: %llu\n", sizeof(long long));
		printf("size of byte: %lld\n", sizeof(std::byte));
		printf("size of b1: %u\n", sizeof(b1));


		//arrays
		int array1[4] = { 1, 2, 3, 4 };
		int array2[20] = { 1, 2, 3, 4 };
		int array3[]{ 1, 2, 3, 4 };
	}
}