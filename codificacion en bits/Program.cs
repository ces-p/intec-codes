using System;
using System.Text;


namespace dataRegister
{
    public class Program
    {
        static void Main(string[] args)
        {
            decode(438);
            encode(27, Convert.ToChar('M'), Convert.ToChar('S'), Convert.ToChar('F'));
        }

        static void decode(Int16 f){
            Console.WriteLine(new String ('=', 80));
            if(findSex(f))
                Console.WriteLine("Sex: M"); 
            else
                Console.WriteLine("Sex: F"); 
            if(findCS(f))
                Console.WriteLine("Civil status: Single"); 
            else
                Console.WriteLine("Civil status: Married"); 
            Console.WriteLine("Academic Degree: " + findAc(f));
            Console.WriteLine("Age: " + findAge(f));
            Console.WriteLine(new String ('=', 80));
        }

        static void encode(byte age, Char Ac, Char Cs, Char s){
            Int16 H = 0;
            H += Convert.ToInt16(codeAge(age)<<4);
            H += Convert.ToInt16(Convert.ToByte(codeAc(Ac))<<2);
            H += Convert.ToInt16(Convert.ToByte(codeCs(Cs))<<1);
            H += Convert.ToByte(codeSex(s));
            Console.WriteLine(H);
            Console.WriteLine(new String ('=', 80));
        }

        static bool findSex(Int16 b){
            Int16 a = 1;
            if((b & a) == 1)
                return true;
            else
                return false;
        }

        static bool codeSex(Char s){
            if(s.Equals(Convert.ToChar('F')))
                return false;
            else
                return true;
        }

        static bool findCS(Int16 b){    
            Int16 a = 1;
            if(((b>>1) & a) == 1)
                return true;
            else
                return false;
        }

        static bool codeCs(Char Cs){
            if(Cs.Equals(Convert.ToChar('M')))
                return false;
            else
                return true;
        }


        static char findAc(Int16 b){
            
            Int16 a = 0B11;
            char i = 'I';
            char m = 'M';
            char g = 'G';
            char p = 'P';
            char c = 'C';
            switch (((b>>2) & a)){
                
                case(0B00):
                    return i;
                    break;
                case(0B01):
                    return m;
                    break;
                case(0B10):
                    return g;
                    break;
                case(0B11):
                    return p;
                    break;
                default:
                    return c;
                    break;
            }
        }

        static byte codeAc(Char Ac){
            byte i = 0B00;
            byte m = 0B01;
            byte g = 0B10;
            byte p = 0B11;
            byte c = 0;
            switch (Ac){
                case('I'):
                    return i;
                    break;
                case('M'):
                    return m;
                    break;
                case('G'):
                    return g;
                    break;
                case('P'):
                    return p;
                    break;
                default:
                    return c;
                    break;
            }
        }

        static byte findAge(Int16 b){    
            Int16 a = 0B1111111;
            byte c = Convert.ToByte((b>>4) & a);
            return c;
        }

        static Int16 codeAge(byte b){    
            return b;
        }

    }
}