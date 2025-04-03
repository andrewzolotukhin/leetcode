const div = (t, b) => {
  return { op: 'n', op1: t.op1 * b.op2, op2: b.op1 * t.op2 };
};
const mul = (l, r) => {
  return { op: 'n', op1: l.op1 * r.op1, op2: l.op2 * r.op2 };
};
const add = (l, r) => {
  return { op: 'n', op1: (l.op1 * r.op2 + r.op1 * l.op2), op2: l.op2 * r.op2 };
};
const sub = (l, r) => {
  return { op: 'n', op1: (l.op1 * r.op2 - r.op1 * l.op2), op2: l.op2 * r.op2 };
};
const is24 = (n) => {
  if (n.op2 === 0) return false;
  if (n.op1 % n.op2 != 0) return false;
  return n.op1 / n.op2 == 24;
};
const genExps2 = (op1, op2) => {
  return [
    { op: '+', op1, op2 },
    { op: '-', op1, op2 },
    { op: '*', op1, op2 },
    { op: '/', op1, op2 },
  ];
};
const genExps3 = (op1, op2, op3) => {
  var result = [];
  for (let p of genExps2(op1, op2)) {
    for (let p2 of genExps2(p, op3)) {
      result.push(p2);
    }
  }
  for (let p of genExps2(op2, op3)) {
    for (let p2 of genExps2(op1, p)) {
      result.push(p2);
    }
  }
  return result;
}
const genExps4 = (op1, op2, op3, op4) => {
  var result = [];
  for (let p of genExps3(op1, op2, op3)) {
    for (let p2 of genExps2(p, op4)) {
      result.push(p2);
    }
  }
  for (let p of genExps3(op2, op3, op4)) {
    for (let p2 of genExps2(op1, p)) {
      result.push(p2);
    }
  }
  for (let p of genExps2(op1, op2)) {
    for (let p2 of genExps2(op3, op4)) {
      for (let p3 of genExps2(p, p2)) {
        result.push(p3);
      }
    }
  }
  return result;
};
const evaluate = (exp) => {
  if (exp.op == 'n') return exp;

  let func;
  switch (exp.op) {
    case '+':
      func = add;
      break;
    case '-':
      func = sub;
      break;
    case '*':
      func = mul;
      break;
    default:
      func = div;
  }
  return func(evaluate(exp.op1), evaluate(exp.op2));
};
function perms(curr, av, res) {
  if (av.length == 0) {
    res.push([...curr]);
    return;
  }
  for (let i = 0; i < av.length; i++) {
    curr.push(av[i]);
    perms(curr, av.filter((v, j) => j != i), res);
    curr.pop();
  }
}

/**
 * @param {number[]} cards
 * @return {boolean}
 */
var judgePoint24 = function (cards) {
  const nums = cards.map(c => ({ op: 'n', op1: c, op2: 1 }));
  const perm = [];
  perms([], nums, perm);
  for (const p of perm) {
    const exps = genExps4(...p);
    for (const exp of exps) {
      //console.log(JSON.stringify(exp, null, 3));
      //console.log('=============');
      if (is24(evaluate(exp))) return true;
    }
  }
  return false;
};
