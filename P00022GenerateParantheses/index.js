/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function (n) {
  const r = [];
  const getch = (k, c) =>
    new Array(k)
      .fill(0)
      .map((_) => c)
      .join("");
  const work = (p, o, c) => {
    if (n - o === 0) {
      r.push(p + getch(o - c, ")"));
      return;
    }
    if (o < n) {
      work(p + "(", o + 1, c);
    }

    if (c < n && o > 0 && c < o) {
      work(p + ")", o, c + 1);
    }
  };
  work("(", 1, 0);
  return r;
};
