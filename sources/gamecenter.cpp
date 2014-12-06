#include "gamecenter.hpp"
#include <fstream>

// void GameCenter::put_ranking(){
//
// 	ifstream fin;
//
// 	fin.open("ranking.txt");
//
//
// 	if(fin.is_open()){
// 		//랭킹 파일이 있어서 열렸을 때
// 		char buffer[100];//파일에서 값을 읽어와 저장할 변수
// 				for(int i=0; i<100; i++)
// 					buffer[i]=NULL;//NULL로 초기화
// 		int count=0;
// 		int score_arr[3];//3등까지 점수저장
// 		for(int k=0; k<3; k++)
// 			score_arr[k]=NULL;//NULL로 초기화
// 		char* id_array[3];//3등까지 이름저장
//
// 		/* 랭킹파일 포맷
// 		1AAA1000----점수가 4자리 수인 경우
// 		2BBB521-----점수가 3자리수인 경우
// 		3CCC21----점수가 2자리 수인 경우
// 		01234567
// 		이렇게 등수/아이디/점수로 출력하게됨
// 		*/
//
//
// 				while(fin.getline(buffer,100)){
// 					//이제 버퍼에 값이 들어간다.
// 					id_array[count][0]=buffer[2];
// 					id_array[count][1]=buffer[3];
// 					id_array[count][2]=buffer[4];
//
//
// 					if(buffer[5]==NULL){
// 						//점수가 한자리수!
// 						score_arr[count]=(int(buffer[4]-48));
// 					}
// 					else if(buffer[6]==NULL){
// 						//점수가 두 자리수!
// 						score_arr[count]=(int(buffer[4]-48))*10+(int(buffer[5]-48));
// 					}
// 					else if(buffer[7]==NULL){
// 						//점수가 세 자리수 !
// 						score_arr[count]=(int(buffer[4]-48))*100+(int(buffer[5]-48))*10+(int(buffer[6]-48));
// 					}
// 					else if(buffer[8]==NULL){
// 						//점수가 세 자리수 !
// 						score_arr[count]=(int(buffer[4]-48))*1000+(int(buffer[5]-48))*100+(int(buffer[6]-48))*10+(int(buffer[7]-48));
// 					}
//
// 					count++;
//
// 				for(int i=0; i<100; i++)
// 					buffer[i]=NULL;//NULL로 초기화
// 				}
//
//
//
// 				//이제 1,2,3등의 정보가 모두 들어갔다.
// 				//정확히 count만큼 ---1등의 정보만 있었다면 count는 1이 되어있음
// 				//랭킹에 1등, 2등이 있었다면 1,2 등의 정보가 array에 저장되고 count는 2가 되어있음.
// 				int i=0;
// 				int current_score=score(_character->get_study(),_character->get_relationship(),_character->get_self_develop);
// 				//현재 게임하던 아이의 점수 정보
// 				while(i<count){
// 					if(current_score>=score_arr[i]){
// 						break;
// 					}
// 					i++;
// 				}
// 				//이 친구는 array의 i 자리에 들어가야 한다.
// 				if(i>2){
// 					//3등안에 못들었음 무쓸모
// 				}
// 				else{
// 					for(int j=i; j<3;j++){
// 						score_arr[j+1]=score_arr[j];//한칸씩 미룬다.
//
// 						id_array[j+1][0]=id_array[j][0];
// 						id_array[j+1][1]=id_array[j][1];
// 						id_array[j+1][2]=id_array[j][2]; //id도 한칸씩 미룬다.
// 					}
// 					score_arr[i]=current_score;
//
// 					cin>>id_array[i];// id 입력받아서 저장
//
// 					ofstream fout("ranking.txt",ios::trunc);//이제 랭킹파일을 다시 연다.
//
// 					fout.open();//파일 열고
//
// 					i=0;
// 					while(score_arr[i]!=NULL && i<3){//점수 어레이에 들어있는 명수 만큼 내보냄. 2등까지만 있으면 2명의 정보만 내보내야함
// 						//처음에 score_arr가 NULL로 초기화 되어있었던 걸 이용
// 						fout<<i+1;//등수
// 						fout<<id_array[i];//아이디
// 						fout<<score_arr[i];//점수 입력
// 						fout<<endl;//한 번 치고 엔터
// 					}
// 				}
//
// 					fin.close();//파일을 닫는다.
// 	}
// 	else{
// 		//랭킹 파일이 없을 때
// 		//바로 1등으로 넣어버리면 됨.
// 		ofstream fout("ranking.txt");
// 		fout.open();//파일 열고
//
// 		fout<<1;//등수 입력
//
// 		char* id;
//
// 		cin>>id;//id입력받음
//
// 		fout<<id;//id입력
//
// 		fout<<score(_character->get_study(),_character->get_relationship(),_character->get_self_develop);//점수 입력
//
//
// 		//등수,아이디,점수가 순서대로 들어가게 됨
//
//
//
// 		fout.close();
// 	}
//
// }
//
// void GameCenter::savefile(){
//
// 	float study=_character->get_study();
// 	float self_develop=_character->get_self_develop();
// 	float relationship=_character->get_relationship();
// 	float energy=_character->get_energy();
// 	float love=_character->get_love();
// 	sexuality sex=_character->get_sex();
//
// 	ofstream fout;
// 	fout.open("savefile.txt", ios::trunc);
// 	fout<<sex<<endl;
// 	fout<<study<<endl;
// 	fout<<self_develop<<endl;
// 	fout<<relationship<<endl;
// 	fout<<energy<<endl;
// 	fout<<love<<endl;
// 	fout<<
//
// 	//여기서 칭호 리턴
// 	bool title=_character->get_title(0);
// 	//첫번째 칭호
// 	fout<<int(title)<<endl;
//
// 	bool title=_character->get_title(1);
// 	//두번째 칭호
// 	fout<<int(title)<<endl;
//
// 	bool title=_character->get_title(2);
// 	//세번째 칭호
// 	fout<<int(title)<endl;
//
// 	bool title=_character->get_title(3);
// 	//네번째 칭호
// 	fout<<int(title)<endl;
//
// 	bool title=_character->get_title(4);
// 	//다섯번째 칭호
// 	fout<<int(title)<endl;
//
// 	bool title=_character->get_title(5);
// 	//여섯번째 칭호
// 	fout<<int(title)<endl;
//
// 	bool title=_character->get_title(6);
// 	//일곱번째 칭호
// 	fout<<int(title)<endl;
//
// 	fout<<current_postion<<endl;
//
//
//
// 	/*파일 예시
// 	1   --------성별
// 	340 --------공부
// 	234 --------자기계발
// 	342 --------인간관계
// 	29  --------에너지
// 	98  --------연애
// 	1   --------7개 칭호
// 	0
// 	0
// 	1
// 	0
// 	0
// 	0
// 	300 -------current position
// 	이렇게
// 	성별/공부/자기계발/인간관계/에너지/연애/7개 칭호/커런트 포지션가 순서대로 출력되게 만듬
// 	*/
//
//
//
// 	fout.close();
//
// }
//
// int check_num(char* buffer){
// 	//받아온 값이 몇자리의 자연수인지를 파악하여 해당하는 숫자 리턴
// 	if(buffer[0]!=NULL && buffer[1]==NULL && buffer[2]==NULL){
// 		//한자리수
// 		return (int(buffer[0]-48));
// 	}
//
// 	if(buffer[0]!=NULL && buffer[1]!=NULL && buffer[2]==NULL){
// 		//두자리수
// 		return ((int(buffer[0]-48))*10+(int(buffer[1]-48)));
// 	}
//
// 	if(buffer[0]!=NULL && buffer[1]!=NULL && buffer[2]!=NULL){
// 		//세자리수
// 		return ((int(buffer[0]-48))*100+(int(buffer[1]-48))*10+(int(buffer[2]-48)));
// 	}
// }
//
//
// void GameCenter::loadgame(){
//
//
// 	/*파일 예시
// 	1   --------성별
// 	340 --------공부
// 	234 --------자기계발
// 	342 --------인간관계
// 	29  --------에너지
// 	98  --------연애
// 	1   --------7개 칭호
// 	0
// 	0
// 	1
// 	0
// 	0
// 	0
// 	300 -------current position
// 	이렇게
// 	성별/공부/자기계발/인간관계/에너지/연애/7개 칭호/커런트 포지션이 있으니
// 	이걸 순서대로 가져와서 저장하는 방식
// 	*/
//
//
// 	ifstream fin;
// 	fin.open("savefile.txt");
// 	if(fin.is_open()){
//
// 	char buffer[100];//파일에서 값을 읽어와 저장할 변수
// 	for(int i=0; i<100; i++)
// 		buffer[i]=NULL;//NULL로 초기화
//
//
// 	int count=0;
//
//
// 	while(fin.getline(buffer,100)){
// 		//파일에서 한 줄씩 받아온다.
//
// 		if(count==0){
// 			//가장 처음 들어 있는 정보인 성별을 받아 올 때이다.
// 			sexuality sex=int(buffer[0]-48);
// 			count++;
// 		}
// 		else if(count==1){
// 			//두번 째 정보인 study
// 			float study=check_num(buffer);
// 			count++;
// 		}
//
// 		else if(count==2){
// 			//세번 째 정보인 self develop
// 			float self_develop=check_num(buffer);
// 			count++;
// 		}
//
// 		else if(count==3){
// 			//네번 째 정보인 relationship
// 			float relationship=check_num(buffer);
// 			count++;
// 		}
// 		else if(count==4){
// 			//다섯번 째 정보인 energy
// 			float energy=check_num(buffer);
// 			count++;
// 		}
// 		else if(count==5){
// 			//여섯번 째 정보인 love
// 			float love=check_num(buffer);
// 			count++;
// 			//이제 기본적으로 필요한 정보가 입력이 완료됨
//
// 			_character->new hero(love, energy, relationship, self_develop, study, sex);
//
// 		}
//
//
// 		//여기까지 정보가 입력됨
//
// 		else if(count==6){
// 			//일곱번 째 정보인 첫번째 칭호
// 			_character->set_title(0,bool(buffer[0]-48));
// 			count++;
// 		}
//
// 		else if(count==7){
// 			//여덟번 째 정보인 두번째 칭호
// 			_character->set_title(1,bool(buffer[0]-48));
// 			count++;
// 		}
//
// 		else if(count==8){
// 			//아홉번 째 정보인 세번째 칭호
// 			_character->set_title(2,bool(buffer[0]-48));
// 			count++;
// 		}
//
// 		else if(count==9){
// 			//열번 째 정보인 네번째 칭호
// 			_character->set_title(3,bool(buffer[0]-48));
// 			count++;
// 		}
//
// 		else if(count==10){
// 			//열한번 째 정보인 다섯번째 칭호
// 			_character->set_title(4,bool(buffer[0]-48));
// 			count++;
// 		}
//
// 		else if(count==11){
// 			//열두번 째 정보인 여섯째 칭호
// 			_character->set_title(5,bool(buffer[0]-48));
// 			count++;
// 		}
//
// 		else if(count==12){
// 			//열세번 째 정보인 일곱번째 칭호
// 			_character->set_title(6,bool(buffer[0]-48));
// 			count++;
// 		}
//
// 		else if(count==13){
// 			//열네번째 정보인 위치
//
// 			current_postion=int(buffer[0]-48);
// 		}
//
//
//
// 	for(int i=0; i<100; i++)
// 		buffer[i]=NULL;//버퍼 초기화
// 	}
// 		fin.close();
// 	}
// 	else
// 		cout<<"error"<<endl;
// }









