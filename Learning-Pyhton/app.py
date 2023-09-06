class Car:

    wheels = 4

    def __init__(self, make, model, year, color):
        self.make = make
        self.model = model
        self.year = year
        self.color = color

    def drive(self):
        print(f"The {self.model} is driving")

    def stop(self):
        print(f"The {self.make} has stopped")

car_1 = Car("Toyota","Camry","2021","Blue")


print(car_1.wheels)

car_1.drive()
car_1.stop() 