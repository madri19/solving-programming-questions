// Lets say you got a buffer string from a device through UART, make sure you parse the data and add it to the struct below with appropriate data types.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct{
  int value;
  char *name;
  float lat;
  float longit;
  int active;
  int flag;
    
}data_handler;

int main () {
  //This can be something like gps data that you need to parse and add into a struct with the correct data types.
  char str[80] = "123,abcdefghi,3213.32,6541.14,1,false";
  const char s[] = ",";

  int len = strlen(str);

  //replace ',' with null so the string can be split.
  for(int i = 0; i < len; i++){
     if(str[i] == *s){
          str[i] = '\0';
     }
  }

 char *pointer = str;

 //do some pointer math as you iteract through all the separate strings and convert the value to the approppriate data type and assign it to our struct object.
 data_handler.value = atoi(pointer);
 pointer = str+strlen(str)+1;
 data_handler.name = pointer;
 pointer = pointer+strlen(pointer)+1;
 data_handler.lat = atof(pointer);
 pointer = pointer+strlen(pointer)+1;
 data_handler.longit = atof(pointer);
 pointer = pointer+strlen(pointer)+1;
 data_handler.active = atoi(pointer);
 pointer = pointer+strlen(pointer)+1;
 if(strcmp(pointer, "false") == 0)
  data_handler.flag = 0;
 else
  data_handler.flag = 1;
   
   
  printf( " %d\n", data_handler.value );
  printf( " %s\n", data_handler.name );
  printf( " %f\n", data_handler.lat );
  printf( " %f\n", data_handler.longit );
  printf( " %d\n", data_handler.active );
  printf( " %d\n", data_handler.flag );
  
  return 0;
}
