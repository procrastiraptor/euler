int p9() {
  for (int a = 1; a < 1000; a++) {
    for (int b = a + 1; b < 1000; b++) {
      int c = 1000 - a - b;
      if (c * c == a * a + b * b) {
        return a * b * c;
      }
    }
  }
  return 0;
}
