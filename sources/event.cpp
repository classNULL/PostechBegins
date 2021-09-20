#include "event.hpp"

wstring march_event::check_success(hero* hero,
                                   const PersonalStatus& increased_status) {
  //월 별 이벤트의 조건을 검사하고, 성공했을 시에는 성공 메시지를,
  //그렇지 않을 때는 실패 메시지를 전달한다.
  if (increased_status.relationship > 60) {  //식별자 정의 필요
    hero->up_event();
    return L"Mission Clear! 사람을 많이 사귀었나봐요?";
  }
  return L"흐잉 3월인데 사람도 만나고 하지 그랬어요ㅠ";
}
wstring march_event::introduction_message() const {
  //이 method에서는 이벤트를 소개하는 메시지를 전달한다.
  return L"대학을 처음왔으면! 일단 친해져보자!";
}
//이하 모든 class는 march_event와 동일하나, 내부 메시지와 성공 조건만 다르다.

wstring april_event::introduction_message() const {
  return L"중간고사 기간이네! 노는거도 이때해야 재밌지!";
}
wstring april_event::check_success(hero* hero,
                                   const PersonalStatus& increased_status) {
  if (increased_status.study > 0) {  //식별자 정의 필요
    hero->up_event();
    return L"Mission Clear! 시험기간엔 공부해야죠! 무슨소리를!";
  }
  return L"인생은 시키는 대로 하는 게 아닙니다";
}

wstring may_event::introduction_message() const {
  return L"시험도 끝났겠다. 공부가 뭐죠?";
}
wstring may_event::check_success(hero* hero,
                                 const PersonalStatus& increased_status) {
  if (increased_status.self_develop > 15) {  //식별자 정의 필요
    hero->up_event();
    return L"Mission Clear! 동아리 활동도 열심히 해야죠!";
  }
  return L"힌트에 답이 있는 건 아닙니다 동아리 활동도 하고 그러셨길 "
         L"바랬는데..(시무룩)";
}

wstring june_event::introduction_message() const {
  return L"와 벌써 방학이 한달남았다. 기말엔 공부를 좀 해야될거 같은데...?";
}
wstring june_event::check_success(hero* hero,
                                  const PersonalStatus& increased_status) {
  if (increased_status.relationship > 60) {  //식별자 정의 필요
    hero->up_event();
    return L"Mission Clear! 기말고사는 던져야 제맛!";
  }
  return L"인생은 시키는 대로 하는게 아니죠! 역시!";
}

wstring september_event::introduction_message() const {
  return L"2학기 개강이라능. 개총개총개총개총!";
}
wstring september_event::check_success(hero* hero,
                                       const PersonalStatus& increased_status) {
  if (increased_status.relationship > 60) {  //식별자 정의 필요
    hero->up_event();
    return L"술은 많이 드셨나요?!";
  }
  return L"2학기 개강하자마자 공부만 한거에요 설마?";
}

wstring october_event::introduction_message() const {
  return L"중간고사? 공부가 뭐죠? 그거 1학기에 보니 해도 안되더라. 님들 "
         L"공부하지말고 카이스트 미꾸라지들 먼저 처리하죠 ㄱㄱ";
}
wstring october_event::check_success(hero* hero,
                                     const PersonalStatus& increased_status) {
  if (increased_status.love > 60) {  //식별자 정의 필요
    hero->up_event();
    return L"카이스트보단 연애가 개이득";
  }
  return L"정말 미꾸라지만 만났군요! 남들은 연애하고 있다구요";
}

wstring november_event::introduction_message() const {
  return L"우왕 시험 끝 ㅋ 동아리 축제고 POP고 할게많네";
}
wstring november_event::check_success(hero* hero,
                                      const PersonalStatus& increased_status) {
  if (increased_status.energy < -40) {  //식별자 정의 필요
    hero->up_event();
    return L"시험끝나곤 쉬어야죠! 축제는 무슨!";
  }
  return L"지금 안 쉬면 나중에 힘들텐데..";
}

wstring december_event::introduction_message() const {
  return L"와 1학기 있으면 후배들어옴. 신입생으로써 마지막을 불태우자 술 ㄱㄱ";
}
wstring december_event::check_success(hero* hero,
                                      const PersonalStatus& increased_status) {
  if (increased_status.relationship > 60) {  //식별자 정의 필요
    hero->up_event();
    return L"신입생 카페에서 많이 노셨나봐요?";
  }
  return L"2학년 되자마자 아싸가 될 것 같아요. 인간관계에 더 신경써야해요!";
}
