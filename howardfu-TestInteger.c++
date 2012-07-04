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

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TestSuite.h"               // TestSuite
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Integer.h"

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

    // -----------
    // plus_digits
    // -----------

    void test_plus_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {8, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits2 () {
        const int a[] = {1, 2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 8, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 4, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits3 () {
        const int a[] = {2, 3, 4};
        const int b[] = {1, 5, 6, 7};
        const int c[] = {1, 8, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 4, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits4 () {
        const int a[] = {2, 3, 4};
        const int b[] = {0};
        const int c[] = {2, 3, 4};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits5 () {
        const int a[] = {2, 3, 4};
        const int b[] = {1, 2, 3};
        const int c[] = {3, 5, 7};
	std::vector<int> result;
	result.resize(5);
        std::vector<int>::iterator p = plus_digits(a, a + 3, b, b + 3, result.begin());
	std::vector<int>::iterator tempbegin = result.begin();
	result.resize(p - tempbegin);
        CPPUNIT_ASSERT(result.end() - result.begin() == 3);
        CPPUNIT_ASSERT(std::equal(result.begin(), result.end(), c));}

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

    void test_minus_digits2 () {
        const int a[] = {3, 0, 0};
        const int b[] = {1, 9, 9};
        const int c[] = {1, 0, 1};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits3 () {
        const int a[] = {2, 0};
        const int b[] = {1, 0, 0, 0};
        const int c[] = {9, 8, 0};
              int x[10];
        const int* p = minus_digits(a, a + 2, b, b + 4, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits4 () {
        const int a[] = {1, 6};
        const int b[] = {1};
        const int c[] = {1, 5};
              int x[10];
        const int* p = minus_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
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
   
    void test_multiplies_digits2 () {
        const int a[] = {1, 0, 0};
        const int b[] = {1, 1};
        const int c[] = {1, 1, 0, 0};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits3 () {
        const int a[] = {0};
        const int b[] = {5, 6, 7};
        const int c[] = {0};
              int x[10];
        const int* p = multiplies_digits(a, a + 1, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits4 () {
        const int a[] = {0};
        const int b[] = {0};
        const int c[] = {0};
              int x[10];
        const int* p = multiplies_digits(a, a + 1, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits5 () {
        const int a[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
        const int b[] = {2, 2, 2, 2, 2, 2, 2};
        const int c[] = {1,2,3,4,5,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,5,4,3,2,1,0};
              int x[30];
        const int* p = multiplies_digits(a, a + 20, b, b + 7, x);
        CPPUNIT_ASSERT(p - x == 27);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

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


    void test_divides_digits2 () {
        const int a[] = {5, 6, 6};
        const int b[] = {5, 6, 7};
        const int c[] = {0};
              int x[10];
        const int* p = divides_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_divides_digits3 () {
        const int a[] = {1, 3};
        const int b[] = {1};
        const int c[] = {1, 3};
              int x[10];
        const int* p = divides_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits4 () {
        const int a[] = {1, 3};
        const int b[] = {1, 3};
        const int c[] = {1};
              int x[10];
        const int* p = divides_digits(a, a + 2, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    // -----------
    // constructor
    // -----------

    void test_constructor_1 () {
        try {
            const Integer<int> x("abc");
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));}}

    void test_constructor_2 () {
        try {
            const Integer<int> x("2");
	    CPPUNIT_ASSERT(x == 2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
	}

    void test_constructor_3 () {
        try {
            const Integer<int> x(2);
	    CPPUNIT_ASSERT(x == 2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
	
	}

    //minus equals

    void test_minusequals () {
        try {
            Integer<int>  x = 2;
            Integer<int>  y = 1;
	    Integer<int>  z = x - y;
            CPPUNIT_ASSERT( x == 2);
	    CPPUNIT_ASSERT( z == 1);
            CPPUNIT_ASSERT( y == 1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minusequals2 () {
        try {
            Integer<int>  x = 2;
            Integer<int>  y = 1;
	    Integer<int>  z = x -= y;
            CPPUNIT_ASSERT( x == 1);
	    CPPUNIT_ASSERT( z == 1);
            CPPUNIT_ASSERT( y == 1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minusequals3 () {
        try {
            Integer<int>  x = 2;
            Integer<int>  y = 2;
	    Integer<int>  z = x -= y;
            CPPUNIT_ASSERT( x == 0);
	    CPPUNIT_ASSERT( z == 0);
            CPPUNIT_ASSERT( y == 2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
  
    // ---
    // abs
    // ---

    void test_abs_1 () {
        try {
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
            const Integer<int> x = 1;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == 1);
            CPPUNIT_ASSERT(y == 1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    // --------
    // equal_to
    // --------

    void test_equal_to () {
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

    void test_equal_to2 () {
        try {
            const Integer<int> x = 1;
            const Integer<int> y = 1;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == 1);
            CPPUNIT_ASSERT(  	1 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != 1));
            CPPUNIT_ASSERT(!(1 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

     void test_equal_to3 () {
        try {
            const Integer<int> x = -98765;
            const Integer<int> y = -98765;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == -98765);
            CPPUNIT_ASSERT(  -98765 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != -98765));
            CPPUNIT_ASSERT(!(-98765 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --------
    // negation
    // --------

    void test_negation () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == -98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_negation2 () {
        try {
            const Integer<int> x = -98765;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == 98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_negation3 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ------
    // output
    // ------

    void test_output () {
        try {
            const Integer<int> x = 98765;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "98765");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output2 () {
        try {
            const Integer<int> x = -98765;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "-98765");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_output3 () {
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
            Integer<int>       x =  2;
            const int          e =  10;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 10);
            CPPUNIT_ASSERT( x == 1024);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 10;
            const int          e =  5;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 10);
            CPPUNIT_ASSERT(e ==  5);
            CPPUNIT_ASSERT(y == 100000);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_3 () {
        try {
            const Integer<int> x =  20;
            const int          e =  0;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 20);
            CPPUNIT_ASSERT(e ==  0);
            CPPUNIT_ASSERT(y == 1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestInteger);
    CPPUNIT_TEST(test_shift_left_digits);
    CPPUNIT_TEST(test_shift_right_digits);
    CPPUNIT_TEST(test_plus_digits);
    CPPUNIT_TEST(test_plus_digits2);
    CPPUNIT_TEST(test_plus_digits3);
    CPPUNIT_TEST(test_plus_digits4);
    CPPUNIT_TEST(test_plus_digits5);
    CPPUNIT_TEST(test_minus_digits);
    CPPUNIT_TEST(test_minus_digits2);
    CPPUNIT_TEST(test_minus_digits3);
    CPPUNIT_TEST(test_minus_digits4);
    CPPUNIT_TEST(test_multiplies_digits);
    CPPUNIT_TEST(test_multiplies_digits2);
    CPPUNIT_TEST(test_multiplies_digits3);
    CPPUNIT_TEST(test_multiplies_digits4);
    CPPUNIT_TEST(test_multiplies_digits5);
    CPPUNIT_TEST(test_divides_digits);
    CPPUNIT_TEST(test_divides_digits2);
    CPPUNIT_TEST(test_divides_digits3);
    CPPUNIT_TEST(test_divides_digits4);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_equal_to);
    CPPUNIT_TEST(test_equal_to2);
    CPPUNIT_TEST(test_equal_to3);
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_abs_3);
    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_negation2);
    CPPUNIT_TEST(test_negation3);
    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_output2);
    CPPUNIT_TEST(test_output3);
    CPPUNIT_TEST(test_pow_1);
    CPPUNIT_TEST(test_pow_2);
    CPPUNIT_TEST(test_pow_3);
    CPPUNIT_TEST(test_minusequals);
    CPPUNIT_TEST(test_minusequals2);
    CPPUNIT_TEST(test_minusequals3);
    CPPUNIT_TEST_SUITE_END();
    };

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
