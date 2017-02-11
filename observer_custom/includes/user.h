#ifndef USER_H
#define USER_H
#include <iostream>

class User {
 public:
    User(std::string name, int id);
    // User(const User &rhs);
    virtual ~User();
    // const User & operator=(const User & rhs);
    //tostring
    //getid
    const int GetId();
    //setid
    void SetId(int id);
    //getname
    const std::string GetName();
    //ostream
 private:
    std::string user_name_;
    int user_id_;
};

#endif // USER_H
