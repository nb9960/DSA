// Author:Nishtha

#include <bits/stdc++.h> 
using namespace std; 

int applyOp(int a, int b, char op){
  switch(op){
    case '+' : return a+b;
    case '-' : return a-b;
    case '*' : return a*b;
    case '/' : return a/b;
  }
}

int precedence(char op){
  if(op == '+'||op == '-')
  return 1;
  if(op == '*'||op == '/')
  return 2;
  return 0;
}
  
int evaluate(string tokens){
  int i;
  stack<int> values, operators;
  for(i=0;i<tokens.length();i++){
    if(tokens[i]==' ') continue;
    else if(tokens[i]=='(')
      operators.push(tokens[i]);
    else if(isdigit(tokens[i])){
      int val=0;
      while(i<tokens.length() && isdigit(tokens[i])){
        val = (val*10) + (tokens[i]-'0');
        i++;
      }
      values.push(val);
      i--;
    }
    else if(tokens[i]==')'){
      while(!operators.empty() && operators.top() != '('){
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = operators.top();
        operators.pop();

        values.push(applyOp(val1, val2, op));
      }
      if(!operators.empty())
        operators.pop();
    }else{
      // token is operator
      while(!operators.empty() && precedence(operators.top())>=precedence(tokens[i])){
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(applyOp(val1, val2, op));
      }
      operators.push(tokens[i]);
    }
  }

  while(!operators.empty()){
    int val2 = values.top();
    values.pop();
    int val1 = values.top();
    values.pop();
    char op = operators.top();
    operators.pop();
    values.push(applyOp(val1, val2, op));
  }
  return values.top();
}

int main(){
  cout << evaluate("10 + 2 * 6") << "\n";
  cout << evaluate("100 * 2 + 12") << "\n";
  cout << evaluate("100 * ( 2 + 12 )") << "\n";
  cout << evaluate("100 * ( 2 + 12 ) / 14");
  return 0;
}