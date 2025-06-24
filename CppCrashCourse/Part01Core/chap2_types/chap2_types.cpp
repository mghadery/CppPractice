#include "chap2_types.h"
#include <inttypes.h>
#include <cstdio>
#include <iostream>
#include <cstddef>

namespace chap2_types
{
	struct Person {
		char firstname[100];
		char lastname[100];

		Person()
		{
			firstname[0] = 0;
			lastname[0] = 0;
		}

		Person(const char* first, const char* last) {
			std::strcpy(firstname, first);
			std::strcpy(lastname, last);
		}
	};


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


		//characters and strings
		const char* s = "old سstyle\n";
		printf(s);
		char str1[]{ 'T', 'e', 's', 't', '1', '\n', '\0' };
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
		char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";

		wprintf(str6);

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

		printf("Size of array: %zd\n", sizeof(array3) / sizeof(int));
		printf("Size of array with std::size: %zd\n", std::size(array3));

		//structs
		Person person1 = Person("aa", "bb");
		Person person2("cc", "dd");
		Person person3{ "ee", "ff" };
		Person persons[]{ person1 , person2 , person3, {"hh", "jj"} };
		for (Person person : persons)
		{
			printf("First name: %s, Last name: %s\n", person.firstname, person.lastname);
		}
		printf("person2 = person1;\n");
		person2 = person1;
		//array does not change. It means it contains the copies
		for (Person person : persons)
		{
			printf("First name: %s, Last name: %s\n", person.firstname, person.lastname);
		}
		printf("persons[0] = person1;\n");
		persons[0] = person1;
		persons[1] = person2;
		persons[2] = person3;
		for (Person person : persons)
		{
			printf("First name: %s, Last name: %s\n", person.firstname, person.lastname);
		}

		printf("person2.firstname[0] = 'z';\n");
		person2.firstname[0] = 'z';
		printf("First name: %s, Last name: %s\n", person1.firstname, person1.lastname);
		printf("First name: %s, Last name: %s\n", person2.firstname, person2.lastname);

		char s1[] = "qwe";
		char s2[] = "asd";
		Person person4(s1, s2);
		printf("First name: %s, Last name: %s\n", person4.firstname, person4.lastname);

		Person person5;

		int a(0);
		int b();  //a function prototype
		int c{};
		printf("c:%d\n", c);
		int d = {};
		printf("d:%d\n", d);
		int e;
		try
		{
			//printf("e:%d\n", e);  //it is not an exception! as there is no throw!
		}
		catch (const std::exception& e)
		{
			printf("Exception: %s\n", e.what());
		}
		catch (...)
		{
			printf("Ooops\n");
		}
	}
}