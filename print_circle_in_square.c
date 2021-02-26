//Create a function that takes a square and a circle and draw a circle within the center of the square.
#include <stdio.h>
#include <math.h>

//Figure out the distance of an x,y to the center, return the distance from the center.
int distanceFromCenter(int x, int y, int size){
  int c;
  int center = size/2;
  int a,b;
  
  a = x - center;
  b = y - center;
  
  c = (a*a) + (b*b);
  c = sqrt(c);
  
  return c;
}

//Print out the square with a circle in it.
void print_square_circle(int size, int circleDiameter){
 int fromCenter;
  
  for(int i = 0; i < size; i++){
    
    for(int j = 0; j < size; j++){
      
      fromCenter = distanceFromCenter(i, j, size);
      
      if(fromCenter < circleDiameter/2)
          print(" FF");
      else
          print(" 00");
      
      if(j == size - 1)
        print("\n");
    }
  }
}
 int main(){
  print_square_circle(20, 15);
  return 0;
 }
