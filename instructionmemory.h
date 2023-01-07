#include <string>
#include <bits/stdc++.h>
#include <math.h>
#include <cstdlib>

using namespace std;

class InstMem
{
private:
    bitset<32> *IM = (bitset<32>*)malloc(4294967296 * sizeof(bitset<32>));
    template<size_t size>
    int binaryToDec(bitset<size> addr);
public:
    bitset<32> readValue(bitset<32> addr);
    void writeValue(bitset<32> addr, bitset<32> value);
    ~InstMem();
};


InstMem::~InstMem(){
    free(IM);
}
void InstMem::writeValue(bitset<32> addr, bitset<32> value){
    int address = binaryToDec(addr);
    IM[address] = value;
}

bitset<32> InstMem::readValue(bitset<32> addr){
    int address = binaryToDec(addr);
    return IM[address];
}

template <size_t size>
int InstMem::binaryToDec(bitset<size> addr){
    int num = 0;
    
    for(int i = 0; i < 5; i++){
        num += addr[i] * (int) pow(2, i);
    }

    return num;
}
