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
    double numerator = 1.0;
    double denominator = 1.0;

    for (int i = 1; i < iterations; ++i) {
        numerator *= x;
        denominator *= i;
        result += numerator / denominator;
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

EMSCRIPTEN_KEEPALIVE
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        // Swap and recursively heapify the affected subtree
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

EMSCRIPTEN_KEEPALIVE
// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

EMSCRIPTEN_KEEPALIVE
void heapSortWS(int n) {

    if(n > 1000000)
        n = 1000000;

    int arr[1000000];

    for(int i=0; i<n; i++)
        arr[i] = n-i;

    heapSort(arr, n);
}

EMSCRIPTEN_KEEPALIVE
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

EMSCRIPTEN_KEEPALIVE
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

EMSCRIPTEN_KEEPALIVE
void bubbleSortWS(int n) {

    if(n > 10000)
        n = 10000;

    int arr[10000];

    for(int i=0; i<n; i++)
        arr[i] = n-i;

    bubbleSort(arr, n);
}
