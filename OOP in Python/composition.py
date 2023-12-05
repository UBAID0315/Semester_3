class Engine:
    def start(self):
        return "Engine Started"
    
class Car:
    def __init__(self):
        self.engine = Engine() #composition: Car has an Engine

    def start(self):
        return f'Car started. {self.engine.start()}'
    
my_car = Car()
print(my_car.start())
