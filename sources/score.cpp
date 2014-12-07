#include "score.hpp"

float Score::calc_grade_score(float grade) {//게임을 진행하여 받은 학점을 최종 점수에 합산할 수 있는 점수로 변환해주는 함수이다. grade의 범위에 따라 점수 변환이 다른 식으로 계산된다. 이는 학점에 따라 학사경고, 장학금 짤림 등이 결정되기 때문이다.
  if (grade < 0)//grade가 0보다 작으면 runtime error임을 알려준다.
    throw runtime_error("0보다 작으면 안됨");
  else if (grade < 2.0)//아래에는 grade의 범위에 따라 각각에 따른 점수 변환을 해준다.
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

float Score::generate_grade(float study) {//게임 진행 결과 학점을 정해주는 함수이다. 게임에서 얻은 공부점수 만큼 학점을 부여하는데, 학점은 어느 정도의 운이 따르기 때문에 rand()를 이용하여 약간의 오차가 발생하도록 설정하였다.
  return max(0.0, min(4.3, (study / 100) * 4.3 + ((rand() % 30 - 15) / 100.0)));
}

Score Score::score(const hero& _hero) {
  //grade 400
  //relationship 300
  //improvement 300
  return {
    .grade_score = static_cast<int>(calc_grade_score(_hero.get_average_grade())),
    .relationship = static_cast<int>(_hero.status().relationship * 3),
    .self_develop = static_cast<int>(_hero.status().self_develop * 3),
    .love = _hero.is_mosol()?0:100
  };
}
wstring Score::evaluate_total() {//전체 점수를 평가하여 그에 대한 메시지를 출력한다.
  float total = this->get_total();
  if (total > 800) {
   return L"1학년 생활을 굉장히 잘 보내었군요! 당신은 훌륭한 POSTECH의 인재가 될 것입니다!";
  }
  else if (total > 600) {
    return L"높은 점수를 받으셨군요! 축하드립니다! 다음엔 최고를 향해서 도전해 보시기 바랍니다!";
  }
  else if (total > 400) {
    return L"무언가 잊고 사시지는 않았나요? 한가지, 두가지 놓치고 산 것이 큰 영향을 미칠 수 있답니다.";
  }
  else if (total > 200) {
    return L"아메바는 면하셨군요. 이러한 대학생활에 만족하십니까?";
  }
  else
    return L"재입학하시는게 어떠십니까?";
}
wstring Score::evaluate_grade_score() {//학점에 대한 점수를 평가하여 그에 대한 메시지를 출력한다.
  switch (this->grade_score / 100) {
    case 4: case 3://300이상
      return L"와 학점왕! 일 년 동안 후회 없이 공부했네요!";
     case 2://200이상
      return L"오 학점, 좋아 좋아. 일 학년이라면 적당히 놀고 적당히 공부하고. 딱 좋네요.";
   case 1://100이상
      return L"음...학점이 참...거참.... 일 학년이지만 이건 아닌데...음...아닌데...";
   case 0://100미만
      return L"학점이 가관입니다. 혼자 허리케인 같은 일학년 삶을 살았구만요. 계속되면 안됩니다..";
  }
  throw runtime_error("학점 점수가 이상합니다.");
}
wstring Score::evaluate_relationship() {//인간관계에 대한 점수를 평가하여 그에 대한 메시지를 출력한다.
  switch (this->relationship / 100){
    case 3:case 2://200이상
      return L"일학년 동안 만날 사람 다 만났네요. 인간 관계가 아주 훌륭합니다.";
    case 1://100이상
      return L"인간 관계 좋아요. 적절히 잘 쌓았군요.";
      case 0://100미만
      return L"인간 관계가 약간 부족해요. 일학년 때 놓치면 안될 사람들도 많은데!";

  }
  throw runtime_error("인간관계 점수가 이상합니다.");
}
wstring Score::evaluate_self_develop() {//자기계발에 대한 평가를 하여 이에 대한 메시지를 출력한다.
  switch (this->self_develop / 100){
    case 3: case 2://200이상
      return L"탄탄한 자기 계발로 보낸 1년. 많이 성장했겠습니다~!";
     case 1://100이상
      return L"가끔은 자기 계발에도 시간을 투자하는 것도 좋아요.";
    case 0://100미만
      return L"이건 아닌데.... 진정한 포스테키안이라면 자기 계발은 선택이 아니라 필수입니다. 분발하세요!";
  }
  throw runtime_error("자기계발 점수가 이상합니다.");
}
