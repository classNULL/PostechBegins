#include "cell.hpp"

cell_option_book cell::call_option_zero(hero* _hero, int day) {
    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy =8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
        day);
    }));

    return cell_option_book(L"에너지가 부족합니다.", options);
}
cell_option_book cell::call_option_special(hero* _hero, int day) {
    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
        day);
        return L"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다.";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 6 },
        day);
        return L"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다..";
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 1, .love = 1, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
        return;
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        bool is_inLove = _hero->get_title_book().has_title("couple");
        if (is_inLove){
            _hero->get_title_book_pointer()->remove_title("couple");
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = -15, .stress = 15 },
            day);
            return L"........오늘 헤어졌다.아..스트레스 받아.....";
        }
        else {
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = -8, .stress = 6 },
            day);
            return L"....어장관리 당했다....괜히 시간만 날렸다..";
        }
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2 },
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

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 8 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 5 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 1, .love = 1, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().love,
        day);
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
    }));

    return cell_option_book(options);
}


cell_option_book weekend::call_option_zero(hero* _hero, int day){
    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;
    options.push_back(cell_option(L"휴식", [_hero, day](){
        _hero->change_status(
        {
            .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
            day);
    }));
    return cell_option_book(L"에너지가 부족합니다.", options);
}
cell_option_book weekend::call_option_special(hero* _hero, int day){
    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
        day);
        return L"날씨가 너무 화창한바람에 공부가 되지 않는다...괜히 시간만날렸다.";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 6 },
        day);
        return L"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다. 괜히 시간만 날렸다..";
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 1, .love = 1, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
        return;
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day](){
        bool is_inLove = _hero->get_title_book().has_title("couple");
        if (is_inLove){
            _hero->get_title_book_pointer()->remove_title("couple");
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = -15, .stress = 15 },
            day);
            return L"......오늘 헤어졌다. 아..스트레스 받아.....";
        }
        else {
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = -8, .stress = 6 },
            day);
            return L"....어장관리 당했다....괜히 시간만 날렸다..";
        }
    }));
    options.push_back(cell_option(L"휴식", [_hero, day](){
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2 },
        day);
        return L"..퀴즈 점수가 나왔다.. 나는 먼지같은 인간이다.. 이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다...";
    }));
    options.push_back(cell_option(L"집가기", [_hero, day](){
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = 3 },
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

    options.push_back(cell_option(L"공부하기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 8 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 5 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 1, .love = 1, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().love,
        day);
    }));
    options.push_back(cell_option(L"휴식", [_hero, day](){
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
    }));
    options.push_back(cell_option(L"집가기", [_hero, day](){
        _hero->change_status(
        { .energy = 0, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().home,
        day);
        _hero->recover_energy();
    }));

    return cell_option_book(options);
}


cell_option_book march::call_option(hero* _hero, int day){
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    if (rand() % 100 == 1)
        return this->call_option_special(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 8 },
        day);
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 5 },
        day);
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 5 },
        day);
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
        day);
    }));
    options.push_back(cell_option(L"휴식", [_hero, day](){
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
        day);
    }));
    options.push_back(cell_option(L"밥사달라고하기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = 5, .self_develop = 0, .love = 1, .stress = -3 },
        day);
    }));

    return cell_option_book(options);
}

cell_option_book special::call_option(hero* _hero, int day) {
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"참가한다", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 8, .self_develop = 0, .love = 0, .stress = 4 },
        day);
    }));
    options.push_back(cell_option(L"참가하지 않는다", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .study = 4, .relationship = -8, .self_develop = 0, .love = 0, .stress = -2 },
        day);
    }));

    return cell_option_book(options);
}

cell_option_book eve_1::call_option(hero* _hero, int day) {
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"수업가기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = 4, .relationship = -2, .self_develop = 0, .love = 0, .stress = 10 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 6, .self_develop = 0, .love = 2, .stress = 7 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
    }));
    options.push_back(cell_option(L"나들이", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 3, .stress = -2 },
        day);
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
    }));

    return cell_option_book(options);
}

cell_option_book eve_2::call_option(hero* _hero, int day) {
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = 1, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 4, .self_develop = 0, .love = -1, .stress = 6 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 4, .self_develop = 1, .love = 1, .stress = 1 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 4, .stress = 3 },
        _hero->get_title_book().get_total_title_effect().love,
        day);
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
    }));

    return cell_option_book(options);
}

