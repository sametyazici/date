//
//  date.hpp
//  date
//
//  Created by samet on 25.08.2022.
//

#ifndef date_hpp
#define date_hpp

#ifndef DATE_H
#define DATE_H
#include <iosfwd>
#include <ctime>
#include "iostream"

namespace project {
    class Date {
    public:
        static constexpr int year_base = 1900;  //1
        static constexpr int random_min_year = 1940;  //2
        static constexpr int random_max_year = 2020;  //3
        
        enum class Weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday }; //4
        
        Date():m_d { 1 }, m_m{ 1 }, m_y{ 1900 }{} //5

        Date(int d, int m, int y) :m_d{ d }, m_m{ m }, m_y{ y } {}  //6

        Date(const char *p);  //7

        Date(std::time_t timer); //8

        int get_month_day()const//9
        {
            return m_d;
        }

        int get_month()const //10
        {
            return m_m;
        }

        int get_year()const //11
        {
            return m_y;
        }
        int get_year_day()const //12
        {
            int sum=m_d;
            
            for (int i= 1; i<m_m; ++i)
                 sum += mondays(m_y, i);
            
            return sum;
        }

        Weekday get_week_day()const; //13

        Date &set_month_day(int day) //14
        {
            m_d=day;
            return *this;
        }
        Date &set_month(int month) //15
        {
            m_m=month;
            return *this;
        }
        Date &set_year(int year) //16
        {
            m_y=year;
            return *this;
        }
        
        Date &set(int day, int mon, int year) //17
        {
            m_d = day;
            m_m = mon;
            m_y = year;
            return *this;
        }
        
        Date operator-(int day);const //18
        
        
        Date &operator+=(int totaldays) //19
        {
            int y = year_base;
            totaldays=totalday()+totaldays;
            while (totaldays > (isleap(y) ? 366 : 365)) {
                totaldays -= isleap(y) ? 366 : 365;
                ++y;
            }
            int m = 1;

            while (totaldays > mondays(y, m)) {
                totaldays -= mondays(y, m);
                ++m;
            }

            int d = totaldays;
            m_d=d;
            m_m=m;
            m_y=y;
            return *this;
            
            
        }
        
        Date &operator-=(int day); //20
        Date &operator++(); //21
        Date operator++(int); //22
        Date &operator--(); //23
        Date operator--(int); //24

        friend bool operator<(const Date &, const Date &); //27
        friend bool operator==(const Date &, const Date &); //27
        static Date random_date(); //25
        
        static constexpr bool isleap(int y) //26
        {
            return y % 4 == 0 && (y % 100 || y % 400 == 0);
        }
        

        friend std::ostream &operator<<(std::ostream &os, const Date &date); //31
        friend std::istream &operator>>(std::istream &is, Date &date); //32
    private:
        int m_d, m_m, m_y;
        
        static constexpr int daytabs[][13] = {
            {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
            {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        };
        
        static constexpr int mondays(int y, int m)
        {
            return daytabs[isleap(y)][m];
        }
        int totalday()
        {
            int sum=get_year_day();
            
            for (int i=year_base; i<m_y; i++) {
                sum += isleap(i) ? 366:365;
            }
            return sum;
        }
    };

    bool operator<(const Date &, const Date &); //27
    bool operator<=(const Date &, const Date &); //27
    bool operator>(const Date &, const Date &); //27
    bool operator>=(const Date &, const Date &); //27
    bool operator==(const Date &, const Date &); //27
    bool operator!=(const Date &, const Date &); //27

    int operator-(const Date &d1, const Date &d2); //28
    Date operator+(const Date &date, int n); //29
    Date operator+(int n, const Date &); //29
    Date::Weekday &operator++(Date::Weekday &r); //30
    Date::Weekday operator++(Date::Weekday &r, int); //30
    Date::Weekday &operator--(Date::Weekday &r); //30
    Date::Weekday operator--(Date::Weekday &r, int); //30
}
#endif




#endif /* date_hpp */
