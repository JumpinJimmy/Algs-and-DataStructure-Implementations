#ifndef USER_SERVICE_H
#define USER_SERVICE_H
#include <iostream>
#include "./user.h"

class UserService {
 public:
    UserService(std::string name);
    // UserService(const UserService &rhs);
    virtual ~UserService();
    // const UserService & operator=(const UserService & rhs);
    //tostring
    //getid
    //setid
    //getname
    //ostream
 private:
    std::string service_name_;
    // int user_id_;
    // users map
    // services map
};

#endif // USER_SERVICE_H
