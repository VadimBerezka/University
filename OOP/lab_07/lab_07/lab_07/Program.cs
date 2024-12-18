using System.Text;
interface GenericInterface<T>
{
    void Add(T item);
    void Delete(T item);
    void Watch();
}

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

    public void Watch()
    {
        Console.WriteLine("элементы в коллекции:");
        foreach (var item in items)
        {
            Console.WriteLine(item);
        }
    }

}
public class CollectionType<T> : GenericInterface<T> where T : class
{
    private List<T> items;
    public CollectionType()
    {
        items = new List<T>();
    }

    // добавление
    public void Add(T item)
    {
        try
        {
            if (items.Contains(item))
            {
                throw new InvalidOperationException("элемент уже есть");
            }
            items.Add(item);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"ошибка: {ex.Message}");
        }
        finally
        {
            Console.WriteLine($"добавил элемент {item}");
        }
    }

    // удаление 
    public void Delete(T item)
    {
        try
        {
            if (!items.Remove(item))
            {
                throw new InvalidOperationException("элемент не найден");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"ошибка: {ex.Message}");
        }
        finally
        {
            Console.WriteLine($"удалил элемент {item}");
        }
    }

    // просмотр
    public void Watch()
    {
        Console.WriteLine("элементы в коллекции:");
        foreach (var item in items)
        {
            Console.WriteLine(item);
        }
    }

    // нахождение в коллекции
    public List<T> Find(Func<T, bool> predicate)
    {
        List<T> foundItems = new List<T>();

        foreach (var item in items)
        {
            if (predicate(item))
            {
                foundItems.Add(item);
            }
        }
        return foundItems;
    }

    public void SaveToFile(string filePath)
    {
        try
        {
            using (StreamWriter writer = new StreamWriter(filePath))
            {
                foreach (var item in items)
                {
                    writer.WriteLine(item.ToString());
                }
            }
            Console.WriteLine("коллекция сохранена в файл.");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"ошибка: {ex.Message}");
        }
    }
    public void LoadFromFile(string filePath)
    {
        try
        {
            if (File.Exists(filePath))
            {
                items.Clear();
                using (StreamReader reader = new StreamReader(filePath))
                {
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        var item = ParseLine(line);
                        if (item != null)
                        {
                            items.Add(item);
                        }
                    }
                }
                Console.WriteLine("коллекция загружена из файла.");
            }
            else
            {
                Console.WriteLine("файл не найден.");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"ошибка: {ex.Message}");
        }
    }
    protected virtual T ParseLine(string line)
    {
        return null;
    }
}

public interface IDriveable
{
    void Start();
    void Stop();
    bool DoDrive(); // ex4
}
public sealed class Car : AbstractVehicle
{
    private CarControl control;

    public CarControl Control
    {
        get
        {
            return control;
        }
        set
        {
            control = value;
        }
    }

    public Car(string brand, string model, Engine engine) : base(brand, model, engine)
    {
        Control = new CarControl();
    }

    public override void Start()
    {
        Console.WriteLine($"{Brand} {Model} стартует");
        Control.Accelerate();
    }

    public override void Stop()
    {
        Control.Brake();
        Console.WriteLine($"{Brand} {Model} стоп");
    }

    public override bool DoDrive()
    {
        Console.WriteLine($"{Brand} {Model} водим");
        return true;
    }

    public override string ToString()
    {
        return base.ToString() + " машинка";
    }
}
public class CarControl
{
    public void Accelerate()
    {
        //Console.WriteLine("ускоряемся");
    }

    public void Brake()
    {
        //Console.WriteLine("сломалась");
    }
}
public abstract class AbstractVehicle : IDriveable
{
    private string brand;
    private string model;
    private Engine engine;

    public string Brand
    {
        get
        {
            return brand;
        }
        set
        {
            brand = value;
        }
    }

    public string Model
    {
        get
        {
            return model;
        }
        set
        {
            model = value;
        }
    }

    public Engine Engine
    {
        get
        {
            return engine;
        }
        set
        {
            engine = value;
        }
    }

    protected AbstractVehicle(string brand, string model, Engine engine)
    {
        Brand = brand;
        Model = model;
        Engine = engine;
    }

    public abstract void Start();
    public abstract void Stop();
    public abstract bool DoDrive(); // ex4

    public override string ToString()
    {
        return $"{GetType().Name}: {Brand} {Model}, {Engine}";
    }
}
public class Engine
{
    private int horsePower;

    public int HorsePower
    {
        get
        {
            return horsePower;
        }
        set
        {
            horsePower = value;
        }
    }

    public Engine(int horsePower)
    {
        HorsePower = horsePower;
    }

    public override string ToString()
    {
        return $"{HorsePower} лошадок";
    }
}

public class Program
{
    public static void Main()
    {
        // работа со стандартными типами
        CollectionType<string> str = new CollectionType<string>();
        str.Add("1");
        str.Add("2");
        str.Add("3");
        str.Add("3");
        str.Add("4");
        str.Add("5");
        str.Watch();
        str.Delete("4");
        str.Watch();

        var foundStrings = str.Find(item => item == "2");
        Console.WriteLine("найдено в коллекции:");
        foreach (var item in foundStrings)
        {
            Console.WriteLine(item);
        }
        Console.WriteLine("\n\n");
        
        CollectionType<Set> sets = new CollectionType<Set>();
        var set1 = new Set();
        set1.Add(1);
        set1.Add(2);
        set1.Add(3);
        set1.Watch();

        var set2 = new Set();
        set2.Add(3);
        set2.Add(4);
        set2.Add(5);
        set2.Watch();

        sets.Add(set1);
        sets.Add(set2);
        sets.Watch();
        sets.Delete(set1);
        sets.Watch();
        Console.WriteLine("\n\n");

        var car1 = new Car("Toyota", "Supra", new Engine(1000));
        var car2 = new Car("Honda", "Civic", new Engine(900));

        CollectionType<Car> carCollection = new CollectionType<Car>();
        carCollection.Add(car1);
        carCollection.Add(car2);
        carCollection.Watch();
        carCollection.Delete(car1);
        carCollection.Watch();

        string filePath = "carCollection.txt";
        carCollection.SaveToFile(filePath);
        CollectionType<Car> loadedCarCollection = new CollectionType<Car>();
        loadedCarCollection.LoadFromFile(filePath);
    }
}