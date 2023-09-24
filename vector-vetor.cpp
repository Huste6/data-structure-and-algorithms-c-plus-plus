#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n1,n2;
    cin>>n1>>n2;
    std::vector<std::vector<int>> A;
    std::vector<std::vector<int>> B;
    int sizeofa;
    for(int i=0;i<n1;i++){
        cin>>sizeofa;
        std::vector<int> a(sizeofa);//tao vector co kich thuoc sizeofa;
        for(int j=0;j<sizeofa;j++){
            cin>>a[j];
        }
        A.push_back(a);
    }
    int sizeofb;
    for(int i=0;i<n2;i++){
        std::vector<int> b(2);
        for(int j=0;j<2;j++){
            cin>>b[j];
        }
        B.push_back(b);
    }
    for(int i=0;i<n2;i++){
        std::cout<<A[B[i][0]][B[i][1]]<<endl;
    }
    return 0;
}

