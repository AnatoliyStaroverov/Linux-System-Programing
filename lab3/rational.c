#include <stdio.h>
#include <stdlib.h> 
#include "rational.h"


// bug 
static Rational rtnl_simplify(Rational rtnl){

    //Euclid's algorithm
    int Euclid_algorithm(int top,int bottom){
          if (top == 0){
              return bottom;
          }
          return Euclid_algorithm(bottom%top, top);
    }

    int gcd =  Euclid_algorithm(rtnl.num,rtnl.denom);
    Rational simp;
    simp.num = rtnl.num / gcd;
    simp.denom  = rtnl.denom / gcd;
    return simp;
}
// function to return simplified rational sum computation.
extern Rational rtnl_add(Rational rtnl0, Rational rtnl1){

    Rational sum;
    sum.num = (rtnl0.num * rtnl1.denom);
    sum.denom = (rtnl0.denom * rtnl1.denom);
    return rtnl_simplify(sum);
}
// not done 
extern Rational rtnl_sub(Rational rtnl0, Rational rtnl1){

    Rational sub;
    sub.num = (rtnl0.num * rtnl1.denom) + (rtnl0.denom * rtnl1.num);
    sub.denom = (rtnl0.denom * rtnl1.denom);
     return rtnl_simplify(sub);
}
// function to return simplified rational mul computation.
extern Rational rtnl_mul(Rational rtnl0, Rational rtnl1){
    Rational mul;
    mul.num = (rtnl0.num * rtnl1.num);
    mul.denom = (rtnl0.denom * rtnl1.denom);
    return rtnl_simplify(mul);
}
// function to return simplified rational div computation.
extern Rational rtnl_div(Rational rtnl0, Rational rtnl1){

    Rational div;
    div.num = (rtnl0.num * rtnl1.denom);
    div.denom = (rtnl0.denom * rtnl1.num);
    return rtnl_simplify(div);
}

extern Rational rtnl_init(int num, int denom){
     Rational init;
     init.num = num;
     init.denom = denom;
     return init;
}

// doesnt take into account negative power.  BUGG
extern Rational rtnl_ipow(Rational rtnl, int ipow){

    Rational power;
    for(int i =0;i<ipow;i++){
        power.num += power.num *power.num;
        power.denom += power.denom *power.denom;
    }
    return power;
}

extern char *rtnl_asStr(Rational rtnl, char buf[RTNL_BUF_SIZE]){

    //char * rationalStr = (char *)malloc(buf);
    char num_str[4];
    sprintf(num_str, "%f", rtnl.num);
    char denom_str[4]; // = itoa(rtnl.denom,denom_str,4);
    sprintf(denom_str, "%f", rtnl.denom);

    buf[0] = '(';
    for(int i =1;i<=RTNL_BUF_SIZE;i++){

        if(i<5){
            int j = 0;
            while(num_str[j] != '\0'){
                buf[i] = num_str[j];
                i++;
                j++;
            }
            i = 5;
            buf[i] = '/';
        }
        else{
            int j = 0;
            while(denom_str[j] != '\0'){
                buf[i] = denom_str[j];
                i++;
                j++;
            }
        }

    }
    buf[RTNL_BUF_SIZE] = ')';
    return buf;
}