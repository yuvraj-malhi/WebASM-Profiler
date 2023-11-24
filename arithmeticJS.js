


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
    let result = 0;
    for (let n = 0; n < iterations; n++) {
        result += (Math.pow(x, n) / factorial(n));
    }
    return result;
}

