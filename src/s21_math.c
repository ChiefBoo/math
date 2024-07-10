#include "s21_math.h"

int s21_abs(int x) { return (x > 0) ? x : -x; }

long double s21_acos(double x) {
  long double fx = 0;

  if (0 < x && x <= 1) {
    fx = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x == 0) {
    fx = s21_PI_2;
  } else {
    fx = s21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  }
  return fx;
}

long double s21_asin(double x) {
  long double fx = 0;

  fx = s21_atan(x / s21_sqrt(1 - x * x));
  return fx;
}

long double s21_atan(double x) {
  long double res = 0.0;
  long double next_member = 0.0;
  long long pow_eps = 500000;  // number of members

  double x1 = (s21_fabs(x) <= 1.0) ? x : 1.0 / x;

  res = x1;
  next_member = x1;

  for (int i = 2; i < pow_eps && s21_fabs(next_member) > 1e-18;
       i += 2) {  // taylor expansion
    next_member *= (-x1 * x1) * (i - 1) / (i + 1);
    res += next_member;
  }

  if (s21_fabs(x) >= 1.0) {
    if (x > 0.0) res = s21_PI_2 - res;
    if (x < 0.0) res = -s21_PI_2 - res;
  }

  return res;
}

long double s21_ceil(double x) {
  long double res = (long long int)x;
  if (s21_fabs(x) == s21_INF || (x - (long long int)x) == 0) {
    res = x;
  } else if (x != x) {
    res = s21_NAN;
  } else if (x > 0) {
    res += 1.0;
  }
  return res;
}

long double s21_cos(double x) {
  long double fx = 0;  //  cos(a) = sin(pi/2 + a)
  x = s21_fabs(x);     //  cos(-a) = cos(a)
  fx = s21_sin(s21_PI_2 + x);
  return fx;
}

long double s21_exp(double x) {
  int acc = 100000;
  long double next_member = 1.0;
  long double fx = next_member;
  if (x == 0) {
    fx = 1.0;
  } else if (x == 1) {
    fx = s21_E;
  } else if (x == s21_INF || x != x) {
    fx = s21_INF;
  } else if (x == -s21_INF) {
    fx = 0.0;
  } else {
    for (int i = 1; i < acc && next_member > 1e-16; i++) {
      next_member *= (s21_fabs(x) / i);
      fx += next_member;
    }
  }
  if (x < 0 && x != -s21_INF) fx = 1.0 / fx;
  return fx;
}

long double s21_fabs(double x) { return (x > 0) ? x : -x; }

// functions 9 - 15

long double s21_floor(double x) {
  long double res = (int)x;
  if (x == s21_INF || x == -s21_INF || (x - (int)x) == 0) {
    res = x;
  } else if (x != x) {
    res = s21_NAN;
  } else if (x < 0) {
    res -= 1.0;
  }
  return res;
}

long double s21_fmod(double x, double y) {
  long double r = 0.0, q = 0.0;
  if (y == 0 || x != x || y != y || x == s21_INF || x == -s21_INF) {
    q = s21_NAN;
  } else if (y == s21_INF || y == -s21_INF) {
    q = x;
  } else {
    r = (int)(x / y);  //  integer part
    q = x - r * y;     //  fractional part
  }
  return q;
}

long double s21_log(double x) {
  long double res = 0.0;
  long double next_member = 0.0;
  int rank = 0;
  int pow_eps = 100000;  // number of members
  if (x == s21_E) {      // x == e
    res = 1.0;
  } else if (x == 0) {  // x == 0
    res = -s21_INF;
  } else if (x == s21_INF) {  // x == INF
    res = x;
  } else if (x < 0) {  // x < 0
    res = s21_NAN;
  } else {
    while (x >= 2) {  // 542 -> ln (542/(n*e)) + /n\ * lne = ln (542/(n*e)) + n
      x /= s21_E;
      rank++;
    }
    x -= 1;
    res = x;
    next_member = x;
    for (int i = 2; i < pow_eps && s21_fabs(next_member) > 1e-16;
         i++) {  // 0 <= x <= 2
      next_member *= (-x * (i - 1) / i);
      res += next_member;
    }
    res += rank;
  }
  return res;
}

long double s21_pow(double bas, double exp) {
  long double res = 1.0;
  if (exp == 0.0 || ((s21_fabs(bas) == 1.0) &&
                     (s21_fabs(exp) == s21_INF))) {  // a^0 || +-1^+-inf
    res = 1.0;
  } else if (exp == s21_INF && (s21_fabs(bas) == s21_INF)) {  // +-inf^inf
    res = s21_INF;
  } else if ((bas == s21_INF || bas == -s21_INF) && exp < 0) {
    res = 0.0;
  } else if (bas < 0) {  // bas < 0
    if (exp - (int)exp == 0) {
      if (s21_fmod(exp, 2) == 0) {
        res = s21_exp(exp * s21_log(s21_fabs(bas)));
      } else {
        res = -s21_exp(exp * s21_log(s21_fabs(bas)));
      }
    } else {
      res = s21_NAN;
    }
  } else {
    res = s21_exp(exp * s21_log(bas));
  }
  return res;
}

long double s21_sin(double x) {
  long double res = 0.0;
  long double next_member = 0.0;
  int pow_eps = 100000;      // number of members
  int sign = x < 0 ? 1 : 0;  // sin(-x) = -sin(x)
  x = s21_fabs(x);
  if (x == s21_INF || x != x) {
    res = s21_NAN;
  } else {
    while (x >= 2 * s21_PI) {  // -2Pi
      x -= 2 * s21_PI;
    }
    res = x;
    next_member = x;
    for (int i = 3; i < pow_eps && s21_fabs(next_member) > 1e-16;
         i += 2) {  // taylor expansion
      next_member *= (-x * x) / ((i - 1) * i);
      res += next_member;
    }
  }
  return sign ? -res : res;
}

long double s21_sqrt(double x) {
  long double res = 0.0;
  if (x >= 0) {
    if (x == 0.0) {
      res = 0.0;
    } else if (x == 1) {
      res = 1.0;
    } else {
      res = s21_pow(x, 0.5);
    }
  } else {
    res = s21_NAN;
  }
  return res;
}

long double s21_tan(double x) {
  long double res = 0.0;
  if (x == 0.0) {
    res = 0.0;
  } else {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}