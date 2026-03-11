#include "Base.hpp"
#include "support.hpp"

Base::~Base(void) {}

Base*   generate(void){
  switch (rand() % 3){
    case 0: return new A();
    case 1: return new B();
    case 2: return new C();
    default: return NULL;
  }
}

void    identify(Base* p){
  if (dynamic_cast<A*>(p)) print("A");
  else if (dynamic_cast<B*>(p)) print("B");
  else print("C");
}

void    identify(Base& p){
  try{
    (void)dynamic_cast<A&>(p);
    print("A");
    return ;
  }
  catch (...){
    try{
      (void)dynamic_cast<B&>(p);
      print("B");
      return ;
    }
    catch (...){
      print("C");
    }
  }
}
