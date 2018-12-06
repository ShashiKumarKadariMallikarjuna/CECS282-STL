//Shashi Kumar Kadari Mallikarjuna
//CECS 282
//Program 5- Standard Template Library
//Due:  11/27/2018

#ifndef BIGINT_H
#define BIGINT_H
#include <string>
#include <vector>
using namespace std;
class BigInt {
private:
	vector <int> v;
public:
	BigInt();
	BigInt(int);
	BigInt(string);
	BigInt operator+(BigInt);
	friend ostream & operator << (ostream &, const BigInt &);
};
#endif