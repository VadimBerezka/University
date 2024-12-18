using System;
using Lec03LibN;    // библиотека
using PP03;         // сборка приложения
class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Лабораторная работа # 3");

        IFactory l1 = Lec03LibN.Lec03LibN.getL1();      // фабрика 1

        Employee employee1 = new Employee(l1.GetA(25));    // 1-a
        Console.WriteLine(string.Format("Bonus-L1-A = {0}", employee1.calcBonus(4)));

        Employee employee2 = new Employee(l1.GetB(25, 1.1f));    // 1-b
        Console.WriteLine(string.Format("Bonus-L1-B = {0}", employee2.calcBonus(4)));

        Employee employee3 = new Employee(l1.GetC(25, 1.1f, 5.0f));    // 1-c
        Console.WriteLine(string.Format("Bonus-L1-C = {0}", employee3.calcBonus(4)));

        IFactory l2 = Lec03LibN.Lec03LibN.getL2(1);    // фабрика 2

        Employee employee4 = new Employee(l2.GetA(25));    // 2-a
        Console.WriteLine(string.Format("Bonus-L2-A = {0}", employee4.calcBonus(4)));

        Employee employee5 = new Employee(l2.GetB(25, 1.1f));    // 2-b
        Console.WriteLine(string.Format("Bonus-L2-B = {0}", employee5.calcBonus(4)));

        Employee employee6 = new Employee(l2.GetC(25, 1.1f, 5.0f));    // 2-c
        Console.WriteLine(string.Format("Bonus-L2-C = {0}", employee6.calcBonus(4)));

        IFactory l3 = Lec03LibN.Lec03LibN.getL3(1, 0.5f);    // фабрика 3

        Employee employee7 = new Employee(l3.GetA(25));    // 3-a
        Console.WriteLine(string.Format("Bonus-L3-A = {0}", employee7.calcBonus(4)));

        Employee employee8 = new Employee(l3.GetB(25, 1.1f));    // 3-b
        Console.WriteLine(string.Format("Bonus-L3-B = {0}", employee8.calcBonus(4)));

        Employee employee9 = new Employee(l3.GetC(25, 1.1f, 0.5f));    // 3-c
        Console.WriteLine(string.Format("Bonus-L3-C = {0}", employee9.calcBonus(4)));
    }
}
