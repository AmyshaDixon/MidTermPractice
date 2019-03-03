/* Author: Amy Dixon, Ken Meerdink
* Date: 02.11.2019
* Purpose: This program in MidtermExam.cpp
*				 utlizes 4 practice functions that make calculations, alter string content, and
*				  modify vectors.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void harmonicMeans();
void capEs(string& s);
int binaryToDecimal(const int& a);
void removeConsecutiveDuplicates(vector<int>& v);


int main() {
#pragma region Problem 1 Tests
	harmonicMeans();
	cout << endl;
#pragma endregion

#pragma region Problem 2 Tests
	string testString1 = "Hello Ernie!";
	cout << testString1 << " with cap Es: ";
	capEs(testString1);
	cout << testString1 << endl;

	testString1 = "Eeeee Eee Eeee";
	cout << testString1 << " with cap Es: ";
	capEs(testString1);
	cout << testString1 << endl << endl;
#pragma endregion

#pragma region Problem 3 Tests
	int n = 101100; // 44
	cout << n << " in binary: " << binaryToDecimal(n) << endl;
	n = 1000; // 8
	cout << n << " in binary: " << binaryToDecimal(n) << endl << endl;
#pragma endregion

#pragma region Problem 4 Tests
	vector<int> v{ 1, 2, 2, 3, 2, 2, 3 };
	cout << "before removeConsecutiveDuplicates: ";
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << ' ';
	}
	removeConsecutiveDuplicates(v);
	cout << endl << "after removeConsecutiveDuplicates:  ";
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << ' ';
	} 
	cout << endl;

	vector<int> w{ 11, 11, 11, 44, 44, 0, 29, 33, 33, 33, 33, 33 };
	cout << "before removeConsecutiveDuplicates: ";
	for (int i = 0; i < w.size(); ++i) {
		cout << w[i] << ' ';
	}
	removeConsecutiveDuplicates(w);
	cout << endl << "after removeConsecutiveDuplicates:  ";
	for (int i = 0; i < w.size(); ++i) {
		cout << w[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
#pragma endregion
}

void harmonicMeans() {
	int a = 0;
	int b = 0;

	cout << "Enter two integer values: ";
	cin >> a;
	cin >> b;

	while (a != 0 && b != 0) {
		cout << "The harmonic mean of " << a << " and " << b << " is " << 2.0 * a* b / (a + b) << endl;

		cout << "Enter two integer values: ";
		cin >> a;
		cin >> b;
	}
}

void capEs(string& s) {
	for (char& letter : s) {
		if (letter == 'e') {
			letter = 'E';
		}
	}
}

int binaryToDecimal(const int& a) {
	int b = a; // Making copy
	int base2 = 1;
	int decim = 0;

	while (b > 0) {		
		decim += (b % 10) * base2;
		base2 *= 2;

		// Get rid of last digit
		b = b / 10;
	}

	return decim;
}

void removeConsecutiveDuplicates(vector<int>& v) {
	for (int i = 0; i < v.size() - 1; ++i) {
		if (v[i] == v[i + 1]) {
			v.erase(v.begin() + i);

			i--;
		}
	}
}
