// --------------------------------
// projects/integer/TestInteger.c++
// Copyright (C) 2012
// Glenn P. Downing
// --------------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    HelperMacros.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -ansi -pedantic -lcppunit -ldl -Wall TestInteger.c++ -o TestInteger.c++.app
    % valgrind TestInteger.c++.app >& TestInteger.out
*/

// --------
// includes
// --------

#include <algorithm> // equal
#include <cstring>   // strcmp
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==
#include <vector>
#include <deque>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TestSuite.h"               // TestSuite
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Integer.h"

using namespace std;

// --------
// typedefs
// --------

typedef vector<int> VI;
typedef deque<int> DI;


// -----------
// TestInteger
// -----------

struct TestInteger : CppUnit::TestFixture {
    
    // -----------------
    // shift_left_digits
    // -----------------

    void test_shift_left_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {2, 3, 4, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}
  
    void test_shift_left_digits_1 () {
        VI a; 
        a.push_back(2);
        a.push_back(3);
 	a.push_back(4);
	VI b;
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(0);
	b.push_back(0);
        int x[10];
        const int* p = shift_left_digits(a.begin(), a.end(), 2, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b.begin()));}

    void test_shift_left_digits_2 () {
        DI a; 
        a.push_back(2);
        a.push_back(3);
 	a.push_back(4);
	DI b;
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(0);
	b.push_back(0);
        int x[10];
        const int* p = shift_left_digits(a.begin(), a.end(), 2, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b.begin()));}

    void test_shift_left_digits_3 () {
        const int a[] = {2, 3, 4};
        const int b[] = {2, 3, 4};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 0, x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}
 
    // ------------------
    // shift_right_digits
    // ------------------

    void test_shift_right_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {2};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_right_digits_1 () {
        VI a; 
        a.push_back(2);
        a.push_back(3);
 	a.push_back(4);
	VI b;
	b.push_back(2);
        int x[10];
        const int* p = shift_right_digits(a.begin(), a.end(), 2, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b.begin()));}
 
    void test_shift_right_digits_2 () {
        DI a; 
        a.push_back(2);
        a.push_back(3);
 	a.push_back(4);
	DI b;
	b.push_back(2);
        int x[10];
        const int* p = shift_right_digits(a.begin(), a.end(), 2, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b.begin()));}
 
 
    void test_shift_right_digits_3 () {
        const int a[] = {2, 3, 4};
        const int b[] = {2, 3, 4};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 0, x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    // -----------
    // plus_digits
    // -----------

    void test_plus_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {8, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

     void test_plus_digits_1 () {
        VI a; 
        a.push_back(2);
        a.push_back(3);
 	a.push_back(4);
	VI b;
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
        VI c;
	c.push_back(8);
	c.push_back(0);
 	c.push_back(1);
        int x[10];
        const int* p = plus_digits(a.begin(), a.end(), b.begin(), b.end(), x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c.begin()));}

    void test_plus_digits_2 () {
        DI a; 
        a.push_back(2);
        a.push_back(3);
 	a.push_back(4);
	DI b;
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
        DI c;
	c.push_back(8);
	c.push_back(0);
 	c.push_back(1);
        int x[10];
        const int* p = plus_digits(a.begin(), a.end(), b.begin(), b.end(), x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c.begin()));}

    void test_plus_digits_3 () {
        const int a[] = {1, 2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 8, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 4, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_4 () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7, 8};
        const int c[] = {5, 9, 1, 2};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 4, x);
        CPPUNIT_ASSERT((p - x) == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_5 () {
        const int a[] = {9, 9, 9, 9};
        const int b[] = {1};
        const int c[] = {1, 0, 0, 0, 0};
              int x[10];
        const int* p = plus_digits(a, a + 4, b, b + 1, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // ------------
    // minus_digits
    // ------------

    void test_minus_digits () {
        const int a[] = {8, 0, 1};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 4};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_1 () {
        VI a; 
        a.push_back(8);
        a.push_back(0);
 	a.push_back(1);
	VI b;
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
        VI c;
	c.push_back(2);
	c.push_back(3);
 	c.push_back(4);
        int x[10];
        const int* p = minus_digits(a.begin(), a.end(), b.begin(), b.end(), x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c.begin()));}

    void test_minus_digits_2 () {
        DI a; 
        a.push_back(8);
        a.push_back(0);
 	a.push_back(1);
	DI b;
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
        DI c;
	c.push_back(2);
	c.push_back(3);
 	c.push_back(4);
        int x[10];
        const int* p = minus_digits(a.begin(), a.end(), b.begin(), b.end(), x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c.begin()));}

    void test_minus_digits_3 () {
        const int a[] = {1, 8, 0, 1};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 2, 3, 4};
              int x[10];
        const int* p = minus_digits(a, a + 4, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_4 () {
        const int a[] = {9, 8, 7, 6, 5};
        const int b[] = {9, 8, 7, 2, 0};
        const int c[] = {4, 5};
              int x[10];
        const int* p = minus_digits(a, a + 5, b, b + 5, x);
        CPPUNIT_ASSERT((p - x) == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_5 () {
        const int a[] = {1, 0, 0, 0, 0};
        const int b[] = {1};
        const int c[] = {9, 9, 9, 9};
              int x[10];
        const int* p = minus_digits(a, a + 5, b, b + 1, x);
        CPPUNIT_ASSERT((p - x) == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

 

    // -----------------
    // multiplies_digits
    // -----------------

    void test_multiplies_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 3, 2, 6, 7, 8};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_1 () {
        VI a; 
        a.push_back(2);
        a.push_back(3);
 	a.push_back(4);
	VI b;
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
        VI c;
	c.push_back(1);
	c.push_back(3);
 	c.push_back(2);
	c.push_back(6);
	c.push_back(7);
	c.push_back(8);
        int x[10];
        const int* p = multiplies_digits(a.begin(), a.end(), b.begin(), b.end(), x);
        CPPUNIT_ASSERT((p - x) == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c.begin()));}

    void test_multiplies_digits_2 () {
        DI a;
        a.push_back(2);
        a.push_back(3);
 	a.push_back(4);
	DI b;
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
        DI c; 
	c.push_back(1);
	c.push_back(3);
 	c.push_back(2);
	c.push_back(6);
	c.push_back(7);
	c.push_back(8);
        int x[10];
        const int* p = multiplies_digits(a.begin(), a.end(), b.begin(), b.end(), x);
        CPPUNIT_ASSERT((p - x) == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c.begin()));}

    void test_multiplies_digits_3 () {
        const int a[] = {1, 8, 0, 1};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 0, 2, 1, 1, 6, 7};
              int x[10];
        const int* p = multiplies_digits(a, a + 4, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 7);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_4 () {
        const int a[] = {9, 1, 2};
        const int b[] = {5, 6, 7, 8};
        const int c[] = {5, 1, 7, 8, 3, 3, 6};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 4, x);
        CPPUNIT_ASSERT((p - x) == 7);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_5 () {
        const int a[] = {1, 0, 0, 0, 0};
        const int b[] = {1};
        const int c[] = {1, 0, 0, 0, 0};
              int x[10];
        const int* p = multiplies_digits(a, a + 5, b, b + 1, x);
	for(int i = 0; i < 10; ++i) 
	     cout << x[i];
	cout << endl;
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}



    // --------------
    // divides_digits
    // --------------

    void test_divides_digits () {
        const int a[] = {1, 3, 2, 6, 7, 8};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 4};
              int x[10];
        const int* p = divides_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_1 () {
        VI a; 
        a.push_back(1);
        a.push_back(3);
 	a.push_back(2);
        a.push_back(6);
        a.push_back(7);
        a.push_back(8);
	VI b;
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
        VI c;
	c.push_back(2);
	c.push_back(3);
 	c.push_back(4);
        int x[10];
        const int* p = divides_digits(a.begin(), a.end(), b.begin(), b.end(), x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c.begin()));}

    void test_divides_digits_2 () {
        DI a;
        a.push_back(1);
        a.push_back(3);
 	a.push_back(2);
	a.push_back(6);
	a.push_back(7);
	a.push_back(8);
	DI b;
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
        DI c; 
	c.push_back(2);
	c.push_back(3);
 	c.push_back(4);
        int x[10];
        const int* p = divides_digits(a.begin(), a.end(), b.begin(), b.end(), x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c.begin()));}

    void test_divides_digits_3 () {
        const int a[] = {1, 0, 2, 1, 1, 6, 7};
        const int b[] = {1, 8, 0, 1};
        const int c[] = {5, 6, 7};
              int x[10];
        const int* p = divides_digits(a, a + 7, b, b + 4, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_4 () {
        const int a[] = {9, 1, 2};
        const int b[] = {5, 6, 7, 8};
        const int c[] = {0};
              int x[10];
        const int* p = divides_digits(a, a + 3, b, b + 4, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_5 () {
        const int a[] = {1, 0, 0, 0, 0};
        const int b[] = {1};
        const int c[] = {1, 0, 0, 0, 0};
              int x[10];
        const int* p = divides_digits(a, a + 5, b, b + 1, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}



    // -----------
    // string constructor
    // -----------

    void test_string_constructor_1 () {
        try {
            const Integer<int> x("abc");
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));}}

    void test_string_constructor_2 () {
        try {
            const Integer<int> x("2");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_string_constructor_3 () {
        try {
            const Integer<int> x("-2");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_string_constructor_4 () {
        try {
            const Integer<int> x("-");
	    CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));}}

    void test_string_constructor_5 () {
        try {
            const Integer<int> x("");
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));}}

    void test_string_constructor_6 () {
        try {
            const Integer<int> x("-0");
	    const Integer<int> y = 0;
	    CPPUNIT_ASSERT(x == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
 
    // -----------
    // int constructor
    // -----------

    void test_int_constructor_1 () {
        try {
            const Integer<int> x(2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_int_constructor_2 () {
        try {
            const Integer<int> x(-2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
 
    void test_int_constructor_3 () {
        try {
            const Integer<int> x(0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
  
    void test_int_constructor_4 () {
        try {
            const Integer<int> x(-0);
	    const Integer<int> y = 0;
	    CPPUNIT_ASSERT(x == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
         
    void test_int_constructor_5 () {
        try {
            long v = 18273409182734L;
            const Integer<int> x(v);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
 
    // ---------
    // less_than
    // ---------

    void test_less_than_1 () {
	try {
 	    Integer<int> x = 100;
	    Integer<int> y = 1000;
	    CPPUNIT_ASSERT(x < y);}
	catch (std::invalid_argument& e) {
	    CPPUNIT_ASSERT(false);}}    

    void test_less_than_2 () {
	try {
 	    Integer<int> x = 1000;
	    Integer<int> y = 100;
	    CPPUNIT_ASSERT(!(x < y));}
	catch (std::invalid_argument& e) {
	    CPPUNIT_ASSERT(false);}}    


    void test_less_than_3 () {
	try {
 	    Integer<int> x = 100;
	    Integer<int> y = 100;
	    CPPUNIT_ASSERT(!(x < y));}
	catch (std::invalid_argument& e) {
	    CPPUNIT_ASSERT(false);}}    


    void test_less_than_4 () {
	try {
 	    Integer<int> x = -100;
	    Integer<int> y = 1000;
	    CPPUNIT_ASSERT(x < y);}
	catch (std::invalid_argument& e) {
	    CPPUNIT_ASSERT(false);}}    


    void test_less_than_5 () {
	try {
 	    Integer<int> x = 100;
	    Integer<int> y = -1000;
	    CPPUNIT_ASSERT(!(x < y));}
	catch (std::invalid_argument& e) {
	    CPPUNIT_ASSERT(false);}}    

    void test_less_than_6 () {
	try {
 	    Integer<int> x = 0;
	    Integer<int> y = 1000;
	    CPPUNIT_ASSERT(x < y);}
	catch (std::invalid_argument& e) {
	    CPPUNIT_ASSERT(false);}}    

    void test_less_than_7 () {
	try {
 	    Integer<int> x = -100;
	    Integer<int> y = 0;
	    CPPUNIT_ASSERT(x < y);}
	catch (std::invalid_argument& e) {
	    CPPUNIT_ASSERT(false);}}    


    void test_less_than_8 () {
	try {
 	    Integer<int> x = -100;
	    Integer<int> y = -1000;
	    CPPUNIT_ASSERT(!(x < y));}
	catch (std::invalid_argument& e) {
	    CPPUNIT_ASSERT(false);}}    


    void test_less_than_9 () {
	try {
 	    Integer<int> x = -1000;
	    Integer<int> y = -100;
	    CPPUNIT_ASSERT(x < y);}
	catch (std::invalid_argument& e) {
	    CPPUNIT_ASSERT(false);}}    


    void test_less_than_10 () {
	try {
 	    Integer<int> x = 0;
	    Integer<int> y = 0;
	    CPPUNIT_ASSERT(!(x < y));}
	catch (std::invalid_argument& e) {
	    CPPUNIT_ASSERT(false);}}    

    // -----------
    // plus_equals
    // -----------

    void test_plus_equals_1 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y =  1234;
	    x += y;
            CPPUNIT_ASSERT(x ==  99999);
            CPPUNIT_ASSERT(y ==  1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_equals_2 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y = -1234;
	    x += y;
            CPPUNIT_ASSERT(x ==  97531);
            CPPUNIT_ASSERT(y ==  -1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_equals_3 () {
        try {
            Integer<int> x = -98765;
            Integer<int> y =  1234;
	    x += y;
            CPPUNIT_ASSERT(x == -97531);
            CPPUNIT_ASSERT(y ==  1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

     void test_plus_equals_4 () {
        try {
            Integer<int> x = -98765;
            Integer<int> y = -1234;
	    x += y;
            CPPUNIT_ASSERT(x ==  -99999);
            CPPUNIT_ASSERT(y ==  -1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_equals_5 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y = 0;
	    x += y;
            CPPUNIT_ASSERT(x ==  98765);
            CPPUNIT_ASSERT(y ==  0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
 
    // -----------
    // minus_equals
    // -----------

    void test_minus_equals_1 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y =  1234;
	    x -= y;
            CPPUNIT_ASSERT(x ==  97531);
            CPPUNIT_ASSERT(y ==  1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_equals_2 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y = -1234;
	    x -= y;
            CPPUNIT_ASSERT(x ==  99999);
            CPPUNIT_ASSERT(y ==  -1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_equals_3 () {
        try {
            Integer<int> x = -98765;
            Integer<int> y =  1234;
	    x -= y;
            CPPUNIT_ASSERT(x == -99999);
            CPPUNIT_ASSERT(y ==  1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

     void test_minus_equals_4 () {
        try {
            Integer<int> x = -98765;
            Integer<int> y = -1234;
	    x -= y;
            CPPUNIT_ASSERT(x ==  -97531);
            CPPUNIT_ASSERT(y ==  -1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_equals_5 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y = 0;
	    x -= y;
            CPPUNIT_ASSERT(x ==  98765);
            CPPUNIT_ASSERT(y ==  0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_equals_6 () {
        try {
            Integer<int> x = 0;
            Integer<int> y = 98765;
	    x -= y;
            CPPUNIT_ASSERT(x == -98765);
            CPPUNIT_ASSERT(y ==  98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ------------
    // times_equals
    // ------------

    void test_times_equals_1 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y =  1234;
	    x *= y;
            CPPUNIT_ASSERT(x ==  121876010);
            CPPUNIT_ASSERT(y ==  1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_times_equals_2 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y = -1234;
	    x *= y;
            CPPUNIT_ASSERT(x ==  -121876010);
            CPPUNIT_ASSERT(y ==  -1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_times_equals_3 () {
        try {
            Integer<int> x = -98765;
            Integer<int> y =  1234;
	    x *= y;
            CPPUNIT_ASSERT(x == -121876010);
            CPPUNIT_ASSERT(y ==  1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

     void test_times_equals_4 () {
        try {
            Integer<int> x = -98765;
            Integer<int> y = -1234;
	    x *= y;
            CPPUNIT_ASSERT(x ==  121876010);
            CPPUNIT_ASSERT(y ==  -1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_times_equals_5 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y = 0;
	    x *= y;
            CPPUNIT_ASSERT(x ==  0);
            CPPUNIT_ASSERT(y ==  0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
 
    // -------------
    // divide_equals
    // -------------

    void test_divide_equals_1 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y =  1234;
	    x /= y;
            CPPUNIT_ASSERT(x ==  80);
            CPPUNIT_ASSERT(y ==  1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_divide_equals_2 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y = -1234;
	    x /= y;
            CPPUNIT_ASSERT(x ==  -80);
            CPPUNIT_ASSERT(y ==  -1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_divide_equals_3 () {
        try {
            Integer<int> x = -98765;
            Integer<int> y =  1234;
	    x /= y;
            CPPUNIT_ASSERT(x == -80);
            CPPUNIT_ASSERT(y ==  1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

     void test_divide_equals_4 () {
        try {
            Integer<int> x = -98765;
            Integer<int> y = -1234;
	    x /= y;
            CPPUNIT_ASSERT(x ==  80);
            CPPUNIT_ASSERT(y ==  -1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_divide_equals_5 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y = 0;
	    x /= y;
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(true);}}

    void test_divide_equals_6 () {
        try {
            Integer<int> x = 0;
            Integer<int> y = 98765;
	    x /= y;
            CPPUNIT_ASSERT(x == 0);
            CPPUNIT_ASSERT(y == 98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ----------
    // mod_equals
    // ----------

    void test_mod_equals_1 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y =  1234;
	    x %= y;
            CPPUNIT_ASSERT(x == 45);
            CPPUNIT_ASSERT(y ==  1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_mod_equals_2 () {
        try {
            Integer<int> x = -98765;
            Integer<int> y =  1234;
	    x %= y;
            CPPUNIT_ASSERT(x == -45);
            CPPUNIT_ASSERT(y ==  1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_mod_equals_3 () {
        try {
            Integer<int> x = 0;
            Integer<int> y = 1234;
	    x %= y;
            CPPUNIT_ASSERT(x ==  0);
            CPPUNIT_ASSERT(y ==  1234);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_mod_equals_4 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y = 0;
	    x %= y;
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(true);}}


    void test_mod_equals_5 () {
        try {
            Integer<int> x = 98765;
            Integer<int> y = -5;
	    x %= y;
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(true);}}

    // -----------------
    // left_shift_equals
    // -----------------

    void test_left_shift_equals_1 () {
        try {
            Integer<int> x = 98765;
            int y =  1;
	    x <<= y;
            CPPUNIT_ASSERT(x ==  987650);
            CPPUNIT_ASSERT(y ==  1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_left_shift_equals_2 () {
        try {
            Integer<int> x = 98765;
            int y = 0;
	    x <<= y;
            CPPUNIT_ASSERT(x == 98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_left_shift_equals_3 () {
        try {
            Integer<int> x = 98765;
            int y =  -1;
	    x <<= y;
            CPPUNIT_ASSERT(x == 9876);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ------------------
    // right_shift_equals
    // ------------------

    void test_right_shift_equals_1 () {
        try {
            Integer<int> x = 98765;
            int y = 1;
	    x >>= y;
            CPPUNIT_ASSERT(x ==  9876);
            CPPUNIT_ASSERT(y ==  1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_right_shift_equals_2 () {
        try {
            Integer<int> x = 98765;
            int y = 0;
	    x >>= y;
            CPPUNIT_ASSERT(x == 98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_right_shift_equals_3 () {
        try {
            Integer<int> x = 98765;
            int y =  -1;
	    x >>= y;
            CPPUNIT_ASSERT(987650);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

     void test_right_shift_equals_4 () {
        try {
            Integer<int> x = 98765;
            int y = 5;
	    x >>= y;
            CPPUNIT_ASSERT(x ==  0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---
    // abs
    // ---

    void test_abs_1 () {
        try{ 
            Integer<int>  x = -98765;
            Integer<int>& y = x.abs();
            CPPUNIT_ASSERT( x == 98765);
            CPPUNIT_ASSERT(&x == &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_abs_2 () {
        try {
            const Integer<int> x = -98765;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == -98765);
            CPPUNIT_ASSERT(y ==  98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_abs_3 () {
        try {
            Integer<int>  x = 98765;
            x.abs();
            CPPUNIT_ASSERT( x == 98765); }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_abs_4 () {
        try {
            Integer<int> x = 0;
            x.abs();
            CPPUNIT_ASSERT(x == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_abs_5 () {
        try {
            Integer<int>  x = -0;
            x.abs();
            CPPUNIT_ASSERT(x == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --------
    // equal_to
    // --------

    void test_equal_to_1 () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = 98765;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == 98765);
            CPPUNIT_ASSERT(  98765 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != 98765));
            CPPUNIT_ASSERT(!(98765 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to_2 () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y("98765");
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == 98765);
            CPPUNIT_ASSERT(  98765 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != 98765));
            CPPUNIT_ASSERT(!(98765 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_equal_to_3 () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = -98765;
            CPPUNIT_ASSERT(      x != y);
            CPPUNIT_ASSERT(      x == 98765);
            CPPUNIT_ASSERT(  -98765 == y);
            CPPUNIT_ASSERT(    (x != y));
            CPPUNIT_ASSERT(    (x != -98765));
            CPPUNIT_ASSERT((98765 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to_4 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = -0;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == 0);
            CPPUNIT_ASSERT(  	 0 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}



    // --------
    // negation
    // --------

    void test_negation_1 () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == -98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_negation_2 () {
        try {
            const Integer<int> x = -98765;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == 98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_negation_3 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_negation_4 () {
        try {
            const Integer<int> x = -0;
            const Integer<int> y = -x;
	    CPPUNIT_ASSERT(x == 0);
            CPPUNIT_ASSERT(y == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ------
    // output
    // ------

    void test_output_1 () {
        try {
            const Integer<int> x = 98765;
            std::ostringstream out;
            out << x;
    	    CPPUNIT_ASSERT(out.str() == "98765");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_2 () {
        try {
            const Integer<int> x = -98765;
            std::ostringstream out;
            out << x;
    	    CPPUNIT_ASSERT(out.str() == "-98765");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_3 () {
        try {
            const Integer<int> x = 0;
            std::ostringstream out;
            out << x;
    	    CPPUNIT_ASSERT(out.str() == "0");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---
    // pow
    // ---

    void test_pow_1 () {
        try {
            Integer<int>       x = 98765;
            const int          e =  9867;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 9867);
            CPPUNIT_ASSERT( x ==    0);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 98765;
            const int          e =  9867;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 98765);
            CPPUNIT_ASSERT(e ==  9867);
            CPPUNIT_ASSERT(y ==     0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_3 () {
        try {
            Integer<int> x = 2;
            const int e =  2;
            x.pow(e);
  	    x.toString(cout);
	    cout << endl;
            CPPUNIT_ASSERT(x == 4);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_4 () {
        try {
            Integer<int> x = 2;
            const int e = 3;
	    x.pow(e);
  	    x.toString(cout);
	    cout << endl;
            CPPUNIT_ASSERT(x == 8);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_pow_5 () {
        try {
            Integer<int> x = 2;
            const int e =  25;
            x.pow(e);
            CPPUNIT_ASSERT(x == 33554432);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_6 () {
        try {
            Integer<int> x = 3;
	    Integer<int> y("515377520732011331036461129765621272702107522001");
            const int e = 100;
	    x.pow(e);
            CPPUNIT_ASSERT(x == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestInteger);
    CPPUNIT_TEST(test_shift_left_digits);
    CPPUNIT_TEST(test_shift_left_digits_1);
    CPPUNIT_TEST(test_shift_left_digits_2);
    CPPUNIT_TEST(test_shift_left_digits_3);
    CPPUNIT_TEST(test_shift_right_digits);
    CPPUNIT_TEST(test_shift_right_digits_1);
    CPPUNIT_TEST(test_shift_right_digits_2);
    CPPUNIT_TEST(test_shift_right_digits_3);
    CPPUNIT_TEST(test_plus_digits);
    CPPUNIT_TEST(test_plus_digits_1);
    CPPUNIT_TEST(test_plus_digits_2);
    CPPUNIT_TEST(test_plus_digits_3);
    CPPUNIT_TEST(test_plus_digits_4);
    CPPUNIT_TEST(test_plus_digits_5);
    CPPUNIT_TEST(test_minus_digits);
    CPPUNIT_TEST(test_minus_digits_1);
    CPPUNIT_TEST(test_minus_digits_2);
    CPPUNIT_TEST(test_minus_digits_3);
    CPPUNIT_TEST(test_minus_digits_4);
    CPPUNIT_TEST(test_minus_digits_5);
    CPPUNIT_TEST(test_multiplies_digits);
    CPPUNIT_TEST(test_multiplies_digits_1);
    CPPUNIT_TEST(test_multiplies_digits_2);
    CPPUNIT_TEST(test_multiplies_digits_3);
    CPPUNIT_TEST(test_multiplies_digits_4);
    CPPUNIT_TEST(test_multiplies_digits_5);
    CPPUNIT_TEST(test_divides_digits);
    CPPUNIT_TEST(test_divides_digits_1);
    CPPUNIT_TEST(test_divides_digits_2);
    CPPUNIT_TEST(test_divides_digits_3);
    CPPUNIT_TEST(test_divides_digits_4);
    CPPUNIT_TEST(test_divides_digits_5);
    CPPUNIT_TEST(test_string_constructor_1);
    CPPUNIT_TEST(test_string_constructor_2);
    CPPUNIT_TEST(test_string_constructor_3);
    CPPUNIT_TEST(test_string_constructor_4);
    CPPUNIT_TEST(test_string_constructor_5);
    CPPUNIT_TEST(test_string_constructor_6);
    CPPUNIT_TEST(test_int_constructor_1);
    CPPUNIT_TEST(test_int_constructor_2);
    CPPUNIT_TEST(test_int_constructor_3);
    CPPUNIT_TEST(test_int_constructor_4);
    CPPUNIT_TEST(test_int_constructor_5);
    CPPUNIT_TEST(test_less_than_1);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
    CPPUNIT_TEST(test_less_than_4);
    CPPUNIT_TEST(test_less_than_5);
    CPPUNIT_TEST(test_less_than_6);
    CPPUNIT_TEST(test_less_than_7);
    CPPUNIT_TEST(test_less_than_8);
    CPPUNIT_TEST(test_less_than_9);
    CPPUNIT_TEST(test_less_than_10); 
    CPPUNIT_TEST(test_equal_to_1);
    CPPUNIT_TEST(test_equal_to_2);
    CPPUNIT_TEST(test_equal_to_3);
    CPPUNIT_TEST(test_equal_to_4);
    CPPUNIT_TEST(test_plus_equals_1);
    CPPUNIT_TEST(test_plus_equals_2);
    CPPUNIT_TEST(test_plus_equals_3);
    CPPUNIT_TEST(test_plus_equals_4);
    CPPUNIT_TEST(test_plus_equals_5);
    CPPUNIT_TEST(test_minus_equals_1);
    CPPUNIT_TEST(test_minus_equals_2);
    CPPUNIT_TEST(test_minus_equals_3);
    CPPUNIT_TEST(test_minus_equals_4);
    CPPUNIT_TEST(test_minus_equals_5);
    CPPUNIT_TEST(test_minus_equals_6);
    CPPUNIT_TEST(test_times_equals_1);
    CPPUNIT_TEST(test_times_equals_2);
    CPPUNIT_TEST(test_times_equals_3);
    CPPUNIT_TEST(test_times_equals_4);
    CPPUNIT_TEST(test_times_equals_5);
    CPPUNIT_TEST(test_divide_equals_1);
    CPPUNIT_TEST(test_divide_equals_2);
    CPPUNIT_TEST(test_divide_equals_3);
    CPPUNIT_TEST(test_divide_equals_4);
    CPPUNIT_TEST(test_divide_equals_5);    
    CPPUNIT_TEST(test_mod_equals_1);
    CPPUNIT_TEST(test_mod_equals_2);
    CPPUNIT_TEST(test_mod_equals_3);
    CPPUNIT_TEST(test_mod_equals_4);
    CPPUNIT_TEST(test_mod_equals_5);    
    CPPUNIT_TEST(test_left_shift_equals_1);    
    CPPUNIT_TEST(test_left_shift_equals_2);    
    CPPUNIT_TEST(test_left_shift_equals_3);    
    CPPUNIT_TEST(test_right_shift_equals_1);    
    CPPUNIT_TEST(test_right_shift_equals_2);    
    CPPUNIT_TEST(test_right_shift_equals_3);    
    CPPUNIT_TEST(test_right_shift_equals_4);    
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_abs_3);
    CPPUNIT_TEST(test_abs_4);
    CPPUNIT_TEST(test_abs_5);
    CPPUNIT_TEST(test_negation_1);
    CPPUNIT_TEST(test_negation_2);
    CPPUNIT_TEST(test_negation_3);
    CPPUNIT_TEST(test_negation_4);
    CPPUNIT_TEST(test_output_1);
    CPPUNIT_TEST(test_output_2);
    CPPUNIT_TEST(test_output_3);
   // CPPUNIT_TEST(test_pow_1);
   // CPPUNIT_TEST(test_pow_2);
    CPPUNIT_TEST(test_pow_3);
    CPPUNIT_TEST(test_pow_4);
    CPPUNIT_TEST(test_pow_5);
    CPPUNIT_TEST(test_pow_6);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);          // turn off synchronization with C I/O
    cout << "TestInteger.c++" << endl << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestInteger::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
