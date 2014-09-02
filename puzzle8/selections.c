#ifdef CODE
/* 
 * CS:APP Data Lab @ Universiteit van Amsterdam
 *
 * Modification to original Data Lab:
 *
 * the collection of puzzles is automatically generated for each 
 * programming pair.
 * 
 * Augustus 2011: A.Visser@uva.nl
 *
 */
#endif
#ifdef CODE

/* Global ID to identify the combination of puzzles */
int lab_id = 8;

#endif

#ifdef PROTOTYPE
int bitAnd(int, int);
int test_bitAnd(int, int);
#endif
#ifdef DECL
 {"bitAnd", (funct_t) bitAnd, (funct_t) test_bitAnd, 2, "| ~", 8, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
#endif
#ifdef CODE
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
#ifdef FIX
  return ~(~x | ~y);
#else
  return 2;
#endif
}
#endif
#ifdef TEST
int test_bitAnd(int x, int y)
{
  return x&y;
}
#endif
#ifdef PROTOTYPE
int fitsBits(int, int);
int test_fitsBits(int, int);
#endif
#ifdef DECL
 {"fitsBits", (funct_t) fitsBits, (funct_t) test_fitsBits, 2,
    "! ~ & ^ | + << >>", 15, 2,
  {{TMin, TMax},{1,32},{TMin,TMax}}},
#endif
#ifdef CODE
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
#ifdef FIX
  int shift = 32 + ~n + 1;
  int move = (x << shift) >> shift;
  return !(x ^ move);
#else
  return 2;
#endif
}
#endif
#ifdef TEST
int test_fitsBits(int x, int n)
{
  int TMin_n = -(1 << (n-1));
  int TMax_n = (1 << (n-1)) - 1;
  return x >= TMin_n && x <= TMax_n;
		
}
#endif
#ifdef PROTOTYPE
int isLessOrEqual(int, int);
int test_isLessOrEqual(int, int);
#endif
#ifdef DECL
 {"isLessOrEqual", (funct_t) isLessOrEqual, (funct_t) test_isLessOrEqual, 2,
    "! ~ & ^ | + << >>", 24, 3,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
#endif
#ifdef CODE
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
#ifdef FIX
  int x_neg = x>>31;
  int y_neg = y>>31;  
  return !((!x_neg & y_neg) | (!(x_neg ^ y_neg) & (y+~x+1)>>31));
#else
  return 2;
#endif
}
#endif
#ifdef TEST
int test_isLessOrEqual(int x, int y)
{
  return x <= y;
}
#endif
#ifdef PROTOTYPE
int ilog2(int);
int test_ilog2(int);
#endif
#ifdef DECL
 {"ilog2", (funct_t) ilog2, (funct_t) test_ilog2, 1, "! ~ & ^ | + << >>", 90, 4,
  {{1, TMax},{TMin,TMax},{TMin,TMax}}},
#endif
#ifdef CODE
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
#ifdef FIX
  int m16 = ((1<<16) + ~0) << 16;                         /* groups of 16 */
  int m8 = (((1<<8)  + ~0) << 24) + (((1<<8) + ~0) << 8); /* groups of 8 */
  int m4 = (0xf0<<24) + (0xf0<<16) + (0xf0<<8) + 0xf0;    /* groups of 4 */
  int m2 = (0xcc<<24) + (0xcc<<16) + (0xcc<<8) + 0xcc;    /* groups of 2 */
  int m1 = (0xaa<<24) + (0xaa<<16) + (0xaa<<8) + 0xaa;    /* groups of 1 */
  int result = 0;
  int upper;
  int mask;

  /* m16 */
  upper = !!(x & m16);
  result += upper << 4;
  mask = m16 ^ ~((upper<<31)>>31);

  /* m8 */
  upper = !!(x & m8 & mask);
  result += upper << 3;
  mask &= (m8 ^ ~((upper<<31)>>31)); 

  /* m4 */
  upper = !!(x & m4 & mask);
  result += upper << 2;
  mask &= (m4 ^ ~((upper<<31)>>31)); 

  /* m2 */
  upper = !!(x & m2 & mask);
  result += upper << 1;
  mask &= (m2 ^ ~((upper<<31)>>31)); 

  /* m1 */
  upper = !!(x & m1 & mask);
  result += upper;

  return result;
#else
  return 2;
#endif
}
#endif
#ifdef TEST
int test_ilog2(int x) {
  int mask, result;
  /* find the leftmost bit */
  result = 31;
  mask = 1 << result;
  while (!(x & mask)) {
    result--;
    mask = 1 << result;
  }
  return result;
}
#endif
#ifdef PROTOTYPE
unsigned float_neg(unsigned);
unsigned test_float_neg(unsigned);
#endif
#ifdef DECL
 {"float_neg", (funct_t) float_neg, (funct_t) test_float_neg, 1,
    "$", 10, 2,
     {{1, 1},{1,1},{1,1}}},
#endif
#ifdef CODE
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
#ifdef FIX
	unsigned mask = 1 << 31;
	unsigned result = uf ^ mask;
	unsigned abs = uf & ~mask;
	if (abs > 0x7F800000){
	     /* NaN */
	     result = uf;
	}
	return result;
#else
	return 2;
#endif
}
#endif
#ifdef TEST
unsigned test_float_neg(unsigned uf) {
    float f = u2f(uf);
    float nf = -f;
    if (isnan(f))
	return uf;
    else
	return f2u(nf);
}
#endif
#ifdef PROTOTYPE
unsigned float_twice(unsigned);
unsigned test_float_twice(unsigned);
#endif
#ifdef DECL
 {"float_twice", (funct_t) float_twice, (funct_t) test_float_twice, 1,
    "$", 30, 4,
     {{1, 1},{1,1},{1,1}}},
#endif
#ifdef CODE
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
#ifdef FIX
  unsigned sign = uf>>31;
  unsigned exp = uf>>23 & 0xFF;
  unsigned frac = uf & 0x7FFFFF;
  if (exp == 0) {
    /* Denormalized.  Must double fraction */
    frac = 2*frac;
    if (frac > 0x7FFFFF) {
      /* Result normalized */
      frac = frac & 0x7FFFFF; /* Chop off leading bit */
      exp = 1;
    }
  } else if (exp < 0xFF) {
    /* Normalized.  Increase exponent */
    exp++;
    if (exp == 0xFF) {
      /* Infinity */
      frac = 0;
    }
  }
  /* Infinity and NaN do not require any changes */
  return (sign << 31) | (exp << 23) | frac;
#else
  return 2;
#endif
}
#endif
#ifdef TEST
unsigned test_float_twice(unsigned uf) {
  float f = u2f(uf);
  float tf = 2*f;
  if (isnan(f))
    return uf;
  else
    return f2u(tf);
}
#endif
