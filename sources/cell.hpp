#ifndef _CELL_H_
#define _CELL_H_

#include <iostream>
#include "global.hpp"
#include "celloption.hpp"
#include "hero.hpp"

using namespace std;

class cell{//한 칸의 정보로 Abstract class이다.
public:
   virtual ~cell() {};
   virtual wstring get_cell_message() const = 0;
   virtual cell_option_book call_option(hero* _hero, int day) = 0;
   bool stop_cell() const { return stop; }//무조건 멈추는 칸을 나타내기 위함으로, 멈춰야 하는 칸에서는 이 값이 true로 설정된다.
   bool skip_cell() const { return skip; }
   bool birth_cell() { return birth; }
   void set_birth(bool is_birthday) { birth = is_birthday; }
protected:
   bool stop = false;
   bool skip = false;
   bool birth = false;
   virtual cell_option_book call_option_zero(hero* _hero, int day);
   virtual cell_option_book call_option_special(hero* _hero, int day);
};
class normal :public cell{//각각의 칸은 cell class를 상속받아 만들어진다.
public:
   cell_option_book call_option(hero* _hero, int day);//캐릭터가 칸에 도달하였을때 선택지를 호출한다.
   wstring get_cell_message() const { return L"무엇을 하시겠습니까?"; }
};
class weekend :public cell{//주말을 나타내는 칸
public:
   cell_option_book call_option(hero* _hero, int day);
   cell_option_book call_option_special(hero* _hero, int day);
   cell_option_book call_option_zero(hero* _hero, int day);
   wstring get_cell_message() const { return L"주말입니다."; }
};
class march :public cell{//3월을 나타내는 칸
public:
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"무엇을 하시겠습니까?"; }
};
class before_exam :public cell{//시험기간을 나타내는 칸
public:
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"시험기간입니다."; }
};
class exam :public cell{//중간고사, 기말고사를 나타내는 칸
public:
   exam(){ stop = true; skip = true; }
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"시험날입니다."; }
};
class after_exam :public cell{//시험기간 직후
public:
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"시험이 끝났습니다."; }
};
class festival :public cell{//pop, 해맞이 한마당, 포카전 등 축제
public:
   festival(){ stop = true; }
   cell_option_book call_option(hero* _hero, int day);
   cell_option_book call_option_special(hero* _hero, int day);
   cell_option_book call_option_zero(hero* _hero, int day);
   virtual wstring get_cell_message() const { return L"오늘은 해맞이 한마당이 있는 날입니다."; }
};
class poka :public festival{//포카전
public:
   wstring get_cell_message() const { return L"오늘은 포카전이 있습니다."; }
};
class pop :public festival{//피오피
public:
   wstring get_cell_message() const { return L"오늘은 POP가 있습니다."; }
};
class dance :public cell{//학과춤 준비 기간
public:
   cell_option_book call_option(hero* _hero, int day);
   cell_option_book call_option_special(hero* _hero, int day);
   wstring get_cell_message() const { return L"학과 춤을 준비하는 기간입니다."; }
};
class special :public cell{//개총, 종총, MT 등 반드시 멈춰야하는 칸
public:
   special(){ stop = true; }
   cell_option_book call_option(hero* _hero, int day);
};
class bunban_lecstart :public special{//분반 개총
public:
   wstring get_cell_message() const { return L"오늘은 분반 개총날입니다."; }
};
class bunban_lecend :public special{//분반 종총
public:
   wstring get_cell_message() const { return L"오늘은 분반 종총날입니다."; }
};
class bunban_mt :public special{//분반 엠티
public:
   wstring get_cell_message() const { return L"오늘은 분반 MT입니다."; }
};
class bunban_face :public special{//분반 대면식
public:
   wstring get_cell_message() const { return L"오늘은 분반 대면식입니다."; }
};
class dept_lecstart :public special{//과 개총
public:
   wstring get_cell_message() const { return L"오늘은 과 개총날입니다."; }
};
class dept_lecend :public special{//과 종총
public:
   wstring get_cell_message() const { return L"오늘은 과 종총날입니다."; }
};
class dept_mt :public special{//과 엠티
public:
   wstring get_cell_message() const { return L"오늘은 과 MT입니다."; }
};
class dept_face :public special{//과 대면식
public:
   wstring get_cell_message() const { return L"오늘은 과 대면식입니다."; }
};
class eve_1 :public special{//첫 번째 이벤트
public:
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"태풍이 왔습니다. 78 폭포가 형성되었습니다."; }
};
class eve_2 :public special{//두 번째 이벤트
public:
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"과제를 하느라 밤을 샜습니다. ㅠㅠ"; }
};
class eve_3 :public special{//세 번째 이벤트
public:
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"빨래 하는걸 깜빡해 입을 옷이 없습니다.."; }
};
class vacation :public cell{//방학
public:
   vacation(){ skip = true; }
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"야 방학이다!"; }
};
class win_vac : public cell{
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"1학년이 끝났습니다."; }
};
#endif
