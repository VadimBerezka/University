using System.IO.Compression;

public static class BVSFileManager
{
    public static string[] ListFilesAndFolders(string path)
    {
        string[] files = Directory.GetFileSystemEntries(path);
        return files;
    }
    public static void ShowListFilesAndFolders(string path)
    {
        string[] files = ListFilesAndFolders(path);

        foreach (string file in files)
        {
            Console.WriteLine(file);
        }
    }
    public static void CreateDirectory(string path, string directoryName)
    {
        string inspectDirectory = Path.Combine(path, directoryName);

        if (!Directory.Exists(inspectDirectory))
        {
            Directory.CreateDirectory(inspectDirectory);
        }
    }
    public static void SaveDirectoryInfo(string path)
    {
        if (Directory.Exists(path))
        {
            string inspectDirectory = Path.Combine(path, "BVSInspect", "bvsdirinfo.txt");
            using (StreamWriter writer = new StreamWriter(inspectDirectory))
            {
                foreach (string file in ListFilesAndFolders(path))
                {
                    writer.WriteLine(file);
                }
            }
        }
        else
        {
            Console.WriteLine("Такого пути не существует");
        }
    }
    public static void CreateCopyAndRename(string path, string destinationPath)
    {

        string inspectDirectory = Path.Combine(path, "BVSInspect", "bvsdirinfo.txt");
        if (File.Exists(inspectDirectory))
        {
            File.Copy(inspectDirectory, destinationPath);
        }
        else
        {
            Console.WriteLine("Такого пути не существует");
        }
    }
    public static void DeleteFile(string path)
    {

        string inspectDirectory = Path.Combine(path, "BVSInspect", "bvsdirinfo.txt");
        if (File.Exists(inspectDirectory))
        {
            File.Delete(inspectDirectory);
        }
        else
        {
            Console.WriteLine("Такого пути не существует");
        }
    }
    public static void CopyFilesWithExtension(string path, string destPath, string extension)
    {
        string[] files = Directory.GetFiles(path, $"*.{extension}");
        foreach (var file in files)
        {
            string fileName = Path.GetFileName(file);
            string destinationPath = Path.Combine(destPath, fileName);
            File.Copy(file, destinationPath);
        }
    }
    public static void MoveDirectory(string path, string destPath)
    {
        string sourcePath = Path.Combine(path, "BVSFiles");
        string destinationPath = Path.Combine(destPath, "BVSFiles");

        if (Directory.Exists(sourcePath))
        {
            Directory.Move(sourcePath, destinationPath);
        }
        else
        {
            Console.WriteLine("Такого пути не существует");
        }
    }

    public static void CreateArchive(string path, string archivePath)
    {
        string sourcePath = Path.Combine(path, "BVSFiles");

        if (Directory.Exists(sourcePath))
        {
            string zipPath = Path.Combine(archivePath, "BVSFiles.zip");
            ZipFile.CreateFromDirectory(sourcePath, zipPath);
        }
        else
        {
            Console.WriteLine("Такого пути не существует");
        }
    }

    public static void ExtractArchive(string path, string archivePath)
    {
        string zipPath = Path.Combine(archivePath, "BVSFiles.zip");

        if (File.Exists(zipPath))
        {
            string destinationPath = Path.Combine(path, "ExtractedBVSFiles");
            ZipFile.ExtractToDirectory(zipPath, destinationPath);
        }
        else
        {
            Console.WriteLine("Такого пути не существует");
        }
    }
}