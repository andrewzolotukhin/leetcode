var longestValidParentheses = function (s) {
  if (s.length <= 1) return 0;

  const levels = s.split().map(() => 0);

  let i = 0;
  while (s[i] === ")" && i < s.length) {
    i++;
  }

  if (i >= s.length) return 0;

  levels[i] = s[i] === "(" ? 1 : -1;

  const negs = [];
  negs.push(i - 1);

  let hasOpen = false;

  if (i == 0) i++;

  for (; i < s.length; i++) {
    //     if(s[i] === ")" && !hasOpen) continue;
    //     hasOpen = true;
    levels[i] = levels[i - 1] + (s[i] === "(" ? 1 : -1);
    if (levels[i] < 0 && levels[i - 1] >= 0) negs.push(i);
  }

  negs.push(s.length);

  let result = 0;
  for (let i = 1; i < negs.length; i++) {
    //     console.log(negs[i], negs[i - 1], levels[negs[i] - 1]);
    const l = negs[i] - negs[i - 1] - 1 - levels[negs[i] - 1];
    if (l > result && Math.abs(negs[i] - negs[i - 1] - 1) > 1) result = l;
  }

  console.log("negs:", negs);
  console.log("levels:", levels);
  return result;
};

const tests = [
  { i: "()", o: 2 },
  { i: ")(", o: 0 },
  { i: "())(", o: 2 },
  { i: ")()", o: 2 },
  { i: ")())", o: 2 },
  { i: ")()())", o: 4 },
  { i: ")()((((((((((())))))))))))", o: 24 },
  { i: "(()", o: 2 },
  { i: "()(()", o: 2 },
];

for (let { i, o } of tests) {
  console.log(i, longestValidParentheses(i), o);
}
