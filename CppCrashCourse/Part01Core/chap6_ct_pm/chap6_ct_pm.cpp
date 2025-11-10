#include <iostream>
using namespace std;
namespace chap6_ct_pm {
	template <typename T> struct generic_array {
	public:
		generic_array(int s) : asize{ s }, x{ new T[s] } {

		}

		generic_array(int s, T init_val) : asize{ s }, x{ new T[s] } {
			for (size_t i = 0; i < asize; i++)
			{
				x[i] = init_val;
			}

		}

		void set(int ind, T val) {
			x[ind] = val;
		}

		void display() {
			for (size_t i = 0; i < asize; i++)
			{
				cout << i << ": " << x[i] << "\n";
			}
		}
	
	private:
		int asize;
		T* x;
	};

	template <typename T> struct unique_ptr {
		unique_ptr() = default;
		unique_ptr(T* ptr) : ptr{ ptr } {
			cout << "unique_ptr constructor\n";
		}
		unique_ptr(const unique_ptr&) = delete; //to avoid double delete interesting: no need to name the input parameter
		unique_ptr& operator=(const unique_ptr&) = delete;

		//move semantics
		unique_ptr(unique_ptr&& other) noexcept {
			ptr = other.ptr;
			other.ptr = nullptr;
		}
		unique_ptr& operator=(unique_ptr&& other) noexcept {
			if (ptr) delete ptr;
			ptr = other.ptr;
			other.ptr = nullptr;
			return *this;
		}

		~unique_ptr() {
			if (ptr) delete ptr;
			cout << "unique_ptr destructor\n";
		}

		T* get() {
			return ptr;
		}
	private:
		T* ptr;
	};

	struct Square {
		Square(double size) : size{ size } {}

		double get_size() {
			return size;
		}
		double area() {
			return size * size;
		}
	private:
		double size;
	};

	void square_consumer(unique_ptr<Square> square_ptr) {
		cout << "consumer parameter pointer value: " << square_ptr.get() << "\n";
		cout << "Size: " << square_ptr.get()->get_size() << "\n";
		cout << "Area: " << square_ptr.get()->area() << "\n";
	}

	void run() {
		cout << "chap6_ct_pm\n";

		cout << "templates\n";
		generic_array<double> ga{ 2 };

		ga.set(0, 3);
		ga.set(1, 3.3);
		ga.display();

		//template type deduction
		generic_array ga2 { 2, 1 };
		ga2.set(0, 3);
		ga2.display();

		cout << "named conversions\n";
		cout << "const_cast\n";
		int x1{ 2 };
		const int& y{ x1 };
		auto x2 = const_cast<int&>(y);  //!!!!!!!!!!!auto leads to a value variable not a refrence!
		auto& x3 = const_cast<int&>(y);
		x2++;
		cout << x1 << " " << y << " " << x2 << " "  << x3 << "\n";
		x3++;
		cout << x1 << " " << y << " " << x2 << " " << x3 << "\n";

		cout << "static_cast\n";
		short q = 2;
		void* w = &q;
		short* e = static_cast<short*>(w);
		*e = *e + 1;
		cout << q << " " << " " << *e << "\n";

		cout << "reinterpret_cast\n";
		char numbytes[4]{ 255,1,1,1 };  //16843263
		int* nump = reinterpret_cast<int*>(numbytes);
		*nump = *nump + 1;
		for (size_t i = 0; i < size(numbytes); i++)
		{
			cout << (int)numbytes[i] << " ";
		}
		cout << "\n";
		cout << *nump << "\n";   //16843264

		cout << "unique pointer\n";
		auto square_ptr_a = unique_ptr(new Square(2));
		cout << "square_ptr_a: " << square_ptr_a.get() << "\n";
		square_consumer(std::move(square_ptr_a));
		cout << "square_ptr_a: " << square_ptr_a.get() << "\n";
	}
}