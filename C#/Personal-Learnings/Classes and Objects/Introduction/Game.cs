using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Security.Principal;
using System.Text;
using System.Threading.Tasks;

//Namespace is a way to organize your code, it is a collection of classes
namespace Introduction
{


    //internal means that the class can only be accessed within the same assembly
    //Class 1 that implements the IGame interface
    //This class has a constructor that initializes the values of the object
    internal class Game: IGame
    {
        //public keywords means that the variable can be accessed from outside the class
        public string title = "Hello World";
        public string studio;
        public double rating;
        public int year;
  
        public Game(string argtitle, string argstudio, double argrating, int argyear)
        {
            title = argtitle;
            studio = argstudio;
            rating = argrating;
            year = argyear;

        }

        public static Game operator +(Game a, Game b) {
                        return new Game(a.title + b.title, a.studio + b.studio, (a.rating + b.rating) / 2, (a.year + b.year) / 2);
        }


        //ToString already exists in the Object class, so we are overriding it
        //This is a method that is called when we want to convert the object to a string
        public override string ToString()
        {
            return "Title: " + title + "\nStudio: " + studio + "\nRating: " + rating + "\nYear: " + year;
        }


        public bool Start(String Data)
        {

            if (Data == "True"){
                return true;
            }
            else
            {
                return false;
            }
            
        }


    }


    //Class 2 that implements the IGame interface
    //This class has a method that calculates the sum of two numbers
    internal class Calculator: IGame
    {

        int calculate(int x, int y)
        {
            return x + y; // Example implementation
        }

        //For the Interface IGame
        public bool Start(string Data)
        {
            return Start(Data, 12, 12);
        }

        //Overloaded method, this method is called when we want to pass the optional parameters
        public bool Start(string Data, int optional_num1 = 0, int optional_num2 = 0)
        {
            if (Data == "True")
            {
                int result = calculate(optional_num1, optional_num2);
                Console.WriteLine($"Calculator Result: {result}");
                return true;
            }
            else
            {
                Console.WriteLine("FAILED EXECUTION");
                return false;
            }

        }
    }


    //Interface that has a method Start
    //Is used to by multiple classes to implement the Start method
    interface IGame
    {
        bool Start(string Data);
    }

}
