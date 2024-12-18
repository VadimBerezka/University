using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Text.RegularExpressions;
    internal class Program
    {
        static void Main(string[] args)
        {
        // 1
        BVSLog.WriteToFile("hi");
        BVSLog.WriteToFile("bye");
        BVSLog.ReadFromFile();

        // 2
        //BVSDiskInfo.ShowFreeSpace();
        //BVSDiskInfo.ShowFileSystemInfo();
        //BVSDiskInfo.ShowAllDisksInfo();

        //// 3
        //BVSFileInfo.ShowFullPath("lab_12.sln");
        //BVSFileInfo.ShowSizeAndExtension(@"C:\University\OOP\lab_12\lab_12\\lab_12.sln");
        //BVSFileInfo.ShowCreationAndChangeDate("lab_12.sln");

        ////  4
        //BVSDirInfo.ShowFileCount(@"C:\University\OOP\lab_12\lab_12");
        //BVSDirInfo.ShowCreationTime(@"C:\University\OOP\lab_12\lab_12");
        //BVSDirInfo.ShowSubdirectories(@"C:\University\OOP\lab_12\lab_12");
        //BVSDirInfo.ShowParentDirectories(@"C:\University\OOP\lab_12\lab_12");

        ////5
        //BVSFileManager.ShowListFilesAndFolders(@"C:\University\OOP\lab_12\lab_12");
        //Console.WriteLine();

        //BVSFileManager.CreateDirectory(@"C:\University\OOP\lab_12\lab_12", "BVSInspect");
        //BVSFileManager.ShowListFilesAndFolders(@"C:\University\OOP\lab_12\lab_12");
        //Console.WriteLine();

        //BVSFileManager.SaveDirectoryInfo(@"C:\University\OOP\lab_12\lab_12");
        //BVSFileManager.CreateCopyAndRename(@"C:\University\OOP\lab_12\lab_12", @"C:\University\OOP\lab_12\lab_12\bvsdirinfo.txt");
        //BVSFileManager.DeleteFile(@"C:\University\OOP\lab_12\lab_12");


        //BVSFileManager.CreateDirectory(@"C:\University\OOP\lab_12\lab_12", "BVSInspect");
        //BVSFileManager.CreateDirectory(@"C:\University\OOP\lab_12\lab_12", "BVSFiles");
        //BVSFileManager.CopyFilesWithExtension(@"C:\University\OOP\lab_12\lab_12\", @"C:\University\OOP\lab_12\lab_12\BVSFiles", "txt");
        //BVSFileManager.MoveDirectory(@"C:\University\OOP\lab_12\lab_12", @"C:\University\OOP\lab_12\lab_12\BVSInspect");

        //BVSFileManager.CreateArchive(@"C:\University\OOP\lab_12\lab_12", @"C:\University\OOP\lab_12\lab_12");
        //BVSFileManager.ExtractArchive(@"C:\University\OOP\lab_12\lab_12", @"C:\University\OOP\lab_12\lab_12");

        //6
/*        DateTime date = new DateTime(2024, 12, 06);
        BVSLog.FindInfoByDate(date);

        DateTime start = new DateTime(2024, 12, 05, 0, 0, 0);
        DateTime end = new DateTime(2024, 12, 06, 0, 0, 0);
        BVSLog.FindInfoByTimeRange(start, end);

        BVSLog.FindInfo("hi");

        BVSLog.CountRecords();
        BVSLog.DeleteOldRecords();*/
    }
}