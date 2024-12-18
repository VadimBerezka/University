using System;
using System.Text;

class lab1
{
    static void Main(String[] args)
    {
        A1();
        Console.WriteLine("---------------------------------------------------");
        A2();
        Console.WriteLine("---------------------------------------------------");
        A3();
        Console.WriteLine("---------------------------------------------------");
        A4();
        Console.WriteLine("---------------------------------------------------");
        A5();
        Console.WriteLine("---------------------------------------------------");
        A6();
        Console.WriteLine("---------------------------------------------------");
        B1();
        Console.WriteLine("---------------------------------------------------");
        B2();
        Console.WriteLine("---------------------------------------------------");
        B3();
        Console.WriteLine("---------------------------------------------------");
        B4();
        Console.WriteLine("---------------------------------------------------");
        C1();
        Console.WriteLine("---------------------------------------------------");
        C2();
        Console.WriteLine("---------------------------------------------------");
        C3();
        Console.WriteLine("---------------------------------------------------");
        C4();
        Console.WriteLine("---------------------------------------------------");
        D1();
        Console.WriteLine("---------------------------------------------------");
        D2();
        Console.WriteLine("---------------------------------------------------");
        Zad5();
        Console.WriteLine("---------------------------------------------------");
        Zad6();
        Console.WriteLine("---------------------------------------------------");
        Zad62();
        Console.WriteLine("---------------------------------------------------");
    }

    static void A1()
    {
        bool a = false;
        byte b = 0;
        sbyte c = 22;
        char d = (char)52;
        decimal i = 2.1m;
        double f = 12.3;
        float g = 3_000.5F;
        int h = 1;
        uint e = 234122312;
        nint j = 2;
        nuint v = 80;
        long n = 3333333333;
        ulong q = 9999999999999;
        short w = 31000;
        ushort r = 56000;

        Console.WriteLine(a);
        Console.WriteLine(b);
        Console.WriteLine(c);
        Console.WriteLine(d);
        Console.WriteLine(i);
        Console.WriteLine(f);
        Console.WriteLine(g);
        Console.WriteLine(h);
        Console.WriteLine(e);
        Console.WriteLine(j);
        Console.WriteLine(v);
        Console.WriteLine(n);
        Console.WriteLine(q);
        Console.WriteLine(w);
        Console.WriteLine(r);

    }

    static void A2()
    {
        double a = 2425.3;
        int b = (int)a;
        float g = (float)2.5;
        int c = (int)3.14;
        float f = 10.5F;
        decimal dec = (decimal)f;
        char q = 'A';
        int pre = (int)q;
        int i = 42;
        long l = i;

        Console.WriteLine(b);
        Console.WriteLine(g);
        Console.WriteLine(c);
        Console.WriteLine(dec);
        Console.WriteLine(pre);
        Console.WriteLine(l);

    }

    static void A3()
    {
        int i = 123;
        object a = i;
        Console.WriteLine(a);
        a = 123;
        int s = (int)a;
        Console.WriteLine(s);

    }

    static void A4()
    {
        var a = 5;
        var b = 'C';
        var c = 5.12;

        Console.WriteLine(a.GetType());
        Console.WriteLine(b.GetType());
        Console.WriteLine(c.GetType());

    }

    static void A5()
    {
        int? a = null;
        Console.WriteLine(a);

    }

    static void A6()
    {
        {
            // Ошибка неявного преобразования типа.
            var a = "Hello";
            // a = 123;
            Console.WriteLine(a);
        }
    }

    static void B1()
    {
        var s1 = "stroka1";
        var s2 = "stroka";

if (s1 == s2)
        {
            Console.WriteLine("Строки равны");
        }
        else
        {
            Console.WriteLine("Строки не равны");
        }
    }
    static void B2()
    {
        string s1 = "Aleksei";
        string s2 = "bstuisit";
        string s3 = "2kurs";

        string scepl = string.Concat(s1, s2, s3);
        Console.WriteLine(scepl);

        string copied = string.Copy(s2);
        Console.WriteLine(copied);

        string sub = s2.Substring(0, 4);
        Console.WriteLine(sub);

        string[] words = scepl.Split(" ");
        foreach (string word in words)
        {
            Console.WriteLine(word);
        }
        string insertedStr = s1.Insert(3, "p");
        Console.WriteLine(insertedStr);

        string removedStr = s3.Replace("2kurs", "");
        Console.WriteLine(removedStr);

        int num = 42;
        string inter = $"My age is {num}";
        Console.WriteLine(inter);
    }

    static void B3()
    {
        string empty = "";
        string nullstring = null;

        Console.WriteLine(string.IsNullOrEmpty(empty));
        Console.WriteLine(string.IsNullOrEmpty(null));

        bool sravn = empty == nullstring;
        Console.WriteLine($"Пустая строка == null строка: {sravn}");
    }

    static void B4()
    {
        StringBuilder s1 = new StringBuilder("Aleksei", 50);
        s1.Remove(2, 3);
        Console.WriteLine(s1);
        s1.Insert(0, "Hello ");
        Console.WriteLine(s1);
        s1.Append(" Vadimovich");
        Console.WriteLine(s1);

    }

