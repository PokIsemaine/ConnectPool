//
// Created by zsl on 7/11/22.
//

#ifndef THREADPOOL_PUBLIC_HPP
#define THREADPOOL_PUBLIC_HPP

#include <iostream>
#include <string>


inline void LOG(std::string str)
{
    std::cout << __FILE__ << ":" << __LINE__ << " " <<
         __TIMESTAMP__ << ":" << str << std::endl;
}

#endif //THREADPOOL_PUBLIC_HPP
