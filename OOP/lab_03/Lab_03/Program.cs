using System.Text;

public class Set 
{
    private List<int> items;

    public Set()
    {
        items = new List<int>();
    }

    public Set(List<int> initialItems)
    {
        items = new List<int>();
        foreach (var item in initialItems)
        {
            Add(item);
        }
    }

    // проверка на дубликаты
    public void Add(int item)
    {
        if (!items.Contains(item))
        {
            items.Add(item);
        }
    }

    // добавление элемента в множество
    public static Set operator +(Set set, int item)
    {
        set.Add(item);
        return set;
    }

    // объединение множеств
    public static Set operator +(Set set1, Set set2)
    {
        var newSet = new Set(set1.items);
        foreach (var item in set2.items)
        {
            newSet.Add(item);
        }
        return newSet;
    }

    // пересечение множеств
    public static Set operator *(Set set1, Set set2)
    {
        var intersection = new Set();
        foreach (var item in set1.items)
        {
            if (set2.items.Contains(item))
            {
                intersection.Add(item);
            }
        }
        return intersection;
    }

    // мощность множества
    public static explicit operator int(Set set)
    {
        return set.Count;
    }

    // проверка на принадлежность размера массива определенному диапазону
    public static bool operator false(Set set)
    {
        return set.Count < 10;
    }

    public static bool operator true(Set set)
    {
        return set.Count >= 10;
    }

    public int Count
    {
        get
        {
            return items.Count;
        }
    }

    public List<int> Items
    {
        get
        {
            return items;
        }
    }

    public class Production
    {
        private int id;
        private string orgName;

        public int Id
        {
            get
            {
                return id;
            }
            set
            {
                id = value;
            }
        }

        public string OrgName
        {
            get
            {
                return orgName;
            }
            set
            {
                orgName = value;
            }
        }

        public Production()
        {
            Id = 10;
            OrgName = "BSTU";
        }
    }

    public class Developer
    {
        private string fullName;
        private int id;
        private string department;

        public string FullName
        {
            get
            {
                return fullName;
            }
            set
            {
                fullName = value;
            }
        }

        public int Id
        {
            get
            {
                return id;
            }
            set
            {
                id = value;
            }
        }

        public string Department
        {
            get
            {
                return department;
            }
            set
            {
                department = value;
            }
        }

        public Developer()
        {
            FullName = "Berezka Vadim Sergeevich";
            Id = 3;
            Department = "FIT";
        }
    }
}

public static class StatisticOperation
{
    public static int Sum(Set set)
    {
        int sum = 0;
        foreach (var item in set.Items)
        {
            sum += item;
        }
        return sum;
    }

    public static int Difference(Set set)
    {
        int max = int.MinValue;
        int min = int.MaxValue;

        foreach (var item in set.Items)
        {
            if (item > max) max = item;
            if (item < min) min = item;
        }

        return max - min;
    }

    public static int Count(Set set)
    {
        return set.Count;
    }

    public static string AddComma(this string str)
    {
        return str + ",";
    }

    public static IEnumerable<int> RemoveDuplicates(this IEnumerable<int> source)
    {
        return source.Distinct();
    }

    public static string AddCommas(this Set set)
    {
        var result = new StringBuilder();
        foreach (var item in set.Items)
        {
            result.Append(item).Append(",");
        }
        return result.ToString();
    }

    public static Set RemoveDuplicates(this Set set)
    {
        var uniqueItems = new List<int>();
        var newSet = new Set();

        foreach (var item in set.Items)
        {
            if (!uniqueItems.Contains(item))
            {
                uniqueItems.Add(item);
                newSet.Add(item);
            }
        }

        return newSet;
    }
}

public class Program
{
    public static void Main()
    {
        var set1 = new Set();
        set1.Add(1);
        set1.Add(2);
        set1.Add(3);

        var set2 = new Set();
        set2.Add(3);
        set2.Add(4);
        set2.Add(5);

        Console.WriteLine("Исходные множества:");
        PrintSet("Set1", set1);
        PrintSet("Set2", set2);
       
        var newSet = set1 + 6; 
        PrintSet("Новый Set1", newSet);
    
        var resultSet = set1 + set2;
        PrintSet("Объединение множеств", resultSet);

        var intersectionSet = set1 * set2;
        PrintSet("Пересечение множеств", intersectionSet);

        Console.WriteLine($"Сумма элементов: {StatisticOperation.Sum(resultSet)}");
        Console.WriteLine($"Разница между максимальным и минимальным: {StatisticOperation.Difference(resultSet)}");
        Console.WriteLine($"Количество элементов: {StatisticOperation.Count(resultSet)}");

        Console.WriteLine(resultSet ? "Множество содержит 10 или более элементов." : "Множество содержит менее 10 элементов.");

        var list = new List<int> { 16, 12, 11, 5, 32, 55, 12, 11, 5 };
        Console.Write("Все элементы: ");
        foreach (var item in list)
        {
            Console.Write(item + " ");
        }
        Console.WriteLine();

        var uniqueList = list.Distinct();
        Console.Write("Уникальные элементы: ");
        foreach (var item in uniqueList)
        {
            Console.Write(item + " ");
        }
        Console.WriteLine();
       
    }

    private static void PrintSet(string title, Set set)
    {
        Console.Write(title + ": ");
        foreach (var item in set.Items)
        {
            Console.Write(item + " ");
        }
        Console.WriteLine();
    }
}

