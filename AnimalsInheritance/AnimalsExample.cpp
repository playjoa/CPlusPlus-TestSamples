#include <iostream>

class Animal
{
    public:
        Animal(const std::string& name, int age, int maxHealth, int damage) : name(name), age(age), maxHealth(maxHealth), damage(damage)
        {
			currentHealth = maxHealth;
            std::cout << "Animal Created: " << name << " \n ";
        }
        
        virtual void Speak() const = 0;
        virtual void GettingAttackedHandler(Animal& attackingAnimal) = 0;
        
		void GetAttacked(Animal& attackingAnimal)
		{
			if (this == &attackingAnimal)
			{
                std::cout << "Cant deal damage to self "<< name << " \n";
				return;
			}
			
			if (IsDead())
			{
                std::cout << "Cant deal damage to "<< name << ". It's already dead \n";
				return;
			}
			
            if (attackingAnimal.IsDead())
			{
                std::cout << "Cant deal damage to "<< name << ". Attacker is Dead: "<< attackingAnimal.GetName() << " \n";
				return;
			}
			
			GettingAttackedHandler(attackingAnimal);
		}
		
		void Revive()
		{
			if (!IsDead()) return;
			
			currentHealth = maxHealth;
		}
    
        const std::string& GetName() const 
        {
            return name;
        }

        // Getter for the age
        int GetAge() const 
        {
            return age;
        }
        
        int GetDamage() const 
        {
            return damage;
        }
        
        bool IsDead() const
        {
            return currentHealth <= 0;
        }
        
    protected:
        std::string name;
        int age;
        int maxHealth;
        int currentHealth;
        int damage;
		
		void DealDamage(Animal& attackingAnimal)
		{            
			int attackingDamage = attackingAnimal.GetDamage();
			currentHealth -= attackingDamage;
			
            std::cout << name << " was just attacked by: " << attackingAnimal.GetName() << " that dealt: "<< attackingAnimal.GetDamage() <<" \n ";
			
			if (IsDead())
			{
				std::cout << name << " Could not SURVIVE attack by: " << attackingAnimal.GetName() <<" \n ";
			}
			else
			{
				std::cout << name << " SURVIVED attack by: " << attackingAnimal.GetName() <<" Remaining Health: " << currentHealth << "\n ";
			}
		}
};

class Dog : public Animal
{
    public:
        Dog(const std::string& name, int age, int maxHealth, int damage) : Animal(name, age, maxHealth, damage) 
        {
            std::cout << "A dog named: "<< name << " Has Been Created \n";
        }
    
        void Speak() const override
        {
            std::cout << "I'm a dog named: "<< name << " and I'm "<< age << " years old! \n";
        }
        
        void GettingAttackedHandler(Animal& attackingAnimal) override
        {
			if (typeid(attackingAnimal) == typeid(Dog))
			{
				std::cout << "A DOG cant attack another DOG "<< attackingAnimal.GetName() << " tryed to attack "<< name << " \n";
				return;
			}
				
			DealDamage(attackingAnimal);
        }
};

class Cat : public Animal
{
    public:
        Cat(const std::string& name, int age, int maxHealth, int damage) : Animal(name, age, maxHealth, damage) 
        {
            std::cout << "A CAT named: " << name << " Has Been Created \n";
        }
        
        void Speak() const override
        {
            std::cout << "I'm a cat named: " << name <<" and I'm " << age << " years old! \n";
        }
		
		void GettingAttackedHandler(Animal& attackingAnimal) override
        {
			if (typeid(attackingAnimal) == typeid(Cat))
			{
				std::cout << "A CAT cant attack another CAT "<< attackingAnimal.GetName() << " tryed to attack "<< name << " \n";
				return;
			}
			
			DealDamage(attackingAnimal);
        }
};

class Bird : public Animal
{
    public:
        Bird(const std::string& name, int age, int maxHealth, int damage) : Animal(name, age, maxHealth, damage) 
        {
            std::cout << "A Bird named: " << name << " Has Been Created \n";
        }
        
        void Speak() const override
        {
            std::cout << "I'm a bird named: " << name <<" and I'm " << age << " years old! \n";
        }
		
		void GettingAttackedHandler(Animal& attackingAnimal) override
        {
			if (typeid(attackingAnimal) == typeid(Cat) || typeid(attackingAnimal) == typeid(Dog))
			{
				std::cout << "A CAT or DOG cant attack a flying bird "<< attackingAnimal.GetName() << " tryed to attack "<< name << " \n";
				return;
			}
			
			DealDamage(attackingAnimal);
        }
};

int main() 
{
    std::cout << "--------------- CREATING ANIMALS ---------------";
    std::cout << "\n";
	
    Dog wickDog("Wick", 6, 100, 35);
    Dog poodleDog("Poodle", 9, 100, 20);
    Cat tutiCat("Tuti", 18, 50, 10);
    Cat garfieldCat("Garfield", 12, 150, 5);
    Bird loroBird("Loro", 13, 75, 13);
    Bird blueBird("Blue", 12, 75, 17);
	
    std::cout << "--------------- DONE CREATING ANIMALS ---------------";
    std::cout << "\n";
    std::cout << "\n";
    
    std::cout << "--------------- ANIMALS WILL SPEAK ---------------";
    std::cout << "\n";
    std::cout << "\n";
    
    wickDog.Speak();
    poodleDog.Speak();
    tutiCat.Speak();
    garfieldCat.Speak();
    loroBird.Speak();
    blueBird.Speak();
	
	std::cout << "\n";
	std::cout << "\n";
	
    std::cout << "--------------- ANIMALS WILL FIGHT ---------------";
    std::cout << "\n";
    std::cout << "\n";
    
	wickDog.GetAttacked(poodleDog);
	wickDog.GetAttacked(tutiCat);
	
	blueBird.GetAttacked(wickDog);
	blueBird.GetAttacked(garfieldCat);
	loroBird.GetAttacked(tutiCat);
	loroBird.GetAttacked(blueBird);
	blueBird.GetAttacked(loroBird);
	
	garfieldCat.GetAttacked(garfieldCat);
	garfieldCat.GetAttacked(blueBird);
	garfieldCat.GetAttacked(loroBird);
	
	tutiCat.GetAttacked(wickDog);
	tutiCat.GetAttacked(garfieldCat);
	tutiCat.GetAttacked(poodleDog);
	tutiCat.GetAttacked(poodleDog);
	tutiCat.GetAttacked(wickDog);

    return 0;
}