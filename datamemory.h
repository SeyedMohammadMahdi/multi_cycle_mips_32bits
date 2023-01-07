#include <string>
#include <bits/stdc++.h>
#include <math.h>
#include <cstdlib>

using namespace std;

class DataMem
{
private:
    bitset<32> *DM = (bitset<32>*)malloc(4294967296 * sizeof(bitset<32>));
    template<size_t size>
    int binaryToDec(bitset<size> addr);
public:
    bitset<32> readValue(bitset<32> addr);
    void writeValue(bitset<32> addr, bitset<32> value);
    ~DataMem();
};


DataMem::~DataMem(){
    free(DM);
}
void DataMem::writeValue(bitset<32> addr, bitset<32> value){
    int address = binaryToDec(addr);
    DM[address] = value;
}

bitset<32> DataMem::readValue(bitset<32> addr){
    int address = binaryToDec(addr);
    return DM[address];
}

template <size_t size>
int DataMem::binaryToDec(bitset<size> addr){
    int num = 0;
    
    for(int i = 0; i < 5; i++){
        num += addr[i] * (int) pow(2, i);
    }

    return num;
}
