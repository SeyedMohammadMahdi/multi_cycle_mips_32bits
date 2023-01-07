#include "registerfile.h"
#include <bits/stdc++.h>
#include "datamemory.h"
#include "instructionmemory.h"
#include "ALU.h"
using namespace std;
class CPU
{
private:

    // DataMem DM;
    // InstMem IM;
    ALU opAlu, pcAlu;
    // RFile RF;
    // bitset<32> pc;
    // int decoder(bitset<32> mCode);
    bitset<6> func;
    bitset<32> opcode[5];
    int op[5];
    bitset<32> pcs[5];
    bitset<32> a[5];
    bitset<32> b[5];
    bitset<5> destination[5];
    bitset<32> values[5];
    bitset<32> writeData;
    int stall;
    int decoder();
    void shifter(int n);
    void dataFetch();
    void exe();
    void mem();
    void wb();
    bool compare(bitset<5> b1, bitset<5> b2);

public:
    InstMem IM;
    DataMem DM;
    RFile RF;
    bitset<32> pc;
    void cpu();
    CPU();
    int iCount;
};

CPU::CPU(){
    RF.writeValue(bitset<5>(0), bitset<32>(0));
    for(int i = 0; i < 5; i++){
        this->opcode[i] = bitset<32>(0);
        this->op[i] = 0;
        this->a[i] = bitset<32>(0);
        this->b[i] = bitset<32>(0);
        this->values[i] = bitset<32>(0);
    }
    this->stall = 0;
}


void CPU::cpu(){
    for(int i = 0; i < this->iCount; i++){

        decoder();
        dataFetch();
        exe();
        mem();
        wb();
        // if(op[4] == 32){
        //     // add
        //     RF.writeValue(this->destination[4], this->values[3]);
        // }
        // else if(op[4] == 34){
        //     // sub
        //     RF.writeValue(this->destination[4], this->values[4]);
        // }
        // else if(op[4] == 36){
        //     // and
        //     RF.writeValue(this->destination[4], this->values[4]);
        // }
        // else if(op[4] == 37){
        //     // or
        //     RF.writeValue(this->destination[4], this->values[4]);
        // }
        // else if(op[4] == 42){
        //     // slt
        //     RF.writeValue(this->destination[4], this->values[4]);
        // }
        // else if(op[1] == 2){
        //     // jump
        //     bitset<28> imm(0);
        //     for(int j = 25; j >= 0; j--){
        //         imm[j] = this->opcode[1][j];
        //     }
        //     imm <<= 2;
        //     for(int j = 27; j >= 0; j--){
        //         pc[j] = imm[j];
        //     }
        // }
        // else if(op[4] == 8){
        //     // addi
        //     RF.writeValue(this->destination[4], this->values[4]);
        // }
        // else if(op[4] == 12){
        //     // andi
        //     RF.writeValue(this->destination[4], this->values[4]);
        // }

        // else if(op[4] == 13){
        //     // ori
        //     RF.writeValue(this->destination[4], this->values[4]);
        // }
        // else if(op[4] == 10){
        //     // slti
        //     RF.writeValue(this->destination[4], this->values[4]);
        // }

        // else if(op[4] == 35){
        //     // lw
        //     RF.writeValue(this->destination[4], this->values[4]);
        // }
        // else if(op[4] == 43){
        //     // sw
        // }
        // else if(op[1] == 4){
        //     // beq
        //     bitset<5> add1, add2;
        //     for(int j = 25, k = 4; j >= 21; j--, k--){
        //         add1[k] = this->opcode[1][j];
        //         add2[k] = this->opcode[1][j - 5];
        //     }

        //     bitset<32> data1 = RF.readValue(add1);
        //     bitset<32> data2 = RF.readValue(add2);
        //     if(opAlu.sub(data1, data2) == 0){
        //         bitset<32> imm;
        //         if(this->opcode[1][15] == 1){
        //             imm.set();
        //         }
        //         else{
        //             imm.reset();
        //         }

        //         for(int j = 15; j >= 0; j--){
        //             imm[j] = this->opcode[1][j];
        //         }
        //         imm <<= 2;
        //         pc = opAlu.add(pc, imm);
        //     }
        //     else{
        //         pc = opAlu.add(pc, bitset<32>(4));
        //     }
        // }
        // else if(op[1] == 5){
        //     // bnq
        //     bitset<5> add1, add2;
        //     for(int j = 25, k = 4; j >= 21; j--, k--){
        //         add1[k] = this->opcode[1][j];
        //         add2[k] = this->opcode[1][j - 5];
        //     }

        //     bitset<32> data1 = RF.readValue(add1);
        //     bitset<32> data2 = RF.readValue(add2);
        //     if(opAlu.sub(data1, data2).to_ulong() != 0){
        //         bitset<32> imm;
        //         if(this->opcode[1][15] == 1){
        //             imm.set();
        //         }
        //         else{
        //             imm.reset();
        //         }

        //         for(int j = 15; j >= 0; j--){
        //             imm[j] = this->opcode[1][j];
        //         }
        //         imm <<= 2;
        //         pc = opAlu.add(pc, imm);
        //     }
        //     else{
        //         pc = opAlu.add(pc, bitset<32>(4));
        //     }
        // }
        if(this->stall == 0)
            this->shifter(0);
        else{
            this->shifter(2);
        }
    }   

}


