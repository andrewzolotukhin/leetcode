const data1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
const data2 = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]];
const data3 = [[1, 2, 3, 4]];
const data4 = [[1], [2], [3], [4]];

const data = data2;

var spiralOrder = function (matrix) {
  const result = [];

  const copy = matrix.map(r => r.map(() => 0));

  const isInside = (r, c) => r >= 0 && r < matrix.length && c >= 0 && c < matrix[0].length;
  const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
  let direction = 0;
  let x = 0, y = 0;

  while (true) {
    result.push(matrix[x][y]);
    copy[x][y] = 1;
    let currDirection = directions[direction];
    let newX = x + currDirection[0];
    let newY = y + currDirection[1];
    if (!isInside(newX, newY) || copy[newX][newY] === 1) {

      direction++;
      if (direction > directions.length - 1) {
        direction = direction % directions.length;
      }
      currDirection = directions[direction];

      newX = x + currDirection[0];
      newY = y + currDirection[1];

      if (!isInside(newX, newY) || copy[newX][newY] === 1) break;
    }
    x = newX;
    y = newY;
  }

  return result;
}

var spiralOrder2 = function (matrix) {
  const M = matrix.length;
  const N = matrix[0].length;

  let stepsBeforeTurn = [N - 1, M - 2];
  let steps = 0;
  const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
  let direction = 0;
  let position = [0, 0];

  const result = [];

  while (stepsBeforeTurn[0] >= 0 || stepsBeforeTurn[1] >= 0) {
    let currDirection = directions[direction];
    const stepsLeft = stepsBeforeTurn[direction & 1 ? 1 : 0] - steps;
    console.log(123, position, stepsLeft);
    result.push(matrix[position[0]][position[1]]);
    // console.log(position[0], position[1], stepsLeft, currDirection, stepsBeforeTurn);
    if (stepsLeft > 0) {
      position[0] += currDirection[0];
      position[1] += currDirection[1];
      steps++;
    } else {
      stepsBeforeTurn[direction & 1 ? 1 : 0]--;
      direction++;
      if (direction > directions.length - 1) {
        direction = direction % directions.length;
      }
      steps = 0;
      currDirection = directions[direction];
      position[0] += currDirection[0];
      position[1] += currDirection[1];
      console.log(321, direction, stepsBeforeTurn);
    }
  }

  console.log(result);

};

console.log(spiralOrder(data));

