/**
 * @param {string} s
 * @param {string} locked
 * @return {boolean}
 */
const canBeValid = (s, locked) => {
  if (s.length % 2 === 1) return false;

  const opened = [];
  const unlocked = [];

  for (let i = 0; i < s.length; i++) {
    if (locked[i] === '1') {
      if (s[i] === '(') {
        opened.push(i);
      } else {
        if (opened.length !== 0) {
          opened.pop();
        } else if (unlocked.length !== 0) {
          unlocked.pop();
        } else {
          return false;
        }
      }
    } else {
      unlocked.push(i);
    }
  }

  if (opened.length <= unlocked.length) {
    while (opened.length) {
      if (opened[opened.length - 1] < unlocked[unlocked.length - 1]) {
        opened.pop();
        unlocked.pop();
      } else {
        return false;
      }
    }
  }

  return unlocked.length % 2 === 0;
};

const t = [
  { s: '(()(', l: '0110', e: true },
  { s: ')()(', l: '0110', e: true },
  { s: ')()(', l: '0111', e: false },
  { s: ')()())))', l: '00001111', e: true },
  { s: '()()((', l: '011011', e: false },
  { s: '())()))()(()(((())(()()))))((((()())(())', l: '1011101100010001001011000000110010100101', e: true },
  { s: '())(()(()(())()())(())((())(()())((())))))(((((((())(()))))(', l: '100011110110011011010111100111011101111110000101001101001111', e: false },
];

for (const { s, l, e } of t) {
  console.log(s, l);
  console.log(canBeValid(s, l) === e ? 'YES' : 'NO');
}

