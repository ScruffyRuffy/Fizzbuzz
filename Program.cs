using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FizzBuzz
{
    class Program
    {
        static void Main(string[] args)
        {
            string triggers = "";
            string triggerNumbers = "";
            string tempNumber="";
            bool triggerEnd = false;
            int numberOfTriggers = 0;
            string trigger;
            bool enteredNumber = false;
            while ((triggerEnd != true) && (numberOfTriggers <= 2))
            {
                if (numberOfTriggers > 0)
                {
                    triggers += ".";
                    triggerNumbers += ".";
                }
                Console.WriteLine("Enter a triggger like Fizz or Buzz");
                trigger = Console.ReadLine();
                triggers += trigger;
                numberOfTriggers += 1;
                Console.WriteLine("{0},What mulitple triggers this?",numberOfTriggers);
                while (enteredNumber != true) {
                    tempNumber = Console.ReadLine();
                    try
                    {
                        Convert.ToInt32(tempNumber);
                        enteredNumber = true;
                    }
                    catch
                    {
                        Console.WriteLine("That is not a number");
                    }
                }
                enteredNumber = false;
                triggerNumbers += tempNumber;
                if (numberOfTriggers >= 2)
                {
                    Console.WriteLine("Do you want to add an other trigger? (enter Y for yes)");
                    if (Console.ReadLine() == "Y")
                    {
                        triggerEnd = false;
                    }
                    else
                    {
                        triggerEnd = true;
                    }
                }
            }
            string[] TriggersToUse = triggers.Split('.');
            string[] multipliers = triggerNumbers.Split('.');
            int[] MultipliersToUse = new int[numberOfTriggers];
            int counter = 0;
            foreach (string num in multipliers)
            {
                if (counter < numberOfTriggers)
                {
                    MultipliersToUse[counter] = Convert.ToInt32(num);
                    counter += 1;
                }
            }
            int checkCounter;
            bool triggered;
            string Max;
            int MaxNumber = 0;
            enteredNumber = false;
            Console.WriteLine("What number do you want it to go to?");
            // try to convert to int if exception retry
            while (enteredNumber != true)
            {
                Max = Console.ReadLine();
                try
                {
                    MaxNumber = Convert.ToInt32(Max);
                    enteredNumber = true;
                }
                catch
                {
                    Console.WriteLine("That is not a number");
                }
            }
            for (int i=1; i<=MaxNumber; i++)
            {
                checkCounter = 0;
                triggered = false;
                foreach (int check in MultipliersToUse)
                {
                    if ((i % check) == 0)
                    {
                        triggered = true;
                        Console.Write(TriggersToUse[checkCounter]);
                        Console.Write(" ");
                    }
                    checkCounter += 1;
                }
                if (!triggered)
                {
                    Console.Write(i);
                }
                Console.Write("\n");
            }
            Console.ReadLine();
        }// end of main
    }
}
