// C = A + B, A >= 0, B >= 0
vector<int> Add(vector<int> &A, vector<int> &B) {
  if ((int) A.size() < (int) B.size()) {
    return add(B, A);
  }
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size(); i++) {
    t += A[i];
    if (i < B.size()) {
      t += B[i];
    }
    C.push_back(t % 10);
    t /= 10;
  }
  if (t) {
    C.push_back(t);
  }
  return C;
}

// C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> Sub(vector<int> &A, vector<int> &B) {
  vector<int> C;
  for (int i = 0, t = 0; i < (int) A.size(); i++) {
    t = A[i] - t;
    if (i < B.size()) {
      t -= B[i];
    }
    C.push_back((t + 10) % 10);
    if (t < 0) {
      t = 1;
    } else {
      t = 0;
    }
  }
  while (C.size() > 1 && C.back() == 0) {
    C.pop_back();
  }
  return C;
}

// C = A * b, A >= 0, b > 0
vector<int> Mul(vector<int> &A, int b) {
  vector<int> C;
  int t = 0;
  for (int i = 0; i < (int) A.size() || t; i++) {
    if (i < A.size()) {
      t += A[i] * b;
    }
    C.push_back(t % 10);
    t /= 10;
  }
  return C;
}

vector<int> Mul(vector<int> &A, vector<int> &B) {
  vector<int> C((int) A.size() + (int) B.size());
  for (int i = 0; i < (int) A.size(); i++) {
    for (int j = 0; j < (int) B.size(); j++) {
      C[i + j] += A[i] * B[j];
      C[i + j + 1] += C[i + j] / 10;
      C[i + j] %= 10;
    }
  }
  while ((int) C.size() > 1 && C.back() == 0) {
    C.pop_back();
  }
  return C;
}

// A / b = C ... r, A >= 0, b > 0
vector<int> Div(vector<int> &A, int b, int &r) {
  vector<int> C;
  r = 0;
  for (int i = (int) A.size() - 1; i >= 0; i--) {
    r = r * 10 + A[i];
    C.push_back(r / b);
    r %= b;
  }
  reverse(C.begin(), C.end());
  while ((int) C.size() > 1 && C.back() == 0) {
    C.pop_back();
  }
  return C;
}
