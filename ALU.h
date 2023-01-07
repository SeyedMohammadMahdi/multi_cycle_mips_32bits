#include <bits/stdc++.h>
#include <string>
#include <variant>
using namespace std;

class ALU
{
private:
//    bitset<32> a, b;
    
    // bitset<32> sub(bitset<32> a, bitset<32> b);
    // bitset<32> and_(bitset<32>& a, bitset<32>& b);
    // bitset<32> or_(bitset<32>& a, bitset<32>& b);
    // bitset<32> twosComplement(bitset<32>& a);
    bool fullAdder(bool b1, bool b2, bool& carry);

public:
    // bitset<32> output;
    // variant<bitset<32>, bool> alu(bitset<6> operation, bitset<32> a, bitset<32> b);
    bitset<32> add(bitset<32> a, bitset<32> b);
    bitset<32> sub(bitset<32> a, bitset<32> b);
    bitset<32> twosComplement(bitset<32> a);
    bitset<32> and_(bitset<32> a, bitset<32> b);
    bitset<32> or_(bitset<32> a, bitset<32> b);
    bitset<32> slt(bitset<32> a, bitset<32> b);
};




bool ALU::fullAdder(bool b1, bool b2, bool& carry)
{
    bool sum = (b1 ^ b2) ^ carry;
    carry = (b1 && b2) || (b1 && carry) || (b2 && carry);
    return sum;
}


bitset<32> ALU::add(bitset<32> a, bitset<32> b)
{
    bool carry = false;
    
    bitset<32> ans;
    for (int i = 0; i < 32; i++) {
        ans[i] = fullAdder(a[i], b[i], carry);
    }
    return ans;
}


bitset<32> ALU::sub(bitset<32> a, bitset<32> b){
    return add(a, twosComplement(b));
}


bitset<32> ALU::twosComplement(bitset<32> a){
    return add(~a, bitset<32>(1));
}


bitset<32> ALU::and_(bitset<32> a, bitset<32> b){
    return (a & b);
}
bitset<32> ALU::or_(bitset<32> a, bitset<32> b){
    return (a | b);
}

bitset<32> ALU::slt(bitset<32> a, bitset<32> b){
    bitset<32> res = sub(a, b);
    if(res[31] == 1){
        return bitset<32>(1);
    }
    
    return bitset<32>(0);
}

