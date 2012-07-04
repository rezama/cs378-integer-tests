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

    void test_shift_left_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {2, 3, 4, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    //BEGINNING OF MY UNIT TESTS

    void test_shift_left_digits_1 () {
        const int a[] = {0, 0, 0};
        const int b[] = {0, 0, 0, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits_2 () {
        const int a[] = {9, 1, 1};
        const int b[] = {9, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
              int x[100];
        const int* p = shift_left_digits(a, a + 3, 20, x);
        CPPUNIT_ASSERT((p - x) == 23);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits_3 () {
        const int a[] = {13};
        const int b[] = {13, 0};
              int x[2];
        const int* p = shift_left_digits(a, a + 1, 1, x);
        CPPUNIT_ASSERT((p - x) == 2);
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

    //BEGINNING OF MY UNIT TESTS

    void test_shift_right_digits_1 () {
        const int a[] = {2, 3, 4, 5};
        const int b[] = {2};
              int x[10];
        const int* p = shift_right_digits(a, a + 4, 3, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_right_digits_2 () {
        const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
        const int b[] = {1, 2, 3, 4};
              int x[10];
        const int* p = shift_right_digits(a, a + 10, 6, x);
        CPPUNIT_ASSERT((p - x) == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_right_digits_3 () {
        const int a[] = {2, 3, 4, 0, 9, 1, 1, 0};
        const int b[] = {2, 3, 4, 0, 9};
              int x[10];
        const int* p = shift_right_digits(a, a + 8, 3, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    // -----------
    // plus_digits
    // -----------

    void test_plus_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {7, 9, 1, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    //BEGINNING OF MY UNIT TESTS
    void test_plus_digits_1 () {
        const int a[] = {5, 6, 7};
        const int b[] = {2, 3, 4};
        const int c[] = {7, 9, 1, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_2 () {
        const int a[] = {9, 9, 9};
        const int b[] = {8, 8, 8};
        const int c[] = {7, 8, 8, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_3 () {
        const int a[] = {9, 9, 9, 9, 9, 9, 9, 9, 9};
        const int b[] = {8, 8, 8, 8, 8, 8, 8, 8, 8};
        const int c[] = {7, 8, 8, 8, 8, 8, 8, 8, 8, 1};
              int x[10];
        const int* p = plus_digits(a, a + 10, b, b + 10, x);
        CPPUNIT_ASSERT(p - x == 10);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_4 () {
        const int a[] = {5, 8, 7, 2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {0, 5, 5, 3, 3, 4};
              int x[10];
        const int* p = plus_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_5 () {
        const int a[] = {9, 9, 9, 2, 3, 4};
        const int b[] = {7, 6, 7};
        const int c[] = {6, 6, 7, 3, 3, 4};
              int x[10];
        const int* p = plus_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    // ------------
    // minus_digits
    // ------------

    void test_minus_digits () {
        const int a[] = {8, 0, 2};
        const int b[] = {5, 3, 1};
        const int c[] = {3, 7, 0};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_1 () {
        const int a[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
        const int b[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
        const int c[] = {0};//should it be {} or {0}?
              int x[10];
        const int* p = minus_digits(a, a + 10, b, b + 10, x);
        CPPUNIT_ASSERT(p - x == 1);//should it be 0?
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_2 () {
        const int a[] = {0};
        const int b[] = {0};
        const int c[] = {0};
              int x[10];
        const int* p = minus_digits(a, a + 1, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_3 () {
        const int a[] = {8, 0, 1};
        const int b[] = {2};
        const int c[] = {6, 0, 1};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_4 () {
        const int a[] = {2, 8, 9};
        const int b[] = {8, 0, 1};
        const int c[] = {4, 7, 8};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // -----------------
    // multiplies_digits
    // -----------------

    void test_multiplies_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {0, 8, 4, 0, 3, 3};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    //MY UNIT TESTS BEGIN HERE

    void test_multiplies_digits_1 () {
        const int a[] = {0};
        const int b[] = {5, 6, 7};
        const int c[] = {0};
              int x[10];
        const int* p = multiplies_digits(a, a + 1, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_2 () {
        const int a[] = {2, 3, 4};
        const int b[] = {1};
        const int c[] = {2, 3, 4};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_3 () {
        const int a[] = {9, 9, 9, 8};
        const int b[] = {9, 9, 9, 9};
        const int c[] = {1, 0, 0, 1, 8, 9, 9, 8};
              int x[10];
        const int* p = multiplies_digits(a, a + 4, b, b + 4, x);
        CPPUNIT_ASSERT(p - x == 8);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // --------------
    // divides_digits
    // --------------

    void test_divides_digits () {
        const int a[] = {1, 3, 2, 6, 7, 8};
        const int b[] = {5, 6, 7};
        const int c[] = {5, 4, 1, 1};
              int x[10];
        const int* p = divides_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_1 () {
        const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        const int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        const int c[] = {1};
              int x[10];
        const int* p = divides_digits(a, a + 10, b, b + 10, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_2 () {
        const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        const int b[] = {1};
        const int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
              int x[10];
        const int* p = divides_digits(a, a + 10, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 10);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_3 () {
        const int a[] = {1, 3, 2, 6, 7, 8};
        const int b[] = {2};
        const int c[] = {6, 6, 3, 3, 9};
              int x[10];
        const int* p = divides_digits(a, a + 6, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 5);
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
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_3 () {
        try {
            const Integer<int> x(2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    //BEGIN MY UNIT TESTS
    void test_constructor_4 () {
        try {
            const Integer<int> x("1A");
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));}}

    void test_constructor_5 () {
        try {
            const Integer<int> x(123456789);

        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_6 () {
        try {
            const Integer<int> x(-1);}
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

    //BEGIN MY UNIT TESTS

    void test_abs_3 () {
        try {
            Integer<int>  x = 123456789;
            Integer<int> y = x.abs();
            CPPUNIT_ASSERT(x == 123456789);
            CPPUNIT_ASSERT(y == 123456789);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_abs_4 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == 0);
            CPPUNIT_ASSERT(y == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_abs_5 () {
        try {
            Integer<int>  x = 0;
            Integer<int>& y = x.abs();
            CPPUNIT_ASSERT( x == 0);
            CPPUNIT_ASSERT(&x == &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_abs_6 () {
        try {
            const Integer<int> x = -1;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == -1);
            CPPUNIT_ASSERT(y ==  1);}
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

    //BEGIN MY UNIT TESTS

    void test_equal_to_1 () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = -98765;
            CPPUNIT_ASSERT(      x != y);
            CPPUNIT_ASSERT(      x == 98765);
            CPPUNIT_ASSERT(  98765 == x);
            CPPUNIT_ASSERT(    !(x == y));
            CPPUNIT_ASSERT(    !(x != 98765));
            CPPUNIT_ASSERT(!(98765 == y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to_2 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = 0;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == 0);
            CPPUNIT_ASSERT(  0 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != 0));
            CPPUNIT_ASSERT(!(0 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to_3 () {
        try {
            const Integer<int> x = 1;
            const Integer<int> y = 2;
            CPPUNIT_ASSERT(      x != y);
            CPPUNIT_ASSERT(      x == 1);
            CPPUNIT_ASSERT(  1 == x);
            CPPUNIT_ASSERT(    !(x == y));
            CPPUNIT_ASSERT(    !(x != 1));
            CPPUNIT_ASSERT(!(2 != y));}
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

    void test_negation_1 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == 0);}
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
            const Integer<int> x = 1;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == -1);}
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

    void test_output_1 () {
        try {
            const Integer<int> x = 0;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "0");}
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
            const Integer<int> x = 1234567890;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "1234567890");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_4 () {
        try {
            const Integer<int> x = -1234567890;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "-1234567890");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---
    // pow
    // ---

    void test_pow_1 () {
        try {
            Integer<int>       x = 98;
            const int          e = 98;
            Integer<int>&      y = x.pow(e);
            Integer<int>       z("1380878341261486750656911803252309726876604105686729638072729543243701479670593033211008001443536626310535980077544691196522513327846303307992442770355560270350429006522588433404602387992091295744");
            CPPUNIT_ASSERT( e == 98);
            CPPUNIT_ASSERT( x ==  z);
            CPPUNIT_ASSERT(&x ==   &y);
            }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 5;
            const int          e =  0;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 5);
            CPPUNIT_ASSERT(e ==  0);
            CPPUNIT_ASSERT(y ==     1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    //BEGIN MY UNIT TESTS

    void test_pow_3 () {
        try {
            Integer<int>       x = 0;
            const int          e =  9867;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 9867);
            CPPUNIT_ASSERT( x ==    0);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_4 () {
        try {
            const Integer<int> x = 98765;
            const int          e =  0;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 98765);
            CPPUNIT_ASSERT(e ==  0);
            CPPUNIT_ASSERT(y ==     1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_5 () {
        try {
            Integer<int>       x = 2;
            const int          e =  3;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 3);
            CPPUNIT_ASSERT( x ==    8);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_pow_6 () {
        try {
            Integer<int> x = 7;
            const int          e =  10;
            Integer<int>& y = x.pow(e);
            Integer<int>       z("282475249");
            CPPUNIT_ASSERT(z ==  282475249);
            CPPUNIT_ASSERT(x == z);
            CPPUNIT_ASSERT(e ==  10);
            CPPUNIT_ASSERT(y ==  282475249);
            CPPUNIT_ASSERT(&x ==   &y);
        }

        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_pow_7 () {
        try {
            Integer<int>       x = 2;
            const int          e =  4;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 4);
            CPPUNIT_ASSERT( x ==    16);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_8 () {
        try {
            Integer<int>       x = 7;
            const int          e =  3;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 3);
            CPPUNIT_ASSERT( x ==    343);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_9 () {
        try {
            Integer<int>       x = 14;
            const int          e =  3;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 3);
            CPPUNIT_ASSERT( x ==    2744);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_10 () {
        try {
            Integer<int>       x = 2;
            const int          e = 7;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 7);
            CPPUNIT_ASSERT( x ==    128);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    //20th Mersenne Prime
    void test_pow_11 () {
        try {
            Integer<int>       x = 2;
            const int          e = 4423;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 4423);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    //30th Mersenne Prime
    void test_pow_12 () {
        try {
            Integer<int>       x = 2;
            const int          e = 132049;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 13049);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --------------------
    // Extra operator Tests
    // --------------------

    void test_op () {
        try
        {
            Integer<int> x = 72;
            Integer<int> y = 49;
            Integer<int> z = 3528;
            Integer<int> z2 = 72 * 49;
            Integer<int> z3 = x * y;
            CPPUNIT_ASSERT(x == 72);
            CPPUNIT_ASSERT(z == 3528);
            CPPUNIT_ASSERT(z2 == 3528);
            CPPUNIT_ASSERT(z3 == 3528);
            CPPUNIT_ASSERT(z == z2);
            CPPUNIT_ASSERT(z == z3);
            CPPUNIT_ASSERT(&z != &z2);
        }

        catch (std::invalid_argument& e)
        {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_op_1 () {
        try
        {
            Integer<int> x = 3;
            Integer<int> y = 4;
            Integer<int> z = 12;
            Integer<int> z2 = 3 * 4;
            CPPUNIT_ASSERT(x == 3);
            CPPUNIT_ASSERT(z == z2);
            CPPUNIT_ASSERT(&z != &z2);
        }

        catch (std::invalid_argument& e)
        {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_op_2 ()
    {
        try
        {
            Integer<int> x = 1234567;
            Integer<int> y = 1234567;
            CPPUNIT_ASSERT(x == y);
            CPPUNIT_ASSERT(&x != &y);
        }
        
        catch (std::invalid_argument& e)
        {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_op_3 () {
        try
        {
            Integer<int> x = 34;
            Integer<int> y = 75;
            Integer<int> z = 2550;
            Integer<int> z2 = 34 * 75;
            CPPUNIT_ASSERT(x == 34);
            CPPUNIT_ASSERT(z == z2);
            CPPUNIT_ASSERT(&z != &z2);
        }

        catch (std::invalid_argument& e)
        {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_op_4 () {
        try
        {
            Integer<int> x = 349;
            Integer<int> y = 71;
            Integer<int> z = 24779;
            Integer<int> z2 = (x *= y);
            CPPUNIT_ASSERT(x == 24779);
            CPPUNIT_ASSERT(z == z2);
            CPPUNIT_ASSERT(x == z2);
        }

        catch (std::invalid_argument& e)
        {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_op_5 () {
        try
        {
            Integer<int> x = 49;
            Integer<int> y = 49;
            Integer<int> z = 2401;
            Integer<int> z2 = x * y;
            CPPUNIT_ASSERT(x == 49);
            CPPUNIT_ASSERT(z == 2401);
            CPPUNIT_ASSERT(z == z2);
        }

        catch (std::invalid_argument& e)
        {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_op_6 () {
        try
        {
            Integer<int> x = 49;
            Integer<int> y = 31;
            Integer<int> z = 18;
            Integer<int> z2 = x - y;
            CPPUNIT_ASSERT(x == 49);
            CPPUNIT_ASSERT(y == 31);
            CPPUNIT_ASSERT(z == 18);
            CPPUNIT_ASSERT(z == z2);
        }

        catch (std::invalid_argument& e)
        {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_op_7 () {
        try
        {
            const Integer<int> x = (Integer<int>(23) - Integer<int>(6));
            Integer<int> y = 17;
            CPPUNIT_ASSERT(x == 17);
            CPPUNIT_ASSERT(y == 17);
        }

        catch (std::invalid_argument& e)
        {
            CPPUNIT_ASSERT(false);
        }
    }



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
    CPPUNIT_TEST(test_multiplies_digits);
    CPPUNIT_TEST(test_multiplies_digits_1);
    CPPUNIT_TEST(test_multiplies_digits_2);
    CPPUNIT_TEST(test_multiplies_digits_3);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_constructor_4);
    CPPUNIT_TEST(test_constructor_5);
    CPPUNIT_TEST(test_constructor_6);
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_abs_3);
    CPPUNIT_TEST(test_abs_4);
    CPPUNIT_TEST(test_abs_5);
    CPPUNIT_TEST(test_abs_6);
    CPPUNIT_TEST(test_equal_to);
    CPPUNIT_TEST(test_equal_to_1);
    CPPUNIT_TEST(test_equal_to_2);
    CPPUNIT_TEST(test_equal_to_3);
    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_negation_1);
    CPPUNIT_TEST(test_negation_2);
    CPPUNIT_TEST(test_negation_3);
    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_output_1);
    CPPUNIT_TEST(test_output_2);
    CPPUNIT_TEST(test_output_3);
    CPPUNIT_TEST(test_output_4);
    CPPUNIT_TEST(test_pow_1);
    CPPUNIT_TEST(test_pow_2); //DO THIS ONE LATER - IT TOOK FOREVER!
    CPPUNIT_TEST(test_pow_3);
    CPPUNIT_TEST(test_pow_4);
    CPPUNIT_TEST(test_pow_5);
    CPPUNIT_TEST(test_pow_6);
    CPPUNIT_TEST(test_pow_7);
    CPPUNIT_TEST(test_pow_8);
    CPPUNIT_TEST(test_pow_9);
    CPPUNIT_TEST(test_pow_10);
    //THESE NEXT 2 ARE MERSENNE PRIMES
    // CPPUNIT_TEST(test_pow_11);
    // CPPUNIT_TEST(test_pow_12);
    CPPUNIT_TEST(test_op);
    CPPUNIT_TEST(test_op_1);
    CPPUNIT_TEST(test_op_2);
    CPPUNIT_TEST(test_op_3);
    CPPUNIT_TEST(test_op_4);
    CPPUNIT_TEST(test_op_5);
    CPPUNIT_TEST(test_op_6);
    CPPUNIT_TEST(test_op_7);
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