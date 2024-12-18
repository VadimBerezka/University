public static class BVSFileInfo
{
    public static void ShowFullPath(string file)
    {
        Console.WriteLine(Path.GetFullPath(file));
    }
    public static void ShowSizeAndExtension(string path)
    {
        FileInfo fileInfo = new FileInfo(path);

        Console.WriteLine($"размер: {fileInfo.Length}, расширение: {fileInfo.Extension}, имя: {fileInfo.Name}");
    }
    public static void ShowCreationAndChangeDate(string file)
    {
        Console.WriteLine($"дата создания: {File.GetCreationTime(file)}, изменения: {File.GetLastWriteTime(file)}");
    }
}
