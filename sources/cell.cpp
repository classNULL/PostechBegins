#include "cell.hpp"

cell_option_book cell::call_option_zero(hero* _hero, int day) {
    vector<cell_option> options;

    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 7, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -4 },
        day);
        return L"체력이 다 떨어져 쉴 수밖에 없다...";
    }));

    return cell_option_book(L"에너지가 부족합니다.", options);
}
cell_option_book cell::call_option_special(hero* _hero, int day) {
    vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -2, .self_develop = 0, .study = -2, .stress = 7 },
        day);
        return L"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다.";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 5, .self_develop = 0, .study = -4, .stress = 5 },
        day);
        return L"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다..";
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 3, .self_develop = 2, .study = -4, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
        return L"동아리 활동을 즐기자";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        bool is_inLove = _hero->get_title_book().has_title("couple");
        if (is_inLove){
            _hero->get_title_book_pointer()->remove_title("couple");
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .love = -15, .relationship = -2, .self_develop = 0, .study = -4, .stress = 15 },
            day);
            return L"........오늘 헤어졌다.아..스트레스 받아.....";
        }
        else {
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .love = -8, .relationship = -2, .self_develop = 0, .study = -4, .stress = 6 },
            day);
            return L"....어장관리 당했다....괜히 시간만 날렸다..";
        }
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -2 },
        day);
        return L"..퀴즈 점수가 나왔다..나는 먼지같은 인간이다..이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다...";
    }));

    return cell_option_book(options);
}

cell_option_book normal::call_option(hero* _hero, int day) {
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    if (rand() % 100 == 1)
        return this->call_option_special(_hero, day);

    vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -2, .self_develop = 0, .study = 3, .stress = 6 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
        return L"공부를 했다. 뿌듯하다.";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 5, .self_develop = 0, .study = -4, .stress = 3 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
        return L"친구들과 함께 술을 마셨다. 친구들과 더 친해진것 같다.";
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 3, .self_develop = 2, .study = -4, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
        return L"동아리 활동을 했다. 취미생활을 하니 기분이 좋다.";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 5, .relationship = -2, .self_develop = 0, .study = -4, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().love,
        day);
        return L"조금 더 친해진것 같다... 헤헷";
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
        return L"아무것도 하지않고 쉬었다. 가끔은 이럴때도 있어야지..";
    }));

    return cell_option_book(options);
}

cell_option_book weekend::call_option_zero(hero* _hero, int day){
    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -5 },
        day);
        return L"체력이 다 떨어져 쉴 수밖에 없다...";
    }));
    options.push_back(cell_option(L"집가기", [_hero, day]() {
        _hero->change_status(
        { .energy = 50, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().home,
        1);
        return L"집에 다녀왔다. 완전 충전된 기분이야.";
    }));
    return cell_option_book(L"에너지가 부족합니다.", options);
}
cell_option_book weekend::call_option_special(hero* _hero, int day){
    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -2, .self_develop = 0, .study = -2, .stress = 7 },
        day);
        return L"날씨가 너무 화창한바람에 공부가 되지 않는다...괜히 시간만날렸다.";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 5, .self_develop = 0, .study = -4, .stress = 5 },
        day);
        return L"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다. 괜히 시간만 날렸다..";
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 3, .self_develop = 2, .study = -4, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
        return L"동아리 활동을 즐기자";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day](){
        bool is_inLove = _hero->get_title_book().has_title("couple");
        if (is_inLove){
            _hero->get_title_book_pointer()->remove_title("couple");
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .love = -15, .relationship = -2, .self_develop = 0, .study = -4, .stress = 15 },
            day);
            return L"......오늘 헤어졌다. 아..스트레스 받아.....";
        }
        else {
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .love = -8, .relationship = -2, .self_develop = 0, .study = -4, .stress = 6 },
            day);
            return L"....어장관리 당했다....괜히 시간만 날렸다..";
        }
    }));
    options.push_back(cell_option(L"휴식", [_hero, day](){
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -2 },
        day);
        return L"..퀴즈 점수가 나왔다.. 나는 먼지같은 인간이다.. 이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다...";
    }));
    options.push_back(cell_option(L"집가기", [_hero, day](){
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = 3 },
        day);
        return L"..알고보니 나는 제주도 사람이었다... 비행기가 결항되어 집에 갈 수 없다....";
    }));
    return cell_option_book(options);
}
cell_option_book weekend::call_option(hero* _hero, int day){
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    if (rand() % 100 == 1)
        return this->call_option_special(_hero, day);


    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -2, .self_develop = 0, .study = 3, .stress = 6 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
        return L"공부를 했다. 뿌듯하다.";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 5, .self_develop = 0, .study = -4, .stress = 3 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
        return L"친구들과 함께 술을 마셨다. 친구들과 더 친해진것 같다.";
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 3, .self_develop = 2, .study = -4, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
        return L"동아리 활동을 했다. 취미생활을 하니 기분이 좋다.";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 5, .relationship = -2, .self_develop = 0, .study = -4, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().love,
        day);
        return L"조금 더 친해진것 같다... 헤헷";
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
        return L"아무것도 하지않고 쉬었다. 가끔은 이럴때도 있어야지..";
    }));
    options.push_back(cell_option(L"집가기", [_hero, day](){
        _hero->change_status(
        { .energy = 50, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().home,
        1);
        return L"집에 다녀왔다. 완전 충전된 기분이야.";
    }));

    return cell_option_book(options);
}

