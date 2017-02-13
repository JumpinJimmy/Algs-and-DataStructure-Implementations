#ifndef USER_SERVICE_H
#define USER_SERVICE_H
#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

#include "./user.h"

class UserService {
    friend std::ostream& operator<<(std::ostream &os, const UserService& us);
 public:
    explicit UserService(std::string name);
    UserService(const UserService &rhs);
    virtual ~UserService();
    const UserService & operator=(const UserService & rhs);
    const std::string GetName() const;
    // void AddUser(User)

 private:
    std::string service_name_;
    std::unordered_map<std::string, std::unique_ptr<UserService>> service_map_;
    std::unordered_map<int, std::shared_ptr<User>> user_map_;
};

#endif  // USER_SERVICE_H
