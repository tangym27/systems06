#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>


struct mta { char* train; int delay; }; // creates struct prototype
struct mta a;

int values(struct mta x){
  printf("The train name is the %s train!\n", x.train);
  printf("Your train, on a daily basis, has %d delays.\n", x.delay);
  return 0;
}

struct mta randomize(){
  srand(time(NULL));
  struct mta new;
  new.train = "p";
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
  a.train = "n";
  a.delay = 15;
  values(a);
  modify(a, "b", 86);
  randomize();
  return 0;
}
