//VERSION 1.0 with memory usage 
//Name Jorge Tchelidze
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

void read_input(char *rotation_direc, int *rotation_number){

   char line[99];
   int line_count = 0;
   char terminate_input[] = "STOP";

   printf("Type \"%s\" to stop the input\n", terminate_input); 
   while(scanf("%s", line)){
      if(strcmp(line, terminate_input) == 0)
         break;
      int len = strlen(line);
      if(line[0] != 'D' and line[0] != 'L'){
         printf("Wrong direction\n");
         continue;
      }

      char *tmp = (char *)realloc(rotation_direc, (line_count + 1) * sizeof(char));
      if (!tmp) {
         printf("Memory allocation failed\n");
         exit(1);
      }
      rotation_direc = tmp;

      rotation_direc[line_count] = line[0];
      printf("rotation_direc is : %c\n", rotation_direc[line_count]);

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
      printf("numbers: %d\n", numbers);
      rotation_number[line_count] = numbers;

      line_count++;
   }
}


int decode(char *rotation_direc,int n_dire, int *rotation_number,int n_numb){
   int dial = 50;
   int result = 0;
   for(int i = 0; i < n_dire; i++){
      if(rotation_direc[i] == 'D'){
         dial = dial + rotation_number[i];
      }
      else
         dial = dial - rotation_number[i];

      while(dial <0 && dial >Z 99){
         if(dial > 99)
            dial = dial-99;
         else
            dial = dial+99;
      }
      if (dial == 0)
         result++;
   }


   return result;
}


int main() {
   //list of the direction it rotate
   char *rotation_direc = (char *)malloc(sizeof(char) * 1);
   //list of the number of times it rotates
   int *rotation_number = (int *)malloc(sizeof(int) * 1);
   read_input(rotation_direc,rotation_number);

   
   int n_num = sizeof(rotation_number) / sizeof(rotation_number[0]);
   int n_dir = sizeof(rotation_direc) / sizeof(rotation_direc[0]);
   printf("size of the direction %d\n", n_dir);
   printf("size of the Numbers %d\n", n_num);

   printf("direction: %s\n", rotation_direc);
   for(int i = 0; i <= n_num; i++){
      printf("numbers: %d\n", rotation_number[i]);
   }

   int password = decode(rotation_direc, n_dir, rotation_number, n_num);
   
   printf("The password is: %d\n", password);

   free(rotation_direc);
   free(rotation_number);
   rotation_number = NULL;
   rotation_direc = NULL;

   return 0;

}
