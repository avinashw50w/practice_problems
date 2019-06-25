/*We know that there are so many calendar systems. For example, Bangla, Christ, Arabic, Chinese etc. This problem is about Decimal calendar. 
There are 3 months in this calendar. First month is "Hundreds". There are 300 days in this month. Second month is "Tens". 
There are 60 days in this month.
 And this followed by the last month "Ones" having 5 or 6 days depending on whether this is leap year or not. A Decimal year spans a 
 full Christ calendar. 
 That is 1st Hundreds in Decimal Calendar is 1st January in Christi Calendar. Similarly, 31st December of Christ Calendar is 5th or 6th day 
 of Decimal calendar(depending on whether it is leap year or not). A year in Decimal calendar is leap year if the corresponding Christ year 
 is leap year. 
  For example, the Decimal year corresponding to 2000 Christ year is leap year but 2001 is not, and again 1900 is not leap year too. 
  A year in Christ calendar is leap year 
   if the year is divisible by 400 or divisible by 4 but not by 100. You are given a day in Christ calendar in DD-MMM-YYYY format 
   (DD stands for day, MMM stands for first three letters (in CAPS) of the month and YYYY stands for the year). You are to give the date in 
   Decimal Calendar format.
Input

First line contains number of test case. Every test case consists of a date in Christ Calendar format in each line.
Output

You are to output the case number and the date in Decimal Calendar format. Output the date and the month in the Decimal Calendar.
Example

Input:
3
01-JAN-1900
10-JAN-1900
16-DEC-1900

Output:
Case 1: 1 Hundreds
Case 2: 10 Hundreds
Case 3: 50 Tens

Note
First three letters for the months are:
JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC.  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12
 
#define Hundreds 1
#define Tens 2
#define Ones 3
 
int isleap( int year )
{
 
	if ( ( year % 400 == 0 ) || ( (year % 4 == 0) && (year % 100 != 0) ) )
	{
		return 1; // leap year 
	}
	else
	{
		return 0; // not  leap year 
	}
}
 
int dayofyear( int day, int month, int year )
{
 
int days=0;
 
if  (month>1) days += 31;
if  (month>2) days += 28 + isleap(year);
if  (month>3) days += 31;
if  (month>4) days += 30;
if  (month>5) days += 31;
if  (month>6) days += 30;
if  (month>7) days += 31;
if  (month>8) days += 31;
if  (month>9) days += 30;
if  (month>10) days += 31;
if  (month>11) days += 30;
 
days += day ;
 
 
return days;
}
 
char * d_date_month ( int days )
 
{
if ( days<= 300) 
	return "Hundreds";
else if (days <= 360 )
	return "Tens";
else
	return "Ones";
 
}
 
 
int d_date_day ( int days )
 
{
 
 
if ( days<= 300) 
	return days;
else if (days <= 360 )
	return days-300;
else
	return days - 360;
 
}
 
 
int getmonth(char * mmm )
{
 
if (strcmp( mmm, "JAN") == 0 ) return JAN;
if (strcmp( mmm, "FEB") == 0 ) return FEB;
if (strcmp( mmm, "MAR") == 0 ) return MAR;
if (strcmp( mmm, "APR") == 0 ) return APR;
if (strcmp( mmm, "MAY") == 0 ) return MAY;
if (strcmp( mmm, "JUN") == 0 ) return JUN;
if (strcmp( mmm, "JUL") == 0 ) return JUL;
if (strcmp( mmm, "AUG") == 0 ) return AUG;
if (strcmp( mmm, "SEP") == 0 ) return SEP;
if (strcmp( mmm, "OCT") == 0 ) return OCT;
if (strcmp( mmm, "NOV") == 0 ) return NOV;
if (strcmp( mmm, "DEC") == 0 ) return DEC;
 
 
}
 
 
int main()
{
 
int i,n,day,  month, year, days ;
char date[12], day_s[3], month_s[4], year_s[5];
 
//printf ("Hello");
scanf ("%d", &n);
 
for ( i=0; i <n ; i++)
{
	scanf ("%s",date);
//	printf ("\ndebug date %s ", date );
	day_s[0]=date[0];
	day_s[1]=date[1];
	day_s[2]='\0';
 
	month_s[0]=date[3];
	month_s[1]=date[4];
	month_s[2]=date[5];
	month_s[3]='\0';
 
 
	year_s[0]=date[7];
	year_s[1]=date[8];
	year_s[2]=date[9];
	year_s[3]=date[10];
	year_s[4]='\0';
 
	day = atoi(day_s);
	year= atoi(year_s);
	month = getmonth ( month_s);
	
//	printf ("\ndebug --- day = %s ---- month = %s --- year = %d",  day_s, month_s, year);
 
	days = dayofyear( day, month, year);
 
	printf("Case %d: %d %s\n", i+1, d_date_day(days), d_date_month(days));
			
	
}
 return 0;
 
}
