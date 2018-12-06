//Shashi Kumar Kadari Mallikarjuna
//CECS 282
//Program 5- Standard Template Library
//Due:  11/27/2018

#include <iostream>
#include <map>
#include "BigInt.h"
#include <chrono>

using namespace std;
BigInt GoldRabbits(int);
int fact(int);

int main() {
	auto start = chrono::steady_clock::now();
	for (int n = 0; n <= 1000; n++) {
		cout << "\n The GoldRabbit of (" << n << ") is " << GoldRabbits(n)<<endl;
	}
	auto end = chrono::steady_clock::now();
	cout << "\nElapsed time in seconds : "
		<< chrono::duration_cast<chrono::seconds>(end - start).count()
		<< " sec";
	system("pause");
	system("cls");
	for (int i = 0; i < 100; i++) {
		try {
			cout << "Fact(" << i << "):" << fact(i) << endl;
		}
		catch (...) {
			cout << "Fact(" << i << "):" << "Overflow" << endl;
		}
	}
	cout << endl;
	getchar();
	getchar();
}

//Recursion 
BigInt GoldRabbits(int x) {
	static map <int, BigInt>farm;
	if (farm.find(x) == farm.end())
		farm[x] = farm[x - 1] + farm[x - 2];
	if (x == 0 || x == 1)
		farm[x] = BigInt(1);
	return farm[x];
}

//fact function
int fact(int x) {
	if (x > 12)
		throw "Exception";
	if (x == 0)
		return 1;
	else
		return x * fact(x - 1);
}
