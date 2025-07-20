/**
 * @return {Generator<number>}
 */
var fibGenerator = function* () {
  let prev = 0;
  let curr = 1;
  let i = 0;

  yield 0;
  yield 1;

  while (true) {
    const t = prev + curr;

    yield t;

    if (t === 0) {
      curr = 1;
    } else {
      prev = curr;
      curr = t;
    }
  }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
