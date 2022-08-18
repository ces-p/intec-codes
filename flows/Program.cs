using System;

namespace flows
{
    class Program
    {
        static void Main(string[] args)
        {
            
        void flow(int one, int two)
        {

            {

                byte t = (byte)(one+two);
                Console.WriteLine(t);
                var j = one+two;
                if (j != t){
                    Console.WriteLine("What it shoule be: " + j);
                    
                    if(j>byte.MaxValue){
                        Console.WriteLine("overflow");
                        checked{
                            t++;
                        }
                    }else{
                      Console.WriteLine("underflow");  
                      Console.WriteLine("What it shoule be: " + j);
                    }
                }

            }

        }
        flow(-200, -200);
        }
        
    }    
}