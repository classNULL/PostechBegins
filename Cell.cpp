#include "Cell.h"
void normal::call_option(){
	int option;
	cout<<"1. �����ϱ�"<<endl;
	cout<<"2. �����ñ�"<<endl;
	cout<<"3. ���Ƹ� Ȱ���ϱ�"<<endl;
	cout<<"4. �����ϱ�"<<endl;
	cout<<"5. �޽�"<endl;
	//ĭ�� �´� �ɼ��� ����Ͽ� ����ڷ� ���� �ɼ��� �����ϵ��� �Ѵ�.
	cin>>option;

	switch(option)
	{
	case 1: change_value(); //�Է¹��� �ɼǿ� ���� ĳ������ ���� status�� ��ȭ��Ű�� �Լ� change value�� ȣ���ϵ��� �Ѵ�.
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
	cout<<"1. �����ϱ�"<<endl;
	cout<<"2. �����ñ�"<<endl;
	cout<<"3. ���Ƹ� Ȱ���ϱ�"<<endl;
	cout<<"4. �����ϱ�"<<endl;
	cout<<"5. �޽�"<endl;
	cout<<"6. ���޶���ϱ�"<endl;

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
	cout<<"1. �����ϱ�"<<endl;
	cout<<"2. �����ñ�"<<endl;

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
	cout<<"1. �����ϱ�"<<endl;
	cout<<"2. �����ñ�"<<endl;
	cout<<"3. �����ϱ�"<<endl;


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
	cout<<"1. �����ϱ�"<<endl;
	cout<<"2. �����ñ�"<<endl;
	cout<<"3. ���� ����"<<endl;


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
	cout<<"1. �����ϱ�"<<endl;
	cout<<"2. �����ñ�"<<endl;
	cout<<"3. �� �����ϱ�"<<endl;
	

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
	cout<<"1. �����Ѵ�"<<endl;
	cout<<"2. �������� �ʴ´�"<<endl;

	cin>>option;

	switch(option)
	{
	case 1: change_value(); 
		break;

	case 2: change_value();
		break;
	
	
	}
}


int MoveCharacter(int current, int number, cell* cell_pointer){//board���� �����Ǿ���ϴ� �Լ���, �ֻ����� ������ �������� �̵��ؾ� �ϴ� ĭ�� ��ġ�� return�Ѵ�.
	//���ڷδ� ���� ĳ������ ��ġ(���� ��� 3��), �ֻ����� ������ ���� ����, �׸��� ���� �޿� �ش��ϴ� cell �迭�� ����Ű�� cell pointer�� �޴´�(������� march, november�� ���� �ش��ϴ� cell array�� �ɰ�)
	for(int i=current; i<=(current+number); i++)
	{	//���� ���簡 3�Ͽ� ��ġ�� �ִµ� �ֻ����� ���� 5�� ���Դٰ� ��������.
		//�̶�, 7���� Ư��ĭ�� ��� ĳ���ʹ� 8���� �ƴ϶� 7�Ͽ��� ���߾�� �ϹǷ�,
		//�� ���̿� stop������ true�� ���� �ִ����� �ľ��Ͽ��� �Ѵ�.
		if(cell_pointer[i].stop_cell()==true)
			return i;
	}
	return current+number;
}

