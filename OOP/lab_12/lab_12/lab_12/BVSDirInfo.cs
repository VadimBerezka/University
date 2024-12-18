public static class BVSDirInfo
{
    public static void ShowFileCount(string path)
    {
        if (Directory.Exists(path))
        {
            Console.WriteLine(Directory.GetFiles(path).Length);
        }
        else
        {
            Console.WriteLine("Такого пути не существует");
        }
    }
    public static void ShowCreationTime(string path)
    {
        if (Directory.Exists(path))
        {
            Console.WriteLine(Directory.GetCreationTime(path));
        }
        else
        {
            Console.WriteLine("Такого пути не существует");
        }
    }
    public static void ShowSubdirectories(string path)
    {
        if (Directory.Exists(path))
        {
            string[] directories = Directory.GetDirectories(path);
            foreach (string directory in directories)
            {
                Console.WriteLine(directory);
            }
        }
        else
        {
            Console.WriteLine("Такого пути не существует");
        }
    }
    public static void ShowParentDirectories(string path)
    {
        if (Directory.Exists(path))
        {
            var parentDirectories = new List<string>();
            var currentDirectories = new DirectoryInfo(path);

            while (currentDirectories.Parent != null)
            {
                parentDirectories.Add(currentDirectories.Parent.ToString());
                currentDirectories = currentDirectories.Parent;
            }

            foreach (string directory in parentDirectories)
            {
                Console.WriteLine(directory);
            }
        }
        else
        {
            Console.WriteLine("Такого пути не существует");
        }
    }
}