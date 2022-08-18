using System;


namespace dataRegister
{
    public class Program
    {
        static void Main(string[] args)
        {
           Console.WriteLine(mcd(100,20)); 
           Console.WriteLine(mcdI(100,20));
            
        }

        public static int Sum(int n, int x) { // tail
            if (n == 1)
                return x;
            else{
                x+=n;
                return Sum(n-1,x);
            }
        }

        public static int factorial(int n, int m){//tail
            if(n == 0)
                return m;
            else 
                return factorial(n-1, m*n);
        }

        public static int mcd(int n, int m){//tail
            if(n == 0)
                return m;
            if(m==0)
                return n;
            else    
                return mcd(m, n%m); 
        }

        public static int SumI(int n) { // iteration
            int x = 0;
            for(int i = 1; i<=n; i++)
                x +=i;
            return x;
        }

        public static int factorialI(int n){//iteration
            int x = 1;
            for(int i = 1; i<=n; i++)
                x = x*i;
            return x;
        }

        public static int mcdI(int n, int m){//iteration
            int [] array = new int[Convert.ToInt32((n+m)/2+1)];
            int c = 0;
            for(int i = 1; i<array.Length; i++){
                if(n%i == 0 && m%i == 0){
                    array[c]=i;
                    c++;
                }
            }
            int gcd = 0;
            for(int i = 0; i<c; i++){
                if(array[i]>gcd)
                    gcd = array[i];
            }
            return gcd;
        }

    }
}