cell_option_book eve_3::call_option(hero* _hero, int day) {
    if (_hero->exhausted())
        return this->call_option_zero(_hero, day);

    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"수업가기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -5, .self_develop = 0, .love = 0, .stress = 8 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -3, .self_develop = 0, .love = -1, .stress = 5 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -3, .self_develop = 1, .love = -1, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
    }));
    options.push_back(cell_option(L"빨래하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -3, .relationship = 0, .self_develop = 0, .love = 0, .stress = 1 },
        day);
    }));
    options.push_back(cell_option(L"옷 빌리기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = 0, .relationship = 1, .self_develop = 0, .love = 0, .stress = -3 },
        day);
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
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
        { .energy = _hero->get_energy_consuming_rate(), .study = 3, .relationship = -1.6, .self_develop = 0, .love = 0, .stress = 9.6 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -8, .relationship = 6, .self_develop = 0, .love = 1, .stress = 7.5 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -6, .relationship = 6, .self_develop = 0.8, .love = 1, .stress = -3.6 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().love,
        day);
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .study = -3, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2.5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
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
        { .energy = _hero->get_energy_consuming_rate(), .study = 1.4, .relationship = -4, .self_develop = 0, .love = 0, .stress = 8 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = 7.5, .self_develop = 0, .love = 1, .stress = 4 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = 6, .self_develop = 1, .love = 1, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = -3, .self_develop = 0, .love = 5, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().love,
        day);
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
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
        { .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -10, .self_develop = 0, .love = 0, .stress = 8 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -0.8, .relationship = 15, .self_develop = 0, .love = 1, .stress = 4 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -12, .self_develop = 0, .love = 5, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = -10, .self_develop = 0, .love = 0, .stress = -4 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
    }));
    options.push_back(cell_option(L"집가기", [_hero, day]() {
        _hero->change_status(
        { .energy = 0, .study = 0, .relationship = -12, .self_develop = 0, .love = 0, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().home,
        1);
        _hero->recover_energy();
    }));

    return cell_option_book(options);
}
cell_option_book festival::call_option_special(hero* _hero, int day){
    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
        day);
        return L"날씨가 너무 화창한바람에 공부가 되지 않는다...괜히 시간만날렸다.";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day](){
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 6 },
        day);
        return L"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다. 괜히 시간만 날렸다..";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day](){
        bool is_inLove = _hero->get_title_book().has_title("couple");
        if (is_inLove){
            _hero->get_title_book_pointer()->remove_title("couple");
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = -15, .stress = 15 },
            day);
            return L"......오늘 헤어졌다. 아..스트레스 받아.....";
        }
        else {
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = -8, .stress = 6 },
            day);
            return L"....어장관리 당했다....괜히 시간만 날렸다..";
        }
    }));
    options.push_back(cell_option(L"휴식", [_hero, day](){
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2 },
        day);
        return L"..퀴즈 점수가 나왔다.. 나는 먼지같은 인간이다.. 이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다...";
    }));
    options.push_back(cell_option(L"집가기", [_hero, day](){
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = 3 },
        day);
        return L"..알고보니 나는 제주도 사람이었다... 비행기가 결항되어 집에 갈 수 없다....";
    }));
    return cell_option_book(options);
}
cell_option_book festival::call_option_zero(hero* _hero, int day){
    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;
    options.push_back(cell_option(L"휴식", [_hero, day](){
        _hero->change_status(
        {
            .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
            day);
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
        { .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -3, .self_develop = 0, .love = 0, .stress = 8 },
        _hero->get_title_book().get_total_title_effect().study,
        day);
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 5 },
        _hero->get_title_book().get_total_title_effect().alcohol,
        day);
    }));
    options.push_back(cell_option(L"동아리 활동하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 4, .self_develop = 1, .love = 1, .stress = -3 },
        _hero->get_title_book().get_total_title_effect().circle,
        day);
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -3, .self_develop = 0, .love = 5, .stress = 0 },
        _hero->get_title_book().get_total_title_effect().love,
        day);
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = -3, .self_develop = 0, .love = 0, .stress = -5 },
        _hero->get_title_book().get_total_title_effect().rest,
        day);
    }));
    options.push_back(cell_option(L"춤 연습하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 7, .self_develop = 0, .love = 0, .stress = 6 },
        day);
    }));

    return cell_option_book(options);
}
cell_option_book dance::call_option_special(hero* _hero, int day) {
    clog << "'this' pointer" << _hero << endl; vector<cell_option> options;

    options.push_back(cell_option(L"공부하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
        day);
        return L"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다.";
    }));
    options.push_back(cell_option(L"술마시기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 6 },
        day);
        return L"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다..";
    }));
    options.push_back(cell_option(L"연애하기", [_hero, day]() {
        bool is_inLove = _hero->get_title_book().has_title("couple");
        if (is_inLove){
            _hero->get_title_book_pointer()->remove_title("couple");
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = -15, .stress = 15 },
            day);
            return L"........오늘 헤어졌다.아..스트레스 받아.....";
        }
        else {
            _hero->change_status(
            { .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = -8, .stress = 6 },
            day);
            return L"....어장관리 당했다....괜히 시간만 날렸다..";
        }
    }));
    options.push_back(cell_option(L"휴식", [_hero, day]() {
        _hero->change_status(
        { .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2 },
        day);
        return L"..헉 몰래 쉰 것을 선배들한테 들켰다 ㅜㅜㅜ 망했다...";
    }));
    options.push_back(cell_option(L"춤 연습하기", [_hero, day]() {
        _hero->change_status(
        { .energy = _hero->get_energy_consuming_rate(), .study = 0, .relationship = -3, .self_develop = 0, .love = 0, .stress = 5 },
        day);
        return L"...다리를 삐어서 춤연습을 제대로 할 수 없다 ㅜㅜ...";
    }));

    return cell_option_book(options);
}
