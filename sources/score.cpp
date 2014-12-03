#include "score.hpp"

float Score::calc_grade_score(float grade) {
  if (grade < 0)
    throw runtime_error("0보다 작으면 안됨");
  else if (grade < 2.0)
    return (grade) / 2 * 5;
  else if (grade < 2.3)
    return 20 + (grade - 2) / 0.3 * 10;
  else if (grade < 3.0)
    return 50 + (grade - 2.3) / 0.7 * 50;
  else if (grade < 3.3)
    return 200 + (grade - 3.0) / 0.3 * 20;
  else if (grade < 3.7)
    return 230 + (grade - 3.3) / 0.4 * 30;
  else if (grade < 4.0)
    return 280 + (grade - 3.7) / 0.3 * 30;
  else if (grade < 4.3)
    return 350 + (grade - 4.0) / 0.3 * 30;
  else if (grade == 4.3)
    return 400;
  else
    throw runtime_error("4.3보다 큼");
}

float Score::generate_grade(float study) {
  return max(0.0, min(4.3, (study / 100) * 4.3 + ((rand() % 30 - 15) / 100.0)));
}

Score Score::score(const hero& _hero) {
  //grade 400
  //relationship 300
  //improvement 300
  return {
    .grade_score = static_cast<int>(calc_grade_score(_hero.get_average_grade())),
    .relationship = static_cast<int>(_hero.get_relationship() * 3),
    .self_develop = static_cast<int>(_hero.get_self_develop() * 3)
  };
}

string Score::evaluate_grade_score() {
  switch (this->grade_score / 100) {
    case 4:
      return "와 학점왕! 일 년 동안 후회 없이 공부했네요!";
    case 3://300이상
      return "오 학점, 좋아 좋아. 일 학년이라면 적당히 놀고 적당히 공부하고. 딱 좋네요.";
    case 2://200이상
      return "음...학점이 참...거참.... 일 학년이지만 이건 아닌데...음...아닌데...";
    case 1://100이상
      return "학점이 가관입니다. 혼자 허리케인 같은 일학년 삶을 살았구만요. 계속되면 안됩니다..";
    case 0://100미만
      return "오 학점 0점...대? 당신은 카이스트 생?";
  }
  throw runtime_error("학점 점수가 이상합니다.");
}
string Score::evaluate_relationship() {
  switch (this->relationship / 100){
    case 3:
      return "일학년 동안 만날 사람 다 만났네요. 인간 관계가 아주 훌륭합니다.";
    case 2://200이상
      return "인간 관계 좋아요. 적절히 잘 쌓았군요.";
    case 1://100이상
      return "인간 관계가 약간 부족해요. 일학년 때 놓치면 안될 사람들도 많은데!";
    case 0://100미만
      return "인간관계 점수가... 영...0.... 인생은 혼자 사는 게 아니에요~ 다양한 사람과의 교류를 즐겨봅시다.";
  }
  throw runtime_error("인간관계 점수가 이상합니다.");
}
string Score::evaluate_self_develop() {
  switch (this->self_develop / 100){
    case 3:
      return "탄탄한 자기 계발로 보낸 1년. 많이 성장했겠습니다~!";
    case 2://200이상
      return "가끔은 자기 계발에도 시간을 투자하는 것도 좋아요.";
    case 1://100이상
      return "음... 자기 계발에 더 시간을 투자해야만 해요. 앞으로 신경쓰기!";
    case 0://100미만
      return "이건 아닌데.... 진정한 포스테키안이라면 자기 계발은 선택이 아니라 필수입니다. 분발하세요!";
  }
  throw runtime_error("자기계발 점수가 이상합니다.");
}
