#include <string>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class RFile
{
private:
    bitset<32> RF[32];
    int binaryToDec(bitset<5> addr);
public:
    bitset<32> readValue(bitset<5> addr);
    void writeValue(bitset<5> addr, bitset<32> value);


};

void RFile::writeValue(bitset<5> addr, bitset<32> value){
    int address = binaryToDec(addr);
    RF[address] = value;
}

bitset<32> RFile::readValue(bitset<5> addr){
    int address = binaryToDec(addr);
    return RF[address]; 
}


int RFile::binaryToDec(bitset<5> addr){
    int num = 0;
    
    for(int i = 0; i < 5; i++){
        num += addr[i] * (int) pow(2, i);
    }

    return num;
}
