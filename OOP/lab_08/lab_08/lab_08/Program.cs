using System.Text;

public class Director
{
    public delegate void PlusEventHandler(int x);
    public delegate void MinusEventHandler(int x);

    public event PlusEventHandler PlusEvent;
    public event MinusEventHandler MinusEvent;

    private string name;
    private int salary;
    private string specialty;

    public string Name
    {
        get 
        {
            return name; 
        }
        set 
        {
            name = value; 
        }
    }
    public int Salary
    {
        get 
        {
            return salary; 
        }
        set 
        {
            salary = value; 
        }
    }
    public string Specialty
    {
        get 
        {
            return specialty; 
        }
        set 
        {
            specialty = value; 
        }
    }

    public Director(string name, int salary, string specialty)
    {
        Name = name;
        Salary = salary;
        Specialty = specialty;
    }

    public void SubscribeToPlus(PlusEventHandler handler) => PlusEvent += handler;

    public void SubscribeToMinus(MinusEventHandler handler) => MinusEvent += handler;

    public void OnPlus(int x)
    {
        Salary += x;
        PlusEvent?.Invoke(x);
    }

    public void OnMinus(int x)
    {
        Salary -= x;
        MinusEvent?.Invoke(x);
    }

    public void DisplayInfo()
    {
        Console.WriteLine($"имя: {Name}, зарплата: {Salary}, специальность: {Specialty}");
    }
}


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


class Program
{
    static void Main(string[] args)
    {
        Director director1 = new Director("леша", 5000, "токарь");
        Director director2 = new Director("вадим", 4500, "студент");
        
        director1.SubscribeToPlus(x => Console.WriteLine($"{director1.Name} получил повышение на {x}"));
        director2.SubscribeToPlus(x => Console.WriteLine($"{director2.Name} получил повышение на {x}"));

        director2.SubscribeToMinus(x => Console.WriteLine($"{director2.Name} получил штраф на {x}"));

        Console.WriteLine("состояние до событий:");
        director1.DisplayInfo();
        director2.DisplayInfo();

        Console.Write("\nповышение зарплаты на ");
        int plusX = int.Parse(Console.ReadLine());
        director1.OnPlus(plusX);
        director2.OnPlus(plusX);

        director2.OnMinus(200);

        Console.WriteLine("\nсостояние после событий:");
        director1.DisplayInfo();
        director2.DisplayInfo();


        string input = "факультет информационных технологий";

        Func<string, string> removePunctuation = StringMethods.RemovePunct;
        Func<string, string> removeExtraSpaces = StringMethods.TrimSpaces;
        Func<string, string> toUpperCase = StringMethods.ToUpper;
        Func<string, string> replaceSymbol = StringMethods.ReplaceSymbol;

        Action<string> addSymbol = (str) => Console.WriteLine(StringMethods.AppendChar(str, '~'));

        string processedString = input;
        processedString = removePunctuation(processedString);
        processedString = removeExtraSpaces(processedString);
        processedString = toUpperCase(processedString);
        processedString = replaceSymbol(processedString);

        addSymbol(processedString);
    }
}