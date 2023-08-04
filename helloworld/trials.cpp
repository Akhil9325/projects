#include<bits/stdc++.h>
using namespace std;
void deletemiddle(stack<int> &st){
    vector<int> temp = {};
    int n = st.size();
    int mid =  n/2 + 1;
    int diff = n - mid;
    while(diff){
        temp.push_back(st.top());
        st.pop();
        diff--;
    }
    st.pop();
    int num = temp.size();
    for (int i = 0; i < num; i++)
    {
        st.push(temp[i]);
    }
    
}
void display(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(22);
    st.push(343);
    st.push(5);
    deletemiddle(st);
    display(st);

}