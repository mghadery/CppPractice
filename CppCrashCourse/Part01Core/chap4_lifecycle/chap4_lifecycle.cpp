#include "chap4_lifecycle.h"
#include <inttypes.h>
#include <cstdio>
#include <iostream>
#include <cstddef>
#include <vector>


//Both static and extern variables live for the entire lifetime of the program,
// from the time they are created (program start) to when they are destroyed (program termination).
namespace chap4_lifecycle
{
	struct MyMath
	{
		//error: it must be const int to be initialized here
		//static float pi = 3.14;

		//error: it must be const int to be initialized here
		//static const float piii = 3.14;

		static float pi;

		static int y;

		//integral const types are exceptions
		static const int pi_rounded = 3;

		float zzz = 1.2;

		const int x = 1;

		void change_pi()
		{
			pi = 3.141;
		}

		static void change_pi_s()
		{
			pi = 3.1415;
		}
	};

	struct NamedStruct
	{
		NamedStruct(const char *name):name(name)
		{
			printf("%s was constructed\n", name);
		}

		~NamedStruct()
		{
			printf("%s was destructed\n", name);
		}

	private:
		const char* const name;
	};

	struct ExpTest
	{
		ExpTest(const char* name) :name(name)
		{
			printf("%s was constructed\n", name);
			throw std::runtime_error{"constructor exeption"};
			p = new char[100];
		}

		~ExpTest()
		{
			printf("%s was destructed\n", name);
			delete[] p;
		}

	private:
		const char* const name;
		char* p;
	};


	struct SimpleString {
		SimpleString(size_t max_size)
			: max_size{ max_size },
			length{} {
			printf("SimpleString constructor\n");
			if (max_size == 0) {
				throw std::runtime_error{ "Max size must be at least 1." };
			}
			buffer = new char[max_size];
			buffer[0] = 0;
		}
		SimpleString(const SimpleString& other)
			:max_size{ other.max_size },
			length{ other.length },
			buffer{ new char[other.max_size] }
		{
			strncpy(buffer, other.buffer, other.max_size);
		}

		~SimpleString() {
			printf("SimpleString destructor\n");
			delete[] buffer; //it can lead to errors when the object is copied and the first object constructor is called
		}

		void print(const char *s)
		{
			printf("%s%s\n", s, buffer);
		}

		bool append_line(const char* x) {
			const auto x_len = strlen(x);
			if (x_len + length + 2 > max_size) return false;
			std::strncpy(buffer + length, x, max_size - length);
			length += x_len;
			buffer[length++] = '\n';
			buffer[length] = 0;
			return true;
		}
	private:
		size_t max_size;
		char* buffer;
		size_t length;
	};

	//RAII concept:
	//resources are allocated in constructor
	//resources are released in destructor
	//On error exception is thrown
	//after exception stack unwinding occurs and all resources in inner functions are released
	struct SimpleStringOwner {
		SimpleStringOwner(const char* x)
			: string{ 10 } {
			if (!string.append_line(x)) {
				throw std::runtime_error{ "Not enough memory!" };
			}
			string.print("Constructed: ");
		}
		~SimpleStringOwner() {
			string.print("About to destroy: ");
		}
	private:
		SimpleString string;
	};


	struct SimpleStringOwner2 {
		SimpleStringOwner2(const char* x)
			: string{ 10 } {
			isValid = string.append_line(x);
			string.print("Constructed: ");
		}
		~SimpleStringOwner2() {
			string.print("About to destroy: ");
		}
		bool IsValid() {
			return isValid;
		}
	private:
		SimpleString string;
		bool isValid;
	};

	struct Owner2Result {
		SimpleStringOwner2 Sto;
		bool Result;
	};

	//It is problematic because of copying SimpleString object and potential destructing the first one on exit
	//Either a copy constructor must be defined or cleanup is done manually outside destructor.
	Owner2Result makeOwner2() {
		//SimpleStringOwner2 sto{ "01234567890x" };
		SimpleStringOwner2 sto{ "x" };
		return Owner2Result{ sto, sto.IsValid() };
	}

	//DANGEROUS: If copy optimization does not occur, x buffer is released on return
	SimpleString GiveStr() {
		SimpleString x{ 10 };
		x.append_line("test");
		return x;
	}

	//definition must be at global level and NOT inside a function
	int MyMath::y = 4;
	float MyMath::pi = 3.14;

