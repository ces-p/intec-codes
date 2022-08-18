using System;
using System.IO;

namespace dataRegister
{
    class Program
    {
        static void Main(string[] args)
        {
            Program p = new Program();
            int x = 1;
            String s = "";
            int f = 0;
            while (x>0){
                s = Console.ReadLine();
                if(String.IsNullOrEmpty(s)){
                    p.register(f);
                    f++;

                }else{
                    x = -1;
                }


            }
        }

        public void register(int f){
            String[] register = {"cedula", "nombres", "apellidos", "edad"};
            String input = "empty";
            Console.WriteLine("Hola! Escriba su numero de cedula, su nombre, su apellido, y su edad en ese orden sin espacios");
            input = Console.ReadLine();
            Console.WriteLine("¿Quieres grabar esta informacion? Y/N");
            String record = Console.ReadLine();
            if (record.Equals("Y")){
                for(int i = 0; i < register.Length; i++){
                    if(input.IndexOf(",")>0){
                        register[i] = input.Substring(0, input.IndexOf(","));
                        input = input.Substring(input.IndexOf(",")+1);
                    }
  
                }
                register[register.Length - 1] = input;
                StreamWriter File = new StreamWriter("register"+f+".txt");
                foreach(var item in register){
                    File.WriteLine(item);
                }
                File.Close();
            }
            
        }
    }    
}
