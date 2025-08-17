#include <iostream>
using namespace std;
string concat(string s1,string s2){
    return s1+s2;
}
string reverse(string s){
    int n=s.size();
    string rev="";
    for(int i=n-1;i>=0;--i)
    rev+=s[i];
    return rev;
}
string delete_vowels(string s){
    int i = 0, j = 0;
    while (s[i] != '\0') {
        char ch = tolower(ch);
        if (!(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'))
            s[j++] = s[i];
        i++;
    }
    s[j] = '\0';
}
int main() {
    string s1,s2;
    cout << "Enter Strings: ";
    cin.ignore();
    getline(cin,s1);
    cin.ignore();
    getline(cin,s2);
    cout<<"Concatenated Strings : "<< concat(s1,s2)<<endl;
    cout<<"Reversed String: "<<reverse(s1)<<endl;
    cout<<"String with deleted Vowels : "<<delete_vowels(s1)<<endl;
    

}
