#include "Cell.h"
void normal::call_option(){
	int option;
<<<<<<< HEAD
	cout<<"1. �����ϱ�"<<endl;
	cout<<"2. �����ñ�"<<endl;
	cout<<"3. ���Ƹ� Ȱ���ϱ�"<<endl;
	cout<<"4. �����ϱ�"<<endl;
	cout<<"5. �޽�"<endl;
	//ĭ�� �´� �ɼ��� ����Ͽ� ����ڷκ��� �ɼ��� �����ϵ��� �Ѵ�.
=======
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<endl;
	//칸에 맞는 옵션을 출력하여 사용자로 부터 옵션을 선택하도록 한다.
>>>>>>> origin/master
	cin>>option;

	switch(option)
	{
	case 1: change_value(); //입력받은 옵션에 따라 캐릭터의 현재 status를 변화시키는 함수 change value를 호출하도록 한다.
		break;

	case 2: change_value();
		break;
	
	case 3: change_value();
		break;

	case 4: change_value();
		break;

	case 5: change_value();
		break;
	}

	return 0;
}

void march::call_option(){
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<endl;
	cout<<"6. 밥사달라고하기"<endl;

	cin>>option;

	switch(option)
	{
	case 1: change_value(); 
		break;

	case 2: change_value();
		break;
	
	case 3: change_value();
		break;

	case 4: change_value();
		break;

	case 5: change_value();
		break;
	case 6: change_value();
		break;
	}

	return 0;
}
void before_exam::call_option(){
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;

	cin>>option;

	switch(option)
	{
	case 1: change_value(); 
		break;

	case 2: change_value();
		break;
	
	
	}
}
void exam::call_option(){
	
}

void after_exam::call_option(){
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 연애하기"<<endl;


	cin>>option;

	switch(option)
	{
	case 1: change_value(); 
		break;

	case 2: change_value();
		break;
	
	case 3: change_value();
		break;

	
	}
}
void festival::call_option(){
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 집에 가기"<<endl;


	cin>>option;

	switch(option)
	{
	case 1: change_value(); 
		break;

	case 2: change_value();
		break;
	
	case 3: change_value();
		break;

	
	}
}

void dance::call_option(){
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 춤 연습하기"<<endl;
	

	cin>>option;

	switch(option)
	{
	case 1: change_value(); 
		break;

	case 2: change_value();
		break;
	
	case 3: change_value();
		break;

	
	}
}

void special::call_option(){
	int option;
	cout<<"1. 참가한다"<<endl;
	cout<<"2. 참가하지 않는다"<<endl;

	cin>>option;

	switch(option)
	{
	case 1: change_value(); 
		break;

	case 2: change_value();
		break;
	
	
	}
}


int MoveCharacter(int current, int number, cell* cell_pointer){//board에서 구현되어야하는 함수로, 주사위의 굴려진 값에따라 이동해야 하는 칸의 위치를 return한다.
	//인자로는 현재 캐릭터의 위치(예를 들어 3일), 주사위를 굴려서 나온 숫자, 그리고 현재 달에 해당하는 cell 배열을 가리키는 cell pointer를 받는다(예를들어 march, november등 월에 해당하는 cell array가 될것)
	for(int i=current; i<=(current+number); i++)
	{	//만약 현재가 3일에 위치해 있는데 주사위를 굴려 5가 나왔다고 가정하자.
		//이때, 7일이 특수칸일 경우 캐릭터는 8일이 아니라 7일에서 멈추어야 하므로,
		//그 사이에 stop정보가 true인 값이 있는지를 파악하여야 한다.
		if(cell_pointer[i].stop_cell()==true)
			return i;
	}
	return current+number;
}

