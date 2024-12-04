/**
 * @param {number[][]} m
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (m) {
  const l = m.length;

  if (m < 2) return;

  const k = Math.floor(l / 2);
  for (let i = 0; i < k; i++) {
    for (let j = i; j < l - i - 1; j++) {
      let f = m[i][j];
      let s = m[j][l - 1 - i];
      let t = m[l - 1 - i][l - 1 - j];
      let fs = m[l - 1 - j][i];
      m[i][j] = fs;
      m[j][l - 1 - i] = f;
      m[l - 1 - i][l - 1 - j] = s;
      m[l - 1 - j][i] = t;
    }
  }
};
