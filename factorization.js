/**
 * @description - factorization is a function that takes 1 parameter:
 * @return {array} - array of prime factors of n;
 */
Number.prototype.factorization = function () {
    let n = this;
    let res = [];
    let i = 2;
    while (n > 1) {
        if (n % i === 0) {
            res.push(i);
            n /= i;
        } else {
            i++;
        }
    }
    return res;
}

let num = 100;

console.log(num.factorization());