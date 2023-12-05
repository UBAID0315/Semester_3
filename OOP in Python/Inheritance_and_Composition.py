class Name:
    def __init__(self,first,last):
        self.first = first
        self.last = last

class Person:
    def setvalues(self,age,first,last):
        self.name = Name(first,last)
        self.age = age

class Employee(Person):
    def __init__(self,age,first,last,id,designation):
        self.name = Name(first,last)
        self.age = age
        self.id = id
        self.designation = designation


E1 = Employee(20,"bilal","B",1,"Karachi")
E2 = Employee(22,"ubaid","U",2,"Lahore")

print(E1.name.first+" "+E1.name.last)
print(E2.id)
print(E2.designation)
