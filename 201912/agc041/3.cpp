#include "base.hpp"
//#include "consts.hpp"

WI A;

void drawV(int i, int j) {
  A[i][j] = A[i+1][j] = i % 4 * 4 + j % 4 + 1;
}

void drawH(int i, int j) {
  A[i][j] = A[i][j+1] = i % 4 * 4 + j % 4 + 1;
}

void draw3q1(int i, int j) {
  drawV(i, j);
  drawH(i+2, j+1);
}

void draw3q2(int i, int j) {
  drawV(i, j);
  drawH(i+2, j);
  drawV(i+1, j+2);
  drawH(i, j+1);
}

void draw4q3(int i, int j) {
  drawV(i, j);
  drawV(i, j+1);
  drawH(i, j+2);
  drawH(i+1, j+2);
  drawV(i+2, j+2);
  drawV(i+2, j+3);
  drawH(i+2, j);
  drawH(i+3, j);
}

void draw7q3(int i, int j) {
  drawH(i, j);
  drawH(i, j+2);
  drawH(i, j+4);
  drawH(i+5, j);
  drawH(i+5, j+4);
  drawH(i+6, j+2);
  drawH(i+6, j+4);
  drawV(i+1, j+2);
  drawV(i+1, j+3);
  drawV(i+1, j+6);
  drawV(i+3, j);
  drawV(i+3, j+1);
  drawV(i+3, j+6);
  drawV(i+5, j+6);
}

void draw3Mq3(int i, int j, int M) {
  times(M, p) {
    // dd i; j; A;
    draw3q2(i + 3 * p, j + 3 * p);
    // dd i; j; A;
    draw3q1(i + 3 * ((p + 1) % M), j + 3 * p);
  }
}

void solve() {
  int N; cin >> N;

  if(N == 1 || N == 2) {
    cout << -1 ln;
    return;
  }

  A = WI(N, VI(N));

  if(N == 3) {
    draw3q1(0, 0);
  } else if(N % 3 == 0) {
    draw3Mq3(0, 0, N / 3);
  } else if(N == 4) {
    draw4q3(0, 0);
  } else if(N == 7) {
    draw7q3(0, 0);
  } else if(N % 3 == 1) {
    draw4q3(0, 0);
    draw3Mq3(4, 4, N / 3 - 1);
  } else if(N == 5) {
    drawV(0, 0);
    drawV(2, 0);
    drawV(1, 4);
    drawV(3, 4);
    drawH(0, 1);
    drawH(0, 3);
    drawH(4, 0);
    drawH(4, 2);
    draw3q1(1, 1);
  } else if(N == 8) {
    draw4q3(0, 0);
    draw4q3(4, 4);
  } else if(N == 11) {
    draw4q3(0, 0);
    draw7q3(4, 4);
  } else if(N == 14) {
    draw7q3(0, 0);
    draw7q3(7, 7);
  } else {
    assert(N % 3 == 2);
    draw4q3(0, 0);
    draw7q3(4, 4);
    draw3Mq3(11, 11, N / 3 - 3);
  }

  times(N, i) {
    times(N, j) {
      cout << (A[i][j] == 0 ? '.' : (char)('a' + A[i][j] - 1));
    }
    cout ln;
  }
}
