namespace {

constexpr int solutions(int p) {
  int result = 0;
  for (int a = 1; a < p; a++) {
    for (int b = a; b < p; b++) {
      int c = p - a - b;
      if (c > 0 && a * a + b * b == c * c) {
        result++;
      }
    }
  }
  return result;
}

}

int p39() {
  int result = 0;
  int max = 0;
  for (int p = 1; p <= 1000; p++) {
    int s = solutions(p);
    if (s > max) {
      max = s;
      result = p;
    }
  }
  return result;
}