int CPU::decoder(){
    bitset<32> mCode = IM.readValue(pc);
    this->pcs[0] = pc;
    this->opcode[0] = mCode;
    pc = pcAlu.add(pc, bitset<32>(4));

    bool Rtype = true;
    bitset<6> opCode;
    for(int i = 31, j = 0; i >= 26; i--, j++){
        if(mCode[i] == 1){
            Rtype = false;
        }
        opCode[j] = mCode[i];
    }
    
    
    if(Rtype){
        for(int i = 5; i >= 0; i--){
            func[i] = mCode[i];
        }
        this->op[0] = func.to_ulong();
        return func.to_ulong();
    }
    else{
        for(int i = 31, j = 5; i >= 26;i--, j--){
            func[j] = mCode[i];
        }
        this->op[0] = func.to_ulong();
        return func.to_ulong();
    }
    
}

void CPU::shifter(int n){
    for(int i = 3; i >= n; i--){
        this->opcode[i + 1] = this->opcode[i];
        this->op[i + 1] = this->op[i];
        this->destination[i + 1] = this->destination[i];
        this->a[i + 1] = this->a[i];
        this->b[i + 1] = this->b[i];
        this->values[i + 1] = this->values[i];

    }
}


void CPU::dataFetch(){
    if(op[1] == 32 || op[1] == 34 || op[1] == 36 || op[1] == 37 || op[1] == 42){
        bitset<5> add1, add2;
        for(int j = 25, k = 4; j >= 21; j--, k--){
            add1[k] = this->opcode[1][j];
            add2[k] = this->opcode[1][j - 5];
        }

        bitset<32> data1 = RF.readValue(add1);
        bitset<32> data2 = RF.readValue(add2);
        this->a[1] = data1;
        this->b[1] = data2;

        bitset<5> dest;
        for(int j = 15, k = 4; j >= 1; j--, k--){
            dest[k]= this->opcode[1][j];
        }
        this->destination[1] = dest;
    }
    else if(op[1] == 8 || op[1] == 12 || op[1] == 13 || op[1] == 10){
        bitset<5> add1, dest;
        for(int j = 25, k = 4; j >= 21; j--, k--){
            add1[k] = this->opcode[1][j];
            dest[k] = this->opcode[1][j - 5];
        }

        bitset<32> data1 = RF.readValue(add1);
        bitset<32> data2;
        if (this->opcode[1][15] == 1){
            data2.set();
        }
        else{
            data2.reset();
        }

        for(int j = 15; j >= 0; j--){
            data2[j] = this->opcode[1][j];
        }

        this->a[1] = data1;
        this->b[1] = data2;
        this->destination[1] = dest;
    }
    else if(op[1] == 35){
        bitset<5> base, dest;
        for(int j = 25, k = 4; j >= 21; j--, k--){
            base[k] = this->opcode[1][j];
            dest[k] = this->opcode[1][j - 5];
        }

        bitset<32> offset;
        if(this->opcode[1][15] == 1){
            offset.set();
        }
        else{
            offset.reset();
        }

        for(int j = 15; j >= 0; j--){
            offset[j]= this->opcode[1][j];
        }

        bitset<32> data = RF.readValue(base);
        this->a[1] = data;
        this->b[1] = offset;
        this->destination[1] = dest;
    }
    else if(op[1] == 43){
        bitset<5> base, dest;
        for(int j = 25, k = 4; j >= 21; j--, k--){
            base[k] = this->opcode[1][j];
            dest[k] = this->opcode[1][j - 5];
        }

        bitset<32> offset;
        if(this->opcode[1][15] == 1){
            offset.set();
        }
        else{
            offset.reset();
        }

        for(int j = 15; j >= 0; j--){
            offset[j]= this->opcode[1][j];
        }

        bitset<32> data = RF.readValue(base);
        bitset<32> data1 = RF.readValue(dest);

        this->a[1] = data;
        this->b[1] = offset;
        this->writeData = data1;
    }
    else if(this->op[1] == 2){
        bitset<28> imm(0);
            for(int j = 25; j >= 0; j--){
                imm[j] = this->opcode[1][j];
            }
            imm <<= 2;
            for(int j = 27; j >= 0; j--){
                pcs[1][j] = imm[j];
            }
            this->pc = pcs[1];
            this->op[0] = 0;
            this->iCount++;
    }
    else if(this->op[1] == 4){
        bitset<5> add1, add2;
        for(int j = 25, k = 4; j >= 21; j--, k--){
            add1[k] = this->opcode[1][j];
            add2[k] = this->opcode[1][j - 5];
        }

        bitset<32> data1 = RF.readValue(add1);
        bitset<32> data2 = RF.readValue(add2);
        this->a[1] = data1;
        this->b[1] = data2;
    }
    else if(this->op[1] == 5){
        bitset<5> add1, add2;
        for(int j = 25, k = 4; j >= 21; j--, k--){
            add1[k] = this->opcode[1][j];
            add2[k] = this->opcode[1][j - 5];
        }

        bitset<32> data1 = RF.readValue(add1);
        bitset<32> data2 = RF.readValue(add2);
        this->a[1] = data1;
        this->b[1] = data2;
    }
}