GameCenter::GameCenter(sexuality sex) {
  if (sex == sexuality::man)
    this->_character = new hero({ .energy = 100, .study = 100, .relationship = 100, .self_develop = 100, .love = 100, .stress = 100 }, sex);
  else if (sex == sexuality::woman) // woman
    this->_character = new hero({ .energy = 80, .study = 100, .relationship = 80, .self_develop = 100, .love = 100, .stress = 100 }, sex);
}

int GameCenter::move(int step){
  if(this->_map.check_birth(this->_current_position, step)) {
    _character->change_energy(8, 1);
    _character->change_stress(-5, 1);
  }

  int stop = this->_map.check_stop(this->_current_position, step);
  this->_current_position = stop;

  return stop;
}

int GameCenter::pass_skips() {
  int next = this->_map.check_skip(this->_current_position);
  this->_current_position = next;

  return next;
}

// int main() {
//   srand(time(NULL));
//   Manager manager;
//   // cout << "study 100 " <<  manager.generate_grade(100) << endl;
//   // cout << "study 0 " <<  manager.generate_grade(0) << endl;
//   // cout << "study 50 1 " <<  manager.generate_grade(50) << endl;
//   // cout << "study 50 2 " <<  manager.generate_grade(50) << endl;
//   cout << manager.score(manager.generate_grade(70), 0.3, 0.4) << endl;
//   cout << manager.score(manager.generate_grade(100), 1.0, 1.0) << endl;
//   cout << manager.score(manager.generate_grade(0), 0.0, 0.0) << endl;
//
//
// }

void GameCenter::record_current_status(){ //매 달 첫 날의 status 저장
  recorded_status=_character->status();
}
//현재의 status - 과거의 status
PersonalStatus GameCenter::get_status_increase() {
  return _character->status().minus(recorded_status);
}
