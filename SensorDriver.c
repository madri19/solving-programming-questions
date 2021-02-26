// Summary: We have a driver that reads sensor data on an interrupt and stores it.
//Userspace clients all have read access to this data through getLastNData()
//If we currently have 10 pieces of data buffered: [0,1,2,3,4,5,6,7,8,9] where 9 is the most recent data.
//Example: [10,11,12,3,4,5,6,7,8,9] A consumer calling get Last 5 Data will recieve [5,6,7,8,9]

//Todo:
// 1. Implement sensor new data ring buffer
// 2. Implement getLastNData()

#include <stdio.h>

#define MAX 100

int ring[MAX];
int counter = 0;

void recieveNewSensorData(int data){
  //Todo: Store new data in buffer
  ring[counter++] data;
  
  if(counter == MAX)
    counter = 0;
}

//Consumer will call this function to request sensor data.
void getLastNData(int *buffer, int n){
  int k = counter - 1;
  
  for(int i = 0; i < n; i++){
    buffer[i] = ring[k--];
    if(k = -1)
      k = MAX-1;
  }
}

int main(){
  registerISR(&recieveNewSensorData);//fake function to register our interrupt handler.
  while(1){};
  return 0; 
}


