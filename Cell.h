#ifndef _CELL_H_
#define _CELL_H_
#include <iostream>
using namespace std;

class saram;
class cell{//한 칸의 정보로 Abstract class이다.
public:
   cell(){ stop = false; }
   virtual void call_option() = 0;//pure virtual method로 derived class에서 구현한다.
   bool stop_cell(){ return stop; }//무조건 멈추는 칸을 나타내기 위함으로, 멈춰야 하는 칸에서는 이 값이 true로 설정된다.
protected:
   saram* saram;//character를 가리키는 포인터
   bool stop;
};
class normal :public cell{//각각의 칸은 cell class를 상속받아 만들어진다.
public:
   void call_option();//캐릭터가 칸에 도달하였을때 선택지를 호출한다.
};
class march :public cell{
public:
   void call_option();
};
class before_exam :public cell{
public:
   void call_option();
};
class exam :public cell{
public:
   exam(){ stop = true; }
   void call_option();
};
class after_exam :public cell{
public:
   void call_option();
};
class festival :public cell{
public:
   festival(){ stop = true; }
   void call_option();
};
class dance :public cell{
public:
   void call_option();
};
class special :public cell{
public:
   special(){ stop = true; }
   void call_option();
};
#endif