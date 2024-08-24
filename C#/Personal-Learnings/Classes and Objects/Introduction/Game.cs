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
    internal class Game
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

    }
}
