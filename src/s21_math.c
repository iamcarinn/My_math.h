#include "s21_math.h"

int s21_abs(int x) { return (x < 0) ? -x : x; }

long double s21_fabs(double x) {
  if (x != x) return s21_NAN;
  if (x == s21_INF || x == -s21_INF) return s21_INF;
  if (x == -0) return 0;
  return (x < 0) ? -x : x;
}

long double s21_fmod(double x, double y) {
  long double result = 0;
  if (y == 0 || y != y || x == s21_INF || x == -s21_INF || x != x)
    result = s21_NAN;
  else if (y == -s21_INF || y == s21_INF)
    result = x;
  else {
    long long int integerPart;
    integerPart = x / y;
    result = x - y * integerPart;
  }
  return result;
}

long double s21_floor(double x) {
  long double result = 0.;
  if (x != x)
    result = s21_NAN;
  else if (x == -s21_INF)
    result = -s21_INF;
  else if (x == s21_INF)
    result = s21_INF;
  else if (x < 0 && ((long long int)x == 0))
    result = (long long int)x - 1;
  else if (x == (long long int)x)
    result = (long long int)x;
  else {
    long long int tmp;
    tmp = (long long int)x;
    tmp < 0 ? tmp-- : tmp;
    result = (long double)tmp;
  }
  return result;
}

long double s21_ceil(double x) {
  long double result = 0.;
  if (x == s21_INF)
    result = s21_INF;
  else if (x == -s21_INF)
    result = -s21_INF;
  else if (x != x)
    result = s21_NAN;
  else if ((x < 0 && ((long long int)x == 0)) || (x == (long long int)x))
    result = (long long int)x;
  else {
    long long int tmp;
    tmp = (long long int)x;
    tmp < 0 ? tmp : tmp++;
    result = (long double)tmp;
  }
  return result;
}

long double s21_pow(double base, double exp) {
  long double res = 0.;
  long double copyOfBase = base;
  if (exp == 0) {
    res = 1;
  } else if (base == 1) {
    res = 1;
  } else if (base == s21_INF || (base == -s21_INF && s21_fmod(exp, 2) == 0)) {
    res = s21_INF;
  } else if (base < 0 && (long long int)exp != exp) {
    res = s21_NAN;
  } else if (copyOfBase < 0) {
    copyOfBase = -copyOfBase;
    res = s21_exp(exp * s21_log(copyOfBase));
    if (s21_fmod(exp, 2) != 0) {
      res = -res;
    }
  } else {
    res = s21_exp(exp * s21_log(base));
  }
  return res;
}

long double s21_sqrt(double x) {
  long double left = 0;
  long double right = (x < 1) ? 1 : x;
  long double middle;
  if (x == s21_INF)
    middle = s21_INF;
  else if (x == -s21_INF)
    middle = s21_NAN;
  else if (x == 0)
    middle = 0;
  else if (x < 0 || x != x)
    middle = s21_NAN;
  else if (x == 1)
    middle = 1;
  else {
    middle = (left + right) / 2;
    while ((middle - left) > s21_EPS) {
      if ((middle * middle) > x)
        right = middle;
      else
        left = middle;
      middle = (left + right) / 2;
    }
  }
  return middle;
}

long double s21_log(double x) {
  int amount_of_e_in_x = 0;
  double result = 0;
  double previousResult = 0;
  if (x == s21_INF)
    result = s21_INF;
  else if (x == 0)
    result = -s21_INF;
  else if (x < 0)
    result = s21_NAN;
  else if (x == 1)
    result = 0;
  else {
    for (; x >= s21_EXP; x /= s21_EXP, amount_of_e_in_x++) continue;
    for (int i = 0; i < 100; i++) {
      previousResult = result;
      result = previousResult + 2 * (x - s21_exp(previousResult)) /
                                    (x + s21_exp(previousResult));
    }
  }
  return amount_of_e_in_x + result;
}

long double s21_exp(double x) {
  long double newMember = 1.;
  long double i = 1.;
  long double exp = 1.;
  int isNegativeNumber = 0;
  if (x < 0) {
    x *= -1;
    isNegativeNumber = 1;
  }
  while (s21_fabs(newMember) > s21_EPS) {
    newMember *= x / i;
    i++;
    exp += newMember;
    if (exp > s21_LDBL_MAX) {
      exp = s21_INF;
      break;
    }
  }
  if (isNegativeNumber == 1) {
    if (exp > s21_LDBL_MAX)
      exp = 0;
    else
      exp = 1. / exp;
  }
  if (exp > s21_LDBL_MAX) return s21_INF;
  return exp;
}

long double s21_atan(double x) {
  long double result = 0;
  if (x != x) {
    result = s21_NAN;
  } else if (x == 1) {
    result = 0.7853981633974480L;
  } else if (x == -1) {
    result = -0.7853981633974480L;
  } else if (s21_fabs(x - s21_PI / 2) < s21_EPS) {
    result = 1.003884821853887214L;
  } else if (s21_fabs(x + s21_PI / 2) < s21_EPS) {
    result = -1.003884821853887214L;
  } else if (x == s21_INF || x == -s21_INF) {
    result = x < 0 ? -s21_PI / 2 : s21_PI / 2;
  } else if (-1. < x && x < 1.) {
    for (int i = 0; i < 2000; i++) {
      result += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
    }
  } else {
    for (int i = 0; i < 2000; i++) {
      result += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
    }
    result = s21_PI * ((x < 0) ? -x : x) / (2 * x) - result;
  }
  return result;
}

long double s21_asin(double x) {
  long double result = 0.;
  if (x == 1.)
    result = s21_PI / 2;
  else if (x == -1.)
    result = -s21_PI / 2;
  else if (x == 0.7071067811865475244)
    result = s21_PI / 4;
  else if (x == -0.7071067811865475244)
    result = -s21_PI / 4;
  else if (-1. < x && x < 1.)
    result = s21_atan(x / s21_sqrt(1 - x * x));
  else
    result = s21_NAN;
  return result;
}

long double s21_acos(double x) {
  long double result = 0.;
  if (x == 1.)
    result = 0;
  else if (x == -1.)
    result = s21_PI;
  else if (x == 0)
    result = s21_PI / 2;
  else if (x == 0.7071067811865475244)
    result = s21_PI / 4;
  else if (x == -0.7071067811865475244)
    result = 3 * s21_PI / 4;
  else if (0. < x && x < 1.)
    result = s21_atan(s21_sqrt(1 - x * x) / x);
  else if (-1. < x && x < 0.)
    result = s21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  else
    result = s21_NAN;
  return result;
}

long double s21_sin(double x) {
  long double member, result;
  x = s21_fmod(x, s21_TWO_PI);
  member = x;
  result = x;
  if (s21_fabs(x) < s21_EPS) {
    result = 0.;
  } else {
    for (int i = 1; s21_fabs(member) > s21_EPS && i < 100; i++) {
      member *= ((-1.) * x * x / (2. * i * (2. * i + 1.)));
      result += member;
    }
  }
  return result;
}

long double s21_cos(double x) {
  long double member, result;
  x = s21_fmod(x, s21_TWO_PI);
  member = 1;
  result = 1;
  if (s21_fabs(x) < s21_EPS) {
    result = 1.;
  } else {
    for (int i = 1; s21_fabs(member) > s21_EPS && i < 100; i++) {
      member *= ((-1.) * x * x / (2. * i * (2. * i - 1.)));
      result += member;
    }
  }
  return result;
}

long double s21_tan(double x) {
  long double result = 0;
  x = s21_fmod(x, s21_PI);
  if (x == 0) {
    result = 0;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}