	//Both static and extern variables live for the entire lifetime of the program, 
	// from the time they are created(program start) to when they are destroyed(program termination).	
	
	//internal linkage
	//Static storage duration
	static int z1{ 2 };

	//external linkage
	//Static storage duration
	extern int z{ 33 };

	void run()
	{
		printf("This is chap4: lifecycle\n");

		//must be defined in the global level first to work
		MyMath::y = 5;
		MyMath::pi = 3.14;
		printf("MyMath::pi:%g\n", MyMath::pi);

		MyMath myMath;
		MyMath myMath2;
		printf("myMath.pi: %g\n", myMath.pi);

		printf("myMath.change_pi();\n");
		myMath.change_pi();
		printf("MyMath::pi:%g\n", MyMath::pi);
		printf("myMath.pi: %g\n", myMath.pi);

		printf("MyMath::change_pi_s();\n");
		MyMath::change_pi_s();
		printf("MyMath::pi:%g\n", MyMath::pi);
		printf("myMath.pi: %g\n", myMath.pi);
		printf("myMath2.pi: %g\n", myMath2.pi);

		printf("dynamic storage duration");
		int* dptr1 = new int{ 4 };
		printf("after allocation: %d\n", *dptr1);
		delete dptr1;
		printf("after deallocation: %d\n", *dptr1);

		printf("dynamic array\n");
		dptr1 = new int[4] {1};
		printf("after array allocation: %d\n", *dptr1);

		delete[] dptr1;
		printf("after deallocation: %d\n", *dptr1);

		printf("Exception handling\n");


		try
		{
			NamedStruct namedStruct1 = NamedStruct{ "local NamedStruct" };  //when exception occurs, its destructor is called automatically
			NamedStruct* namedStruct2 = new NamedStruct{ "dynamic NamedStruct" };  //when exception occurs, its destructor is NOT called automatically
			throw std::runtime_error{"This is a pretty exception\n"};
		}
		catch (const std::runtime_error& exp)
		{
			printf("Exception ocuured: %s\n", exp.what());
		}

		try
		{
			ExpTest exp1 = ExpTest{ "local ExpTest" };  //as the exception occurs in the constructor, the destructor won't be invoked
		}
		catch (const std::runtime_error& exp)
		{
			printf("Exception ocuured: %s\n", exp.what());
		}

		try
		{
			char x = 222;
			char y = 2 * x; //no exception!
			char z = x;			
		}
		catch (const std::overflow_error& exp)
		{
			printf("Exception ocuured: %s\n", exp.what());
		}

		try
		{
			int x[]{ 1, 2 };
			printf("arry out of range\n");
			printf("x[0]: %d\n", x[0]);
			printf("x[1]: %d\n", x[1]);
			printf("x[2]: %d\n", x[2]); //no exception!

			printf("vector out of range\n");

			std::vector<int> v{ 1, 2 };
			printf("v[0]: %d\n", v.at(0));
			printf("v[1]: %d\n", v.at(1));
			
			//printf("v[2]: %d\n", v[2]);    //no exception but crash!

			printf("v[2]: %d\n", v.at(2)); //exception!

		}
		catch (const std:: out_of_range exp)
		{
			printf("Exception ocuured: %s\n", exp.what());
		}

		try
		{
			throw std::exception("General exception\n");
		}
		catch (...)
		{
			printf("Unknown error...\n");
		}

		printf("SimpleStringOwner sto{ 'x' }\n");
		try {
			SimpleStringOwner sto{ "x" };
		}
		catch (const std::exception& exp) {
			printf("exp: %s\n", exp.what());
		}

		printf("SimpleStringOwner sto{ '01234567890x' }\n");
		try {
			SimpleStringOwner sto{ "01234567890x" }; //~SimpleStringOwner does not execute but ~SimpleString executes
		}
		catch (const std::exception& exp) {
			printf("exp: %s\n", exp.what());
		}

		auto y = GiveStr();

		printf("Crash:\n");
		//the following leads to crash because of double deleting buffer
		//first delete after the copy
		//second delete on exiting out of run() 
		//auto [sto, result] = makeOwner2();
		//if (result)
		//	printf("owner2 created\n");
		//else
		//	printf("owner2 failed to create\n");


		printf("Copy constructor");
		SimpleString ss1{ 100 };
		ss1.append_line("First line");
		auto ss2{ ss1 };
		ss2.append_line("Second line");
		ss1.print("ss1:");
		ss2.print("ss2:");

		printf("End\n");

	}
}