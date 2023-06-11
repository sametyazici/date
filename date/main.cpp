//
//  main.cpp
//  date
//
//  Created by samet on 25.08.2022.
//

#include <iostream>
#include "date.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    project::Date dt;
    
    dt.set(18,8,1900);


//    std::cout<<dt.get_year_day()<<"\n\n";
//    dt.set_year(2001);
//    dt.set_month(4);
//    dt.set_month_day(1);
//    std::cout<<dt.get_month_day()<<"  ";
//    std::cout<<dt.get_year()<<"  ";
//    std::cout<<dt.get_month()<<"  ";
//    std::cout<<dt.get_year_day()<<"\n";
    
    dt += 2850;
    std::cout<<dt.get_month_day()<<"  ";
    std::cout<<dt.get_month()<<"  ";
    std::cout<<dt.get_year()<<"\n\n";

    //std::cout << "Hello, World!\n";
    return 0;
}
