#include "chap4_lifecycle.h"
#include <inttypes.h>
#include <cstdio>
#include <iostream>
#include <cstddef>


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

	//definition must be at lobal level and NOT inside a function
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

		myMath.change_pi();
		printf("MyMath::pi:%g\n", MyMath::pi);
		printf("myMath.pi: %g\n", myMath.pi);


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

		delete dptr1;
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
	}
}