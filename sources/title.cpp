
#include "title.hpp"

bool TitleBook::has_title(string title_name) const {//칭호를 가지고 있는지를 판단한다. 
  return (this->titles.find(title_name) != this->titles.end());
}
void TitleBook::add_title(string title_name) {//칭호를 추가시켜주는 역할을 한다. 
  this->titles.insert({ title_name, Titles::map.at(title_name) });
  this->calc_total_title_effect();
}
void TitleBook::remove_title(string title_name) {//칭호를 없애주는 역할을 한다. 
  this->titles.erase(title_name);
  this->calc_total_title_effect();
}
void TitleBook::calc_total_title_effect() {//칭호로 인한 효과를 계산해주도록 한다. 
  auto result = TitleEffect::get_base();

  for (const auto& pair: this->titles)
    result = result.multiply(pair.second);

  this->total_title_effect = result;
};

TitleEffect Titles::outsider = { // 아싸
  .alcohol = { .energy = 1, .relationship = 1.1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .study = { .energy = 1, .relationship = 1.1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .circle = { .energy = 1, .relationship = 1.1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .love = { .energy = 1, .relationship = 1.1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .rest = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .home = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 }
};
TitleEffect Titles::alcoholic = { // 술쟁이
  .alcohol = { .energy = 1, .relationship = 1.1, .love = 1, .study = 1, .self_develop = 1, .stress = -1 },
  .study = { .energy = 1, .relationship = 1, .love = 1, .study = 0.9, .self_develop = 1, .stress = 1 },
  .circle = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .love = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .rest = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .home = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 }
};
TitleEffect Titles::circle_resident = { // 동방충
  .alcohol = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .study = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .circle = { .energy = 1, .relationship = 1.05, .love = 1, .study = 1, .self_develop = 1, .stress = 1.05 },
  .love = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .rest = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .home = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 }
};
TitleEffect Titles::nerd = { // 공부벌레
  .alcohol = { .energy = 1, .relationship = 0.95, .love = 1, .study = 1.1, .self_develop = 1, .stress = 0.95 },
  .study = { .energy = 1, .relationship = 0.95, .love = 1, .study = 1.1, .self_develop = 1, .stress = 0.95 },
  .circle = { .energy = 1, .relationship = 0.95, .love = 1, .study = 1.1, .self_develop = 1, .stress = 0.95 },
  .love = { .energy = 1, .relationship = 0.95, .love = 1, .study = 1.1, .self_develop = 1, .stress = 0.95 },
  .rest = { .energy = 1, .relationship = 0.95, .love = 1, .study = 1.1, .self_develop = 1, .stress = 0.95 },
  .home = { .energy = 1, .relationship = 0.95, .love = 1, .study = 1.1, .self_develop = 1, .stress = 0.95 }
};
TitleEffect Titles::couple = { // 연애중
  .alcohol = { .energy = 1.1, .relationship = 0.9, .love = -1, .study = 0.9, .self_develop = 0, .stress = 0.9 },
  .study = { .energy = 1.1, .relationship = 0.9, .love = -1, .study = 0.9, .self_develop = 0, .stress = 0.9 },
  .circle = { .energy = 1.1, .relationship = 0.9, .love = -1, .study = 0.9, .self_develop = 0, .stress = 0.9 },
  .love = { .energy = 1.1, .relationship = 0.9, .love = 1, .study = 0.9, .self_develop = 0, .stress = 0.9 },
  .rest = { .energy = 1.1, .relationship = 0.9, .love = 1, .study = 0.9, .self_develop = 0, .stress = 0.9 },
  .home = { .energy = 1.1, .relationship = 0.9, .love = 1, .study = 0.9, .self_develop = 0, .stress = 0.9 }
};
TitleEffect Titles::circle_independent = { // 무동아리
  .alcohol = { .energy = 1, .relationship = 0.9, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .study = { .energy = 1, .relationship = 0.9, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .circle = { .energy = 1, .relationship = 0.9, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .love = { .energy = 1, .relationship = 0.9, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .rest = { .energy = 1, .relationship = 0.9, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .home = { .energy = 1, .relationship = 0.9, .love = 1, .study = 1, .self_develop = 1, .stress = 1 }
};
TitleEffect Titles::weak = { // 체력낮음
  .alcohol = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .study = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .circle = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .love = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
  .rest = { .energy = 1.1, .relationship = 1.1, .love = 1.1, .study = 1.1, .self_develop = 1.1, .stress = 1.1 },
  .home = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 }
};

const map<string, const TitleEffect&> Titles::map = {
  { "outsider", Titles::outsider },
  { "alcoholic", Titles::alcoholic },
  { "circle_resident", Titles::circle_resident },
  { "nerd", Titles::nerd },
  { "couple", Titles::couple },
  { "circle_independent", Titles::circle_independent },
  { "weak", Titles::weak }
};
