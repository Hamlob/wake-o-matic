#include"logging.hpp"

class eventListenerHandler{
//write code that does something
}

class eventChannel{
private:
    using idType id = unsigned int;
    static const idType& genNextId(){
        static idType id = 0;
        return id++;
    }

public:
    static eventListenerHandler regListener
    //write better code :D
}