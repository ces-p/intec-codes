using System;
using static System.Math;

namespace funCounters
{
    class Program
    {
        static void Main(string[] args)
        {               
            Func<int> prim = primes(7);
                Console.WriteLine(prim());
        }

        private static Func<int> natCount(int top){
            int i = 0;
            Func <int> f = () => {
                i = i+1;
                if(i == top +1)
                    i = 1;
                return i;
            };
            return f;
        }

        private static Func<int> fibonacci(int top){
            int x = 0, y = 1, z = 0;
            Func <int> f = () => {
                Console.WriteLine(1+" ");
                for(int i = 0; i<top; i++){
                    z = x+y; 
                    Console.WriteLine(z+" ");
                    x = y;
                    y = z;
                }
                return x+y;
            };
            return f;
        }

        private static Func<int> primes(int num){
            
            Func <int> f = () => {
                var check = true;
                for(int i = 1; i<=num; i++){
                    for(int j = 2; j<i; j++){
                        if(i%j == 0){
                            check = false;
                            j+=i;
                        }  
                    }
                    if(i==1)
                        check = false;
                    if(check)
                        Console.WriteLine(i+ " is prime");
                    else
                        Console.WriteLine(i);
                    check = true;
                }
                return num;
            };
            return f;
        }

    }
}