


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
    let term = 1.0;

    for (let i = 1; i <= term; ++i) {
        term *= x / i;
        result += term;
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