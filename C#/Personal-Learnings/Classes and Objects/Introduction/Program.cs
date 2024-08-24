using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Introduction
{
    internal class Program
    {
        static void Main(string[] args)
        {
            
            /*
             * 
             * Now we cannot use this because we have a constructor that initializes the values of the object
             * 
            Game game1 = new Game();
            game1.title = "FIFA 2020";
            game1.studio = "EA Sports";
            game1.rating = "A";
            game1.year = 2019;

            Console.WriteLine("Title: " + game1.title);
            Console.WriteLine("Studio: " + game1.studio);
            Console.WriteLine("Rating: " + game1.rating);
            Console.WriteLine("Year: " + game1.year);



            //Now we will use a constructor to initialize the values of the object, much cleaner and efficient
            */

            Game game1= new Game( "FIFA 2020", "EA Sports", 9.5, 2019);

            Console.WriteLine("Title: " + game1.title);
            Console.WriteLine("Studio: " + game1.studio);
            Console.WriteLine("Rating: " + game1.rating);
            Console.WriteLine("Year: " + game1.year);



            //Using the Overriden ToString method
            Game game2 = new Game("Call of Duty", "Activision", 8.5, 2019);
            Console.WriteLine(game2.ToString());
            
            



        }
    }
}
