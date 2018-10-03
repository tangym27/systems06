#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct mta {char train[20]; int delay; }; // creates struct prototype
struct mta a;

void values(struct mta x){
  printf("The train name is the: %s!\n", x.train);
  printf("Your train, on a daily basis, has %d delays.\n", x.delay);
}

struct mta randomize(){
  srand(time(NULL));
  struct mta new;
  int key = rand() % 23;
  printf("%d\n",rand());
  char x[] = "ABCDEFLMGJZLSNQRW1234567";
  new.train[0] = x[key];
  new.train[1] = 0;
  char s[10] = " train";
  strcat(new.train,s);
  new.delay = (rand() % 100);
  values(new);
  return new;
}

int modify(struct mta x, char* ntrain, int ndelay){
  char s[10] = " train";
  x.train[0] = ntrain[0];
  x.train[1] = 0;
   strcat(x.train,s);
  x.delay = ndelay;
  values(x);
  return 0;
}
  
int main(){
  struct mta a;
  char s1[2] = "B";
  char s2[2] = "D";
  char s3[2] = "C";
  
  printf("Testing Modify---------\n");
  printf("Expected:\nThe train name is the B train \nYour train, on a daily basis, has 86 delays\n Results:\n");
  modify(a, s1, 86);
  printf("Expected:\nThe train name is the D train \nYour train, on a daily basis, has 90 delays\n Results:\n");
  modify(a, s2,90);
  printf("Expected:\nThe train name is the C train \nYour train, on a daily basis, has 100000 delays\n Results:\n");
  modify(a, s3, 100000);
  
  randomize();

  randomize();
  return 0;
}
