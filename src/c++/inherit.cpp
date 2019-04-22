#include <iostream>
using namespace std;

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
};


class Human : Animal
{
  private:
  string languages_known[10];
  int num_lang_known;
  string occupation;
  string name;

  public:
  Human(string languages_known[], int num_lang_known, string occupation, string name):Animal(true, 4, OMNIVORE)
  {
    for(int i=0; i<num_lang_known; ++i)
    {
      this->languages_known[i] = languages_known[i]; 
    }
    
    this->num_lang_known = num_lang_known;
    this->occupation = occupation;
    this->name = name;
  }

  string how_smart()
  {
    if(num_lang_known < 2)
    {
      return "dumb";
    }else if(num_lang_known < 4)
    {
      return "average";
    }else if(num_lang_known < 5)
    {
      return "smart";
    }else
    {
      return "genius";
    }
  }

  string get_name()
  {
    return name;
  }
};

int main()
{
  string lang_known[] = {"nepali", "english", "hindi", "bengali", "tamil"};
  Human *h = new Human(lang_known, 5, "engineer", "chintan");
  
  cout << h->get_name() << " is " << h->how_smart() << endl;

  delete h;
  return 0;
}
