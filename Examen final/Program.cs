using System;
using static System.Math;
using System.Collections.Generic;

namespace funCounters
{
    class Program
    { 
        public static class List{
            public static LinkedList<int> l = new LinkedList<int>();
        }

        static void add(int x){
            List.l.AddLast(x);
        }

        static bool remove(int x){
            bool result = false;
            var node = List.l.First;
            while(node != null){
                var next = node.Next;
                if(node.Value == x){
                    List.l.Remove(node);
                    result = true;
                    break;
                }
                node = next;
            }
            return result;
        }

        static bool removeAll(int x){
            bool result = false;
            var node = List.l.First;
            while(node != null){
                var next = node.Next;
                if(node.Value == x){
                    List.l.Remove(node);
                    result = true;
                }
                node = next;
            }
            return result;
        }

        static bool contains(int x){
            bool result = false;
            var node = List.l.First;
            while(node != null){
                var next = node.Next;
                if(node.Value == x){
                    result = true;
                    break;
                }
                node = next;
            }
            return result;

        }

        static int length(){
            int x = 0;
            var node = List.l.First;
            while(node != null){
                var next = node.Next;
                x++;
                node = next;
            }
            return x;
        }

        static int[] all(){
            int x = 0;
            int[] y = new int[length()];
            foreach(int i in List.l){
                y[x] = i;
                x++;
            }
             
            return y;
        }

        static bool isEmpty(){
            bool result = false;
            if (List.l.First == null)
                result = true;
            return result;
        }

    

    
        public static class Set{
            public static LinkedList<int> l = new LinkedList<int>();
        }
        

        static bool add1(int x){
            bool result = true;
            var node = Set.l.First;
            while(node != null){
                var next = node.Next;
                if(node.Value == x){
                    result = false;
                    break;
                }
                node = next;
            }
            if(result)
                Set.l.AddLast(x);
                
            return result;
            
        }

        static bool remove1(int x){
            bool result = false;
            var node = Set.l.First;
            while(node != null){
                var next = node.Next;
                if(node.Value == x){
                    Set.l.Remove(node);
                    result = true;
                    break;
                }
                node = next;
            }
            return result;
        }

        static bool removeAll1(int x){
            bool result = false;
            var node = Set.l.First;
            while(node != null){
                var next = node.Next;
                if(node.Value == x){
                    Set.l.Remove(node);
                    result = true;
                }
                node = next;
            }
            return result;
        }

        static bool contains1(int x){
            bool result = false;
            var node = Set.l.First;
            while(node != null){
                var next = node.Next;
                if(node.Value == x){
                    result = true;
                    break;
                }
                node = next;
            }
            return result;

        }

        static int length1(){
            int x = 0;
            var node = Set.l.First;
            while(node != null){
                var next = node.Next;
                x++;
                node = next;
            }
            return x;
        }

        static int[] all1(){
            int x = 0;
            int[] y = new int[length1()];
            foreach(int i in Set.l){
                y[x] = i;
                x++;
            }
             
            return y;
        }

        static bool isEmpty1(){
            bool result = false;
            if (Set.l.First == null)
                result = true;
            return result;
        }

         public static class Stack{
            public static LinkedList<int> l = new LinkedList<int>();
        }
        
        static void push(int x){
            Stack.l.AddFirst(x);
        }

        static void pop(){
            Stack.l.RemoveFirst();
        }

        static int peek(){
            int node = Convert.ToInt32(Stack.l.First.Value);
            return Convert.ToInt32(node);
            
        }
       
        


        static int length2(){
            int x = 0;
            var node = Stack.l.First;
            while(node != null){
                var next = node.Next;
                x++;
                node = next;
            }
            return x;
        }

        static bool isEmpty2(){
            bool result = false;
            if (Stack.l.First == null)
                result = true;
            return result;
        }

        static void Main(string[] args)
        {  
            
            
            push(1);
            push(2);
            push(3);
            push(4);
            
            Console.WriteLine(peek());
            foreach(int i in Stack.l)
                Console.WriteLine(i);  
            Console.WriteLine(length2());
            Console.WriteLine(isEmpty2());
        }

    }

    
       
}
