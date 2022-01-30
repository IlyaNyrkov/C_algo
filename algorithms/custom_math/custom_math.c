#include "custom_math.h"

long long power(int base, unsigned pow) {
    long long result = 1;
    int mul = base;
    while (pow > 0) {
        if (pow & 1) {
            result *= mul;
        }
        mul *= mul;
        pow = pow >> 1;
    }
    return result;
}