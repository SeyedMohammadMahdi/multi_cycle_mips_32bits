
#include <iostream>
#include <string>
#include <bitset>

#include "CPU.h"
using namespace std;        



int main (){
  
  // add  32
  CPU cpu;
  // cpu.RF.writeValue(bitset<5>(1), bitset<32>(1));
  // cpu.RF.writeValue(bitset<5>(2), bitset<32>(3));
  // cpu.IM.writeValue(bitset<32>(0), bitset<32>(string("00000000001000100001100000100000")));
  // cpu.pc = bitset<32>(0);
  // cpu.iCount = 5;
  // cpu.cpu();
  // cout << "1 + 3 " << cpu.RF.readValue(bitset<5>(3)) << endl;

  // sub  34
  // cpu.RF.writeValue(bitset<5>(1), bitset<32>(3));
  // cpu.RF.writeValue(bitset<5>(2), bitset<32>(1));
  // cpu.IM.writeValue(bitset<32>(0), bitset<32>(string("00000000001000100001100000100010")));
  // cpu.pc = bitset<32>(0);
  // cpu.iCount = 5;
  // cpu.cpu();
  // cout << "3 - 1 " << cpu.RF.readValue(bitset<5>(3)) << endl;

  // and 36
  // cpu.RF.writeValue(bitset<5>(1), bitset<32>(3));
  // cpu.RF.writeValue(bitset<5>(2), bitset<32>(1));
  // cpu.IM.writeValue(bitset<32>(0), bitset<32>(string("00000000001000100001100000100100")));
  // cpu.pc = bitset<32>(0);
  // cpu.iCount = 5;
  // cpu.cpu();
  // cout << "3 and 1 " << cpu.RF.readValue(bitset<5>(3)) << endl;

  // or 37
  // cpu.RF.writeValue(bitset<5>(1), bitset<32>(3));
  // cpu.RF.writeValue(bitset<5>(2), bitset<32>(1));
  // cpu.IM.writeValue(bitset<32>(0), bitset<32>(string("00000000001000100001100000100101")));
  // cpu.pc = bitset<32>(0);
  // cpu.iCount = 5;
  // cpu.cpu();
  // cout << "3 or 1 " << cpu.RF.readValue(bitset<5>(3)) << endl;

  // slt 42
  // cpu.RF.writeValue(bitset<5>(1), bitset<32>(3));
  // cpu.RF.writeValue(bitset<5>(2), bitset<32>(1));
  // cpu.IM.writeValue(bitset<32>(0), bitset<32>(string("00000000001000100001100000101010")));
  // cpu.pc = bitset<32>(0);
  // cpu.iCount = 5;
  // cpu.cpu();
  // cout << "slt 3, 1 " << cpu.RF.readValue(bitset<5>(3)) << endl;

  // // j 2
  // cpu.IM.writeValue(bitset<32>(0), bitset<32>(string("00001000000000000000000000000011")));
  // cpu.pc = bitset<32>(0);
  // cpu.cpu(2);
  // cout << "pc = 12 " << cpu.pc << endl;

  // addi 8
  // cpu.RF.writeValue(bitset<5>(1), bitset<32>(3));
  // cpu.IM.writeValue(bitset<32>(0), bitset<32>(string("00100000001000100000000000000001")));
  // cpu.pc = bitset<32>(0);
  // cpu.iCount = 5;
  // cpu.cpu();
  // cout << "3 + 1 " << cpu.RF.readValue(bitset<5>(2)) << endl;

  // andi 12
  // cpu.RF.writeValue(bitset<5>(1), bitset<32>(3));
  // cpu.IM.writeValue(bitset<32>(0), bitset<32>(string("00110000001000100000000000000001")));
  // cpu.pc = bitset<32>(0);
  // cpu.iCount = 5;
  // cpu.cpu();
  // cout << "3 and 1 " << cpu.RF.readValue(bitset<5>(2)) << endl;

  // ori 13
  // cpu.RF.writeValue(bitset<5>(1), bitset<32>(3));
  // cpu.IM.writeValue(bitset<32>(0), bitset<32>(string("00110100001000100000000000000001")));
  // cpu.pc = bitset<32>(0);
  // cpu.iCount = 5;
  // cpu.cpu();
  // cout << "3 or 1 " << cpu.RF.readValue(bitset<5>(2)) << endl;

  // slti 10
  // cpu.RF.writeValue(bitset<5>(1), bitset<32>(3));
  // cpu.IM.writeValue(bitset<32>(0), bitset<32>(string("00101000001000100000000000000001")));
  // cpu.pc = bitset<32>(0);
  // cpu.iCount = 5;
  // cpu.cpu();
  // cout << "slt 3, 1 " << cpu.RF.readValue(bitset<5>(2)) << endl;

  // sw 43
  // cpu.RF.writeValue(bitset<5>(1), bitset<32>(3));
  // cpu.RF.writeValue(bitset<5>(2), bitset<32>(0));
  // cpu.IM.writeValue(bitset<32>(0), bitset<32>(string("10101100010000010000000000000000")));
  // cpu.pc = bitset<32>(0);
  // cpu.iCount = 6;
  // // cpu.cpu();


  // // lw 35
  // cpu.RF.writeValue(bitset<5>(3), bitset<32>(0));
  // cpu.IM.writeValue(bitset<32>(4), bitset<32>(string("10001100011000110000000000000000")));
  // // cpu.pc = bitset<32>(4);
  // cpu.cpu();
  // cout << "sw 3 " <<cpu.DM.readValue(bitset<32>(0)) << endl;
  // cout << "lw 3 " <<cpu.RF.readValue(bitset<5>(3)) << endl;

  // // beq 4
  // cpu.RF.writeValue(bitset<5>(1), bitset<32>(1));
  // cpu.RF.writeValue(bitset<5>(2), bitset<32>(1));
  // cpu.IM.writeValue(bitset<32>(0), bitset<32>(string("00010000001000100000000000000010")));
  // cpu.pc = bitset<32>(0);
  // cpu.cpu(2);
  // cout << "pc = 8 " << cpu.pc << endl;

  // // bnq 5
  // cpu.RF.writeValue(bitset<5>(1), bitset<32>(1));
  // cpu.RF.writeValue(bitset<5>(2), bitset<32>(1));
  // cpu.IM.writeValue(bitset<32>(0), bitset<32>(string("00010100001000100000000000000010")));
  // cpu.pc = bitset<32>(0);
  // cpu.cpu(2);
  // cout << "pc = 4 " << cpu.pc << endl;
  
  return 0;
}