#include "chap3_references.h"
#include "linked_list.h"
#include <inttypes.h>
#include <cstdio>
#include <iostream>
#include <cstddef>
#include <format>

using namespace std;

namespace chap3_references
{
	struct Clock
	{
	private:
		int hour{};
		int min{};

	public:
		Clock() {}
		//using this ponter
		Clock(int hour) :sec{ 0 }
		{
			this->hour = hour;
		}
		//using member initializer list
		Clock(int hour, int min, int sec) :hour{ hour }, min{ min }, sec{ sec } {}
		//const method
		std::string get_time() const
		{
			auto s = format("{:02}:{:02}:{:02}", hour, min, sec);
			return s;
		}
	private:
		//note when we have const operator= is implicitly deleted!
		//we have added const here to see what happens!
		const int sec{};

	public:
		Clock& operator=(const Clock& otherClock)
		{
			hour = otherClock.hour;
			min = otherClock.min;
			//error
			//sec = otherClock.sec;
			return *this;
		}

		void printHello();
	};

	void Clock::printHello()
	{
		cout << "Hello" << endl;
	}

	//to show when an argument is const only its const methods can be invoked
	void printClock(const Clock& clock)
	{
		cout << clock.get_time() << endl;
	}

	//char* parameter
	void testCharP(char* name)
	{
		//the original argument is changed too
		name[0] = 's';
	}

	void run()
	{
		printf("This is chap3 references\n");

		//references
		int x = 2;
		int y = 3;
		int& z = x;

		z = y; //it is not reseated only the value is copied

		printf("%d\n", x);
		printf("%d\n", y);
		printf("%d\n", z);

		auto clock = Clock{};
		printClock(clock);

		clock = Clock{14};
		printClock(clock);

		//note we have overloaded operator= and now sec is not copied!
		clock = Clock{ 1,2,3 };
		printClock(clock);

		Clock clock2{ 1,2,3 };

		clock2.printHello();

		char name[]{ "test" };
		testCharP(name);
		cout << name << "\n" << endl;

		//error const cha* to char * conversion
		//char* p{ "test" };

		//auto
		auto answer = 2ll;
		auto answerP{ &answer };
		auto* answerP2{ &answer };
		
		//Error
		//auto qq{ 1,2 };

		int rr[]{ 1,2 };
		
		//std::initializer_list
		auto autoList = { 1, 2 };

		//linked list
		linked_list::LinkedNode<int> node1{ 1 };
		linked_list::LinkedNode<int> node2{ 2 };
		linked_list::LinkedNode<int> node3{ 3 };

		node1.InsertAfter(&node3);
		node3.InsertBefore(&node2);

		for (linked_list::LinkedNode<int>* node = &node1; node; node = node->Next())
		{
			auto data = node->GetData();
			cout << data << endl;
		}
	}
}