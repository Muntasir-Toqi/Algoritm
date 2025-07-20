#include<iostream>
using namespace std;

void findCommonChar(string s1,string s2,int n1,int n2) {
    for(int i = 0; i < n1 ; i++) {
        for(int j = 0; j < n2; j++) {
            if(s1[i] == s2[j]) {
                cout << s1[i]<<" ";
                break;
            }
        }
    }
}

int main() {

    string s1 = "convention", s2 = "competitive";
    int n1 = s1.length(), n2 = s2.length();
    cout << "Common characters:" << endl;
    findCommonChar(s1, s2,n1,n2);

    return 0;
}