cell_option_book march::call_option(hero* _hero, int day){
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    if (rand() % 100 == 1)
        return this->call_option_special(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -2, .self_develop = 0, .study = 3, .stress = 6 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
        return L"공부를 했다. 뿌듯하다.";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 5, .self_develop = 0, .study = -4, .stress = 3 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
        return L"친구들과 함께 술을 마셨다. 친구들과 더 친해진것 같다.";
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 3, .self_develop = 2, .study = -4, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
        return L"동아리 활동을 했다. 취미생활을 하니 기분이 좋다.";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 5, .relationship = -2, .self_develop = 0, .study = -4, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().love,
        day);
        return L"조금 더 친해진것 같다... 헤헷";
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
        return L"아무것도 하지않고 쉬었다. 가끔은 이럴때도 있어야지..";
    }));
    options.push_back(cell_option(L"밥사달라고하기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 5, .self_develop = 0, .study = -2, .stress = -3 },
        day);
        return L"선배에게 밥을 얻어먹었다.";
    }));

    return cell_option_book(options);
}

cell_option_book special::call_option(hero* _hero, int day) {
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"참가한다", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = 8, .self_develop = 0, .study = -4, .stress = 4 },
        1);
        return L"친구들, 선배들과 좀 더 친해진것 같다.";
    }));
    options.push_back(cell_option(L"참가하지 않는다", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = -8, .self_develop = 0, .study = 4, .stress = -2 },
        1);
        return L"친구들, 선배들과 친해질 기회인데.. 에라 공부나 해야지";
    }));

    return cell_option_book(options);
}

cell_option_book eve_1::call_option(hero* _hero, int day) {
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"수업가기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -2, .self_develop = 0, .study = 5, .stress = 7 },
        _hero->get_title_book().get_total_title_effect().study,
        1);
        return L"뿌듯. 태풍이 불어 왔지만 수업에 갔다왔다";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 2, .relationship = 6, .self_develop = 0, .study = -4, .stress = 4 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        1);
        return L"크..태풍을 바라보며 술 한잔 걸쳤다";
    }));
    options.push_back(cell_option(L"나들이", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 3, .relationship = 5, .self_develop = 0, .study = -4, .stress = -3 },
        1);
        return L"이런 날은 나들이. 나들이 갔다왔다~";
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        1);
        return L"그냥 푹 쉬었다~";
    }));

    return cell_option_book(options);
}

cell_option_book eve_2::call_option(hero* _hero, int day) {
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -2, .self_develop = 0, .study = 1, .stress = 7 },
        _hero->get_title_book().get_total_title_effect().study,
        1);
        return L"크 뿌듯...밤을 샜지만 공부를 했다..";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = -1, .relationship = 4, .self_develop = 0, .study = -4, .stress = 5 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        1);
        return L"무슨 날이든 나는 술은 마신다";
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 2, .self_develop = 2, .study = -4, .stress = 1 },
        _hero->get_title_book().get_total_title_effect().circle,
        1);
        return L"피곤하지만..동아리 활동은 언제나 즐겁징";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 4, .relationship = -2, .self_develop = 0, .study = -4, .stress = 3 },
        _hero->get_title_book().get_total_title_effect().love,
        1);
        return L"졸려죽겠지만....";
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        1);
        return L"피곤하니까 쉬어야지";
    }));

    return cell_option_book(options);
}

