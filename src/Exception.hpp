#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>
#include <sstream>
#include <initializer_list>

class Exception : public std::exception {
    std::string msg;
public:
    Exception(std::initializer_list<std::string>&& strList) {
        std::stringstream s;
        for(auto& str : strList) {
            s << str;
        }
        msg = s.str();
    }
};

#endif  //EXCEPTION_HPP