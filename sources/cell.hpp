#ifndef _CELL_H_
#define _CELL_H_

#include <iostream>
#include "global.hpp"
#include "celloption.hpp"
#include "hero.hpp"

using namespace std;

/** 한 칸의 정보로 Abstract class이다. */
class cell{
public:
   virtual ~cell() {};
   virtual wstring get_cell_message() const = 0;
   virtual cell_option_book call_option(hero* _hero, int day) = 0;
   /** 무조건 멈추는 칸을 나타내기 위함으로, 멈춰야 하는 칸에서는 이 값이 true로 설정된다. */
   bool stop_cell() const { return stop; }
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
/** 각각의 칸은 cell class를 상속받아 만들어진다. */
class normal :public cell{
public:
   /** 캐릭터가 칸에 도달하였을때 선택지를 호출한다. */
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"무엇을 하시겠습니까?"; }
};
/** 주말을 나타내는 칸 */
class weekend :public cell{
public:
   cell_option_book call_option(hero* _hero, int day);
   cell_option_book call_option_special(hero* _hero, int day);
   cell_option_book call_option_zero(hero* _hero, int day);
   wstring get_cell_message() const { return L"주말입니다."; }
};
/** 3월을 나타내는 칸 */
class march :public cell{
public:
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"무엇을 하시겠습니까?"; }
};
/** 시험기간을 나타내는 칸 */
class before_exam :public cell{
public:
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"시험기간입니다."; }
};
/** 중간고사, 기말고사를 나타내는 칸 */
class exam :public cell{
public:
   exam(){ stop = true; skip = true; }
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"시험날입니다."; }
};
/** 시험기간 직후 */
class after_exam :public cell{
public:
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"시험이 끝났습니다."; }
};
/** pop, 해맞이 한마당, 포카전 등 축제 */
class festival :public cell{
public:
   festival(){ stop = true; }
   cell_option_book call_option(hero* _hero, int day);
   cell_option_book call_option_special(hero* _hero, int day);
   cell_option_book call_option_zero(hero* _hero, int day);
   virtual wstring get_cell_message() const { return L"오늘은 해맞이 한마당이 있는 날입니다."; }
};
/** 포카전 */
class poka :public festival{
public:
   wstring get_cell_message() const { return L"오늘은 포카전이 있습니다."; }
};
/** 피오피 */
class pop :public festival{
public:
   wstring get_cell_message() const { return L"오늘은 POP가 있습니다."; }
};
/** 학과춤 준비 기간 */
class dance :public cell{
public:
   cell_option_book call_option(hero* _hero, int day);
   cell_option_book call_option_special(hero* _hero, int day);
   wstring get_cell_message() const { return L"학과 춤을 준비하는 기간입니다."; }
};
/** 개총, 종총, MT 등 반드시 멈춰야하는 칸 */
class special :public cell{
public:
   special(){ stop = true; }
   cell_option_book call_option(hero* _hero, int day);
};
/** 분반 개총 */
class bunban_lecstart :public special{
public:
   wstring get_cell_message() const { return L"오늘은 분반 개총날입니다."; }
};
/** 분반 종총 */
class bunban_lecend :public special{
public:
   wstring get_cell_message() const { return L"오늘은 분반 종총날입니다."; }
};
/** 분반 엠티 */
class bunban_mt :public special{
public:
   wstring get_cell_message() const { return L"오늘은 분반 MT입니다."; }
};
/** 분반 대면식 */
class bunban_face :public special{
public:
   wstring get_cell_message() const { return L"오늘은 분반 대면식입니다."; }
};
/** 과 개총 */
class dept_lecstart :public special{
public:
   wstring get_cell_message() const { return L"오늘은 과 개총날입니다."; }
};
/** 과 종총 */
class dept_lecend :public special{
public:
   wstring get_cell_message() const { return L"오늘은 과 종총날입니다."; }
};
/** 과 엠티 */
class dept_mt :public special{
public:
   wstring get_cell_message() const { return L"오늘은 과 MT입니다."; }
};
/** 과 대면식 */
class dept_face :public special{
public:
   wstring get_cell_message() const { return L"오늘은 과 대면식입니다."; }
};
/** 첫 번째 이벤트 */
class eve_1 :public special{
public:
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"태풍이 왔습니다. 78 폭포가 형성되었습니다."; }
};
/** 두 번째 이벤트 */
class eve_2 :public special{
public:
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"과제를 하느라 밤을 샜습니다. ㅠㅠ"; }
};
/** 세 번째 이벤트 */
class eve_3 :public special{
public:
   cell_option_book call_option(hero* _hero, int day);
   wstring get_cell_message() const { return L"빨래 하는걸 깜빡해 입을 옷이 없습니다.."; }
};
/** 방학 */
class vacation :public cell{
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
