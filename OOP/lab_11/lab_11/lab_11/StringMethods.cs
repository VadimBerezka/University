using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class StringMethods
{
    public static string RemovePunct(string input)
    {
        var result = new StringBuilder();
        foreach (char c in input)
        {
            if (!char.IsPunctuation(c))
            {
                result.Append(c);
            }
        }
        return result.ToString();
    }

    public static string AppendChar(string input, char symbol)
    {
        return input + symbol;
    }

    public static string ToUpper(string input)
    {
        return input.ToUpper();
    }

    public static string TrimSpaces(string input)
    {
        return input.Replace(" ", "");
    }

    public static string ReplaceSymbol(string input)
    {
        return input.Replace('А', '*');
    }
}
