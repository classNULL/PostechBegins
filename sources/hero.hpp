#ifndef HERO
#define HERO

#include <vector>
#include <map>
#include <algorithm>
#include "global.hpp"
#include "title.hpp"

struct CharacterProperty {
  PersonalStatus status;
  PersonalStatus max_status;
  string gender;
};

class hero{
private:
  void set_default_initial_status(sexuality sex);
public:
  hero(const PersonalStatus& status_max, sexuality sex);
  hero(const PersonalStatus& status_max, const PersonalStatus& initial_status, sexuality sex);
  //생성자
  float get_energy_consuming_rate();
  //선택 시 체력이 얼마나 감소하는지
  void change_energy(float, int);
  //체력 감소 * day
	void change_love(float, int);
	//마찬가지
	void change_relationship(float, int);
	void change_self_develop(float, int);
	void change_study(float, int);//status 변화시키는 method
  void change_stress(float, int);
  //스트레스 변화
  void change_status(PersonalStatus status_change, int day);
  void change_status(PersonalStatus status_change, PersonalStatus title_effect, int day);
  //스테이터스 변화
	void up_event();
	//이벤트 개수 상승
  const PersonalStatus& max_status() const { return this->MAX_STATUS; }
  //MAX 스테이터스를 리턴
  const PersonalStatus& status() const { return this->current_status; }
  //스테이터스를 리턴
  bool exhausted() const;
  //체력이 0일때

  void take_exam();
  //시험을 봄
  float get_semester_grade(bool is_spring) const;
  float get_average_grade() const;
  void couple(){ this->_is_mosol = false; }
  bool is_mosol() const { return this->_is_mosol; }
	sexuality get_sexuality() const { return this->sex; };
  const TitleBook& get_title_book() const { return this->title_book; };
  TitleBook* get_title_book_pointer() { return &(this->title_book); };
  //타이틀 북 리턴
  int get_cleared_event() { return this->cleared_event; }
  bool is_spring() const { return this->_is_spring; }
  //1학기인지 아닌지 return
  void finish_semester();
  //학기 종료

  CharacterProperty get_current_property();

private:
  const PersonalStatus MAX_STATUS;
  //스테이터스
  PersonalStatus current_status = {
    .energy = 0,
    .love = 0,
    .relationship = 0,

    .self_develop = 30,
    .study = 100,
    .stress = 0
  };
	vector<float> spring_grades; // 시험 기간에 결정
  vector<float> autumn_grades; // 시험 기간에 결정
	sexuality sex;
  TitleBook title_book;
  int cleared_event = 0;
  bool _is_spring = true;
  bool _is_mosol = true;
  //기본적으로 true이며 한번이라도 연애를 할시 false가 됨
};
#endif