void CPU::exe(){
    if(this->stall == 1){
        this->op[2] = 0;
        this->stall = 0;
    }
    if(op[2] == 32 || op[2] == 8 || op[2] == 43 || op[2] == 35){
        this->values[2] = opAlu.add(this->a[2], this->b[2]);
    }
    else if(op[2] == 34){
        this->values[2] = opAlu.sub(this->a[2], this->b[2]);
    }
    else if(op[2] == 36 || op[2] == 12){
        this->values[2] = opAlu.and_(this->a[2], this->b[2]);
    }
    else if(op[2] == 37 || op[2] == 13){
        this->values[2] = opAlu.or_(this->a[2], this->b[2]);
    }
    else if(op[2] == 42 || op[2] == 10){
        this->values[2] = opAlu.slt(this->a[2], this->b[2]);
    }
    else if(op[2] == 4){
        if(opAlu.sub(this->a[2], this->b[2]) == 0){
            bitset<32> imm;
            if(this->opcode[2][15] == 1){
                imm.set();
            }
            else{
                imm.reset();
            }

            for(int j = 15; j >= 0; j--){
                imm[j] = this->opcode[2][j];
            }
            imm <<= 2;
            pc = opAlu.add(pcs[2], imm);
            iCount += 2;
            op[1] = 0;
            op[0] = 0;
            // cout << pcs[2] << endl;
            
        }
            // else{
            //     pc = opAlu.add(pc, bitset<32>(4));
            // }
    }
    else if(op[2] == 5){
        if(opAlu.sub(this->a[2], this->b[2]) != 0){
            bitset<32> imm;
            if(this->opcode[1][15] == 1){
                imm.set();
            }
            else{
                imm.reset();
            }

            for(int j = 15; j >= 0; j--){
                imm[j] = this->opcode[1][j];
            }
            imm <<= 2;
            pc = opAlu.add(pcs[2], imm);
            iCount += 2;
            op[1] = 0;
            op[0] = 0;
        }
    }

    if(op[2] == 32 || op[2] == 8 || op[2] == 34 || op[2] == 36 || op[2] == 12 ||
    op[2] == 37 || op[2] == 13 || op[2] == 42 || op[2] == 10){

        if(op[1] == 32 || op[1] == 34 || op[1] == 36 || op[1] == 37 || op[1] == 42 || op[1] == 43 || op[1] == 4 || op[1] == 5){
            
            bitset<5> add1, add2;
            for(int j = 25, k = 4; j >= 21; j--, k--){
                add1[k] = this->opcode[1][j];
                add2[k] = this->opcode[1][j - 5];
            }
            
            // cout <<  << endl;
            if(this->compare(add1, this->destination[2])){
                this->a[1] = this->values[2];
                // cout << a[1] << endl;
            }
            
            if(this->compare(add2, this->destination[2])){
                this->b[1] = this->values[2];
            }
        }
        
        else if(op[1] == 8 || op[1] == 12 || op[1] == 13 || op[1] == 10 || op[1] == 35){
            bitset<5> add1;
            for(int j = 25, k = 4; j >= 21; j--, k--){
                add1[k] = this->opcode[1][j];
                // add2[k] = this->opcode[1][j - 5];
            }
            if(this->compare(add1, this->destination[2])){
                this->a[1] = this->values[2];
            }
        }
    }
    else if(op[2] == 35){
        if(op[1] == 32 || op[1] == 34 || op[1] == 36 || op[1] == 37 || op[1] == 42 || op[1] == 43 || op[1] == 4 || op[1] == 5){
            


            bitset<5> add1, add2;
            for(int j = 25, k = 4; j >= 21; j--, k--){
                add1[k] = this->opcode[1][j];
                add2[k] = this->opcode[1][j - 5];
            }
            bool needstall = false;
            // cout <<  << endl;
            if(this->compare(add1, this->destination[2])){
                // this->a[1] = this->values[2];
                needstall = true;
            }
            
            if(this->compare(add2, this->destination[2])){
                // this->b[1] = this->values[2];
                needstall = true;
            }
            if(needstall){
                this->stall = 1;
                this->iCount++;
                this->pc = pcAlu.sub(this->pc, bitset<32>(4));
            }
        }
        
        else if(op[1] == 8 || op[1] == 12 || op[1] == 13 || op[1] == 10 || op[1] == 35){
            bitset<5> add1;
            for(int j = 25, k = 4; j >= 21; j--, k--){
                add1[k] = this->opcode[1][j];
                // add2[k] = this->opcode[1][j - 5];
            }
            if(this->compare(add1, this->destination[2])){
                // this->a[1] = this->values[2];
                this->stall = 1;
                this->iCount++;
                this->pc = pcAlu.sub(this->pc, bitset<32>(4));
            }
        }
    }
}



