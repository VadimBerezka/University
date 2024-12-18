public static class BVSDiskInfo
{
    public static void ShowFreeSpace()
    {
        DriveInfo[] driveInfo = DriveInfo.GetDrives();

        foreach (DriveInfo drive in driveInfo)
        {
            if (drive.IsReady)
            {
                Console.WriteLine($"имя диска: {drive.Name} свободное место на диске: {drive.AvailableFreeSpace/1024/1024/1024}гб");
            }
        }
    }
    public static void ShowFileSystemInfo()
    {
        DriveInfo[] driveInfo = DriveInfo.GetDrives();

        foreach (DriveInfo drive in driveInfo)
        {
            if (drive.IsReady)
            {
                Console.WriteLine($"файловая система: {drive.DriveFormat}");
            }
        }
    }

    public static void ShowAllDisksInfo()
    {
        DriveInfo[] driveInfo = DriveInfo.GetDrives();

        foreach (DriveInfo drive in driveInfo)
        {
            if (drive.IsReady)
            {
                Console.WriteLine($"имя диска: {drive.Name}, объем: {drive.TotalSize / 1024 / 1024 / 1024}гб, доступный объем: {drive.AvailableFreeSpace / 1024 / 1024 / 1024}гб, метка тома: {drive.VolumeLabel}");
            }
        }
    }
}