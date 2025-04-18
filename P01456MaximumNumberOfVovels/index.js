/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxVowels = function (s, k) {
  const n = s.length;
  const tree = new Array(s.length + 1);
  for (let i = 0; i <= n; i++) tree[i] = 0;

  const modify = (i, diff) => {
    i++;
    while (i <= n) {
      tree[i] += diff;
      i += i & -i;
    }
  };

  const query = (i) => {
    i++;
    let ans = 0;

    while (i > 0) {
      ans += tree[i];
      i -= i & -i;
    }

    return ans;
  };

  const rangeQuery = (i, j) => {
    return query(j) - ((i == 0) ? 0 : query(i - 1));
  };

  for (let i = 0; i < s.length; i++) {
    if (s[i] != 'a' && s[i] != 'e' && s[i] != 'o' && s[i] != 'u' && s[i] != 'i') {
      continue;
    }
    modify(i, 1);
  }

  let ans = 0;
  for (let i = 0; i + k - 1 < s.length; i++) {
    ans = Math.max(rangeQuery(i, i + k - 1), ans);
  }

  return ans;
};