void CPU::mem(){
    if(op[3] == 35){
        this->values[3] = DM.readValue(this->values[3]);
    }
    else if(op[3] == 43){
        DM.writeValue(this->values[3], this->writeData);
    }


    if(op[3] == 32 || op[3] == 8 || op[3] == 34 || op[3] == 36 || op[3] == 12 ||
    op[3] == 37 || op[3] == 13 || op[3] == 42 || op[3] == 10 || op[3] == 35){

        if(op[1] == 32 || op[1] == 34 || op[1] == 36 || op[1] == 37 || op[1] == 42 || op[1] == 43 || op[1] == 4 || op[1] == 5){
            
            bitset<5> add1, add2;
            for(int j = 25, k = 4; j >= 21; j--, k--){
                add1[k] = this->opcode[1][j];
                add2[k] = this->opcode[1][j - 5];
            }
            
            // cout <<  << endl;
            if(this->compare(add1, this->destination[3])){
                this->a[1] = this->values[3];
                // cout << a[1] << endl;
            }
            
            if(this->compare(add2, this->destination[3])){
                this->b[1] = this->values[3];
            }
        }
        
        else if(op[1] == 8 || op[1] == 12 || op[1] == 13 || op[1] == 10 || op[1] == 35){
            bitset<5> add1;
            for(int j = 25, k = 4; j >= 21; j--, k--){
                add1[k] = this->opcode[1][j];
                // add2[k] = this->opcode[1][j - 5];
            }
            if(this->compare(add1, this->destination[3])){
                this->a[1] = this->values[3];
            }
        }
    }

}

