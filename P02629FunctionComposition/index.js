/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function (functions) {
  if (functions.length == 0) return (x) => x;
  let ans = (x) => functions[functions.length - 1](x);

  for (let i = functions.length - 2; i >= 0; i--) {
    let prevAns = ans;
    ans = (x) => functions[i](prevAns(x));
  }

  return ans;
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
