//ex1
using System;

class ex1
{
    static void Main()
    {
        Console.WriteLine("ex1-a");
        float temp1 = 20.0F;
        long temp2 = 1_000_000;
        char temp3 = 'B';
        decimal temp4 = 10.0m;
        ushort temp5 = 25;
        byte temp6 = 100;
        double temp7 = 500.5;
        int temp8 = 2020;
        bool temp9 = false;
        sbyte temp10 = 0;
        uint temp11 = 1000;
        nint temp12 = 1;
        nuint temp13 = 10;
        short temp14 = 100;
        ulong temp15 = 1_000_000_000;

        Console.WriteLine(temp1);
        Console.WriteLine(temp2);
        Console.WriteLine(temp3);
        Console.WriteLine(temp4);
        Console.WriteLine(temp5);
        Console.WriteLine(temp6);
        Console.WriteLine(temp7);
        Console.WriteLine(temp8);
        Console.WriteLine(temp9);
        Console.WriteLine(temp10);
        Console.WriteLine(temp11);
        Console.WriteLine(temp12);
        Console.WriteLine(temp13);
        Console.WriteLine(temp14);
        Console.WriteLine(temp15);


        Console.WriteLine("\nex1-b");
        double num1 = 1500.75;
        int num2 = (int)num1;
        float num3 = (float)5.5;
        int num4 = (int)2.99;
        float num5 = 15.2F;
        decimal num6 = (decimal)num5;
        char num7 = 'Z';
        int num8 = (int)num7;
        int num9 = 25;
        long num10 = num9;

        Console.WriteLine(num2);
        Console.WriteLine(num3);
        Console.WriteLine(num4);
        Console.WriteLine(num6);
        Console.WriteLine(num8);
        Console.WriteLine(num10);

        Console.WriteLine("\nex1-c");
        int value1 = 456;
        object value2 = value1;
        Console.WriteLine(value2);
        value2 = 789;
        int value3 = (int)value2;
        Console.WriteLine(value3);
        Console.WriteLine("\nex1-d");
        var num = 10;
        var letter = 'D';
        var decimalValue = 3.14;

        Console.WriteLine(num.GetType());
        Console.WriteLine(letter.GetType());
        Console.WriteLine(decimalValue.GetType());
        Console.WriteLine("\nex1-e");
        int? a = null;
        Console.WriteLine(a);
        Console.WriteLine("\nex1-f");
        // Ошибка неявного преобразования типа.
        var b = "Hello";
        // b = 123;
        Console.WriteLine(b);

    }
}

//ex2
/*using System;
using System.Text;
class ex2
{

    static void Main()
    {
        Console.WriteLine("ex2-a");
        var str1 = "hello";
        var str2 = "world";

        if (str1 == str2)
        {
            Console.WriteLine("Строки равны");
        }
        else
        {
            Console.WriteLine("Строки не равны");
        }

        Console.WriteLine("\nex2-b");
        string firstName = "Vadim";
        string secondPart = "in obshaga";
        string year = "2ndYear";

        string combined = string.Concat(firstName, secondPart, year);
        Console.WriteLine(combined);

        string copiedString = string.Copy(secondPart);
        Console.WriteLine(copiedString);

        string substring = secondPart.Substring(0, 2);
        Console.WriteLine(substring);

        string[] splitWords = combined.Split(" ");
        foreach (string word in splitWords)
        {
            Console.WriteLine(word);
        }

        string insertedString = firstName.Insert(2, "y");
        Console.WriteLine(insertedString);

        string removedString = year.Replace("2ndYear", "");
        Console.WriteLine(removedString);

        int age = 18;
        string interpolated = $"My age is {age}";
        Console.WriteLine(interpolated);

        Console.WriteLine("\nex2-c");
        string strEmpty = "";
        string strNull = null;

        Console.WriteLine(string.IsNullOrEmpty(strEmpty));
        Console.WriteLine(string.IsNullOrEmpty(strNull));

        bool comparison = strEmpty == strNull;
        Console.WriteLine($"Пустая строка == null строка: {comparison}");

        Console.WriteLine("\nex2-d");
        StringBuilder sb = new StringBuilder("Vadim", 50);
        sb.Remove(1, 2);
        Console.WriteLine(sb);
        sb.Insert(0, "Hi ");
        Console.WriteLine(sb);
        sb.Append(" Sergeevich");
        Console.WriteLine(sb);

    }
}*/

