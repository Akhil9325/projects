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
int findmiddle(stack<int> st){
  int n = st.size();
  int mid = (n/2 + 1);
  int diff = (n - mid);
  while(diff){
    st.pop();
    diff--;
  }
  return st.top();
}
int getmin(stack<int> st){
  int min = st.top();
  while(!st.empty()){
    if(st.top() < min){
      min = st.top();
    }
    st.pop();
  }
  return min;
}
void display(stack<int> st){
  cout<<st.top()<<" ";
  st.pop();
}
# define n 20
class queued{
  int* arr;
  int front;
  int back;
  public:
  queued(){
    arr = new int[n];
    front = back = -1;
  }
  void push(int x){
    if(back == n-1){
      cout<<"queue overflow"<<endl;
      return;
    }
    back++;
    arr[back] = x;
    if(front == -1){
      front++;
    }
  }
  void dequeue(){
    if(front == -1 or front > back){
      cout<<"queue empty"<<endl;
      return;
    }
    front++;
  }
  int peek(){
    if(front == -1 or front > back){
      cout<<"queue empty"<<endl;
      return -1;
    }
    return arr[front];
  }
  bool empty(){
    if(front == -1 or front > back){
      return true;
    }
    return false;
  }

};
class stacked{
  public:
  queue<int> q1;
  queue<int> q2;
  void push(int x){
    q1.push(x);
  }
  void pop(){
    while(!q1.size() != 1){
      q2.push(q1.front());
      q1.pop();
    }
    q1.pop();
    queue<int> temp = q2;
    q2 = q1;
    q1 = temp;
  }
};

int main(){
stack<int> str;
queued qu;
qu.push(1);
qu.push(2);
qu.push(3);
qu.push(4);
cout<<qu.peek()<<endl;
qu.dequeue();
cout<<qu.peek()<<endl;

} 