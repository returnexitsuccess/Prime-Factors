#include <stdio.h>
#include <math.h>

struct Factor
{
   int currentCheck;
   int dividend;
   int original;
};
struct Factor factor (struct Factor values);

int main() {

   struct Factor values;
   int returnCheck;
   char buf[15];

   //FOR USER INPUT
   printf ("What number would you like to factor:\n");
   returnCheck = scanf ("%d", &values.dividend);
   
   //FOR FILE INPUT
   //fgets(buf, sizeof(buf), stdin);
   //returnCheck = sscanf(buf, "%d", &values.dividend);

   while (returnCheck == 1) {

      printf ("%d: ", values.dividend);

      values.currentCheck = 2;
      values.original = values.dividend;
      while (values.currentCheck) {

         values = factor (values);

      }

      //FOR FILE INPUT
	  //fgets(buf, sizeof(buf), stdin);
      //returnCheck = sscanf(buf, "%d", &values.dividend);
	  
	  //FOR USER INPUT
      returnCheck = scanf ("%d", &values.dividend);     

   }

   return 0;

}

struct Factor factor (struct Factor values) {

   if (sqrt(values.dividend) < values.currentCheck) {

      if (values.original == values.dividend) {

         printf ("Prime\n");

      } else {

         printf ("%d\n", values.dividend);

      }

      values.currentCheck = 0;

   } else if ((values.dividend % values.currentCheck) == 0) {

      printf ("%d x ", values.currentCheck);
      values.dividend = values.dividend / values.currentCheck;

   } else {

      values.currentCheck++;

   }

   return values;

}
