#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10

int compare (const void *a, const void * b){ 
  return ( *(char *)a - *(char *)b ); 
}

void swap (char* a, char* b){
   char t = *a;
   *a = *b;
   *b = t;
}

void permute(char d[LEN], int len){
  int i,j; 
  //find the rightmost character in it, which is smaller than its next character.
  for(i=len-2;i>=0;--i){
    if(d[i]<d[i+1]) break;
  }
  if(i==-1) return;
  //Now find the ceiling of the ‘first character’. 
  //Ceiling is the smallest character on right of 
  //‘first character’, which is greater than ‘first character’.
  int min=i+1;
  for(j=i+2;j<len;j++){
    if(d[j]>d[i] && d[j]<d[min]){
      min=j;
    }
  }
  //Swap the two characters found in above 2 steps.
  swap(&d[i],&d[min]);

  //Sort the substring (in non-decreasing order) after 
  //the original index of ‘first character’.
  qsort(d+i+1,len-i-1,sizeof(d[0]),compare);  
}


int main(void){      
  char d[LEN] = "0123456789";
  long count = 1;
  while(count<1000000){
    permute(d,LEN);
    count++;
    printf("%s\n",d);
  }
  return EXIT_SUCCESS;
}
