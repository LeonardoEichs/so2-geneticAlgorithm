/**
    Trabalho Sistemas Operacionais II
    @author Leonardo Vailatti Eichstaedt
    @version 1.1 25/07/17
*/

#ifndef OBJECTIVE_H
#define OBJECTIVE_H

#include <string>

using namespace std;

class Objective {
  public:
    enum Sign{
      MAX,
      MIN
    };

  protected:
    string name;
    Sign sign;

  public:
    Objective(string name) : name(name), sign(MIN){};
    Objective(string name, Sign sign) : name(name), sign(sign){};
    string getName() const {  return name;  };
    Sign getSign() const {  return sign;  };
    bool operator <(const Objective& rhs) const {
        return name < rhs.name;
    }

};

#endif
