#include <iostream>

enum FOOD_BEHAVIOR_EN { HERBIVORE, OMNIVORE, CARNIVORE };

class Animal{
  private:
  bool breathes;
  int num_limbs;
  FOOD_BEHAVIOR_EN food_behavior;

  public:

  Animal(int num_limbs, FOOD_BEHAVIOR_EN food_behavior)
  {
    this->breathes = true;
    this->num_limbs = num_limbs;
    this->food_behavior = food_behavior;
  }

  Animal(bool breathes, int num_limbs, FOOD_BEHAVIOR_EN food_behavior)
  {
    this->breathes = breathes;
    this->num_limbs = num_limbs;
    this->food_behavior = food_behavior;
  }
 
  bool is_alive()
  {
    return breathes;
  }

  bool eats_bear_food()
  {
    return food_behavior == OMNIVORE;
  }

  int get_num_limbs()
  {
    return num_limbs;
  }

  bool maybe_human()
  {
    return num_limbs == 4 && food_behavior == OMNIVORE;
  }
  
  virtual std::string talk()
  {
    return "I don't know how I talk";
  }

  //virtual std::string walk() = 0;
};

class Dog : public Animal
{
  private:
  bool has_tail;

  public:
  Dog():Animal(true, 4, OMNIVORE)
  {
    this->has_tail = true;    
  }

  std::string talk()
  {
    return "barks";
  }
  
  std::string describe()
  {
    return "This dog has " + std::to_string(get_num_limbs()) + " legs and " + talk() + " when it sees someone around";
  }
};

int main()
{
  Dog *d = new Dog();
  std::cout << d->describe() << std::endl;
  std::cout << "Dog: " << d->talk() << std::endl;
  std::cout << "Dog maybe human? : " << d->maybe_human() << std::endl;
  std::cout << "Dog eats bear food? : " << d->eats_bear_food() << std::endl;
  delete d;

  Animal *a = new Dog();
  std::cout << "How does a dog referenced by an animal talk? " << a->talk() << std::endl;  
  delete a;

  a = new Animal(true, 4, OMNIVORE);
  std::cout << "How does an animal talk?" << a->talk() << std::endl;
  delete a;
 
  return 0;
}
