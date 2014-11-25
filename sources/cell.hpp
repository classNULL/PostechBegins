#ifndef _CELL_H_
#define _CELL_H_

#include <iostream>
#include "global.hpp"
#include "hero.hpp"

using namespace std;

class cell{//한 칸의 정보로 Abstract class이다.
public:
   virtual ~cell() {};
   virtual void call_option(hero* _hero,int day) = 0;//pure virtual method로 derived class에서 구현한다.
   bool stop_cell(){ return stop; }//무조건 멈추는 칸을 나타내기 위함으로, 멈춰야 하는 칸에서는 이 값이 true로 설정된다.
protected:
   bool stop = false;
   void change(hero* _hero, float energy, float study, float relationship, float self_develop, float love, float stress, int day);
};
class normal :public cell{//각각의 칸은 cell class를 상속받아 만들어진다.
public:
   void call_option(hero* _hero,int day);//캐릭터가 칸에 도달하였을때 선택지를 호출한다.
   static string const className() { return "normal"; };
};
class weekend :public cell{//주말을 나타내는 칸
public:
  void call_option(hero* _hero,int day);
  static string const className() { return "weekend"; };
};
class march :public cell{//3월을 나타내는 칸
public:
   void call_option(hero* _hero,int day);
   static string const className() { return "march"; };
};
class before_exam :public cell{//시험기간을 나타내는 칸
public:
   void call_option(hero* _hero,int day);
   static string const className() { return "before_exam"; };
};
class exam :public cell{//중간고사, 기말고사를 나타내는 칸
public:
   exam(){ stop = true; }
   void call_option(hero* _hero,int day);
   static string const className() { return "exam"; };
};
class after_exam :public cell{//시험기간 직후
public:
   void call_option(hero* _hero,int day);
   static string const className() { return "after_exam"; };
};
class festival :public cell{//pop, 해맞이 한마당, 포카전 등 축제
public:
   festival(){ stop = true; }
   void call_option(hero* _hero,int day);
   static string const className() { return "festival"; };
};
class poka :public festival{//포카전
public:
   static string const className() { return "poka"; };
};
class pop :public festival{//피오피
public:
   static string const className() { return "pop"; };
};
class dance :public cell{//학과춤 준비 기간
public:
   void call_option(hero* _hero,int day);
   static string const className() { return "dance"; };
};
class special :public cell{//개총, 종총, MT 등 반드시 멈춰야하는 칸
public:
   special(){ stop = true; }
   void call_option(hero* _hero,int day);
   static string const className() { return "special"; };
};
class lecstartparty :public special{//개총
public:
   static string const className() { return "lecstartparty"; };
};
class lecendparty :public special{//종총
public:
   static string const className() { return "lecendparty"; };
};
class mt :public special{//엠티
public:
   static string const className() { return "mt"; };
};
class faceparty :public special{//대면식
public:
   static string const className() { return "faceparty"; };
};
class vacation :public cell{//방학
public:
  void call_option(hero* _hero,int day) {  }
  static string const className() { return "vacation"; };
};
#endif
