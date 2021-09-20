
#include "title.hpp"

/** 칭호를 가지고 있는지를 판단한다. */
bool TitleBook::has_title(string title_name) const {
  return (this->titles.find(title_name) != this->titles.end());
}
/** 칭호를 추가시켜주는 역할을 한다. */
void TitleBook::add_title(string title_name) {
  this->titles.insert({title_name, Titles::map.at(title_name)});
  this->calc_total_title_effect();
}
/** 칭호를 없애주는 역할을 한다. */
void TitleBook::remove_title(string title_name) {
  this->titles.erase(title_name);
  this->calc_total_title_effect();
}
/** 칭호로 인한 효과를 계산해주도록 한다. */
void TitleBook::calc_total_title_effect() {
  auto result = TitleEffect::get_base();

  for (const auto& pair : this->titles) result = result.multiply(pair.second);

  this->total_title_effect = result;
}
vector<string> TitleBook::containing_titles() const {
  vector<string> contained;
  for (const auto& pair : this->titles) contained.push_back(pair.first);
  return contained;
}

/** 아싸 */
TitleEffect Titles::outsider = {.alcohol = {.energy = 1,
                                            .love = 1,
                                            .relationship = 1.1,
                                            .self_develop = 1,
                                            .study = 1,
                                            .stress = 1},
                                .study = {.energy = 1,
                                          .love = 1,
                                          .relationship = 1.1,
                                          .self_develop = 1,
                                          .study = 1,
                                          .stress = 1},
                                .circle = {.energy = 1,
                                           .love = 1,
                                           .relationship = 1.1,
                                           .self_develop = 1,
                                           .study = 1,
                                           .stress = 1},
                                .love = {.energy = 1,
                                         .love = 1,
                                         .relationship = 1.1,
                                         .self_develop = 1,
                                         .study = 1,
                                         .stress = 1},
                                .rest = {.energy = 1,
                                         .love = 1,
                                         .relationship = 1,
                                         .self_develop = 1,
                                         .study = 1,
                                         .stress = 1},
                                .home = {.energy = 1,
                                         .love = 1,
                                         .relationship = 1,
                                         .self_develop = 1,
                                         .study = 1,
                                         .stress = 1}};
/** 술쟁이 */
TitleEffect Titles::alcoholic = {.alcohol = {.energy = 1,
                                             .love = 1,
                                             .relationship = 1.1,
                                             .self_develop = 1,
                                             .study = 1,
                                             .stress = -1},
                                 .study = {.energy = 1,
                                           .love = 1,
                                           .relationship = 1,
                                           .self_develop = 1,
                                           .study = 0.9,
                                           .stress = 1},
                                 .circle = {.energy = 1,
                                            .love = 1,
                                            .relationship = 1,
                                            .self_develop = 1,
                                            .study = 1,
                                            .stress = 1},
                                 .love = {.energy = 1,
                                          .love = 1,
                                          .relationship = 1,
                                          .self_develop = 1,
                                          .study = 1,
                                          .stress = 1},
                                 .rest = {.energy = 1,
                                          .love = 1,
                                          .relationship = 1,
                                          .self_develop = 1,
                                          .study = 1,
                                          .stress = 1},
                                 .home = {.energy = 1,
                                          .love = 1,
                                          .relationship = 1,
                                          .self_develop = 1,
                                          .study = 1,
                                          .stress = 1}};
/** 동방충 */
TitleEffect Titles::circle_resident = {.alcohol = {.energy = 1,
                                                   .love = 1,
                                                   .relationship = 1,
                                                   .self_develop = 1,
                                                   .study = 1,
                                                   .stress = 1},
                                       .study = {.energy = 1,
                                                 .love = 1,
                                                 .relationship = 1,
                                                 .self_develop = 1,
                                                 .study = 1,
                                                 .stress = 1},
                                       .circle = {.energy = 1,
                                                  .love = 1,
                                                  .relationship = 1.05,
                                                  .self_develop = 1,
                                                  .study = 1,
                                                  .stress = 1.05},
                                       .love = {.energy = 1,
                                                .love = 1,
                                                .relationship = 1,
                                                .self_develop = 1,
                                                .study = 1,
                                                .stress = 1},
                                       .rest = {.energy = 1,
                                                .love = 1,
                                                .relationship = 1,
                                                .self_develop = 1,
                                                .study = 1,
                                                .stress = 1},
                                       .home = {.energy = 1,
                                                .love = 1,
                                                .relationship = 1,
                                                .self_develop = 1,
                                                .study = 1,
                                                .stress = 1}};
