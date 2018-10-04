#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char s[10] = " train";


struct mta {char train[20]; int delay; };  // creates struct prototype
struct mta a; // initalizes a struct

// Write a function that prints out variables of your structs type in a reasonable way.
void values(struct mta x){
  printf("Your train is the %s.\n", x.train);
  printf("Today, your train has %d delays.\n", x.delay);
}

//Write a function that returns an example of your struct when run.
struct mta randomize(){
  // Creates new struct
  struct mta new;
  char x[] = "ABCDEFLMGJZLSNQRW1234567";
  int key = rand() % 24;
  // Sets char train to a random letter
  new.train[0] = x[key];
  // ADDS A TERMINATING NULL 
  new.train[1] = 0;
  // concatenates the letter and the word train together
  strcat(new.train,s);
  // sets delay to a randomize value 
  new.delay = (rand() % 100);
  // prints out the variables of our struct
  values(new);
  return new;
}

//Write a function that modifies values of your struct's type.
void modify(struct mta x, char* ntrain, int ndelay){
  // sets x.train to have value of ntrain
  x.train[0] = ntrain[0];
  // ADDS A TERMINATING NULL SO IT CAN BE CONCATENATED! 
  x.train[1] = 0;
  strcat(x.train,s);
  // changes delay
  x.delay = ndelay;
  // prints out the variables of our struct
  values(x);
}
 
//Write a main function that tests all these things.
int main(){
  srand(time(NULL));
  
  printf("---Testing Randomize and Values---\n");
  printf("Train 0:\n");
  randomize(); 

  printf("Train 1:\n");
  randomize();

  printf("Train 2:\n");
  randomize();

  printf("---Testing Modify and Values---\n" );
  printf("Currently this is your train: \n");
  a = randomize();
  printf("Change the train to the 1 train and the number of delays to 15:\n");
  modify(a, "1", 15);
  printf("Change the train to the L train and the number of delays to 30:\n");
  modify(a, "L", 30);

  return 0;
}