#include <iostream>

class Base{
  private:
    int x;
  public:
    Base(int x)
    { 
      this->x = x;  
    }

    int getx()
    {
      return x;
    }

    virtual void say_hello()
    {
      std::cout << "I don't know how to say hello" << std::endl;
    }
};

class Derived : public Base {
  public:
    Derived(int x): Base(x)
    { 
    }
    void say_hello()
    {
      std::cout << "Hello !" << std::endl;
    }
};

class Another1 {
  private:
    int x;
  public:
    Another1(int x)
    {
      this->x = x;
    }

    int getx()
    {
      return x;
    }

    void say_hello()
    {
      std::cout << "Hello from Another !" << std::endl;
    }
};

class Another2 {
  private:
    int x;
  public:
    Another2(int x)
    {
      this->x = x;
    }

    int getx()
    {
      return x;
    }

    void say_hello()
    {
      std::cout << "Hello from Another !" << std::endl;
    }
};


int main()
{
  Base *b = new Derived(10);
  b->say_hello();

  Derived *d = (Derived *)b; //C style cast
  d->say_hello();

  b = static_cast<Base*>(d);
  d->say_hello();

  d = static_cast<Derived*>(b);
  d->say_hello();

  b = dynamic_cast<Base*>(d);
  b->say_hello();

  d = dynamic_cast<Derived*>(b);
  d->say_hello();

  delete d;
  Another1 *a1 = new Another1(10);
  Another2 *a2 = reinterpret_cast<Another2*>(a1);
  if(a2 != NULL)
  {
    a2->say_hello();
  }else
  {
    std::cout << "A2 is null!" << std::endl;
  }

  delete a2;
}
