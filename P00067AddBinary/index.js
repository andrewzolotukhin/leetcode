/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function (a, b) {
  const result = [];

  if (a.length < b.length) {
    const t = a;
    a = b;
    b = t;
  }

  let carry = 0;
  for (let i = 0; i < a.length; i++) {
    let r = +a[a.length - 1 - i] + ((i >= b.length) ? 0 : (+b[b.length - 1 - i])) + carry;
    if (r > 1) {
      carry = 1;
      r %= 2;
    } else {
      carry = 0;
    }
    result.unshift(r);
  }

  if (carry) {
    result.unshift(1);
  }

  return result.join('');
};
