//VERSION: 1.2 withouth memory usage
//Name: Jorge Tchelidze 

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>


int main() {
   int password = 0;
   int dial = 50;
   char line[99];
   char terminate_input[] = "STOP";

   printf("Type the input like \"L\"(left) or \"R\"(right) to select the direction, then the amount you want to rotate the dial \n(\"%s\" to stop)\n", terminate_input); 
   while(scanf("%s", line)){
      if(strcmp(line, terminate_input) == 0)
         break;
      int len = strlen(line);
      if(line[0] != 'R' and line[0] != 'L'){
         printf("Wrong direction\n");
         continue;
      }

      char numb[10];
      int valid = 1;
      int j = 0;
      for(int i = 1; i < len; i++){
         if(line[i] >= '0' && line[i] <= '9')
            numb[j++] = line[i];
         else {
            printf("Dont put any letters int the number of time the day should turn!\n");
            valid = 0;
            break;
         }
      }
      if(!valid){
         continue;
      }
      
      numb[j] ='\0';
      int numbers = atoi(numb);
      printf("dial is : %d\nDirection: %c || The number is %d\n", dial, line[0], numbers);
      if(line[0] == 'R'){
         dial = dial + numbers;
      }
      else
         dial = dial - numbers;

      while(dial < 0 || dial > 99){
         if(dial > 99)
            dial = dial-100;
         else
            dial = dial+100;
      }
      printf("Dial end : %d\n",dial);
      if(dial == 0){
         printf("JACKPOT\n");
         password++;
      }
   }
      printf("The password is : %d\n",password);
   return 0;

}
