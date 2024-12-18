using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
using System.Collections.ObjectModel;
using System.Collections.Specialized;

interface IList
{
    void PrintValue();
}

public class MyDictionary<TKey, TValue> : IEnumerable<KeyValuePair<TKey, TValue>>, IList
{
    private Dictionary<TKey, TValue> internalDictionary;

    public MyDictionary()
    {
        internalDictionary = new Dictionary<TKey, TValue>();
    }

    public int Count
    {
        get 
        {
            return internalDictionary.Count; 
        }
    }

    public void Add(TKey key, TValue value)
    {
        if (internalDictionary.ContainsKey(key))
        {
            Console.WriteLine("Ключ уже существует в словаре");
        }
        else
        {
            internalDictionary.Add(key, value);
            Console.WriteLine("Элемент добавлен");
        }
    }

    public TValue Get(TKey key)
    {
        return internalDictionary[key];
    }

    public bool Remove(TKey key)
    {
        return internalDictionary.Remove(key);
    }

    public bool ContainsKey(TKey key)
    {
        return internalDictionary.ContainsKey(key);
    }

    public TValue this[TKey key]
    {
        get
        {
            return Get(key);
        }
        set
        {
            internalDictionary[key] = value;
        }
    }

    public void Clear()
    {
        internalDictionary.Clear();
    }

    public IEnumerator<KeyValuePair<TKey, TValue>> GetEnumerator()
    {
        return internalDictionary.GetEnumerator();
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }

    public void PrintValue()
    {
        foreach (TValue value in internalDictionary.Values)
        {
            Console.WriteLine(value);
        }
    }
}

interface IOrderedDictionary
{
    void sort();
}

public class ConcurrentBag<T> : IEnumerable<T>, IOrderedDictionary
{
    private T[] items;
    private int count;

    public ConcurrentBag()
    {
        items = new T[4];
        count = 0;
    }

    public int Count
    {
        get 
        {
            return count; 
        }
    }

    public T this[int index]
    {
        get
        {
           return items[index];
        }
        set
        {
           items[index] = value;
        }
    }

    public void Add(T item)
    {
        if (count == items.Length)
        {
            Array.Resize(ref items, items.Length * 2);
        }
        items[count] = item;
        count++;
    }

    public void RemoveAt(int index)
    {
        for (int i = index; i < count - 1; i++)
        {
            items[i] = items[i + 1];
        }
        items[count - 1] = default(T);
        count--;
    }

    public IEnumerator<T> GetEnumerator()
    {
        for (int i = 0; i < count; i++)
        {
            yield return items[i];
        }
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }

    public void sort()
    {
        items = items.OrderBy(item => item).ToArray();
    }
}

public class Program
{
    static void Main(string[] args)
    {
        // ex 1
        MyDictionary<string, int> myDict = new MyDictionary<string, int>();

        myDict.Add("хлеб", 1);
        myDict.Add("батон", 2);
        myDict.Add("тортик", 3);

        Console.WriteLine("значение для ключа 'тортик': " + myDict.Get("тортик"));

        Console.WriteLine("весь список:");
        myDict.PrintValue();

        myDict.Remove("тортик");
        Console.WriteLine("после удаления:");
        myDict.PrintValue();

        Console.WriteLine("содержит ли ключ 'хлеб'? " + myDict.ContainsKey("хлеб"));
        Console.WriteLine("содержит ли ключ 'батон'? " + myDict.ContainsKey("батон"));
        Console.WriteLine("содержит ли ключ 'тортик'? " + myDict.ContainsKey("тортик"));

        //myDict.Clear();
        Console.WriteLine("кол-во элементов после очистки: " + myDict.Count);

        // ex 2
        var genericCollection = new List<int> { 1, 2, 3, 4, 5 };

        Console.WriteLine("универсальная коллекция:");
        foreach (var item in genericCollection)
        {
            Console.Write(item + " ");
        }
        Console.WriteLine();

        int n = 2;
        genericCollection.RemoveRange(0, n);

        genericCollection.Add(6);
        genericCollection.Insert(0, 0);

        var secondCollection = new SortedList<string, int>();
        foreach(var  item in myDict)
        {
            secondCollection.Add(item.Key, item.Value);
        }

        Console.WriteLine("вторая коллекция:");
        foreach (var el in secondCollection)
        {
            Console.Write($"[{el.Key}: {el.Value}] ");
        }
        Console.WriteLine();

        // ex 3
        ObservableCollection<ConcurrentBag<string>> bags = new ObservableCollection<ConcurrentBag<string>>();

        bags.CollectionChanged += Bags_CollectionChanged;

        var bag1 = new ConcurrentBag<string>();
        bag1.Add("вадим");
        bag1.Add("влад");
        bags.Add(bag1);

        var bag2 = new ConcurrentBag<string>();
        bag2.Add("семен");
        bag2.Add("леша");
        bags.Add(bag2);

        bags.Remove(bag1);
        bags.Remove(bag2);

        var bag3 = new ConcurrentBag<string>();
        bag3.Add("матвей");
        bags.Add(bag3);

        Console.WriteLine("текущие ConcurrentBag в коллекции:");
        foreach (var bag in bags)
        {
            Console.WriteLine($"Bag содержит {bag.Count} элементов.");
        }
    }

    private static void Bags_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
    {
        if (e.Action == NotifyCollectionChangedAction.Add)
        {
            foreach (ConcurrentBag<string> newBag in e.NewItems)
            {
                Console.WriteLine($"добавлен новый ConcurrentBag с {newBag.Count} элементами.");
            }
        }
        else if (e.Action == NotifyCollectionChangedAction.Remove)
        {
            foreach (ConcurrentBag<string> oldBag in e.OldItems)
            {
                Console.WriteLine($"удален ConcurrentBag с {oldBag.Count} элементами.");
            }
        }
    }
}