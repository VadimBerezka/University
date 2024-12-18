using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

public static class Reflector
{
    public static string AssemblyName(string className)
    {
        Type type = Type.GetType(className);
        return type.Assembly.GetName().Name;
    }

    public static bool PublicConstructors(string className)
    {
        Type type = Type.GetType(className);

        var constructors = type?.GetConstructors(BindingFlags.Public | BindingFlags.Instance);
        return constructors.Length > 0;
    }

    public static IEnumerable<string> PublicMethods(string className)
    {
        Type type = Type.GetType(className);

        return type.GetMethods(BindingFlags.Public | BindingFlags.Instance).Select(method => method.Name);
    }

    public static IEnumerable<string> FieldsAndProperties(string className)
    {
        Type type = Type.GetType(className);

        var fields = type.GetFields(BindingFlags.Public | BindingFlags.Instance).Select(field => field.Name);
        var properties = type.GetProperties(BindingFlags.Public | BindingFlags.Instance).Select(prop => prop.Name);
        return fields.Concat(properties);
    }

    public static IEnumerable<string> ImplementedInterfaces(string className)
    {
        Type type = Type.GetType(className);

        return type.GetInterfaces().Select(i => i.Name);
    }

    public static IEnumerable<string> MethodsByClassName(string className, string parameterTypeName)
    {
        Type type = Type.GetType(className);
        Type parameterType = Type.GetType(parameterTypeName);

        return type.GetMethods().Where(method => method.GetParameters().Any(parameter => parameter.ParameterType == parameterType)).Select(method => method.Name);
    }
    public static void Invoke(object obj, string methodName, string filePath)
    {
        var method = obj.GetType().GetMethod(methodName, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance);
        var paramValues = File.ReadAllLines(filePath);
        var parameters = new object[paramValues.Length];
            for (int i = 0; i < paramValues.Length; i++)
            {
            parameters[i] = Convert.ChangeType(paramValues[i], method.GetParameters()[i].ParameterType);
            }
        method.Invoke(obj, parameters);
    }
    public static void SaveToFile(string className, string path)
    {
        string filePath = @$"C:\University\OOP\lab_11\{path}";

        using (StreamWriter writer = new StreamWriter(filePath))
        {
            writer.WriteLine($"класс: {className}");
            writer.WriteLine($"имя сборки: {AssemblyName(className)}");
            writer.WriteLine($"есть ли публичные конструкторы? ответ: {PublicConstructors(className)}");

            writer.WriteLine("Публичные методы:");
            foreach (var method in PublicMethods(className))
            {
                writer.WriteLine(method);
            }

            writer.WriteLine("Поля и свойства:");
            foreach (var fieldAndProperty in FieldsAndProperties(className))
            {
                writer.WriteLine(fieldAndProperty);
            }

            writer.WriteLine("Реализованные интерфейсы:");
            foreach (var interfaceName in ImplementedInterfaces(className))
            {
                writer.WriteLine(interfaceName);
            }
        }
    }

    public static T Create<T>(params object[] args)
    {
        return (T)Activator.CreateInstance(typeof(T), args);
    }
}