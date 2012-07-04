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
#include <time.h>

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
        const int a[] = {2, 3, 4};
        const int b[] = {2, 3, 4, 0, 0};
        int x[10];
        const int* p = shift_left_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}
    
    void test_shift_left_digits_2 () {
        const int a[] = {1, 2, 3};
        const int b[] = {1, 2, 3, 0, 0, 0};
        int x[10];
        const int* p = shift_left_digits(a, a + 3, 3, x);
        CPPUNIT_ASSERT((p - x) == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}
    
    void test_shift_left_digits_3 () {
        const int a[] = {4, 5, 6};
        const int b[] = {4, 5, 6, 0, 0, 0, 0};
        int x[10];
        const int* p = shift_left_digits(a, a + 3, 4, x);
        CPPUNIT_ASSERT((p - x) == 7);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}
    
    // ------------------
    // shift_right_digits
    // ------------------
    
    void test_shift_right_digits_1 () {
        const int a[] = {2, 3, 4};
        const int b[] = {2};
        int x[10];
        const int* p = shift_right_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}
    
    void test_shift_right_digits_2 () {
        const int a[] = {6, 7, 8};
        const int b[] = {6, 7};
        int x[10];
        const int* p = shift_right_digits(a, a + 3, 1, x);
        CPPUNIT_ASSERT((p - x) == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}
    
    void test_shift_right_digits_3 () {
        const int a[] = {2, 1, 2, 1, 2, 1};
        const int b[] = {2, 1};
        int x[10];
        const int* p = shift_right_digits(a, a + 6, 4, x);
        CPPUNIT_ASSERT((p - x) == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}
    
    // -----------
    // plus_digits
    // -----------
    
    void test_plus_digits_1 () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {8, 0, 1};
        int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    void test_plus_digits_2 () {
        const int b[] = {2, 6, 3};
        const int a[] = {   8, 9};
        const int c[] = {3, 5, 2};
        int x[10];
        const int* p = plus_digits(a, a + 2, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    void test_plus_digits_3 () {
        const int a[] = {   7, 4, 2};
        const int b[] = {   8, 9, 1};
        const int c[] = {1, 6, 3, 3};
        int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    // ------------
    // minus_digits
    // ------------
    
    void test_minus_digits_1 () {
        const int a[] = {8, 5, 4};
        const int b[] = {1, 4, 5};
        const int c[] = {7, 0, 9};
        int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    void test_minus_digits_2 () {
        const int a[] = {8, 0, 1};
        const int b[] = {6, 7};
        const int c[] = {7, 3, 4};
        int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    void test_minus_digits_3 () {
        const int a[] = {2, 1, 5};
        const int b[] = {1, 1, 6};
        const int c[] = {9, 9};
        int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    // -----------------
    // multiplies_digits
    // -----------------
    
    void test_multiplies_digits_1 () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 3, 2, 6, 7, 8};
        int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    void test_multiplies_digits_2 () {
        const int a[] = {5, 3, 2};
        const int b[] = {9, 6, 3};
        const int c[] = {5, 1, 2, 3, 1, 6};
        int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    void test_multiplies_digits_3 () {
        const int a[] = {9, 9, 8};
        const int b[] = {1, 1, 2};
        const int c[] = {1, 1, 1, 7, 7, 6};
        int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    // --------------
    // divides_digits
    // --------------
    
    void test_divides_digits_1 () {
        const int a[] = {1, 3, 2, 6, 7, 7};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 3};
        int x[10];
        const int* p = divides_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    void test_divides_digits_2 () {
        const int a[] = {1, 1, 1, 7, 7, 6};
        const int b[] = {1, 1, 2};
        const int c[] = {9, 9, 8};
        int x[10];
        const int* p = divides_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    void test_divides_digits_3 () {
        const int a[] = {5, 1, 2, 3, 1, 6};
        const int b[] = {5, 3, 2};
        const int c[] = {9, 6, 3};
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
            const Integer<int> x("2");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_constructor_3 () {
        try {
            const Integer<int> x(2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    // ---
    // abs
    // ---
    
    void test_abs_1_1 () {
        try {
            Integer<int>  x = -98765;
            Integer<int>& y = x.abs();
            CPPUNIT_ASSERT( x == 98765);
            CPPUNIT_ASSERT(&x == &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_abs_1_2 () {
        try {
            Integer<int>  x = 2121;
            Integer<int>& y = x.abs();
            CPPUNIT_ASSERT( x == 2121);
            CPPUNIT_ASSERT(&x == &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_abs_1_3 () {
        try {
            Integer<int>  x = -9242;
            Integer<int>& y = x.abs();
            CPPUNIT_ASSERT( x == 9242);
            CPPUNIT_ASSERT(&x == &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_abs_2_1 () {
        try {
            const Integer<int> x = -98765;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == -98765);
            CPPUNIT_ASSERT(y ==  98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_abs_2_2 () {
        try {
            const Integer<int> x = -2387;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == -2387);
            CPPUNIT_ASSERT(y ==  2387);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_abs_2_3 () {
        try {
            const Integer<int> x = -3935;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == -3935);
            CPPUNIT_ASSERT(y ==  3935);}
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
            const Integer<int> x = 2121;
            const Integer<int> y = 2121;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == 2121);
            CPPUNIT_ASSERT(  2121 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != 2121));
            CPPUNIT_ASSERT(!(2121 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_equal_to_3 () {
        try {
            const Integer<int> x = 19826;
            const Integer<int> y = 19826;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == 19826);
            CPPUNIT_ASSERT(  19826 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != 19826));
            CPPUNIT_ASSERT(!(19826 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    
    // --------
    // less_than
    // --------
    
    void test_less_than_1 () {
        try {
            const Integer<int> x = 212121;
            const Integer<int> y = 545454;
            CPPUNIT_ASSERT(      x < y);
            CPPUNIT_ASSERT(      x < 545454);
            CPPUNIT_ASSERT(  545454 > x);
            CPPUNIT_ASSERT(    !(x > 545454));
            CPPUNIT_ASSERT(    !(x > y));
            CPPUNIT_ASSERT(    !(212121 > y));
            CPPUNIT_ASSERT(    !(y < 212121));
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_less_than_2 () {
        try {
            const Integer<int> x = 983;
            const Integer<int> y = 7895;
            CPPUNIT_ASSERT(      x < y);
            CPPUNIT_ASSERT(      x < 7895);
            CPPUNIT_ASSERT(      7895 > x);
            CPPUNIT_ASSERT(    !(x > 7895));
            CPPUNIT_ASSERT(    !(x > y));
            CPPUNIT_ASSERT(    !(983 > y));
            CPPUNIT_ASSERT(    !(y < 983));
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_less_than_3 () {
        try {
            const Integer<int> x = 9834753;
            const Integer<int> y = 123430965;
            CPPUNIT_ASSERT(      x < y);
            CPPUNIT_ASSERT(      x < 123430965);
            CPPUNIT_ASSERT(      123430965 > x);
            CPPUNIT_ASSERT(    !(x > 123430965));
            CPPUNIT_ASSERT(    !(x > y));
            CPPUNIT_ASSERT(    !(9834753 > y));
            CPPUNIT_ASSERT(    !(y < 9834753));
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    
    // --------
    // plus_equals
    // --------
    
    void test_plus_equals_1 () {
        try {
            Integer<int> x = 2121;
            int          e =  21;
            x += e;
            CPPUNIT_ASSERT( e == 21);
            CPPUNIT_ASSERT( x ==   2142);}
        catch (std::invalid_argument& e) {
             CPPUNIT_ASSERT(false);}}
    
    void test_plus_equals_2 () {
        try {
            Integer<int> x = 2121;
            int          e =  2121;
            x += e;
            CPPUNIT_ASSERT( e == 2121);
            CPPUNIT_ASSERT( x ==   4242);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_plus_equals_3 () {
        try {
            Integer<int> x = 98752;
            int          e =  12341;
            x += e;
            CPPUNIT_ASSERT( e == 12341);
            CPPUNIT_ASSERT( x ==   111093);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_plus_equals_4 () {
        try {
            Integer<int> x = -10;
            int          e =  -10;
            x += e;
            CPPUNIT_ASSERT( e == -10);
            CPPUNIT_ASSERT( x ==   -20);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_plus_equals_5 () {
        try {
            Integer<int> x = 10;
            int          e =  -10;
            
            x += e;
            
            CPPUNIT_ASSERT( e == -10);
            CPPUNIT_ASSERT( x ==   0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    // --------
    // minus_equals
    // --------
    
    void test_minus_equals_1 () {
        try {
            Integer<int> x = 2121;
            int          e =  21;
            x -= e;
            CPPUNIT_ASSERT( e == 21);
            CPPUNIT_ASSERT( x ==   2100);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_minus_equals_2 () {
        try {
            Integer<int> x = 2121;
            int          e =  2121;
            x -= e;
            CPPUNIT_ASSERT( e == 2121);
            CPPUNIT_ASSERT( x == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_minus_equals_3 () {
        try {
            Integer<int> x = 98752;
            int          e =  12341;
            x -= e;
            CPPUNIT_ASSERT( e == 12341);
            CPPUNIT_ASSERT( x ==   86411);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_minus_equals_4 () {
        try {
            Integer<int> x = 25;
            int          e =  -5;
            x -= e;
            
            CPPUNIT_ASSERT( e == -5);
            CPPUNIT_ASSERT( x == 30);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_minus_equals_5 () {
        try {
            Integer<int> x = -20;
            int          e =  -20;
            x -= e;
            
            CPPUNIT_ASSERT( e == -20);
            CPPUNIT_ASSERT( x ==   0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_minus_equals_6 () {
        try {
            Integer<int> x = -5;
            int          e =  25;
            x -= e;

            CPPUNIT_ASSERT( e == 25);
            CPPUNIT_ASSERT( x == -30);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_minus_equals_7 () {
        try {
            Integer<int> x = 10;
            int          e =  25;
            x -= e;
            
            CPPUNIT_ASSERT( e == 25);
            CPPUNIT_ASSERT( x == -15);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    // --------
    // times_equals
    // --------
    
    void test_times_equals_1 () {
        try {
            Integer<int> x = 2121;
            int          e =  21;
            x *= e;
            CPPUNIT_ASSERT( e == 21);
            CPPUNIT_ASSERT( x ==   44541);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_times_equals_2 () {
        try {
            Integer<int> x = 2121;
            int          e =  2121;
            x *= e;
            CPPUNIT_ASSERT( e == 2121);
            CPPUNIT_ASSERT( x ==   4498641);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_times_equals_3 () {
        try {
            Integer<int> x = 98752;
            int          e =  12341;
            Integer<int> y ("1218698432");
            
            x *= e;
            
            CPPUNIT_ASSERT( e == 12341);
            CPPUNIT_ASSERT( x == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_times_equals_4 () {
        try {
            Integer<int> x ("2839745624");
            Integer<int> e ("8769342123");
            Integer<int> y ("8769342123");
            Integer<int> z ("24902700919148119752");
            x *= e;            
            CPPUNIT_ASSERT( e == y);
            CPPUNIT_ASSERT( x == z);}
        catch (...) {
            CPPUNIT_ASSERT(false);}}
    
    void test_times_equals_5 () {
        try {
            Integer<int> x = -2;
            int          e =  -2;
            x *= e;
            CPPUNIT_ASSERT( e == -2);
            CPPUNIT_ASSERT( x ==   4);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_times_equals_6 () {
        try {
            Integer<int> x = -2;
            int          e =  2;
            
            x *= e;
            
            CPPUNIT_ASSERT( e == 2);
            CPPUNIT_ASSERT( x == -4);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    // --------
    // divide_equals
    // --------
    
    void test_divide_equals_1 () {
        try {
            Integer<int> x = 4;
            int          e =  2;
            x /= e;
            CPPUNIT_ASSERT(e == 2);
            CPPUNIT_ASSERT(x == 2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_divide_equals_2 () {
        try {
            Integer<int> x = 2121;
            int          e =  2121;
            x /= e;
            CPPUNIT_ASSERT( e == 2121);
            CPPUNIT_ASSERT( x == 1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_divide_equals_3 () {
        try {
            Integer<int> y ("1218698432");
            Integer<int> x = 98752;
            y /= x;
            CPPUNIT_ASSERT( x == 98752);
            CPPUNIT_ASSERT( y == 12341);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_divide_equals_4 () {
        try {
            Integer<int> y (20);
            Integer<int> x = -5;
            
            y /= x;

            CPPUNIT_ASSERT( x == -5);
            CPPUNIT_ASSERT( y == -4);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_divide_equals_5 () {
        try {
            Integer<int> y (-20);
            Integer<int> x = -5;
            y /= x;
            
            CPPUNIT_ASSERT( x == -5);
            CPPUNIT_ASSERT( y == 4);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    // --------
    // mod_equals
    // --------
    
    void test_mod_equals_1 () {
        try {
            Integer<int> x = 1004;
            int          e =  10;
            x %= e;
            CPPUNIT_ASSERT( e == 10);
            CPPUNIT_ASSERT( x ==   4);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_mod_equals_2 () {
        try {
            Integer<int> x = 1876231;
            int          e =  10;
            x %= e;
            CPPUNIT_ASSERT( e == 10);
            CPPUNIT_ASSERT( x ==   1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_mod_equals_3 () {
        try {
            Integer<int> x = 98752;
            int          e =  10;
            x %= e;
            CPPUNIT_ASSERT( e == 10);
            CPPUNIT_ASSERT( x ==   2);}
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
            const Integer<int> x = 212121;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == -212121);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_negation_3 () {
        try {
            const Integer<int> x = 23942;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == -23942);}
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
            const Integer<int> x = 212121;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "212121");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_output_3 () {
        try {
            const Integer<int> x = 736123;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "736123");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    // ---
    // pow
    // ---
    
    void test_pow_1_1 () {
        try {
            
            Integer<int>       x = 2;
            const int          e =  4423;
            Integer<int>&      y = x.pow(e);
            Integer<int>       z ("285542542228279613901563566102164008326164238644702889199247456602284400390600653875954571505539843239754513915896150297878399377056071435169747221107988791198200988477531339214282772016059009904586686254989084815735422480409022344297588352526004383890632616124076317387416881148592486188361873904175783145696016919574390765598280188599035578448591077683677175520434074287726578006266759615970759521327828555662781678385691581844436444812511562428136742490459363212810180276096088111401003377570363545725120924073646921576797146199387619296560302680261790118132925012323046444438622308877924609373773012481681672424493674474488537770155783006880852648161513067144814790288366664062257274665275787127374649231096375001170901890786263324619578795731425693805073056119677580338084333381987500902968831935913095269821311141322393356490178488728982288156282600813831296143663845945431144043753821542871277745606447858564159213328443580206422714694913091762716447041689678070096773590429808909616750452927258000843500344831628297089902728649981994387647234574276263729694848304750917174186181130688518792748622612293341368928056634384466646326572476167275660839105650528975713899320211121495795311427946254553305387067821067601768750977866100460014602138408448021225053689054793742003095722096732954750721718115531871310231057902608580608");
            CPPUNIT_ASSERT( e == 4423);
            CPPUNIT_ASSERT( x ==    z);
            CPPUNIT_ASSERT(&x ==   &y);
        
        
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_pow_1_2 () {
        try {
            Integer<int> x = 2121;
            const int          e =  21;
            Integer<int>&      y = x.pow(e);
            const Integer<int> z ("7200357152237503036324854029214453311188411004300363161612521456508521");
            CPPUNIT_ASSERT( e == 21);
            CPPUNIT_ASSERT( x ==   z);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_pow_1_3 () {
        try {
            Integer<int> x = 5;
            const int          e =  4;
            Integer<int>&      y = x.pow(e);
            const Integer<int> z ( "625");
            CPPUNIT_ASSERT( e == 4);
            CPPUNIT_ASSERT( x ==   z);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_pow_2_1 () {
        try {
            const Integer<int> x = 21;
            const int          e =  3;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 21);
            CPPUNIT_ASSERT(e ==  3);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_pow_2_2 () {
        try {
            const Integer<int> x = 34;
            const int          e =  2;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 34);
            CPPUNIT_ASSERT(e ==  2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_pow_2_3 () {
        try {
            const Integer<int> x = 25;
            const int          e =  5;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 25);
            CPPUNIT_ASSERT(e ==  5);}
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
    CPPUNIT_TEST(test_plus_digits_1);
    CPPUNIT_TEST(test_plus_digits_2);
    CPPUNIT_TEST(test_plus_digits_3);
    CPPUNIT_TEST(test_minus_digits_1);
    CPPUNIT_TEST(test_minus_digits_2);
    CPPUNIT_TEST(test_minus_digits_3);
    CPPUNIT_TEST(test_multiplies_digits_1);
    CPPUNIT_TEST(test_multiplies_digits_2);
    CPPUNIT_TEST(test_multiplies_digits_3);
    CPPUNIT_TEST(test_divides_digits_1);
    CPPUNIT_TEST(test_divides_digits_2);
    CPPUNIT_TEST(test_divides_digits_3);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_abs_1_1);
    CPPUNIT_TEST(test_abs_1_2);
    CPPUNIT_TEST(test_abs_1_3);
    CPPUNIT_TEST(test_abs_2_1);
    CPPUNIT_TEST(test_abs_2_2);
    CPPUNIT_TEST(test_abs_2_3);
    CPPUNIT_TEST(test_equal_to_1);
    CPPUNIT_TEST(test_equal_to_2);
    CPPUNIT_TEST(test_equal_to_3);
    CPPUNIT_TEST(test_less_than_1);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
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
    CPPUNIT_TEST(test_minus_equals_7);
    CPPUNIT_TEST(test_times_equals_1);
    CPPUNIT_TEST(test_times_equals_2);
    CPPUNIT_TEST(test_times_equals_3);
    CPPUNIT_TEST(test_times_equals_4);
    CPPUNIT_TEST(test_times_equals_5);
    CPPUNIT_TEST(test_times_equals_6);
    CPPUNIT_TEST(test_divide_equals_1);
    CPPUNIT_TEST(test_divide_equals_2);
    CPPUNIT_TEST(test_divide_equals_3);
    CPPUNIT_TEST(test_divide_equals_4);
    CPPUNIT_TEST(test_divide_equals_5);
    CPPUNIT_TEST(test_mod_equals_1);
    CPPUNIT_TEST(test_mod_equals_2);
    CPPUNIT_TEST(test_mod_equals_3);
    CPPUNIT_TEST(test_negation_1);
    CPPUNIT_TEST(test_negation_2);
    CPPUNIT_TEST(test_negation_3);
    CPPUNIT_TEST(test_output_1);
    CPPUNIT_TEST(test_output_2);
    CPPUNIT_TEST(test_output_3);
    CPPUNIT_TEST(test_pow_1_1);
    CPPUNIT_TEST(test_pow_1_2);
    CPPUNIT_TEST(test_pow_1_3);
    CPPUNIT_TEST(test_pow_2_1);
    CPPUNIT_TEST(test_pow_2_2);
    CPPUNIT_TEST(test_pow_2_3);
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