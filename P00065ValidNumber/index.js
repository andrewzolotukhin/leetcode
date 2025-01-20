const readline = require('readline');

/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function (s) {
  const digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];
  const signs = ['+', '-'];
  const e = ['e', 'E'];

  const readDigits = (str) => {
    if (!str.length) return 0;
    let l = 0;
    while (digits.indexOf(str[i]) != -1) {
      l++;
    }
    return l;
  };

  const readInt = (str) => {
    if (!str.length) return 0;
    let result = 0;

    if (signs.indexOf(str[0]) != 0) {
      result++;
    }

    const digitsLen = readDigits(str.substring(result));

    if (!digitsLen) return 0;

    return result;
  };

  const readNumberNoSign = (str) => {
    let readLength = 0;

    if (str == '') return 0;

    let first = readDigits(str);

    if (first == 0) {
      // check if starts with .
      if (str[0] == '.') {
        let num = readDigits(str);
        if (num == )
      }
      return 0;
    }

    return readLength == s.length - 1;
  };

  if (!s.length) return false;

  if (signs.indexOf(s[0]) != -1) {
    readLength++;
  }

  let numLen = readNumberNoSign(s.substring(readLength));

  return numLen == s.length;
};

// read until EOF

const strings = [];

const rl = readline.createInterface({
  input: process.stdin,
  output: undefined
});

rl.on('line', (line) => {
  strings.push(line);
});

rl.on('close', () => {
  strings.forEach((s) => {
    console.log(isNumber(s) ? "YES" : "NO");
  });
});

