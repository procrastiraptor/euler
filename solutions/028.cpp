namespace {

constexpr int p() {
  int result = 1;
  int n = 1;
  int diff = 2;
  for (int i = 0; i < 500; i++) {
    for (int j = 0; j < 4; j++) {
      n += diff;
      result += n;
    }
    diff += 2;
  }
  return result;
}

}

int p28() {
  return p();
}
