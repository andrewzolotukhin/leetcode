/**
 * @param {string} s
 * @param {string} locked
 * @return {boolean}
 */
const canBeValid = (s, locked) => {
  if (s.length % 2 === 1) return false;

  let opened = 0, unlocked = 0;

  for (let i = 0; i < s.length; i++) {
    if (locked[i] === '1') {
      if (s[i] === '(') {
        opened++;
      } else {
        if (opened > 0) {
          opened--;
        } else if (unlocked > 0) {
          unlocked--;
        } else {
          return false;
        }
      }
    } else {
      unlocked++;
    }
  }

  let b = 0;

  for (let i = s.length - 1; i >= 0; i--) {
    if (locked[i] === '0') {
      b--;
      unlocked--;
    } else if (s[i] === '(') {
      b++;
      opened--;
    } else {
      b--;
    }
    if (b > 0) {
      return false;
    }
    if (unlocked == 0 && opened == 0) {
      break;
    }
  }

  return opened <= 0;
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

