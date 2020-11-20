#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Zoo {
  public:
  
    // Factory Method, note it's static
    static Zoo *make_animal(string choice);
  
    // method that we will use polymorphically per product
    virtual void io() = 0;
    
    // Note: need to specify an explicicit default destructor
    virtual ~Zoo() = default;
};

class Canine: public Zoo {
  public:
    void io() {
        cout << "Bark!\n";
    }
};

class Feline: public Zoo {
  public:
    void io() {
        cout << "*Meow*\n";
    }
};

class Reptile: public Zoo {
  public:
    void io() {
        cout << "SsssSSss\n";
    }
};
class Amphibian: public Zoo {
  public:
    void io() {
        cout << "~ribbit~\n";
    }
};
class Avian: public Zoo {
  public:
    void io() {
        cout << "SqwuaAaaakk\n";
    }
};
class Fish: public Zoo {
  public:
    void io() {
        cout << "}{Grgglll}{\n";
    }
};

// this is the FACTORY Method
// it does need to know about the derived methods
// but this allows us to abstract this from our 
// "client" calling code in main()
Zoo *Zoo::make_animal(string choice) {
  if (choice ==  "Canine")
    return new Canine;
  else if (choice == "Feline")
    return new Feline;
  else if (choice == "Reptile")
    return new Reptile;
  else if (choice == "Amphibian")
    return new Amphibian;
  else if (choice == "Avian")
    return new Avian;
  else
    return new Fish;
}


// main() is considered the "client"
// while in this example we could hard code the
// derived classes since we are making a menu anyway
// imagine having 

int main() {
  vector<Zoo*> products;
  string choice;
  while (true) {
    cout << "Enter an animal you'd like to add to your zoo!\nChoices include: Canine, Feline, Reptile, Amphibian, Avian, and Fish.\n Enter 0 if done: ";
    cin >> choice;
    if (choice == "0") break;
    products.push_back(Zoo::make_animal(choice));
  }
  for (int i = 0; i < products.size(); i++) {
    products[i]->io();
  }
  for (int i = 0; i < products.size(); i++) {
    delete products[i];
  }
}