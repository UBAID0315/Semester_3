class Animal:
    def make_sound(self):
        pass

class Dog(Animal):
    def make_sound(self):
        return "Woof!"

class Cat(Animal):
    def make_sound(self):
        return "Meow!"

class Duck(Animal):
    def make_sound(self):
        return "Quack!"

def animal_sound(animal):
    return animal.make_sound()

dog = Dog()
cat = Cat()
duck = Duck()

print(animal_sound(dog))
print(animal_sound(cat))
print(animal_sound(duck))
