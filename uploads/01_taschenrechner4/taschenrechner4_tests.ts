#include "taschenrechner5.h"

// checkmk taschenrechner5_tests.ts > taschenrechner5_tests.c
// gcc taschenrechner5.c taschenrechner5_tests.c -o tests -Wall -lsubunit -lm -lpthread -lrt -lcheck -std=c99 -g -fprofile-arcs -ftest-coverage


#test calc_x_equals_y
    int x = 5;
    int y = 5;
    int interval = 1;
    int mod10 = 0;
    ck_assert_int_eq(calc(x, y, interval, mod10), 25);

#test calc_only_x_and_y
    int x = 1;
    int y = 5;
    int interval = 1;
    int mod10 = 0;
    ck_assert_int_eq(calc(x, y, interval, mod10), 55);

#test calc_x_equals_y_interval_5
    int x = 10;
    int y = 10;
    int interval = 5;
    int mod10 = 0;
    ck_assert_int_eq(calc(x, y, interval, mod10), 100);

#test calc_x_and_y_interval_4
    int x = 1;
    int y = 13;
    int interval = 4;
    int mod10 = 0;
    ck_assert_int_eq(calc(x, y, interval, mod10), 276);


#test calc_only_x_and_y_mod10
    int x = 1;
    int y = 5;
    int interval = 1;
    int mod10 = 1;
    ck_assert_int_eq(calc(x, y, interval, mod10), 5);

#test calc_x_equals_y_interval_5_mod10
    int x = 10;
    int y = 10;
    int interval = 5;
    int mod10 = 1;
    ck_assert_int_eq(calc(x, y, interval, mod10), 0);

#test calc_x_and_y_interval_4_mod10
    int x = 1;
    int y = 13;
    int interval = 4;
    int mod10 = 1;
    ck_assert_int_eq(calc(x, y, interval, mod10), 6);


    
