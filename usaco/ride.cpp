/*
ID: wenzeli1
TASK: ride
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b;
    fin>>a>>b;
    int a1=1,a2=1;
    for(auto i:a) a1 = (a1*(i-'A'+1))%47;
    for(auto i:b) a2 = (a2*(i-'A'+1))%47;
    if(a1==a2) fout<<"GO"<<endl;
    else fout<<"STAY"<<endl;
    return 0;
}