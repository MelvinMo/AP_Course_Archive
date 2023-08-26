#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date() { day = 0; month = 0; year = 0; }
	Date(int d, int m, int y) { day = d; month = m; year = y; }
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	void setDay(int d) { day = d; }
	void setMonth(int m) { month = m; }
	void setYear(int y) { year = y; }
	friend class TimeStamp;
	string ToString(string s1)
	{
		if ((s1.compare("Y/m/d")) == 0)
			cout << year << "/" << month << "/" << day;
		if ((s1.compare("y/m/d")) == 0)
			cout << year - 1300 << "/" << month << "/" << day;
		return "";
	}
	Date operator+(const Date &obj)
	{
		Date new_obj(0, 0, 0);
		new_obj.day = this->day + obj.day;
		new_obj.month = this->month + obj.month;
		new_obj.year = this->year + obj.year;
		if (new_obj.day > 30)
		{
			++new_obj.month;
			new_obj.day -= 30;
		}
		if (new_obj.month > 12)
		{
			++new_obj.year;
			new_obj.month -= 12;
		}
		return new_obj;
	}
	Date operator-(const Date &obj)
	{
		Date new_obj(0, 0, 0);
		int tmpday = this->day;
		int tmpmonth = this->month;
		int tmpyear = this->year;
		if (obj.day > tmpday)
		{
			--tmpmonth;
			tmpday += 30;
		}
		if (obj.month > tmpmonth)
		{
			--tmpyear;
			tmpmonth += 12;
		}
		new_obj.day = tmpday - obj.day;
		new_obj.month = tmpmonth - obj.month;
		new_obj.year = tmpyear - obj.year;
		return new_obj;
	}
	bool operator==(const Date& obj)
	{
		int tmpday = this->day;
		int tmpmonth = this->month;
		int tmpyear = this->year;
		if (tmpday == obj.day && tmpmonth == obj.month && tmpyear == obj.year)
			return true;
		else
			return false;
	}
	bool operator>=(const Date& obj)
	{
		int tmpday = this->day;
		int tmpmonth = this->month;
		int tmpyear = this->year;
		if (tmpday > obj.day || tmpmonth > obj.month || tmpyear > obj.year)
			return true;
		else
			return false;
	}
	bool operator<(const Date& obj)
	{
		int tmpday = this->day;
		int tmpmonth = this->month;
		int tmpyear = this->year;
		if (tmpday >= obj.day || tmpmonth >= obj.month || tmpyear >= obj.year)
			return true;
		else
			return false;
	}
};

class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time() { hour = 0; minute = 0; second = 0; }
	Time(int h, int m, int s) { hour = h; minute = m; second = s; }
	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }
	void setHour(int h) { hour = h; }
	void setMinute(int m) { minute = m; }
	void setSecond(int s) { second = s; }
	friend class TimeStamp;
	string ToString(string s1)
	{
		if ((s1.compare("h:i:s a")) == 0)
			if (hour >= 12)
				cout << hour - 12 << ":" << minute << ":" << second << " " << "p.m.";
			else if (hour <= 12)
				cout << hour << ":" << minute << ":" << second << " " << "a.m.";
		if ((s1.compare("h:i a")) == 0)
			if (hour >= 12)
				cout << hour - 12 << ":" << minute << " " << "p.m.";
			else if (hour <= 12)
				cout << hour << ":" << minute << " " << "a.m.";
		if ((s1.compare("h:i")) == 0)
			if (hour >= 12)
				cout << hour - 12 << ":" << minute;
			else if (hour <= 12)
				cout << hour << ":" << minute;
		if ((s1.compare("H:i:s")) == 0)
			cout << hour << ":" << minute << ":" << second;
		if ((s1.compare("H:i")) == 0)
			cout << hour << ":" << minute;
		return "";
	}
	Time operator+(const Time &obj)
	{
		Time new_obj(0, 0, 0);
		new_obj.hour = this->hour + obj.hour;
		new_obj.minute = this->minute + obj.minute;
		new_obj.second = this->second + obj.second;
		if (new_obj.second >= 60)
		{
			++new_obj.minute;
			new_obj.second -= 60;
		}
		if (new_obj.minute >= 60)
		{
			++new_obj.hour;
			new_obj.minute -= 60;
		}
		if (new_obj.hour >= 24)
		{
			new_obj.hour = new_obj.hour - 24;
		}
		return new_obj;
	}
	Time operator-(const Time &obj)
	{
		Time new_obj(0, 0, 0);
		int tmpsecond = this->second;
		int tmpminute = this->minute;
		int tmphour = this->hour;
		if (obj.second > tmpsecond)
		{
			--tmpminute;
			tmpsecond += 60;
		}
		if (obj.minute > tmpminute)
		{
			--tmphour;
			tmpminute += 60;
		}
		new_obj.hour = tmphour - obj.hour;
		new_obj.minute = tmpminute - obj.minute;
		new_obj.second = tmpsecond - obj.second;
		return new_obj;
	}
	bool operator==(const Time& obj)
	{
		int tmpsecond = this->second;
		int tmpminute = this->minute;
		int tmphour = this->hour;
		if (tmpsecond == obj.second && tmpminute == obj.minute && tmphour == obj.hour)
			return true;
		else
			return false;
	}
	bool operator>=(const Time& obj)
	{
		int tmpsecond = this->second;
		int tmpminute = this->minute;
		int tmphour = this->hour;
		if (tmpsecond > obj.second || tmpminute > obj.minute || tmphour > obj.hour)
			return true;
		else
			return false;
	}
	bool operator<(const Time& obj)
	{
		int tmpsecond = this->second;
		int tmpminute = this->minute;
		int tmphour = this->hour;
		if (tmpsecond >= obj.second || tmpminute >= obj.minute || tmphour >= obj.hour)
			return true;
		else
			return false;
	}
};

