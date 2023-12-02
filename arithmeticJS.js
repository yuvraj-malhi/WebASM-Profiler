


function logJS(x, iterations) {
    let result = 0;
    for (let n = 1; n <= iterations; n++) {
        result += (1 / n) * Math.pow((x - 1) / x, n);
    }
    return result;
}

function factorial(n) {
    if (n === 0 || n === 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

function sinJS(x, iterations) {
    let result = 0;
    for (let n = 0; n < iterations; n++) {
        result += (Math.pow(-1, n) / factorial(2 * n + 1)) * Math.pow(x, 2 * n + 1);
    }
    return result;
}


function cosJS(x, iterations) {
    let result = 0;
    for (let n = 0; n < iterations; n++) {
        result += (Math.pow(-1, n) / factorial(2 * n)) * Math.pow(x, 2 * n);
    }
    return result;
}


function expJS(x, iterations) {
    let result = 1.0;
    let numerator = 1.0;
    let denominator = 1.0;

    for (let i = 1; i < iterations; ++i) {
        numerator *= x;
        denominator *= i;
        result += numerator / denominator;
    }

    return result;
}

function piLeibnizJS(numPoints) {
    let pi = 0.0;

    for (let i = 0; i < numPoints; ++i) {
        pi += (i % 2 === 0 ? 1 : -1) * 4.0 / (2 * i + 1);
    }

    return pi;
}

function piBBPJS(numPoints) {
    let pi = 0.0;

    for (let k = 0; k < numPoints; ++k) {
        pi += (1.0 / Math.pow(16, k)) * (
            4.0 / (8 * k + 1) -
            2.0 / (8 * k + 4) -
            1.0 / (8 * k + 5) -
            1.0 / (8 * k + 6)
        );
    }

    return pi;
}

function ratioJS(numTerms) {
    let phi = 1.0;

    for (let i = 0; i < numTerms; ++i) {
        phi = 1.0 + 1.0 / phi;
    }

    return phi;
}

function ratioFibbJS(numTerms) {
    let a = 0, b = 1;

    for (let i = 0; i < numTerms; ++i) {
        let temp = a + b;
        a = b;
        b = temp;
    }

    if (a !== 0) {
        return b / a;
    }

    return -1;  
}

function heapify(arr, n, i) {
    let largest = i;
    const left = 2 * i + 1;
    const right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest !== i) {
        // Swap and recursively heapify the affected subtree
        [arr[i], arr[largest]] = [arr[largest], arr[i]];
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
function heapSort(arr) {
    const n = arr.length;

    // Build heap (rearrange array)
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from the heap
    for (let i = n - 1; i > 0; i--) {
        // Move current root to end
        [arr[0], arr[i]] = [arr[i], arr[0]];

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

function heapSortJS(n){
    
    if(n > 1000000)
        n = 1000000;

    var arraySize = 100000;
    var myArray = new Array(arraySize);
    
    for (let i = 0; i < n; i++) {
        myArray[i] = n-i;
    }

    heapSort(myArray, n);
}


function swap(arr, idx1, idx2) {
    const temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

function bubbleSort(arr) {
    const n = arr.length;

    for (let i = 0; i < n-1; i++) {
        for (let j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
            }
        }
    }
}

function bubbleSortJS(n){
    
    if(n > 10000)
        n = 10000;

    var arraySize = 1000;
    var myArray = new Array(arraySize);
    
    for (let i = 0; i < n; i++) {
        myArray[i] = n-i;
    }

    bubbleSort(myArray, n);
}