void CPU::wb(){

    if(op[4] == 32){
            // add
            RF.writeValue(this->destination[4], this->values[4]);
        }
        else if(op[4] == 34){
            // sub
            RF.writeValue(this->destination[4], this->values[4]);
        }
        else if(op[4] == 36){
            // and
            RF.writeValue(this->destination[4], this->values[4]);
        }
        else if(op[4] == 37){
            // or
            RF.writeValue(this->destination[4], this->values[4]);
        }
        else if(op[4] == 42){
            // slt
            RF.writeValue(this->destination[4], this->values[4]);
        }
        else if(op[1] == 2){
            // jump
            bitset<28> imm(0);
            for(int j = 25; j >= 0; j--){
                imm[j] = this->opcode[1][j];
            }
            imm <<= 2;
            for(int j = 27; j >= 0; j--){
                pc[j] = imm[j];
            }
        }
        else if(op[4] == 8){
            // addi
            RF.writeValue(this->destination[4], this->values[4]);
        }
        else if(op[4] == 12){
            // andi
            RF.writeValue(this->destination[4], this->values[4]);
        }

        else if(op[4] == 13){
            // ori
            RF.writeValue(this->destination[4], this->values[4]);
        }
        else if(op[4] == 10){
            // slti
            RF.writeValue(this->destination[4], this->values[4]);
        }

        else if(op[4] == 35){
            // lw
            RF.writeValue(this->destination[4], this->values[4]);
        }
        else if(op[4] == 43){
            // sw
        }

        if(op[4] == 32 || op[4] == 8 || op[4] == 34 || op[4] == 36 || op[4] == 12 ||
    op[4] == 37 || op[4] == 13 || op[4] == 42 || op[4] == 10 || op[4] == 35){

        if(op[1] == 32 || op[1] == 34 || op[1] == 36 || op[1] == 37 || op[1] == 42 || op[1] == 43 || op[1] == 4 || op[1] == 5){
            
            bitset<5> add1, add2;
            for(int j = 25, k = 4; j >= 21; j--, k--){
                add1[k] = this->opcode[1][j];
                add2[k] = this->opcode[1][j - 5];
            }
            
            // cout <<  << endl;
            if(this->compare(add1, this->destination[4])){
                this->a[1] = this->values[4];
                // cout << a[1] << endl;
            }
            
            if(this->compare(add2, this->destination[4])){
                this->b[1] = this->values[4];
            }
        }
        
        else if(op[1] == 8 || op[1] == 12 || op[1] == 13 || op[1] == 10 || op[1] == 35){
            bitset<5> add1;
            for(int j = 25, k = 4; j >= 21; j--, k--){
                add1[k] = this->opcode[1][j];
                // add2[k] = this->opcode[1][j - 5];
            }
            if(this->compare(add1, this->destination[4])){
                this->a[1] = this->values[4];
            }
        }
    }
}

bool CPU::compare(bitset<5> b1, bitset<5> b2){
    for(int i = 0; i < 5; i++){
        if(b1[i] != b2[i]){
            return false;
        }
    }

    return true;
}