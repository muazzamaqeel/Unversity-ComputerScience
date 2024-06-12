class Employee:
    def __init__(self, name, age, salary):
        self.name = name
        self.age = age
        self.salary = salary

    def __str__(self):
        return "Name: " + self.name + " Age: " + str(self.age) + " Salary: " + str(self.salary)


    def display(self):
        print("Name: ", self.name, "\n"+"Age: ", self.age, "\n"+"Salary: ", self.salary)
            

emp1 = Employee("Muazzam", 25, 1300)
Employee.display(emp1)
#print(repr(emp1.display()))


class Manager(Employee):
    def __init__(self, name, department):
        super().__init__(name, age, salary)
        self.department = department
        self.name = name
    
    def DisplayManager(self):
        print("Name: ", self.name, "\n"+"Department: ", self.department)

manager1 = Manager("Muazzam", "IT")