/*
 * CS:APP Data Lab
 *
 * <Casper Thuis 10341943 & Joop Pascha 10090614>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */
#include <stdio.h> //todo: comment out in final version
#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

Replace the "return" statement in each function with one
or more lines of C code that implements the function. Your code
must conform to the following style:

int Funct(arg1, arg2, ...) {
  /* brief description of how your implementation works */
  int var1 = Expr1;
  ...
    int varM = ExprM;

  varJ = ExprJ;
  ...
    varN = ExprN;
  return ExprR;
}

Each "Expr" is an expression using ONLY the following:
1. Integer constants 0 through 255 (0xFF), inclusive. You are
not allowed to use big constants such as 0xffffffff.
2. Function arguments and local variables (no global variables).
3. Unary integer operations ! ~
4. Binary integer operations & ^ | + << >>

Some of the problems restrict the set of allowed operators even further.
Each "Expr" may consist of multiple operators. You are not restricted to
one operator per line.

You are expressly forbidden to:
1. Use any control constructs such as if, do, while, for, switch, etc.
2. Define or use any macros.
3. Define any additional functions in this file.
4. Call any functions.
5. Use any other operations, such as &&, ||, -, or ?:
6. Use any form of casting.
7. Use any data type other than int.  This implies that you
cannot use arrays, structs, or unions.


You may assume that your machine:
1. Uses 2s complement, 32-bit representations of integers.
2. Performs right shifts arithmetically.
3. Has unpredictable behavior when shifting an integer by more
than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
/*
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 */
int pow2plus1(int x) {
  /* exploit ability of shifts to compute powers of 2 */
  return (1 << x) + 1;
}

/*
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 */
int pow2plus4(int x) {
  /* exploit ability of shifts to compute powers of 2 */
  int result = (1 << x);
  result += 4;
  return result;
}

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
    the coding rules are less strict.  You are allowed to use looping and
    conditional control.  You are allowed to use both ints and unsigneds.
    You can use arbitrary integer and unsigned constants.

    You are expressly forbidden to:
    1. Define or use any macros.
    2. Define any additional functions in this file.
    3. Call any functions.
    4. Use any form of casting.
    5. Use any data type other than int or unsigned.  This means that you
    cannot use arrays, structs, or unions.
    6. Use any floating point data types, operations, or constants.


    NOTES:
    1. Use the dlc (data lab checker) compiler (described in the handout) to
  check the legality of your solutions.
2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
  that you are allowed to use for your implementation of the function.
  The max operator count is checked by dlc. Note that '=' is not
  counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
  header comment for each function. If there are any inconsistencies
  between the maximum ops in the writeup and in this file, consider
  this file the authoritative source.

  /*
   * STEP 2: Modify the following functions according the coding rules.
   *
   *   IMPORTANT. TO AVOID GRADING SURPRISES:
   *   1. Use the dlc compiler to check that your solutions conform
   *      to the coding rules.
   *   2. Use the BDD checker to formally verify that your solutions produce
   *      the correct answers.
   */


#endif

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

  /* Global ID to identify the combination of puzzles */
  int lab_id = 8;
  /*
   * bitAnd - x&y using only ~ and |
   *   Example: bitAnd(6, 5) = 4
   *   Legal ops: ~ |
   *   Max ops: 8
   *   Rating: 1
   */
  int bitAnd(int x, int y) {
    return ~(~x | ~y);
  }

/*
}
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
/// retract one of the n-bit and rightshifts the x 
 // if n is correct the output will be only ones or zeró's. 
int fitsBits(int x, int n) {
  int leadingbit = x >>  (n + ~(0)); 
  int positive = !leadingbit; // returns 1 if the bit is 0 
  int negative = !(leadingbit+1); //  returns 1 of the bit is -1
  return positive|negative; // one of the negative or positive answers needs to 1.
} 





/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
int xNegative = ( x >> 31 );
int yNegative = ( y >> 31 );
int isNotSameSign = (xNegative ^ yNegative);
int xNegYPos = (isNotSameSign & xNegative) & 1;
int overflowOccuredToNegative = (( x + ~y ) >> 31) & 1;
return xNegYPos | (~isNotSameSign & overflowOccuredToNegative);
}



/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  return 2;
}
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
  int removeSignNumber = (~(1 << 31)) & uf; // removes the sign from the number so we dont have a logical shift problem.
  int beforeThePoint = removeSignNumber >> 23; // gets the numbers that are in the exponent
  int afterThePoint = uf << 9; // gets the numbers that are in the frac
  // if the exponent contains only ones it should check if in the frac the 
  // exponent is not zero else return the number itself 
    if (beforeThePoint == 0xFF){
        if(afterThePoint != 0){ 
          return uf;
        }
    }
  // the sign is 1 when zero and zero when 1  
  return uf ^ (1 << 31);
}
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
  return 2;
}
