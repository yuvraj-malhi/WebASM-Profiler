#include <emscripten.h>
#include <math.h>

EMSCRIPTEN_KEEPALIVE
double logWS(double x, int iterations) {
    double result = 0;
    for (int n = 1; n <= iterations; n++) {
        result += (1.0 / n) * pow((x - 1) / x, n);
    }
    return result;
}

EMSCRIPTEN_KEEPALIVE
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

EMSCRIPTEN_KEEPALIVE
double sinWS(double x, int iterations) {
    double result = 0;
    for (int n = 0; n < iterations; n++) {
        result += (pow(-1, n) / factorial(2 * n + 1)) * pow(x, 2 * n + 1);
    }
    return result;
}

EMSCRIPTEN_KEEPALIVE
double cosTaylor(double x, int iterations) {
    double result = 0;
    for (int n = 0; n < iterations; n++) {
        result += (pow(-1, n) / factorial(2 * n)) * pow(x, 2 * n);
    }
    return result;
}

EMSCRIPTEN_KEEPALIVE
double expWS(double x, int iterations) {
    double result = 0;
    for (int n = 0; n < iterations; n++) {
        result += pow(x, n) / factorial(n);
    }
    return result;
}