//ex3
/*using System;
using System.Text;
class ex3
{

    static void Main()
    {
        Console.WriteLine("ex3-a");
        int[,] grid = new int[3, 3]
        {
            { 9, 8, 7 },
            { 6, 5, 4 },
            { 3, 2, 1 }
        };

        for (int row = 0; row < grid.GetLength(0); row++)
        {
            for (int col = 0; col < grid.GetLength(1); col++)
            {
                Console.Write($"{grid[row, col],3} ");
            }
            Console.WriteLine();
        }

        Console.WriteLine("\nex3-b");
        string[] people = new string[] { "Vadim", "Sergey", "Vlad" };
        for (int i = 0; i < people.Length; i++)
        {
            Console.WriteLine($"Элемент {i}: {people[i]}");
        }
        Console.WriteLine(people.Length);
        people[0] = "Semen";
        for (int i = 0; i < people.Length; i++)
        {
            Console.WriteLine($"Элемент {i}: {people[i]}");
        }

        Console.WriteLine("\nex3-c");
        double[][] myArray = new double[3][];
        myArray[0] = new double[2];
        myArray[1] = new double[3];
        myArray[2] = new double[4];

        for (int row = 0; row < myArray.Length; row++)
        {
            for (int col = 0; col < myArray[row].Length; col++)
            {
                Console.Write($"Введите элемент [{row}][{col}]: ");
                myArray[row][col] = Convert.ToDouble(Console.ReadLine());
            }
        }

        Console.WriteLine("\nВывод ступенчатого массива:");
        for (int row = 0; row < myArray.Length; row++)
        {
            for (int col = 0; col < myArray[row].Length; col++)
            {
                Console.Write($"{myArray[row][col]} ");
            }
            Console.WriteLine();
        }

        Console.WriteLine("\nex3-d");
        var numbersArray = new int[] { 4, 5, 6 };
        var name = "Vadim";

        foreach (int num in numbersArray)
        {
            Console.WriteLine(num + "\n");
        }
        Console.WriteLine(name);
    }
}*/

//ex4
/*using System;
using System.Text;
class ex4
{

    static void Main()
    {
        Console.WriteLine("ex4-a");
        (int id, string firstName, char symbol, string lastName, ulong phoneNumber) person = (1, "Vadim", (char)65, "Sergey", 1234567890);

        Console.WriteLine($"{person.id} {person.firstName} {person.symbol} {person.lastName} {person.phoneNumber}");
        Console.WriteLine($"{person.id} {person.symbol} {person.lastName}");

        (int personId, string name, char charSymbol, string surname, ulong number) = person;
        Console.WriteLine("\nОбъявленные переменные:");
        Console.WriteLine($"ID: {personId}, FirstName: {name}, Symbol: {charSymbol}, LastName: {surname}, Number: {number}");

        (_, string nameOnly, _, string surnameOnly, _) = person;
        Console.WriteLine("\nИгнорирование:");
        Console.WriteLine($"FirstName: {nameOnly}, LastName: {surnameOnly}");

        Console.WriteLine("\nНапрямую:");
        Console.WriteLine($"ID: {person.id}, FirstName: {person.firstName}, Symbol: {person.symbol}, LastName: {person.lastName}, Number: {person.phoneNumber}");

        var (id2, firstName2, symbol2, lastName2, number2) = person;
        Console.WriteLine("\nvar:");
        Console.WriteLine($"ID: {id2}, FirstName: {firstName2}, Symbol: {symbol2}, LastName: {lastName2}, Number: {number2}");

        Console.WriteLine("\nex4-b");
        (int id, string name, char initial) person1 = (1, "Ivan", 'I');
        (int id, string name, char initial) person2 = (1, "Ivan", 'I');

        (int id, string name, char initial) person3 = (2, "Vadim", 'V');

        Console.WriteLine($"person1 == person2: {person1 == person2}");
        Console.WriteLine($"person1 == person3: {person1 == person3}");
    }
}*/

//ex5
/*using System;
using System.Text;
class ex5
{

    static void Main()
    {
        Console.WriteLine("ex5");
        int[] values = { 8, 3, 6, 2, 5 };
        string message = "World";

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

        var result = ProcessData(values, message);

        Console.WriteLine($"Максимум: {result.max}");
        Console.WriteLine($"Минимум: {result.min}");
        Console.WriteLine($"Сумма: {result.sum}");
        Console.WriteLine($"Первая буква строки: {result.firstChar}");
    }
}*/

// ex6
/*using System;
using System.Text;
class ex6
{

    static void Main()
    {
        Console.WriteLine("ex6-1");
        // Определение локальной функции с блоком checked
        void CheckOverflow()
        {
            try
            {
                checked
                {
                    int maxInt = int.MaxValue;
                    Console.WriteLine("В функции CheckOverflow: Максимальное значение типа int = " + maxInt);
                    int overflowed = maxInt + 1;
                }
            }
            catch (OverflowException e)
            {
                Console.WriteLine("Ошибка переполнения в функции CheckOverflow: " + e.Message);
            }
        }

        CheckOverflow();

        Console.WriteLine("\nex6-2");
        void CheckUnchecked()
        {
            unchecked
            {
                int maxInt = int.MaxValue;
                Console.WriteLine("В функции CheckUnchecked: Максимальное значение типа int = " + maxInt);
                int overflowedResult = maxInt + 1;
                Console.WriteLine("Результат переполнения в функции CheckUnchecked: " + overflowedResult);
            }
        }

        CheckUnchecked();
    }
}
*/