
#ifndef Error_h
#define Error_h
#include <string>

class Error{
public:
    std::string message(){
        return "ERROR: Invalid command!";
    }
};

#endif /* Error_h */
