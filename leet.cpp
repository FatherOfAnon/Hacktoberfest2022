void solve() {
    vector<int> a = {3, 5, 1, 2, 7, 9}, b = {2, 1, 5};
    int m = a.size(), n = b.size();

    long long sum = 0, idx = 0, lcm = (m / gcd(m, n)) * n;
    while (idx < lcm) {
        int idx1 = idx % m, idx2 = idx % n;
        sum += abs(a[idx1] - b[idx2]);
        idx++;
    }

    long long res = sum * ((m * n) / lcm);
    cout << res << endl;
}