cell_option_book eve_3::call_option(hero* _hero, int day) {
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"수업가기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -5, .self_develop = 0, .study = 2, .stress = 7 },
        _hero->get_title_book().get_total_title_effect().study,
        1);
        return L"오늘 아무도 마주치지 않겠다..";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = -1, .relationship = -3, .self_develop = 0, .study = -4, .stress = 5 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        1);
        return L"술마시는데 차려입을 필요 있나~";
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = -1, .relationship = -4, .self_develop = 1.8, .study = -4, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        1);
        return L"동아리는 편하니까";
    }));
    options.push_back(cell_option(L"빨래하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = 0, .self_develop = 0, .study = -3, .stress = 1 },
        1);
        return L"그래...이제 좀 해야지";
    }));
    options.push_back(cell_option(L"옷 빌리기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = 1, .self_develop = 0, .study = 0, .stress = -3 },
        1);
        return L"나는 언제나 신선함을 유지한다";
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        1);
        return L"입을 옷도 없는데 그냥 방콕해야징";
    }));

    return cell_option_book(options);
}

cell_option_book before_exam::call_option(hero* _hero, int day) {
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    if (rand() % 100 == 1)
        return this->call_option_special(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -1.6, .self_develop = 0, .study = 4, .stress = 8 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
        return L"역시 공부는 시험직전 벼락치기가 제맛이지.";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 6, .self_develop = 0, .study = -8, .stress = 5 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
        return L"친구들과 술을 마셨다. 재미있긴 한데 시험전에 이래도 되려나...";
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 4, .self_develop = 1.5, .study = -6, .stress = -3.6 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
        return L"동아리 활동을 했다. 재미있긴 한데 시험전에 이래도 되려나...";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 5, .relationship = -2, .self_develop = 0, .study = -4, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().love,
        day);
        return L"사이는 좋아진것 같지만 공부해야 되는데...";
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = -3, .stress = -2.5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
        return L"아.. 지금 쉴때가 아닌데...";
    }));

    return cell_option_book(options);
}

cell_option_book exam::call_option(hero* _hero, int day) {
    vector<cell_option> options;
    options.push_back(cell_option(L"시험치기", [_hero, day]() {
        _hero->take_exam();
        return L"시험을 보았다.";
    }));
    return cell_option_book(options);
}

cell_option_book after_exam::call_option(hero* _hero, int day) {
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    if (rand() % 100 == 1)
        return this->call_option_special(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -4, .self_develop = 0, .study = 1.4, .stress = 6 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
        return L"시험 끝나고 공부라니.. 이게 뭐하는 짓이야.";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 7.5, .self_develop = 0, .study = -2, .stress = 4 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
        return L"역시 시험끝나면 술을 달려야 한다.";
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 4, .self_develop = 2, .study = -2, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
        return L"시험도 끝나고 동아리에서 노니 스트레스가 확 풀린다.";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 5, .relationship = -3, .self_develop = 0, .study = -2, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().love,
        day);
        return L"시험도 끝났으니... 헤헷";
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
        return L"시험도 끝났으니 푹 쉬어야지.";
    }));

    return cell_option_book(options);
}

cell_option_book festival::call_option(hero* _hero, int day) {
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    if (rand() % 100 == 1)
        return this->call_option_special(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -10, .self_develop = 0, .study = 3, .stress = 8 },
        _hero->get_title_book().get_total_title_effect().study,
        1);
        return L"축제 때 공부! 공부찐따가 된 기분이군";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 15, .self_develop = 0, .study = -0.8, .stress = 4 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        1);
        return L"역시 축제는 술마시고 노는거징";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 5, .relationship = -12, .self_develop = 0, .study = -4, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().circle,
        1);
        return L"축제에는 역시....(ㅎㅎ)";
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = -10, .self_develop = 0, .study = 0, .stress = -4 },
        _hero->get_title_book().get_total_title_effect().rest,
        1);
        return L"피곤해 죽겠는데 쉬기나 하자";
    }));
    options.push_back(cell_option(L"집가기", [_hero, day]() {
        _hero->change_status(
        { .energy = 50, .love = 0, .relationship = -12, .self_develop = 0, .study = 0, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().home,
        1);
        return L"축제는 휴일의 또 다른 이름! 집이나 가야지~";
    }));

    return cell_option_book(options);
}
cell_option_book festival::call_option_special(hero* _hero, int day){
    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -2, .self_develop = 0, .study = 1, .stress = 7 },
        1);
        return L"괜히 공부했나 시끄러워서 되는 느낌이 안들어!";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 5, .self_develop = 0, .study = -4, .stress = 5 },
        1);
        return L"흑 이상한 선배한테 붙잡혔다...축제 때 이게 뭐야 ㅠㅠ.";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day](){
        bool is_inLove = _hero->get_title_book().has_title("couple");
        if (is_inLove){
            _hero->get_title_book_pointer()->remove_title("couple");
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .love = -15, .relationship = -2, .self_develop = 0, .study = -4, .stress = 15 },
            1);
            return L"......오늘 헤어졌다. 아..스트레스 받아.....";
        }
        else {
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .love = -8, .relationship = -2, .self_develop = 0, .study = -4, .stress = 6 },
            1);
            return L"....어장관리 당했다....괜히 시간만 날렸다..";
        }
    }));
    options.push_back(cell_option(L"휴식", [_hero, day](){
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -2 },
        1);
        return L"밖이 엄청 시끄럽다...쉬어도 쉰 것 같지 않다...";
    }));
    options.push_back(cell_option(L"집가기", [_hero, day](){
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = 3 },
        1);
        return L"..알고보니 나는 제주도 사람이었다... 비행기가 결항되어 집에 갈 수 없다....";
    }));
    return cell_option_book(options);
}
cell_option_book festival::call_option_zero(hero* _hero, int day){
    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -5 },
        1);
        return L"체력이 다 떨어져 쉴 수밖에 없다...";
    }));
    return cell_option_book(L"에너지가 부족합니다.", options);
}

