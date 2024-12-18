using System;

class Program
{
    static void Main()
    {
        byte byteValue = 100;
        int intFromByte = byteValue;
        Console.WriteLine("Неявное приведение byte в int: " + intFromByte);

        int intValue = 123456;
        long longFromInt = intValue;
        Console.WriteLine("Неявное приведение int в long: " + longFromInt);

        float floatValue = 3.14f;
        double doubleFromFloat = floatValue;
        Console.WriteLine("Неявное приведение float в double: " + doubleFromFloat);

        char charValue = 'A';
        int intFromChar = charValue;
        Console.WriteLine("Неявное приведение char в int: " + intFromChar);

        decimal decimalValue = 19.99m;
        double doubleFromDecimal = (double)decimalValue;
        Console.WriteLine("Явное приведение decimal в double: " + doubleFromDecimal);

        int largeInt = 200;
        byte byteFromInt = (byte)largeInt;
        Console.WriteLine("Явное приведение int в byte: " + byteFromInt);

        double largeDouble = 3.14159265359;
        float floatFromDouble = (float)largeDouble;
        Console.WriteLine("Явное приведение double в float: " + floatFromDouble);

        long longValue = 123456789;
        int intFromLong = (int)longValue;
        Console.WriteLine("Явное приведение long в int: " + intFromLong);

        decimal decimalToFloat = 19.99m;
        float floatFromDecimal = (float)decimalToFloat;
        Console.WriteLine("Явное приведение decimal в float: " + floatFromDecimal);

        int intToChar = 65;
        char charFromInt = (char)intToChar;
        Console.WriteLine("Явное приведение int в char: " + charFromInt);
    }
}