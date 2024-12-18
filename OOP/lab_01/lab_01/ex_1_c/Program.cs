using System;

class Program
{
    static void Main()
    {
        int intValue = 42;
        object boxedValue = intValue;
        Console.WriteLine("Упаковка: " + boxedValue);

        int unboxedValue = (int)boxedValue;
        Console.WriteLine("Распаковка: " + unboxedValue);

        double doubleValue = 3.14;
        object boxedDouble = doubleValue;
        Console.WriteLine("Упаковка double: " + boxedDouble);

        double unboxedDouble = (double)boxedDouble;
        Console.WriteLine("Распаковка double: " + unboxedDouble);

        char charValue = 'A';
        object boxedChar = charValue;
        Console.WriteLine("Упаковка char: " + boxedChar);

        char unboxedChar = (char)boxedChar;
        Console.WriteLine("Распаковка char: " + unboxedChar);
    }
}