var fractionToDecimal = function (numerator, denominator) {
  if (!numerator) return '0';

  let ans = '';

  if (Math.sign(numerator) !== Math.sign(denominator)) ans += '-';

  const top = Math.abs(numerator)
  const bottom = Math.abs(denominator)

  ans += Math.floor(top / bottom);
  let rem = top % bottom;
  if (!rem) return ans;
  ans += '.';

  const map = new Map();

  while (rem !== 0) {
    map.set(rem, ans.length);

    rem *= 10;
    ans += Math.floor(rem / bottom);
    rem %= bottom;

    if (map.has(rem)) {
      const idx = map.get(rem);
      return ans.slice(0, idx) + `(${ans.slice(idx)})`;
    }
  }
  return ans;
};
