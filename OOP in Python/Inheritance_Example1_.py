class Employee:
    def __init__(self, name, last) -> None:
        self.name = name
        self.last = last

class Supervisors(Employee):
    def __init__(self, name, last, password) -> None:
        super().__init__(name, last)
        self.password = password

class Chefs(Employee):
    def leave_request(self, days):
        return "May I take a leave for "+ str(days) + " days"

adrian = Employee("Adrian" , "A")
adrian = Supervisors("Adrian", "A", "apple")
emily  = Chefs("Emily", "E")
juno   = Chefs("Juno", "J")

print(emily.leave_request(3))
print(adrian.password)
print(emily.name)