class TimeStamp :private Time,private Date
{
private:
	Date d;
	Time t;
public:
	TimeStamp() { d.day = 0; d.month = 0; d.year = 0; t.second = 0; t.minute = 0; t.hour = 0; }
	TimeStamp(Date obj1, Time obj2) { d = obj1; t = obj2; }
	string ToString(string s1)
	{
		int tmpday = d.day;
		int tmpmonth = d.month;
		int tmpyear = d.year;
		int tmpsecond = t.second;
		int tmpminute = t.minute;
		int tmphour = t.hour;
		if ((s1.compare("h:i:s a")) == 0)
			if (tmphour >= 12)
				cout << tmphour - 12 << ":" << tmpminute << ":" << tmpsecond << " " << "p.m.";
			else if (tmphour <= 12)
				cout << tmphour << ":" << tmpminute << ":" << tmpsecond << " " << "a.m.";
		if ((s1.compare("h:i a")) == 0)
			if (tmphour >= 12)
				cout << tmphour - 12 << ":" << tmpminute << " " << "p.m.";
			else if (tmphour <= 12)
				cout << tmphour << ":" << tmpminute << " " << "a.m.";
		if ((s1.compare("h:i")) == 0)
			if (tmphour >= 12)
				cout << tmphour - 12 << ":" << tmpminute;
			else if (tmphour <= 12)
				cout << tmphour << ":" << tmpminute;
		if ((s1.compare("H:i:s")) == 0)
			cout << tmphour << ":" << tmpminute << ":" << tmpsecond;
		if ((s1.compare("H:i")) == 0)
			cout << tmphour << ":" << tmpminute;
		if ((s1.compare("Y/m/d")) == 0)
			cout << tmpyear << "/" << tmpmonth << "/" << tmpday;
		if ((s1.compare("y/m/d")) == 0)
			cout << tmpyear - 1300 << "/" << tmpmonth << "/" << tmpday;
		if ((s1.compare("y/m/d H:i")) == 0)
			cout << tmpyear - 1300 << "/" << tmpmonth << "/" << tmpday << " " << tmphour << ":" << tmpminute;
		if ((s1.compare("Y/m/d H:i")) == 0)
			cout << tmpyear << "/" << tmpmonth << "/" << tmpday << " " << tmphour << ":" << tmpminute;
		if ((s1.compare("Y/m/d H:i:s")) == 0)
			cout << tmpyear << "/" << tmpmonth << "/" << tmpday << " " << tmphour << ":" << tmpminute << ":" << tmpsecond;
		return "";
	}
	TimeStamp operator+(const TimeStamp &obj)
	{
		TimeStamp new_obj;
		int tmpsecond = this->t.second;
		int tmpminute = this->t.minute;
		int tmphour = this->t.hour;
		int tmpday = this->d.day;
		int tmpmonth = this->d.month;
		int tmpyear = this->d.year;
		new_obj.hour = tmphour + obj.t.hour;
		new_obj.minute = tmpminute + obj.t.minute;
		new_obj.second = tmpsecond + obj.t.second;
		new_obj.day = tmpday + obj.d.day;
		new_obj.month = tmpmonth + obj.d.month;
		new_obj.year = tmpyear + obj.d.year;
		while (new_obj.day > 30 || new_obj.month > 12 || new_obj.second >= 60 || new_obj.minute >= 60 || new_obj.hour >= 24)
		{
			if (new_obj.day > 30)
			{
				++new_obj.month;
				new_obj.day -= 30;
			}
			if (new_obj.month > 12)
			{
				++new_obj.year;
				new_obj.month -= 12;
			}
			if (new_obj.second >= 60)
			{
				++new_obj.minute;
				new_obj.second -= 60;
			}
			if (new_obj.minute >= 60)
			{
				++new_obj.hour;
				new_obj.minute -= 60;
			}
			if (new_obj.hour >= 24)
			{
				++new_obj.day;
				new_obj.hour -= 24;
			}
		}
		cout << new_obj.year << "/" << new_obj.month << "/" << new_obj.day << " " << new_obj.hour << ":" << new_obj.minute << ":" << new_obj.second;
		return new_obj;
	}
	TimeStamp operator-(const TimeStamp &obj)
	{
		TimeStamp new_obj;
		int tmpsecond = this->t.second;
		int tmpminute = this->t.minute;
		int tmphour = this->t.hour;
		int tmpday = this->d.day;
		int tmpmonth = this->d.month;
		int tmpyear = this->d.year;
		if (obj.t.second > tmpsecond)
		{
			--tmpminute;
			tmpsecond += 60;
		}
		if (obj.t.minute > tmpminute)
		{
			--tmphour;
			tmpminute += 60;
		}
		if (obj.d.day > tmpday)
		{
			--tmpmonth;
			tmpday += 30;
		}
		if (obj.d.month > tmpmonth)
		{
			--tmpyear;
			tmpmonth += 12;
		}
		new_obj.day = tmpday - obj.d.day;
		new_obj.month = tmpmonth - obj.d.month;
		new_obj.year = tmpyear - obj.d.year;
		new_obj.hour = tmphour - obj.t.hour;
		new_obj.minute = tmpminute - obj.t.minute;
		new_obj.second = tmpsecond - obj.t.second;
		cout << new_obj.year << "/" << new_obj.month << "/" << new_obj.day << " " << new_obj.hour << ":" << new_obj.minute << ":" << new_obj.second;
		return new_obj;
	}
	bool operator==(const TimeStamp& obj)
	{
		int tmpday = obj.d.day;
		int tmpmonth = obj.d.month;
		int tmpyear = obj.d.year;
		int tmpsecond = obj.t.second;
		int tmpminute = obj.t.minute;
		int tmphour = obj.t.hour;
		if (d.day == tmpday && d.month == tmpmonth && d.year == tmpyear && t.second == tmpsecond && t.minute == tmpminute && t.hour == tmphour)
			return true;
		else
			return false;
	}
	bool operator>=(const TimeStamp& obj)
	{
		int tmpday = obj.d.day;
		int tmpmonth = obj.d.month;
		int tmpyear = obj.d.year;
		int tmpsecond = obj.t.second;
		int tmpminute = obj.t.minute;
		int tmphour = obj.t.hour;
		if (d.day > tmpday || d.month > tmpmonth || d.year > tmpyear || t.second > tmpsecond || t.minute > tmpminute || t.hour > tmphour)
			return true;
		else
			return false;
	}
	bool operator<(const TimeStamp& obj)
	{
		int tmpday = obj.d.day;
		int tmpmonth = obj.d.month;
		int tmpyear = obj.d.year;
		int tmpsecond = obj.t.second;
		int tmpminute = obj.t.minute;
		int tmphour = obj.t.hour;
		if (d.day >= tmpday || d.month >= tmpmonth || d.year >= tmpyear || t.second >= tmpsecond || t.minute >= tmpminute || t.hour >= tmphour)
			return true;
		else
			return false;
	}
};

int main()
{
	Date d(13, 1, 1399);
	Time t(17, 10, 19);
	cout << (d + Date(2, 1, 0)).ToString("y/m/d") << endl;
	cout << (t - Time(1, 10, 20)).ToString("h:i a") << endl;
	TimeStamp ts(d, t);
	cout << ts.ToString("Y/m/d H:i:s") << endl;
	cout << (ts >= TimeStamp(Date(13, 1, 1399), Time(17, 11, 20))) << endl;
	return 0;
}