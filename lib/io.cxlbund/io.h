#include <iostream>
#include <cstring>
#include <vector>
#define start int main(int argc, char* argv[]) {
#define end }
#define exitwith return
#pragma once
void print(std::string s);

template <typename T>
struct num {
  T c;
  num(T w) : c(w) {}
  std::string as_str() {
    return std::to_string(c);
  }
  num operator+(const num& o) {
    return c + o.c;
  }
  num operator-(const num& o) {
    return c - o.c;
  }
  num operator*(const num& o) {
    return c * o.c;
  }
  num operator/(const num& o) {
    return c / o.c;
  }
  void operator+=(const num& o) {
    c += o.c;
  }
  void operator-=(const num& o) {
    c -= o.c;
  }
  void operator*=(const num& o) {
    c *= o.c;
  }
  void operator/=(const num& o) {
    c /= o.c;
  }
  void operator++(int) {
    c++;
  }
  void operator--(int) {
    c--;
  }
  bool operator==(const num& o) {
    if (c == o.c) {
      return true;
    } else {
      return false;
    }
  }
  bool operator!=(const num& o) {
    if (c != o.c) {
      return true;
    } else {
      return false;
    }
  }
  bool operator>(const num& o) {
    if (c > o.c) {
      return true; 
    } else {
      return false;
    }
  }
  bool operator<(const num& o) {
    if (c < o.c) { 
      return true;
    } else {
      return false;
    }
  }
  bool operator>=(const num& o) {
    if (c >= o.c) {
      return true;
    } else {
      return false;
    }
  }
  bool operator<=(const num& o) {
    if (c <= o.c) {
      return true;
    } else {
      return false;
    }
  }
};

template <typename T>
void printi(num<T> i) {
  std::cout << i.c;
}

struct strarr {
  std::vector<std::string> c;
  strarr(std::vector<std::string> w) : c(w) {}
  std::string join(std::string delim) {
    std::string rets;
    for (int i = 0; i < c.size(); i++) {
      rets += c[i];
      rets += delim;
    }
    return rets.erase(rets.size()-1, rets.size());
  }
};

struct str {
  std::vector<std::string> c;
  str(const char* w) {
    c.push_back(w);
  }
  str(std::string w) {  // Not for user -- this is for
    c.push_back(w);     // operator overloading, which
                        // passes elements of the vector as
                        // std::strings.
  }
  int size() {
    return c[0].size();
  }
  friend str operator+(const str& l, const str& r) {
    std::vector<std::string> ret;
    
    ret.push_back("");
    ret.push_back("");
    
    ret[0] = l.c[0].c_str();  
    ret[1] = r.c[0].c_str();
    std::string ret_f = ret[0] + ret[1]; // Take advantage of std::string's concat.
    return str(ret_f);  // This uses the std::string constructor
  }
  void operator+=(const str& o) {
    c[0] += o.c[0];
  }
  bool operator!=(const str& o) {
    if (c[0] != o.c[0]) {
      return true;
    } else {
      return false;
    }
  }
  bool operator==(const str& o) {
    if (c[0] == o.c[0]) {
      return true;
    } else {
      return false;
    }
  }
};

void prints(str s);
str chomp(str what);
str read();
