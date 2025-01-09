/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
  const o = [];
  let carry = 0;
  digits[digits.length - 1]++;
  for (let i = digits.length - 1; i >= 0; i--) {
    let result = digits[i] + carry;
    if (result > 9) {
      carry = 1;
      result = result % 10;
    } else {
      carry = 0;
    }
    o.unshift(result);
  }
  if (carry) {
    o.unshift(carry);
  }
  return o;
};
