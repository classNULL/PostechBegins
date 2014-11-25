#ifndef HERO
#define HERO

#include <iostream>
#include "global.hpp"
#include "hero.hpp"
class hero{
public:
  hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, float max_study, sexuality sex);
	void change_love(float, int);
	void change_energy(float, int);
	void change_relationship(float, int);
	void change_self_develop(float, int);
	void change_study(float, int);//status 변화시키는 method
	float get_MAX_ENERGY() const;
	float get_MAX_LOVE() const;
	float get_MAX_RELATIONSHIP() const;
	float get_MAX_SELF_DEVELOP() const;
	float get_study() const;
	float get_self_develop() const;
	float get_relationship() const;
	float get_energy() const;
	float get_love() const; //status return 받는 method
private:
	const float MAX_ENERGY;
	const float MAX_LOVE;
	const float MAX_RELATIONSHIP;
	const float MAX_SELF_DEVELOP;
	const float MAX_STUDY;
	float energy;
	float love;
	float relationship;
	float self_develop;
	float study;
	sexuality sex;
	bool energy_is_zero = false; //에너지가 0인지 아닌지 구별함. 만약 체력이 0 일경우 다른 행동을 하지 못함

  /*
  체력	인간관계	연애	공부중	스트레스	자기개발
  술
  공부
  동아리
  연애
  휴식
  집

  */
  float titles[7][6][6] = {
    { { 1, 1.1, 1, 1, 1, 1 }, { 1, 1.1, 1, 1, 1, 1 }, { 1, 1.1, 1, 1, 1, 1 }, {1, 1.1, 1, 1, 1, 1}, { 1, 1, 1, 1, 1, 1 }, {1, 1, 1, 1, 1, 1} }, //아싸
    { { 1, 1.1, 1, 1, -1, 1 }, { 1, 1, 1, 0.9, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 } }, //술쟁이
    { { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1.05, 1, 1, 1, 1.05 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 } }, //동방충
    { { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 } }, // 공부벌레
    { { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 } }, // 연애중
    { { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 } },//무동아리
    { { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1.1, 1.1, 1.1, 1.1, 1.1, 1.1 }, { 1, 1, 1, 1, 1, 1 } }//체력낮음
  };
private:
	float grade1, grade2;//각각 1학기, 2학기 성적
	/**
	학점에 따라 게임 결과 총점에 들어갈 점수를 계산한다.

	@param grade 학점. 0에서 4.3 사이.
	*/
	float calc_grade_score(float grade);

	/**
	공부 스탯에 따라 학점을 계산한다.
	학점은 스탯에 비례한 값에 +/-0.15 범위 안에서 결정된다.

	@param study 공부 스탯. 만점에서 나눈 값을 받는다. 0에서 1 사이.
	*/
	float generate_grade() {
		return max(min(study * 4.3 + ((rand() % 30 - 15) / 100.0f), 4.3), 0.0);
	}
	int test=0;//시험을 치른 횟수
public:
	/**
	학점, 인간관계, 자기계발 스탯을 통해 총 점수를 결정한다.

	@param study 공부 점수. 만점에서 나눈 값을 받는다. 0에서 1 사이.
	@param relationship 인간관계 점수. 만점에서 나눈 값을 받는다. 0에서 1 사이.
	@param improvement 자기계발 점수. 만점에서 나눈 값을 받는다. 0에서 1 사이.
	@return 총 점수.
	*/
	//int score();
	float grade();//시험을 치를때 grade 1, grade 2를 업데이트 하고 이를 반환하는 함수
	void game_exit();
};
#endif
