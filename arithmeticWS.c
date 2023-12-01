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
double cosWS(double x, int iterations) {
    double result = 0;
    for (int n = 0; n < iterations; n++) {
        result += (pow(-1, n) / factorial(2 * n)) * pow(x, 2 * n);
    }
    return result;
}

EMSCRIPTEN_KEEPALIVE
double expWS(double x, int iterations) {
    double result = 1.0;
    double term = 1.0;

    for (int i = 1; i <= term; ++i) {
        term *= x / i;
        result += term;
    }

    return result;
}

EMSCRIPTEN_KEEPALIVE
double piLeibnizWS(int numPoints) {
    double pi = 0.0;

    for (int i = 0; i < numPoints; ++i) {
        pi += (i % 2 == 0 ? 1 : -1) * 4.0 / (2 * i + 1);
    }

    return pi;
}

EMSCRIPTEN_KEEPALIVE
double piBBPWS(int numPoints) {
    double pi = 0.0;

    for (int k = 0; k < numPoints; ++k) {
        pi += (1.0 / pow(16, k)) * (
            4.0 / (8 * k + 1) -
            2.0 / (8 * k + 4) -
            1.0 / (8 * k + 5) -
            1.0 / (8 * k + 6)
        );
    }
    return pi;
}

EMSCRIPTEN_KEEPALIVE
double ratioWS(int numTerms) {
    double phi = 1.0;

    for (int i = 0; i < numTerms; ++i) {
        phi = 1.0 + 1.0 / phi;
    }

    return phi;
}

EMSCRIPTEN_KEEPALIVE
double ratioFibbWS(int numTerms) {
    int a = 0, b = 1;

    for (int i = 0; i < numTerms; ++i) {
        int temp = a + b;
        a = b;
        b = temp;
    }

    if (a != 0) {
        return (double)b / a;
    }

    return -1;  // Return -1 for undefined ratio (0/0)
}