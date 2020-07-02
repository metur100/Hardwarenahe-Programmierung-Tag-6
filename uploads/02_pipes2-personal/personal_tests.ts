#include "personal.h"

// checkmk personal_tests.ts > personal_tests.c
// gcc personal.c personal_tests.c -o tests -Wall -lsubunit -lm -lpthread -lrt -lcheck -std=c99 -g -fprofile-arcs -ftest-coverage


// Teste krank_oder_urlaub

#test test_krank_oder_urlaub_true
        ck_assert_int_eq(krank_oder_urlaub("krank"),1);
        ck_assert_int_eq(krank_oder_urlaub("Urlaub"),1);


#test test_krank_oder_urlaub_leerer_String
        ck_assert_int_eq(krank_oder_urlaub(""),0);


#test test_krank_oder_urlaub_bemerkung_ist_teilstring
        ck_assert_int_eq(krank_oder_urlaub("rank"),0);
        ck_assert_int_eq(krank_oder_urlaub("kran"),0);
        ck_assert_int_eq(krank_oder_urlaub("k"),0);
        ck_assert_int_eq(krank_oder_urlaub("laub"),0);

#test test_krank_oder_urlaub_schluesselwort_ist_teilstring
        ck_assert_int_eq(krank_oder_urlaub("Urlaube"),0);
        ck_assert_int_eq(krank_oder_urlaub("kranke"),0);

#test test_krank_oder_urlaub_false_andere_faelle
        ck_assert_int_eq(krank_oder_urlaub("leer"),0);
        ck_assert_int_eq(krank_oder_urlaub("leere"),0);


// Teste hat_bemerkung

#test test_hat_bemerkung_true
        ck_assert_int_eq(hat_bemerkung("Urlaub","Urlaub"),1);
        ck_assert_int_eq(hat_bemerkung("leer","leer"),1);
        ck_assert_int_eq(hat_bemerkung("",""),1);

#test test_hat_bemerkung_false
        ck_assert_int_eq(hat_bemerkung("leere","leer"),0);
        ck_assert_int_eq(hat_bemerkung("","leer"),0);
        ck_assert_int_eq(hat_bemerkung("leer","krank"),0);
        ck_assert_int_eq(hat_bemerkung("rank","krank"),0);
        ck_assert_int_eq(hat_bemerkung("kran","krank"),0);
        ck_assert_int_eq(hat_bemerkung("k","krank"),0);
        ck_assert_int_eq(hat_bemerkung("Urlaub","krank"),0);
        ck_assert_int_eq(hat_bemerkung("Ürlaub","Urlaub"),0);
        ck_assert_int_eq(hat_bemerkung("Urlaube","Urlaub"),0);
        
// teste calc_arbeitszeit

#test test_calc_arbeitszeit_standard_berechnung
        ck_assert_int_eq(calc_arbeitszeit(1, -100, 2, "leer", 0), -101);
        ck_assert_int_eq(calc_arbeitszeit(1, 100, 2, "Dienstreise", 0), 99);

#test test_calc_arbeitszeit_krank_urlaub
        ck_assert_int_eq(calc_arbeitszeit(1, 100, 2, "Urlaub", 0), 101);
        ck_assert_int_eq(calc_arbeitszeit(1, -100, 2, "Urlaub", 0), -99);
        ck_assert_int_eq(calc_arbeitszeit(1, 0, 2, "krank", 0), 1);
        ck_assert_int_eq(calc_arbeitszeit(1, 100, 2, "krank", 0), 101);

#test test_calc_arbeitszeit_standard_ohne_vormonat
        ck_assert_int_eq(calc_arbeitszeit(1000, 0, 2, "leer", 1), 998);
        ck_assert_int_eq(calc_arbeitszeit(1, 100, 2, "Dienstreise", 1), -1);

#test test_calc_arbeitszeit_krank_urlaub_ohne_vormonat
        ck_assert_int_eq(calc_arbeitszeit(1, 100, 2, "krank", 1), 1);
        ck_assert_int_eq(calc_arbeitszeit(1, 0, 2, "Urlaub", 1), 1);
        ck_assert_int_eq(calc_arbeitszeit(40, -100, 2, "krank", 1), 40);
