#include<bits/stdc++.h>
using namespace std;
vector<string> temp ;

void subsequence(string input,string output){
    if(input.length() == 0){
        temp.push_back(output);
        return;
    }
    subsequence(input.substr(1),output);
    subsequence(input.substr(1),output + input[0]);
}
int main(){
    string str = "abc";
    string output = "";
    subsequence(str,output);
    int n = temp.size();
    for (int i = 0; i < n; i++)
    {
        cout<<temp[i]<<" ";
    }
    

}