cell_option_book dance::call_option(hero* _hero, int day) {
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    if (rand() % 100 == 1)
        return this->call_option_special(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -3, .self_develop = 0, .study = 3, .stress = 6 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
        return L"오늘은 아무래도 공부를 해야할 것 같아 ㅜㅜ";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 5, .self_develop = 0, .study = -4, .stress = 3 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
        return L"오늘은...술이 땡기니까...";
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 2, .self_develop = 1.5, .study = -4, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
        return L"오늘 동아리 활동을 빠질 수 없어 ㅜㅜ";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 5, .relationship = -3, .self_develop = 0, .study = -4, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().love,
        day);
        return L"춤때문에 바쁘지만 차근차근";
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = -3, .self_develop = 0, .study = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
        return L"오늘은 도저히 춤 못추겠다 ㅜㅜ쉬어야지";
    }));
    options.push_back(cell_option(L"춤 연습하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = 7, .self_develop = 0, .study = -4, .stress = 3.6 },
        day);
        return L"춤춘다 춤~";
    }));

    return cell_option_book(options);
}
cell_option_book dance::call_option_special(hero* _hero, int day) {
    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -2, .self_develop = 0, .study = -2, .stress = 7 },
        day);
        return L"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다.";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 1, .relationship = 5, .self_develop = 0, .study = -4, .stress = 5 },
        day);
        return L"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다..";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        bool is_inLove = _hero->get_title_book().has_title("couple");
        if (is_inLove){
            _hero->get_title_book_pointer()->remove_title("couple");
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .love = -15, .relationship = -2, .self_develop = 0, .study = -4, .stress = 15 },
            day);
            return L"........오늘 헤어졌다.아..스트레스 받아.....";
        }
        else {
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .love = -8, .relationship = -2, .self_develop = 0, .study = -4, .stress = 6 },
            day);
            return L"....어장관리 당했다....괜히 시간만 날렸다..";
        }
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -2 },
        day);
        return L"..헉 몰래 쉰 것을 선배들한테 들켰다 ㅜㅜㅜ 망했다...";
    }));
    options.push_back(cell_option(L"춤 연습하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .love = 0, .relationship = -3, .self_develop = 0, .study = 0, .stress = 4 },
        day);
        return L"...다리를 삐어서 춤연습을 제대로 할 수 없다 ㅜㅜ...";
    }));

    return cell_option_book(options);
}
cell_option_book vacation::call_option(hero* _hero, int day){
    vector<cell_option> options;
    options.push_back(cell_option(L"놀기", [_hero, day]() {
        _hero->finish_semester();
        _hero->change_status(
        { .energy = 100, .love = 0, .relationship = 0, .self_develop = 0, .study = 0, .stress = -100 },
        1);
        return L"방학 동안 푹 쉬었다! 다음 학기가 시작되었다.";
    }));
    return cell_option_book(options);
}
cell_option_book win_vac::call_option(hero* _hero, int day){
    vector<cell_option> options;
    options.push_back(cell_option(L"결과 보기", [_hero, day]() {
        return L"";
    }));
    return cell_option_book(options);
}
