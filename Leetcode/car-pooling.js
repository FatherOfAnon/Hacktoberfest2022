const carPooling = function (trips, capacity) {
  const arr = Array(1001).fill(0);
  for (let el of trips) {
    const [num, s, e] = el;
    arr[s] += num;
    arr[e] -= num;
  }
  for (let i = 1; i < 1001; i++) {
    if (arr[i] !== 0) arr[i] += arr[i - 1];
    else arr[i] = arr[i - 1];
  }
  for (let e of arr) {
    if (e > capacity) return false;
  }
  return true;
};
