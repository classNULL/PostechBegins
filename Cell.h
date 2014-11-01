#ifndef _CELL_H_
#define _CELL_H_
#include <iostream>
using namespace std;

class saram;
class cell{//�� ĭ�� ������ Abstract class�̴�.
public:
   cell(){ stop = false; }
   virtual void call_option() = 0;//pure virtual method�� derived class���� �����Ѵ�.
   bool stop_cell(){ return stop; }//������ ���ߴ� ĭ�� ��Ÿ���� ��������, ����� �ϴ� ĭ������ �� ���� true�� �����ȴ�.
protected:
   saram* saram;//character�� ����Ű�� ������
   bool stop;
};
class normal :public cell{//������ ĭ�� cell class�� ��ӹ޾� ���������.
public:
   void call_option();//ĳ���Ͱ� ĭ�� �����Ͽ����� �������� ȣ���Ѵ�.
};
class march :public cell{
public:
   void call_option();
};
class before_exam :public cell{
public:
   void call_option();
};
class exam :public cell{
public:
   exam(){ stop = true; }
   void call_option();
};
class after_exam :public cell{
public:
   void call_option();
};
class festival :public cell{
public:
   festival(){ stop = true; }
   void call_option();
};
class dance :public cell{
public:
   void call_option();
};
class special :public cell{
public:
   special(){ stop = true; }
   void call_option();
};
#endif