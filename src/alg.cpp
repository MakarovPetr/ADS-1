// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    for (int i = 2; i < value; i++) {
        if (value % i == 0)
            return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    int count = 0;
    int a = 1;
    int chislo = 0;
    while (count != n) {
        bool Flag = true;
        a++;
        for (int i = 2; i < a; i++) {
            if (a % i == 0)
                Flag = false;
        }
        if (Flag == true) {
            chislo = a;
            count++;
        }
    }
    return chislo;
}

uint64_t nextPrime(uint64_t value) {
    while (1) {
        value++;
        if (checkPrime(value) == false) {
            value++;
            checkPrime(value);
        }
        if (checkPrime(value) == true)
            return value;
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t summ = 0;
    for (int i = 2; i < hbound; i++) {
        if (checkPrime(i) == true) {
            summ += i;
        }
    }
    return summ;
}
