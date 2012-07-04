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

    void test_shift_left_digits_1 () {
        const int a[] = {2, 3, 4, -1, -1};
	    const int b[] = {0, 0, 2, 3, 4};
              int x[10];
        const int* p = shift_left_digits(a, a + 5, 2, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits_2 () {
        const int a[] = {0, 5, -1};
	    const int b[] = {0, 0, 5};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 1, x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits_3 () {
        const int a[] = {5, 4, 3, 8};
	    const int b[] = {5, 4, 3, 8};
              int x[10];
        const int* p = shift_left_digits(a, a + 4, 0, x);
        CPPUNIT_ASSERT((p - x) == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    //
    // <<
    //

    void test_lshift_operator_1 () {
        const Integer<int> x(2);
	CPPUNIT_ASSERT((x << 0) == 2);
    }

    void test_lshift_operator_2 () {
        const Integer<int> x(0);
	CPPUNIT_ASSERT((x << 2) == 0);
    }

    void test_lshift_operator_3 () {
        const Integer<int> x(20);
	CPPUNIT_ASSERT((x << 1) == 200);
    }

    //
    // >>
    //
    void test_rshift_operator_1 () {
        const Integer<int> x(223);
	CPPUNIT_ASSERT((x >> 0) == 223);
    }

    void test_rshift_operator_2 () {
        const Integer<int> x(0);
	CPPUNIT_ASSERT((x >> 2) == 0);
    }

    void test_rshift_operator_3 () {
        const Integer<int> x(32478546);
	CPPUNIT_ASSERT((x >> 5) == 324);
    }
  
    void test_rshift_operator_4 () {
        const Integer<int> x(2213);
	CPPUNIT_ASSERT((x >> 5) == 0);
    }

    //
    // <
    //

    void test_less_operator_1 (){
	const Integer<int> x(1);
	const Integer<int> y(15);
	CPPUNIT_ASSERT((x < y) == true);
    }

    void test_less_operator_2 (){
	const Integer<int> x(0);
	const Integer<int> y(0);
	CPPUNIT_ASSERT((x < y) == false);
    }

    void test_less_operator_3 (){
	const Integer<int> x(1);
	const Integer<int> y(-15);
	CPPUNIT_ASSERT((x < y) == false);
    }

    // ------------------
    // shift_right_digits
    // ------------------

    void test_shift_right_digits_1 () {
        const int a[] = {4, 3, 2};
        const int b[] = {2};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_right_digits_2 () {
        const int a[] = {3, 1, 4, 7, 2};
	    const int b[] = {4, 7, 2};
              int x[10];
        const int* p = shift_right_digits(a, a + 5, 2, x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_right_digits_3 () {
        const int a[] = {3, 2, 9, 4, 7, 2, 3};
	    const int b[] = {4, 7, 2, 3};
              int x[10];
        const int* p = shift_right_digits(a, a + 7, 3, x);
        CPPUNIT_ASSERT((p - x) == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    // -----------
    // plus_digits
    // -----------

    void test_plus_digits_1 () {
        const int a[] = {4, 3, 2, 0};
        const int b[] = {5, 6, 2};
        const int c[] = {9, 9, 4, 0};
              int x[10];
        const int* p = plus_digits(a, a + 4, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_2 () {
        const int a[] = {4, 3, 5, 0};
        const int b[] = {1, 2};
        const int c[] = {5, 5, 5, 0};
              int x[10];
        const int* p = plus_digits(a, a + 4, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_3 () {
        const int a[] = {5, 0, 2, 0};
        const int b[] = {1, 6, 9};
        const int c[] = {6, 6, 1, 1};
              int x[10];
        const int* p = plus_digits(a, a + 4, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    //
    // += and +
    //
  
    void test_addition_1 (){
	const Integer<int> x(1);
	const Integer<int> y(2);
	CPPUNIT_ASSERT((x + y) == 3);}

    void test_addition_2 (){
	const Integer<int> x(5);
	const Integer<int> y(72);
	CPPUNIT_ASSERT((x + y) == 77);}

    void test_addition_3 (){
	const Integer<int> x(-10);
	const Integer<int> y(150);
	CPPUNIT_ASSERT((x + y) == 140);}

    void test_addition_4 (){
	const Integer<int> x(-2000);
	const Integer<int> y(-8001);
	CPPUNIT_ASSERT((x + y) == -10001);}
	
	void test_addition_5 (){
	const Integer<int> x(123);
	const Integer<int> y(-81);
	CPPUNIT_ASSERT((x + y) == 42);}
	
	void test_addition_6 (){
	const Integer<int> x(-10);
	const Integer<int> y(10);
	CPPUNIT_ASSERT((x + y) == 0);}


    // ------------
    // minus_digits
    // ------------

    void test_minus_digits_1 () {
        const int a[] = {1, 0, 8};
        const int b[] = {7, 6, 5};
        const int c[] = {4, 3, 2};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_2 () {
        const int a[] = {1, 2, 3, 4};
        const int b[] = {6, 4};
        const int c[] = {5, 7, 2, 4};
              int x[10];
        const int* p = minus_digits(a, a + 4, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_3 () {
        const int a[] = {3, 0, 8};
        const int b[] = {9, 6, 5};
        const int c[] = {4, 3, 2};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    //
    // -= and -
    //
  
    void test_minus_1 (){
	const Integer<int> x(-1);
	const Integer<int> y(2);
	CPPUNIT_ASSERT((x - y) == -3);}

    void test_minus_2 (){
	const Integer<int> x(-5);
	const Integer<int> y(-32);
	CPPUNIT_ASSERT((x - y) == 27);}

    void test_minus_3 (){
	const Integer<int> x(-7);
	const Integer<int> y(-7);
	CPPUNIT_ASSERT((x - y) == 0);}

    void test_minus_4 (){
	const Integer<int> x(10);
	const Integer<int> y(140);
	CPPUNIT_ASSERT((x - y) == -130);}
	
	void test_minus_5 (){
	const Integer<int> x(73);
	const Integer<int> y(2);
	CPPUNIT_ASSERT((x - y) == 71);}
	
	void test_minus_6 (){
	const Integer<int> x(0);
	const Integer<int> y(-29);
	CPPUNIT_ASSERT((x - y) == 29);}

    // -----------------
    // multiplies_digits
    // -----------------

    void test_multiplies_digits () {
        const int a[] = {4, 3, 2};
        const int b[] = {7, 6, 5};
        const int c[] = {8, 7, 6, 2, 3, 1};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
		//for(int i = 0; i < 6; i++) std::cout << x[i];
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
		
    //
    // *= and *
    //
  
    void test_multiply_1 (){
	const Integer<int, std::deque<int> > x(10213);
	const Integer<int, std::deque<int> > y(3243);
	CPPUNIT_ASSERT((x * y) == 33120759);}

    void test_multiply_2 (){
	const Integer<int, std::deque<int> > x(-5);
	const Integer<int, std::deque<int> > y(-32);
	CPPUNIT_ASSERT((x * y) == 160);}

    void test_multiply_3 (){
	const Integer<int, std::deque<int> > x(1);
	const Integer<int, std::deque<int> > y(-7);
	CPPUNIT_ASSERT((x * y) == -7);}

    void test_multiply_4 (){
	const Integer<int, std::deque<int> > x(10);
	const Integer<int, std::deque<int> > y(140);
	CPPUNIT_ASSERT((x * y) == 1400);}
	
	void test_multiply_5 (){
	const Integer<int, std::deque<int> > x(73);
	const Integer<int, std::deque<int> > y(0);
	CPPUNIT_ASSERT((x * y) == 0);}
	
	void test_multiply_6 (){
	const Integer<int, std::deque<int> > x(0);
	const Integer<int, std::deque<int> > y(-29);
	CPPUNIT_ASSERT((x * y) == 0);}	

    // --------------
    // test_divide
    // --------------
	
	void test_divide_1 (){
	const Integer<int> x(15);
	const Integer<int> y(4);
	CPPUNIT_ASSERT((x / y) == 3);}	
	
	void test_divide_2 (){
	const Integer<int> x(34);
	const Integer<int> y(3);
	CPPUNIT_ASSERT((x / y) == 11);}
	
	void test_divide_3 (){
	const Integer<int> x(0);
	const Integer<int> y(4);
	CPPUNIT_ASSERT((x / y) == 0);}
	
	void test_divide_4 (){
	const Integer<int> x(1);
	const Integer<int> y(1);
	CPPUNIT_ASSERT((x / y) == 1);}
	
	void test_divide_5 (){
	const Integer<int> x(2434);
	const Integer<int> y(7);
	CPPUNIT_ASSERT((x / y) == 347);}
	
	// -----------------
    // divides_remainder
    // -----------------
	
	void test_remainder_1 (){
	const Integer<int> x(2434);
	const Integer<int> y(7);
	CPPUNIT_ASSERT((x % y) == 5);}
	
	void test_remainder_2 (){
	const Integer<int> x(2434);
	const Integer<int> y(532);
	CPPUNIT_ASSERT((x % y) == 306);}
	
	void test_remainder_3 (){
	const Integer<int> x(23);
	const Integer<int> y(343);
	CPPUNIT_ASSERT((x % y) == 23);}
	
	void test_remainder_4 (){
	const Integer<int> x(2434);
	const Integer<int> y(1);
	CPPUNIT_ASSERT((x % y) == 0);}

	// ---------------
    // divides_digits
    // ---------------
	
    void test_divides_digits () {
        const int a[] = {1, 3, 2, 6, 7, 8};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 4};
              int x[10];
        const int* p = divides_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
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
            CPPUNIT_ASSERT(false);}}

    void test_constructor_3 () {
        try {
            const Integer<int> x(2);
	    CPPUNIT_ASSERT(x == 2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_4 () {
        try {
            const Integer<int> x(234);
            CPPUNIT_ASSERT(x == 234);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_constructor_5 () {
        try {
            const Integer<int> x("0000");
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));}}
    
    void test_constructor_6 () {
        try {
            const Integer<int> x(0);
            CPPUNIT_ASSERT(x == 0);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_7 () {
        try {
            const Integer<int> x("0200");
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));}}

    void test_constructor_8 () {
        try {
            const Integer<int> x("-5");
            CPPUNIT_ASSERT(x == -5);
        }
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
            Integer<int> x = 0;
            Integer<int>& y = x.abs();
            CPPUNIT_ASSERT(x == 0);
            CPPUNIT_ASSERT(&x == &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_abs_4 () {
        try {
            const Integer<int> x = 765;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == 765);
            CPPUNIT_ASSERT(y == 765);}
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
            const Integer<int> x = 5712;
            const Integer<int> y = 5712;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == 5712);
            CPPUNIT_ASSERT(  5712 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != 5712));
            CPPUNIT_ASSERT(!(5712 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to_3() {
        try {
            const Integer<int> x = -20;
            const Integer<int> y = -20;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == -20);
            CPPUNIT_ASSERT(  -20 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != -20));
            CPPUNIT_ASSERT(!(-20 != y));}
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
            const Integer<int> x = 0;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_negation_3 () {
        try {
            const Integer<int> x = -128;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == 128);}
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
            const Integer<int> x = 0;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "0");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_3 () {
        try {
            const Integer<int> x = -23;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "-23");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---
    // pow
    // ---

    void test_pow_1 () {
        try {
            Integer<int>       x = 98765;
            const int          e =  0;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 0);
            CPPUNIT_ASSERT( x ==    1);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int, std::deque<int> > x = 76;
            const int          e =  4;
            const Integer<int, std::deque<int> > y = pow(x, e);
            CPPUNIT_ASSERT(x == 76);
            CPPUNIT_ASSERT(e ==  4);
            CPPUNIT_ASSERT(y == 33362176);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_3 () {
        try {
            Integer<int> x = 4;
            const int    e =  10;
            Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x ==  4);
            CPPUNIT_ASSERT(e ==  10); 
            CPPUNIT_ASSERT(y == 1048576);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
    void test_pow_4 () {
        try {
            Integer<int, std::deque<int> > x = 0;
            const int          e =  3;
            Integer<int, std::deque<int> > y = pow(x, e);
            CPPUNIT_ASSERT(x ==  0);
            CPPUNIT_ASSERT(e ==  3);
            CPPUNIT_ASSERT(y == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}	

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestInteger);
    CPPUNIT_TEST(test_shift_left_digits_1);
    CPPUNIT_TEST(test_shift_left_digits_2);
    CPPUNIT_TEST(test_shift_left_digits_3);

    CPPUNIT_TEST(test_shift_right_digits_1);
    CPPUNIT_TEST(test_shift_right_digits_2);
    CPPUNIT_TEST(test_shift_right_digits_3);

    CPPUNIT_TEST(test_lshift_operator_1);
    CPPUNIT_TEST(test_lshift_operator_2);
    CPPUNIT_TEST(test_lshift_operator_3);

    CPPUNIT_TEST(test_rshift_operator_1);
    CPPUNIT_TEST(test_rshift_operator_2);
    CPPUNIT_TEST(test_rshift_operator_3);
    CPPUNIT_TEST(test_rshift_operator_4);

    CPPUNIT_TEST(test_less_operator_1);
    CPPUNIT_TEST(test_less_operator_2);
    CPPUNIT_TEST(test_less_operator_3);

    CPPUNIT_TEST(test_plus_digits_1);
    CPPUNIT_TEST(test_plus_digits_2);
    CPPUNIT_TEST(test_plus_digits_3);

    CPPUNIT_TEST(test_addition_1);
    CPPUNIT_TEST(test_addition_2);
    CPPUNIT_TEST(test_addition_3);
    CPPUNIT_TEST(test_addition_4);
    CPPUNIT_TEST(test_addition_5);
    CPPUNIT_TEST(test_addition_6);

    CPPUNIT_TEST(test_minus_digits_1);
    CPPUNIT_TEST(test_minus_digits_2);
    CPPUNIT_TEST(test_minus_digits_3);

    CPPUNIT_TEST(test_minus_1);
    CPPUNIT_TEST(test_minus_2);
    CPPUNIT_TEST(test_minus_3);
    CPPUNIT_TEST(test_minus_4);
    CPPUNIT_TEST(test_minus_5);
    CPPUNIT_TEST(test_minus_6);

   // CPPUNIT_TEST(test_multiplies_digits);
    //CPPUNIT_TEST(test_divides_digits);
    
	CPPUNIT_TEST(test_multiply_1);
	CPPUNIT_TEST(test_multiply_2);
	CPPUNIT_TEST(test_multiply_3);
	CPPUNIT_TEST(test_multiply_4);
	CPPUNIT_TEST(test_multiply_5);
	CPPUNIT_TEST(test_multiply_6);
	
	CPPUNIT_TEST(test_divide_1);
	CPPUNIT_TEST(test_divide_2);
	CPPUNIT_TEST(test_divide_3);
	CPPUNIT_TEST(test_divide_4);
	CPPUNIT_TEST(test_divide_5);
	
    CPPUNIT_TEST(test_remainder_1);
	CPPUNIT_TEST(test_remainder_2);
	CPPUNIT_TEST(test_remainder_3);
	CPPUNIT_TEST(test_remainder_4);

    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_constructor_4);
    CPPUNIT_TEST(test_constructor_5);
    CPPUNIT_TEST(test_constructor_6);
    CPPUNIT_TEST(test_constructor_7);
    CPPUNIT_TEST(test_constructor_8);

    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_abs_3);
    CPPUNIT_TEST(test_abs_4);

    CPPUNIT_TEST(test_negation_1);
    CPPUNIT_TEST(test_negation_2);
    CPPUNIT_TEST(test_negation_3);

    CPPUNIT_TEST(test_equal_to_1);
    CPPUNIT_TEST(test_equal_to_2);
    CPPUNIT_TEST(test_equal_to_3);

    CPPUNIT_TEST(test_output_1);
    CPPUNIT_TEST(test_output_2);
    CPPUNIT_TEST(test_output_3);

    CPPUNIT_TEST(test_pow_1);
    CPPUNIT_TEST(test_pow_2); 
    CPPUNIT_TEST(test_pow_3);
    CPPUNIT_TEST(test_pow_4);
	
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
