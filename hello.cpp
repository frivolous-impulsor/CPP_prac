#include <typeindex>
#include <iostream>
#include <string>
#include <string_view>
#include <algorithm> // for std::max
#include <cmath>     // for std::abs

void getNameAge(){
	std::cout << "enter full name: ";
	std::string name {};
	std::getline(std::cin>>std::ws, name);

	std::cout << "enter fav color:";
	std::string color {};
	std::getline(std::cin>>std::ws, color);

	int len {static_cast<int>(color.length())};

	std::cout<<"your name is "<<name<<" you like "<< color<< " which is "<<len<< " characters long";
}

void string_view(){
	//make sure the string object being viewed upon is not modified, 
	//other wise undefined due to memory manipulation
	std::string s {"hello"};
	std::string_view v {s};
	v.remove_prefix(1);
	std::string new_s {static_cast<std::string>(v)};
	std::cout<<new_s;
}

int squre_and_mult(int base, int exp){
	if(base == 0){
		if(exp == 0){
			return 1;
		}else{
			return 0;
		}
	}
	int result {1};
	while(exp > 0){
		if(exp & 1){
			result *= base;
		}
		base *=base;
		exp /=2;
	}
	return result;
}

bool approxEqual(double a, double b, double relEps){
	return (std::abs(a -b) <= (std::max(std::abs(a), std::abs(b)))*relEps);
}

std::bitset<4> rotl(std::bitset<4> bits)
{
	if(bits.test(3)){
		bits = bits << 1;
		bits.set(0);
	}else{
		bits = bits << 1;
	}
	return bits;
}


void bitOperation(){
	std::uint8_t x {0b001001};
	x = x<<3;
    std::cout << std::bitset<8>(x) << '\n';
}

void reference(){
	//type& is reference type, making ref_x an alias of x. This is NOT address pointer
	int x {5};
	int& ref_x {x};
	std::cout << "x: "<<x<<" ref_x: "<< ref_x<<'\n';
	x = 9;
	std::cout << "x: "<<x<<" ref_x: "<< ref_x<<'\n';
	ref_x = 7;
	std::cout << "x: "<<x<<" ref_x: "<< ref_x<<'\n';

	//a non-const reference can only refer another non-const var
	const int y {10};
	const int& ref_y {y};
	std::cout << "y: "<<y<<" ref_y: "<< ref_y<<'\n';

}

void nullPointer(){
	//int x {5};
	int* ptr {};
	{
		int x {10};
		ptr = &x;
	}
	std::cout<< ((ptr == nullptr)? "is null" : "is not null");
	std::cout<< *ptr;
}

void passByReference(std::string& ref_x){
	std::cout<<ref_x;
}

void printByConstRef(const int& ref_x){
	std::cout<<"ref_x: "<<ref_x<<'\n';
	std::cout<<"address of ref_x: "<<&ref_x<<'\n';
}

int main()
{
	int c {8};
	std::cout<<"address of c: "<<&c<<'\n';
	const int cc {9};
	std::cout<<"address of cc: "<<&cc<<'\n';
	printByConstRef(c);
	printByConstRef(cc);
	printByConstRef(77);

	return 0;
}