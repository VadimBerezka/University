using System;
using System.Linq;

public class MonthQueries
{
    private string[] months;

    public MonthQueries(string[] months)
    {
        this.months = months;
    }

    public void MonthsWithLength(int length)
    {
        var filteredMonths = months.Where(month => month.Length == length);
        Console.WriteLine($"месяцы с длиной {length}:");
        foreach (var month in filteredMonths)
        {
            Console.WriteLine(month);
        }
    }

    public void SummerAndWinterMonths()
    {
        var summerAndWinterMonths = months.Where(month =>
            month == "June" || month == "July" || month == "August" ||
            month == "December" || month == "January" || month == "February");

        Console.WriteLine("\nлетние и зимние месяцы:");
        foreach (var month in summerAndWinterMonths)
        {
            Console.WriteLine(month);
        }
    }

    public void SortedMonths()
    {
        var sortedMonths = months.OrderBy(month => month);
        Console.WriteLine("\nмесяцы в алфавитном порядке:");
        foreach (var month in sortedMonths)
        {
            Console.WriteLine(month);
        }
    }

    public void MonthsWithU()
    {
        var countOfMonthsWithU = months.Count(month =>
            month.Contains('u') && month.Length >= 4);
        Console.WriteLine($"\nкол-во месяцев, содержащих 'u' и длиной не менее 4-х: {countOfMonthsWithU}\n");
    }
}