/** 공부벌레 */
TitleEffect Titles::nerd = {.alcohol = {.energy = 1,
                                        .love = 1,
                                        .relationship = 0.95,
                                        .self_develop = 1,
                                        .study = 1.1,
                                        .stress = 0.95},
                            .study = {.energy = 1,
                                      .love = 1,
                                      .relationship = 0.95,
                                      .self_develop = 1,
                                      .study = 1.1,
                                      .stress = 0.95},
                            .circle = {.energy = 1,
                                       .love = 1,
                                       .relationship = 0.95,
                                       .self_develop = 1,
                                       .study = 1.1,
                                       .stress = 0.95},
                            .love = {.energy = 1,
                                     .love = 1,
                                     .relationship = 0.95,
                                     .self_develop = 1,
                                     .study = 1.1,
                                     .stress = 0.95},
                            .rest = {.energy = 1,
                                     .love = 1,
                                     .relationship = 0.95,
                                     .self_develop = 1,
                                     .study = 1.1,
                                     .stress = 0.95},
                            .home = {.energy = 1,
                                     .love = 1,
                                     .relationship = 0.95,
                                     .self_develop = 1,
                                     .study = 1.1,
                                     .stress = 0.95}};
/** 연애중 */
TitleEffect Titles::couple = {.alcohol = {.energy = 1.1,
                                          .love = -1,
                                          .relationship = 0.9,
                                          .self_develop = 0,
                                          .study = 0.9,
                                          .stress = 0.9},
                              .study = {.energy = 1.1,
                                        .love = -1,
                                        .relationship = 0.9,
                                        .self_develop = 0,
                                        .study = 0.9,
                                        .stress = 0.9},
                              .circle = {.energy = 1.1,
                                         .love = -1,
                                         .relationship = 0.9,
                                         .self_develop = 0,
                                         .study = 0.9,
                                         .stress = 0.9},
                              .love = {.energy = 1.1,
                                       .love = 1,
                                       .relationship = 0.9,
                                       .self_develop = 0,
                                       .study = 0.9,
                                       .stress = 0.9},
                              .rest = {.energy = 1.1,
                                       .love = 1,
                                       .relationship = 0.9,
                                       .self_develop = 0,
                                       .study = 0.9,
                                       .stress = 0.9},
                              .home = {.energy = 1.1,
                                       .love = 1,
                                       .relationship = 0.9,
                                       .self_develop = 0,
                                       .study = 0.9,
                                       .stress = 0.9}};
/** 무동아리 */
TitleEffect Titles::circle_independent = {.alcohol = {.energy = 1,
                                                      .love = 1,
                                                      .relationship = 0.9,
                                                      .self_develop = 1,
                                                      .study = 1,
                                                      .stress = 1},
                                          .study = {.energy = 1,
                                                    .love = 1,
                                                    .relationship = 0.9,
                                                    .self_develop = 1,
                                                    .study = 1,
                                                    .stress = 1},
                                          .circle = {.energy = 1,
                                                     .love = 1,
                                                     .relationship = 0.9,
                                                     .self_develop = 1,
                                                     .study = 1,
                                                     .stress = 1},
                                          .love = {.energy = 1,
                                                   .love = 1,
                                                   .relationship = 0.9,
                                                   .self_develop = 1,
                                                   .study = 1,
                                                   .stress = 1},
                                          .rest = {.energy = 1,
                                                   .love = 1,
                                                   .relationship = 0.9,
                                                   .self_develop = 1,
                                                   .study = 1,
                                                   .stress = 1},
                                          .home = {.energy = 1,
                                                   .love = 1,
                                                   .relationship = 0.9,
                                                   .self_develop = 1,
                                                   .study = 1,
                                                   .stress = 1}};
/** 체력낮음 */
TitleEffect Titles::weak = {.alcohol = {.energy = 1,
                                        .love = 1,
                                        .relationship = 1,
                                        .self_develop = 1,
                                        .study = 1,
                                        .stress = 1},
                            .study = {.energy = 1,
                                      .love = 1,
                                      .relationship = 1,
                                      .self_develop = 1,
                                      .study = 1,
                                      .stress = 1},
                            .circle = {.energy = 1,
                                       .love = 1,
                                       .relationship = 1,
                                       .self_develop = 1,
                                       .study = 1,
                                       .stress = 1},
                            .love = {.energy = 1,
                                     .love = 1,
                                     .relationship = 1,
                                     .self_develop = 1,
                                     .study = 1,
                                     .stress = 1},
                            .rest = {.energy = 1.1,
                                     .love = 1.1,
                                     .relationship = 1.1,
                                     .self_develop = 1.1,
                                     .study = 1.1,
                                     .stress = 1.1},
                            .home = {.energy = 1,
                                     .love = 1,
                                     .relationship = 1,
                                     .self_develop = 1,
                                     .study = 1,
                                     .stress = 1}};

const map<string, const TitleEffect&> Titles::map = {
    {"outsider", Titles::outsider},
    {"alcoholic", Titles::alcoholic},
    {"circle_resident", Titles::circle_resident},
    {"nerd", Titles::nerd},
    {"couple", Titles::couple},
    {"circle_independent", Titles::circle_independent},
    {"weak", Titles::weak}};
