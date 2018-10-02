#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>


struct mta {char* train; int delay; }; // creates struct prototype
struct mta a;

void values(struct mta x){
  printf("The train name is the %s train!\n", x.train);
  printf("Your train, on a daily basis, has %d delays.\n", x.delay);
}

struct mta randomize(){
  srand(time(NULL));
  struct mta new;
  int key = rand() % 24;
  char x[25] = "ABCDEFLMGJZLSNQRW1234567";
  char c = x[key];
  new.train = &c;
  new.delay = (rand()/10000000);
  values(new);
  return new;
}

int modify(struct mta x, char* ntrain, int ndelay){
  x.train = ntrain;
  x.delay = ndelay;
  values(x);
  return 0;
}
  
int main(){
  struct mta a;
  printf("Testing Modify---------\n");
  printf("Expected:\nThe train name is the B train \n Your train, on a daily basis, has 86 delays\n Results\n");
  modify(a, "B", 86);
  printf("Expected:\nThe train name is the D train \n Your train, on a daily basis, has 90 delays\n Results\n");
  modify(a, "D",90);
  printf("Expected:The train name is the C train \n Your train, on a daily basis, has 100000 delays\n Results\n");
  modify(a, "C", 100000);
  randomize();
  return 0;
}
