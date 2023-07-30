#include<bits/stdc++.h>
using namespace std;
void reversestring(string s){
  stack<string> st;
  for (int i = 0; i < s.length(); i++)
  {
    string words = "";
    while(s[i] != ' ' && i<s.length()){
      words += s[i];
      i++;
    }
    st.push(words);
  }
  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
}
void insertatbottom(stack<int> &st,int ele){
  if(st.empty()){
    st.push(ele);
    return;
  }
  int topele = st.top();
  st.pop();
  insertatbottom(st,ele);
  st.push(topele);
}
void reverse(stack<int> &st){
  if(st.empty()){
    return;
  }
  int ele = st.top();
  st.pop();
  reverse(st);
  insertatbottom(st,ele);

}
int prefixeval(string str){
  int n = str.length();
  stack<int> st;
  for (int i = n-1; i>=0; i--)
  {
    if(str[i]>='0' && str[i]<='9'){
      st.push(str[i] - '0');
    }
    else{
      int op1 = st.top();
      st.pop();
      int op2 = st.top();
      st.pop();
      switch(str[i]){
        case '+':
        st.push(op1 + op2);
        break;
        case '-':
        st.push(op1 - op2);
        break;
        case '*':
        st.push(op1 * op2);
        break;
        case '/':
        st.push(op1/op2);
        break;
        case '^':
        st.push(pow(op1,op2));
        break;
      }

    }
  }
  return st.top();
  
}
int main(){
stack<int> str;
str.push(1);
str.push(2);
str.push(3);
str.push(4);
string ss = "-5*36";
cout<<prefixeval(ss);
}