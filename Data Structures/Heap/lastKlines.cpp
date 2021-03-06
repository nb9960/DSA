#include <bits/stdc++.h>
using namespace std;
#define DELIM '\n'

void print_last_lines(const char* s, int n){
  const char *start = NULL;
  int count = 0;
  int indexend = -1;

  if(s) indexend = (int)strlen(s) - 1;
  while(count != n && indexend != -1){
    if(s[indexend] == '\n')
    count++;
    indexend--;
  }
  if(indexend == -1) start = &s[0];
  else start = &s[indexend];
  printf("%s", start);
}

int main(void){
  const char *s1 ="str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8\nstr9"
                "\nstr10\nstr11\nstr12\nstr13\nstr14\nstr15\nstr16\nstr17"
                "\nstr18\nstr19\nstr20\nstr21\nstr22\nstr23\nstr24\nstr25";  
  int k =10;
  print_last_lines(s1,k);
  return 0;
}