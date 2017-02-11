#ifndef USER_H
#define USER_H
#include <iostream>
#include <sstream>



class User {
    friend std::ostream& operator<<(std::ostream &os, const User& user);
 public:
    User(std::string name, int id);
    User(const User &rhs);
    virtual ~User();
    const User & operator=(const User & rhs);
    const int GetId() const;
    void SetId(int id);
    const std::string GetName() const;
    std::string toString();
 private:
    std::string user_name_;
    int user_id_;
};

#endif // USER_H
