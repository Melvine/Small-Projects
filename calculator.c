/*Melvin Nguyen 1/26/2014*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

 int main(){ 
   double x,y,result;
   char sign;
   printf("enter expression: ");
   scanf("%lf %c %lf", &x,&sign,&y);
   /*printf("%lf %c %lf \n", x, sign, y);*/

   if(isalnum(sign) != 0){
     printf("bad expression \n");
     return 1; 
   }
   
   
   switch(sign){
    case '+':
      result = x + y;
      break;
    case '-':
      result = x - y;
      break;
    case '/':
      if (y == 0.0){ printf("Can't divide by zero \n"); return 1;}  
      result = x/y;
      break;
    case '*':
      result = x*y;
      break;
   }  
   
   printf("result: %.3lf \n", result);    
   return 0;
}
 
