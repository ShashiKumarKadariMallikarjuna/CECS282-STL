//Shashi Kumar Kadari Mallikarjuna
//CECS 282
//Program 5- Standard Template Library
//Due:  11/27/2018

#include "BigInt.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//constructor
BigInt::BigInt()
{
	v.push_back(0);
}

//Overloaded constructor which takes in int
BigInt::BigInt(int num)
{
	if (num == 0) {
		v.push_back(0);
	}
	while (num / 10 > 1) {
		v.push_back(num % 10);
		num = num / 10;
	}
	v.push_back(num);
}

//Overloaded constructor which takes in string of numbers
BigInt::BigInt(string num)
{
	int c = 0;
	for (int i=num.length()-1;i>=0;i--)
	{
		c = num.at(i) - '0';
		v.push_back(c);
	}
}

//Overloaded operators

//cout
ostream & operator<<(ostream & out,const BigInt & num)
{
	vector<int> temp=num.v;
	vector<int>::reverse_iterator itr;
	for (itr = temp.rbegin(); itr != temp.rend(); itr++) {
		out << *itr;
	}
	return out;
}


//operator +
BigInt 	BigInt::operator+(BigInt num) {
	BigInt temp(*this);
	while (num.v.size() != temp.v.size()) {
		if (num.v.size() > temp.v.size()) {
			temp.v.push_back(0);
		}
		else {
			num.v.push_back(0);
		}
	}
	int carry = 0;
	for (int i = 0; i < temp.v.size(); i++) {
		if (carry == 1) {
			carry = 0;
			temp.v[i] += 1;
		}
		if (temp.v[i] + num.v[i] >= 10) {
			carry = 1;
		}
		temp.v[i] += num.v[i] - carry * 10;
	}
	if (carry == 1) {
		temp.v.push_back(1);
	}
	return temp;
}



