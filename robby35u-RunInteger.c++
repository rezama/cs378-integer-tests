// -------------------------------:// projects/integer/RunInteger.c++
// Copyright (C) 2012
// Glenn P. Downing
// -------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl, ios_base
#include <deque>    // deque
#include <cstdlib>
#include <cmath>
#include "Integer.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);         // turn off synchronization with C I/O
    cout << "RunInteger.c++" << endl << endl;

    // less than 300 ms without valgrind
    // less than  15  s with    valgrind
    cout << "*** 20th Mersenne prime: 1,332 digits ***" << endl << endl;

    {
    const Integer<int> n = Integer<int>(2).pow(4423) - 1;
    cout << "2^4423 - 1 = " << n << endl << endl;
    }

    {
    const Integer< int, std::deque<int> > n = Integer< int, std::deque<int> >(2).pow(4423) - 1;
    cout << "2^4423 - 1 = " << n << endl << endl;
    }

    // --------------------------
    // extra credit (5 bonus pts)
    // --------------------------

    // less than 4 min without valgrind
    // don't run with valgrind
    cout << "*** 30th Mersenne prime: 39,751 digits ***" << endl << endl;

    {
    const Integer<int> n = Integer<int>(2).pow(132049) - 1;
    cout << "2^132049 - 1 = " << n << endl << endl;
    }
    
    cout << "*************My tests*************" << endl;
    cout << boolalpha;
    const int num_iters = 10;
    cout << "equals...." << endl;
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
        int right = rand() % 101 - 50; 
        bool out = left == right;
        Integer<int> l(left);
        Integer<int> r(right);
        bool o = l == r;
	cout << (bool)(o == out) << endl;}

    cout << "not equals...." << endl;	 
    for(int i = 0; i < num_iters; ++i){	 
    	int left = rand() % 101 - 50; 
    	int right = rand() % 101 - 50; 
	bool out = left != right;
    	Integer<int> l(left);
    	Integer<int> r(right);
    	bool o = l != r;
    	cout << (bool)(o == out) << endl;}

    cout << "less than...." << endl;
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
        int right = rand() % 101 - 50; 
        bool out = left < right;
        Integer<int> l(left);
        Integer<int> r(right);
        bool o = l < r;
	cout << (bool)(o == out) << endl;}
 
    cout << "less than equals...." << endl;	 
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
        int right = rand() % 101 - 50; 
        bool out = left <= right;
        Integer<int> l(left);
        Integer<int> r(right);
        bool o = l <= r;
	cout << (bool)(o == out) << endl;};

    cout << "greater than...." << endl;	 
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
        int right = rand() % 101 - 50; 
        bool out = left > right;
        Integer<int> l(left);
        Integer<int> r(right);
        bool o = l > r;
	cout << (bool)(o == out) << endl;}
 
    cout << "greater than equals...." << endl;
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
        int right = rand() % 101 - 50; 
        bool out = left >= right;
        Integer<int> l(left);
        Integer<int> r(right);
        bool o = l >= r;
	cout << (bool)(o == out) << endl;}
 
    cout << "times...." << endl;	 
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
        int right = rand() % 101 - 50; 
	int out = left * right;
        Integer<int> l(left);
        Integer<int> r(right);
        Integer<int> o = l * r;
	cout << (bool)(o == out) << endl;}

    cout << "left shift...." << endl;
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
        int right = rand() % 101; 
        int out = left << right;
        Integer<int> l(left);
        Integer<int>  o = l << right;
	cout << (bool)(o == out) << endl;}
  
    cout << "right shift...." << endl;
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
        int right = rand() % 101; 
        int out = left >> right;
        Integer<int> l(left);
        Integer<int>  o = l >> right;
	cout << (bool)(o == out) << endl;}
 
    cout << "output...." << endl;
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
	stringstream out;
	out << left;
        Integer<int> l(left);
        stringstream o;
	l.toString(o);
	cout << (bool)(o == out) << endl;}
 
    cout << "abs...." << endl;
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
        int out = abs(left);
        Integer<int> l(left);
        Integer<int> o = l.abs();
	cout << (bool)(o == out) << endl;}
 
    cout << "pow...." << endl;
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
        int right = rand() % 101 + (!left); 
        long out = std::pow(left,right);
        Integer<int> l(left);
        Integer<int> o = l.pow(right);
	cout << (bool)(o == out) << endl;}
    cout << "post increment...." << endl;
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
        Integer<int> l(left);
	int out = left++;
        Integer<int> o = l++;
	cout << (bool)(o == out && left == l) << endl;}

   cout << "pre decrement...." << endl;
    for(int i = 0; i < num_iters; ++i) {
        int left = rand() % 101 - 50; 
        Integer<int> l(left);
	int out = --left;
        Integer<int> o = --l;
	cout << (bool)(o == out && left == l) << endl;}

    cout << "post decrement...." << endl;
    for(int i = 0; i < num_iters; ++i){
        int left = rand() % 101 - 50; 
        Integer<int> l(left);
	int out = left--;
        Integer<int> o = l--;
	cout << (bool)(o == out && left == l) << endl;}

    cout << "negates...." << endl;
    for(int i = 0; i < num_iters; ++i){
        int left = rand() % 101 - 50; 
        int out = -left;
        Integer<int> l(left);
        Integer<int> o = l;
	cout << (bool)(o == out) << endl;}


    cout << "plus equals...." << endl;	 
    for(int i = 0; i < num_iters; ++i){ 
        int left = rand() % 101 - 50; 
        int right = rand() % 101 - 50; 
        bool out = left += right;
        Integer<int> l(left);
        Integer<int> r(right);
        Integer<int> o = l += r;
	cout << (bool)(o == out) << endl;}
 
    cout << "minus equals...." << endl;	 
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
        int right = rand() % 101 - 50; 
        bool out = left -= right;
        Integer<int> l(left);
        Integer<int> r(right);
        Integer<int> o = l -= r;
	cout << (bool)(o == out) << endl;}
 
    cout << "times equals...." << endl;	 
    for(int i = 0; i < num_iters; ++i){	 
        int left = rand() % 101 - 50; 
        int right = rand() % 101 - 50; 
        bool out = left *= right;
        Integer<int> l(left);
        Integer<int> r(right);
        Integer<int> o = l *= r;
	cout << (bool)(o == out) << endl;}

    cout << "Done." << endl;

    return 0;}
