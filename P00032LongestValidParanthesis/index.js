var longestValidParentheses = function (s) {
  if (s.lenth <= 1) return 0;

  const levels = s.split().map(() => 0);
  const negs = [-1];

  levels[0] = s[0] === "(" ? 1 : -1;

  for (let i = 1; i < s.length; i++) {
    levels[i] = levels[i - 1] + (s[i] === "(" ? 1 : -1);
    if (levels[i] < 0 && levels[i - 1] >= 0) negs.push(i);
  }

  negs.push(s.length);

  let result = 0;
  for (let i = 1; i < negs.length; i++) {
    const l = -levels[negs[i]] + (negs[i] - negs[i - 1] - 1);
    if (l < result) result = l;
  }

  console.log(negs);
  console.log(levels);
  return result;
};

const tests = [
  { i: "()", o: 2 },
  { i: ")(", o: 0 },
  { i: ")()", o: 2 },
  { i: ")())", o: 2 },
  { i: ")()())", o: 4 },
  { i: ")()((((((((((())))))))))))", o: 24 },
  { i: "(()", o: 2 },
];

for (let { i, o } of tests) {
  console.log(i, longestValidParentheses(i), o);
}
