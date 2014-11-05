enum Month{March, April, May, June, July, August, September, October,November, December}

int cal_date(Month month, int day){

	int date;

	switch(month){
	case March: date=0;
		break;
	case April: date=31;
		break;
	case May: date=61;
		break;
	case June: date=92;
		break;
	case July: date=122;
		break;
	case August: date=153;
		break;
	case September: date=184;
		break;
	case October: date=214;
		break;
	case November: date=245;
		break;
	case December: date=275;
		break;
	}

	date=date+day;//이 날짜가 정해진다.


	return date;
}
int cal_month_day(int date){
	int month_day_info;
	Month month;
	if(date>=1 && date<=31){
		month=March;
		month_day_info=date-0;
	}
	else if(date>=32 && date<=61){
		month=April;
		month_day_info=date-31;
	}

	else if(date>=62 && date<=92){

		month=May;
		month_day_info=date-61;
	}
	else if(date>=93 && date<=122){
		month=June;
		month_day_info=date-92;
	}
	else if(date>=123 && date<=153){
		month=July;
		month_day_info=date-122;
	}
	else if(date>=154 && date<=184){
		month=August;
		month_day_info=date-153;
	}
	else if(date>=185 && date<=214){
		month=September;
		month_day_info=date-184;
	}
	else if(date>=215 && date<=245){
		month=October;
		month_day_info=date-214;
	}
	else if(date>=246 && date<=275){
		month=November;
		month_day_info=date-245;
	}
	else if(date>=276 && date<=306){
		month=December;
		month_day_info=date-275;
	}

	month_day_info=(month+3)*100;
	//정수형으로 들고 있을 수 있게 한다.
	//month_day_info를 100으로 나눈 몫이 월의 정보, 나머지가 일의 정보가 된다.
	return month_day_info;


}


int main(){
	Cell date_array[306];
	//각각을 지정한후

	

	return 0;
}
