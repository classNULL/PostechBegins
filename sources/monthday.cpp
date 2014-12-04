#include "monthday.hpp"

MonthDay MonthDay::from_calendar(Month month, int day){
	MonthDay monthday;
	monthday._month = month;
	monthday._day = day;

	int month_zero;
	switch(month) {
		case March: month_zero=0;
			break;
		case April: month_zero=31;
			break;
		case May: month_zero=61;
			break;
		case June: month_zero=92;
			break;
		case July: month_zero=122;
			break;
		case August: month_zero=153;
			break;
		case September: month_zero=184;
			break;
		case October: month_zero=214;
			break;
		case November: month_zero=245;
			break;
		case December: month_zero=275;
			break;
	}

	monthday._date_index = month_zero + day - 1;//이 날짜가 정해진다.
	return monthday;
}
MonthDay MonthDay::from_index(int date_index){
	MonthDay monthday;
	monthday._date_index = date_index;

	int month_day_info;
	Month month;
	date_index++; // zero-based to one-based
	if(date_index>=1 && date_index<=31){
		month=March;
		month_day_info=date_index-0;
	}
	else if(date_index>=32 && date_index<=61){
		month=April;
		month_day_info=date_index-31;
	}
	else if(date_index>=62 && date_index<=92){

		month=May;
		month_day_info=date_index-61;
	}
	else if(date_index>=93 && date_index<=122){
		month=June;
		month_day_info=date_index-92;
	}
	else if(date_index>=123 && date_index<=153){
		month=July;
		month_day_info=date_index-122;
	}
	else if(date_index>=154 && date_index<=184){
		month=August;
		month_day_info=date_index-153;
	}
	else if(date_index>=185 && date_index<=214){
		month=September;
		month_day_info=date_index-184;
	}
	else if(date_index>=215 && date_index<=245){
		month=October;
		month_day_info=date_index-214;
	}
	else if(date_index>=246 && date_index<=275){
		month=November;
		month_day_info=date_index-245;
	}
	else if(date_index>=276 && date_index<=306){
		month=December;
		month_day_info=date_index-275;
	}

	monthday._month = month;
	monthday._day = month_day_info;
	return monthday;
}

int MonthDay::containing_days(Month month) {
	switch(month) {
		case March:
			return 31;
		case April:
			return 30;
		case May:
			return 31;
		case June:
			return 30;
		case July:
			return 31;
		case August:
			return 31;
		case September:
			return 30;
		case October:
			return 31;
		case November:
			return 30;
		case December:
			return 31;
	}
}

// int main(){
// 	Cell date_array[306];
// 	//각각을 지정한후
//
//
//
// 	return 0;
// }
