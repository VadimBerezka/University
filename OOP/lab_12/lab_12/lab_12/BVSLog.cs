using System.Text.RegularExpressions;

public static class BVSLog
{
    private static string filename = "bvslogfile.txt";
    private static string path = @$"C:\University\OOP\lab_12\lab_12\{filename}";
    private static DateTime ExtractDateFromLog(string log)
    {
        string pattern = @"\d{2}\.\d{2}\.\d{4} \d{2}:\d{2}:\d{2}";

        Match match = Regex.Match(log, pattern);

        if (match.Success)
        {
            DateTime date = DateTime.Parse(match.Value);
            return date;
        }
        else
        {
            Console.WriteLine("Дата не найдена в логе.");
            return DateTime.MinValue;
        }
    }

    public static void WriteToFile(string action)
    {
        DateTime dateTime = DateTime.Now;

        string line = $"действие: {action}, имя файла: {filename}, путь: {path}, время: {dateTime}";

        using (StreamWriter writer = new StreamWriter(path, true))
        {
            writer.WriteLine(line);
        }
    }
    public static void ReadFromFile()
    {
        string line;
        using (StreamReader reader = new StreamReader(path))
        {
            while ((line = reader.ReadLine()) != null)
            {
                Console.WriteLine(line);
            }
        }
    }
    public static void FindInfo(string action)
    {
        string line;
        using (StreamReader reader = new StreamReader(path))
        {
            while ((line = reader.ReadLine()) != null)
            {
                Console.WriteLine(line.Contains(action));
            }
        }
    }

    public static void FindInfoByDate(DateTime date)
    {
        string line;
        using (StreamReader reader = new StreamReader(path))
        {
            while ((line = reader.ReadLine()) != null)
            {
                if (line.Contains(date.ToString("yyyy-MM-dd")))
                {
                    Console.WriteLine(line);
                }
            }
        }
    }

    public static void FindInfoByTimeRange(DateTime startTime, DateTime endTime)
    {
        string line;
        using (StreamReader reader = new StreamReader(path))
        {
            while ((line = reader.ReadLine()) != null)
            {
                DateTime logTime = ExtractDateFromLog(line);
                if (logTime >= startTime && logTime <= endTime)
                {
                    Console.WriteLine(line);
                }
            }
        }
    }
    public static void CountRecords()
    {
        int count = 0;
        string line;
        using (StreamReader reader = new StreamReader(path))
        {
            while ((line = reader.ReadLine()) != null)
            {
                count++;
            }
        }
        Console.WriteLine($"Количество записей: {count}");
    }
    public static void DeleteOldRecords()
    {
        DateTime currentHour = DateTime.Now;
        string[] lines = File.ReadAllLines(path);
        var currentHourLogs = new List<string>();

        foreach (var line in lines)
        {
            DateTime logTime = ExtractDateFromLog(line);
            if (logTime.Hour == currentHour.Hour && logTime.Date == currentHour.Date)
            {
                currentHourLogs.Add(line);
            }
        }
        File.WriteAllLines(path, currentHourLogs);
    }
}
