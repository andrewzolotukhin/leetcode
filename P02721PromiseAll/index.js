/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {
  return new Promise((res, rej) => {
    let completed = 0;
    const result = [];

    for (let i = 0; i < functions.length; i++) {
      let k = i;
      functions[k]().then((r) => {
        result[k] = r;
        completed++;
        if (completed == functions.length) res(result);
      }).catch(rej);
    }
  });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