    static void C1()
    {
        int[,] matrix = new int[3, 3]
        {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };
        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                Console.Write($"{matrix[i, j],3} ");
            }
            Console.WriteLine();
        }

    }

    static void C2()
    {
        string[] names = new string[] { "Vadim", "Sergey", "Prokhor" };
        for (int i = 0; i < names.Length; i++)
        {
            Console.WriteLine($"Элемент {i}: {names[i]}");
        }
        Console.WriteLine(names.Length);
        names[0] = "Alexey";
        for (int i = 0; i < names.Length; i++)
        {
            Console.WriteLine($"Элемент {i}: {names[i]}");
        }
    }

    static void C3()
    {
        double[][] a = new double[3][];
        a[0] = new double[2];
        a[1] = new double[3];
        a[2] = new double[4];


        for (int i = 0; i < a.Length; i++)
        {
            for (int j = 0; j < a[i].Length; j++)
            {
                Console.Write($"Введите элемент [{i}][{j}]: ");
                a[i][j] = Convert.ToDouble(Console.ReadLine());
            }
        }


        Console.WriteLine("\nВывод ступенчатого массива:");
        for (int i = 0; i < a.Length; i++)
        {
            for (int j = 0; j < a[i].Length; j++)
            {
                Console.Write($"{a[i][j]} ");
            }
            Console.WriteLine();
        }
    }

    static void C4()
    {
        var mas = new int[] { 1, 2, 3 };
        var stroka = "Alexey";

        foreach (int number in mas)
        {
            Console.WriteLine(number + "\n");
        }
        Console.WriteLine(stroka);
    }

    static void D1()
    {
        (int, string, char, string, ulong) k1 = (1, "Alexey", (char)52, "Vadim", 2222222222);

        // целиком
        Console.WriteLine($"{k1.Item1} {k1.Item2} {k1.Item3} {k1.Item4} {k1.Item5}");

        //  выборочно 
        Console.WriteLine($"{k1.Item1} {k1.Item3} {k1.Item4}");

        // Распаковка в переменные
        (int id, string firstName, char symbol, string lastName, ulong number) = k1;
        Console.WriteLine("\nОбъявленные переменные:");
        Console.WriteLine($"ID: {id}, FirstName: {firstName}, Symbol: {symbol}, LastName: {lastName}, Number: {number}");

// Игнорирование  при распаковке
        (_, string nameOnly, _, string lastNameOnly, _) = k1;
        Console.WriteLine("\nИгнорирование:");
        Console.WriteLine($"FirstName: {nameOnly}, LastName: {lastNameOnly}");

        //  напрямую
        Console.WriteLine("\nНапрямую:");
        Console.WriteLine($"ID: {k1.Item1}, FirstName: {k1.Item2}, Symbol: {k1.Item3}, LastName: {k1.Item4}, Number: {k1.Item5}");

        // Распаковка  с использованием var
        var (id2, firstName2, symbol2, lastName2, number2) = k1;
        Console.WriteLine("\nvar:");
        Console.WriteLine($"ID: {id2}, FirstName: {firstName2}, Symbol: {symbol2}, LastName: {lastName2}, Number: {number2}");
    }

    static void D2()
    {
        (int, string, char) k1 = (1, "Alexey", 'A');
        (int, string, char) k2 = (1, "Alexey", 'A');

        (int, string, char) k3 = (2, "Vadim", 'B');

        Console.WriteLine($"k1 == k2: {k1 == k2}");
        Console.WriteLine($"k1 == k3: {k1 == k3}");
    }

    static void Zad5()
    {
        int[] numbers = { 5, 2, 9, 1, 7 };
        string inputString = "Hello";

        // Локальная функция
        (int max, int min, int sum, char firstChar) ProcessData(int[] arr, string str)
        {

            int maxValue = int.MinValue;
            int minValue = int.MaxValue;
            int sumValue = 0;

            foreach (var num in arr)
            {
                if (num > maxValue)
                    maxValue = num;
                if (num < minValue)
                    minValue = num;
                sumValue += num;
            }

            return (maxValue, minValue, sumValue, str[0]);
        }

        var result = ProcessData(numbers, inputString);

        Console.WriteLine($"Максимум: {result.max}");
        Console.WriteLine($"Минимум: {result.min}");
        Console.WriteLine($"Сумма: {result.sum}");
        Console.WriteLine($"Первая буква строки: {result.firstChar}");
    }

    static void Zad6()
    {
        // Определение локальной функции с блоком checked
        void Checked()
        {
            try
            {
                checked
                {
                    int maxValue = int.MaxValue;
                    Console.WriteLine("В функции CheckedFunction: Максимальное значение типа int = " + maxValue);
                    int overflowedValue = maxValue + 1;
                }
            }
            catch (OverflowException e)
            {
                Console.WriteLine("Ошибка переполнения в функции CheckedFunction: " + e.Message);
            }
        }

        Checked();
    }

    static void Zad62()
    {
        void Unchecked()
        {
            unchecked
            {
                int maxValue = int.MaxValue;
                Console.WriteLine("В функции UncheckedFunction: Максимальное значение типа int = " + maxValue);
                int overflowedValue = maxValue + 1;
                Console.WriteLine("Результат переполнения в функции UncheckedFunction: " + overflowedValue);
            }
        }

        Unchecked();
    }
}