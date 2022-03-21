/* 
 * <Please put your name and userid here>
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
#include <stdio.h>
#include <math.h>
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int ans;
  ans = ~(~(x & ~(x & y))&(~(y & ~(x & y))));
  return ans;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (1<<31);
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {

  return !(~x & (1<<31 -1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int ans;
  ans = 0xAA + (0xAA<<16) + (0xAA<<8);
  return !((x & ans)^ans);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {

  //
  int ansH, ansL, check1, check2;


  ansH = 0x3a;
  ansL = 0x29;

  check1 = (x + (~ansL + 1)) >> 31;
  check2 = (x + (~ansH + 1)) >> 31;

  return ! (((~ansL + 1) + x) >> 31) & ((~ansH + 1) + x) >> 31;
  
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {

int ans1, ans2, ans3, ans4;
 ans1 = !!x; //Here we make x such that it is either 0 (if all )
 ans2 = ~ans2 +1; // we get the negation of x in 0 or one for two's compliment
 ans3 = ~ans2 & y;
 ans4 = (ans2 & z);


  return ans3 | ans4;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {

  int x1 = x>>31; int y1 = x>>31; //extract the sign bit;
  

  int combo = ((x + (~y +1)) >> 31) & 1;//check to see if x is less than

  return (!(x1 & y1) & combo) | !(x ^ y); // return if less than OR equal
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {

  int check;

  //Here, the goal is to bassically check if its zero.
  //And after a double negation, 0 is the only number that will not change
  // In comparison to the regular negation (WITHOUT adding one)
  // because it has no sign (in this format of int);

  check = (~x) & (~(negate(x)));
  return (1 & (check>>31));
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */

int howManyBits(int x) {

    
    int s, end, hold, part4, part3, part2, part1;

    int comp1, comp2, fin;
  //This will represent the sign of the number
    s = (x >> 31);
    
    //Since we are looking for the minimum we check for the amount of bits and ignore the sign
    comp1 = (s & ~x); 
    comp2 = (~s & x);

    x = comp1 | comp2;
    
  //Now, we conduct a search for each bit sequence to check for amount of bits using shifts as follows:
  //we do this, by starting from the end of the bits to the beggining and check at each section
  //how many bits are used
    part1 = !!(x >> 16) << 4;
    part2 = !!(x >> 8) << 3;
    part3 = !!(x >> 4) << 2;
    part4 = !!(x >> 2) << 1;
    hold = !!(x >> 1);
    x >>= part1;
    x >>= part2;
    x >>= part3;
    x >>= part4;
    x >>= hold;

    fin =  part1 + part2 + part3 + part4 + hold;
    
  //At this step we are checking the one place bit(s); every other 
  //section of the bits was tested above.

    end = x;

    

    //The extra one is to acount for the sign bit that is needed

    return fin + end + 1;
}

//float
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

  int check , s;
 if (uf == 0  || uf == 0xFF000000){ //This returns in a scenario where the value
  //is 0  or when what is stored in uf is Not a Number.
    return uf;
  }
  //This case is where there could be denormalized, we set a variable to check the exponent
 /* check = (((uf << 1) >> 24) << 23); //This gets us to the exp
  s = ((uf >> 31) << 31);
  if ( check == 0)
  {
    return (s | (uf << 1));
  }
  */
  
  // Here we have determined that the number is ok to just multiply by two.
  //Since we are in the floating point representation, we want to do this
  //by adding one to the exponent portion of the floating point structure
  
    return  uf + (1 << 23);
  
  
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  //First we extract the sign bit
  int s = (x & (1>>31));
  unsigned exp = 127; //establish the bias
  unsigned frac;
  int count = 0;
  int still = x;
  if(x == 0){
    return 0;
  }
  if (x < 0){
    still = -x;
  }
  

  while (still > 1) //in this step, we keep tract of how long it takes to divide out the number by two which is going to help us 
  // figure out the exponent section in the floating point representation
  {
    still >>= 1;
    count++;

  }

  exp = exp + count; // we add the exp bit to the bias 

  frac = still & ((1 << count ) - 1); //then we set the frac bit assuming no rounding is needed

  int spots = count - 23;

  int round = 0;

  if(spots>0) //in such a scenrio we will have to round because there are more than 23 bits
  {
    frac>>=spots;
    int chang = frac & ((1<<spots) - 1);
    int cut = 1<< (spots -1);
 
    if (chang>cut || ((frac & 0x1) && chang==cut)) //
    {
      round = 1;
    }

     


  }
      else{
      frac <<= (-spots);
    }
  


  return ((s << 31) | (exp << 23) | frac) + round;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {

  int s = (uf >> 31);

  int exp = (0xFF & (uf >> 23)); //This is the standard spot and amount of bits in I-EEE floating point

  

  int Expo = exp - 127; // This calculates the actual exponent value after factoring in bias

  // To account for Not a Number and infinity we check the exponent and make sure its non zero
   if( exp == 0x7F800000){
     return 0x80000000u;
   }

  //Next we account for the scenario where the actual exponent value is beyond the limit for integers
   if(Expo>=31){

     return 0x80000000u;
   }

   if (Expo < 0) // Here the exp is less than the standard bias value so we return 0
   {
     return 0;
   }

    
    int mant = (0x7FFFFF & uf);

    mant = (0x80000000u | mant);
   
   if (exp <= 23) // In this scenario we conduct a bitwise shift to the right

   {
     mant = (mant >> (23 -Expo));
   }

   else{
     mant = (mant << (Expo - 23));
   }

  int ans1 = (1 & (uf >> 31));

  if(ans1){
    return negate(mant);
  }

 
    return mant;
  
   
   
}

int main(){
  //printf("%d",bitXor(4,5));
  //printf("%d",allOddBits(0xAAAAAAAA));
  //printf("%d",allOddBits(0xFFFFFFFD));
   //printf("%d",negate(3));
   //printf("%d",isAsciiDigit(0x35));
   //printf("\n");
   //         printf("%d",isAsciiDigit(0x3a));
   //         printf("%d",isAsciiDigit(0x05));
   //printf("%d", tmin());
  //printf("%d", isTmax(2147483647));
  //printf("%d", isTmax(255999));
  //printf("%d",conditional(2,4,5));
  //printf("%d" , isLessOrEqual(4,2));

 //printf("%d" , logicalNeg(3));
 //printf("%d" , logicalNeg(0));
 //printf("%d" , float_twice(25));
  //printf("%d", (float_f2i(2)));
  //printf("%d", (howManyBits(10)));
}
