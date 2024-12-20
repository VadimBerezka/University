using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

class Program
{
    static async Task Main(string[] args)
    {
        int limit = 1000;
        int numberOfRuns = 5;

        await ManageSuppliersAndCustomers();

        for (int run = 1; run <= numberOfRuns; run++)
        {
            Console.WriteLine($"Прогон {run}:");
            CancellationTokenSource cts = new CancellationTokenSource();
            Stopwatch stopwatch = Stopwatch.StartNew();

            try
            {
                // 1
                var primesTask = FindPrimes(limit, cts.Token);
                var calculationsTask = PerformCalculations(cts.Token);

                Task.Delay(100).ContinueWith(_ => cts.Cancel());

                primesTask.ContinueWith(primesResult =>
                {
                    if (primesResult.IsCanceled)
                    {
                        Console.WriteLine("Задача поиска простых чисел была отменена.");
                    }
                    else
                    {
                        Console.WriteLine($"Найдено {primesResult.Result.Count} простых чисел до {limit}.");
                    }
                }, TaskContinuationOptions.OnlyOnRanToCompletion);

                // 4.1
                calculationsTask.ContinueWith(calculationResult =>
                {
                    if (calculationResult.IsCanceled)
                    {
                        Console.WriteLine("Задача расчетов была отменена.");
                    }
                    else
                    {
                        Console.WriteLine($"Результаты расчетов: {string.Join(", ", calculationResult.Result)}");
                        var finalResult = calculationResult.Result.Sum();
                        Console.WriteLine($"Сумма результатов расчетов: {finalResult}");
                    }
                }, TaskContinuationOptions.OnlyOnRanToCompletion);

                // 4.2
                var awaiter = calculationsTask.GetAwaiter();
                if (awaiter.IsCompleted)
                {
                    var results = awaiter.GetResult();
                    Console.WriteLine($"Результаты расчетов: {string.Join(", ", results)}");
                    var finalResult = results.Sum();
                    Console.WriteLine($"Сумма результатов расчетов: {finalResult}");
                }
                else
                {
                    await calculationsTask;
                    var results = calculationsTask.Result;
                    Console.WriteLine($"Результаты расчетов: {string.Join(", ", results)}");
                    var finalResult = results.Sum();
                    Console.WriteLine($"Сумма результатов расчетов: {finalResult}");
                }

                var primes = await primesTask;
            }
            catch (OperationCanceledException)
            {
                Console.WriteLine("Поиск был отменён.");
            }
            finally
            {
                stopwatch.Stop();
                Console.WriteLine($"Время выполнения: {stopwatch.ElapsedMilliseconds} мс\n");
            }
        }

        ParallelPerformanceTest();
    }

    //7
    static async Task ManageSuppliersAndCustomers()
    {
        var warehouse = new BlockingCollection<string>();
        var suppliers = new List<Task>();
        var customers = new List<Task>();

        for (int i = 1; i <= 5; i++)
        {
            int supplierId = i;
            suppliers.Add(AddProductAsync(supplierId, warehouse));
        }

        for (int i = 1; i <= 10; i++)
        {
            int customerId = i;
            customers.Add(BuyProductAsync(customerId, warehouse));
        }

        await Task.WhenAll(suppliers);
        warehouse.CompleteAdding();
        await Task.WhenAll(customers);
    }

    //8
    static async Task AddProductAsync(int supplierId, BlockingCollection<string> warehouse)
    {
        for (int j = 1; j <= 1; j++)
        {
            string product = $"Товар {supplierId}";
            await Task.Delay(new Random().Next(500, 2000));
            warehouse.Add(product);
            Console.WriteLine($"Поставщик {supplierId} добавил: {product}");
            DisplayWarehouse(warehouse);
            Console.WriteLine($"Завершена задача {Task.CurrentId} для поставщика {supplierId}: {true}");
        }
    }

    //8
    static async Task BuyProductAsync(int customerId, BlockingCollection<string> warehouse)
    {
        await Task.Delay(new Random().Next(500, 1500));
        if (warehouse.TryTake(out string purchasedProduct))
        {
            Console.WriteLine($"Покупатель {customerId} купил: {purchasedProduct}");
            DisplayWarehouse(warehouse);
            Console.WriteLine($"Завершена задача {Task.CurrentId} для покупателя {customerId}: {true}");
        }
        else
        {
            Console.WriteLine($"Покупатель {customerId} не нашел товара и ушел.");
            Console.WriteLine($"Завершена задача {Task.CurrentId} для покупателя {customerId}: {true}");
        }
    }

    static void DisplayWarehouse(BlockingCollection<string> warehouse)
    {
        Console.WriteLine("Товары на складе: " + string.Join(", ", warehouse));
    }

    // 2
    static async Task<List<int>> FindPrimes(int limit, CancellationToken cancellationToken)
    {
        bool[] isPrime = Enumerable.Repeat(true, limit + 1).ToArray();
        isPrime[0] = isPrime[1] = false;

        var tasks = new List<Task>();

        for (int i = 2; i * i <= limit; i++)
        {
            cancellationToken.ThrowIfCancellationRequested();
            int current = i;

            tasks.Add(Task.Run(() =>
            {
                Console.WriteLine($"Старт задачи {Task.CurrentId} для числа {current}");
                if (isPrime[current])
                {
                    for (int j = current * current; j <= limit; j += current)
                    {
                        cancellationToken.ThrowIfCancellationRequested();
                        isPrime[j] = false;
                    }
                }
                Console.WriteLine($"Завершена задача {Task.CurrentId} для числа {current}: {true}");
            }, cancellationToken));
        }

        try
        {
            await Task.WhenAll(tasks);
        }
        catch (OperationCanceledException)
        {
            throw;
        }

        var primes = new List<int>();
        for (int i = 2; i <= limit; i++)
        {
            if (isPrime[i])
            {
                primes.Add(i);
            }
        }

        return primes;
    }

    // 3
    static async Task<List<int>> PerformCalculations(CancellationToken cancellationToken)
    {
        var tasks = new List<Task<int>>();
        tasks.Add(Task.Run(() => CalculateSquare(10), cancellationToken)); 
        tasks.Add(Task.Run(() => CalculateCube(3), cancellationToken)); 
        tasks.Add(Task.Run(() => CalculateFactorial(5), cancellationToken)); 

        var results = await Task.WhenAll(tasks);
        return results.ToList();
    }

    static int CalculateSquare(int number) => number * number;
    static int CalculateCube(int number) => number * number * number;
    static int CalculateFactorial(int number) => number == 0 ? 1 : number * CalculateFactorial(number - 1);

    static void ParallelPerformanceTest()
    {
        int arraySize = 1000000;
        int[] numbers = new int[arraySize];
        Random rand = new Random();

        for (int i = 0; i < arraySize; i++)
        {
            numbers[i] = rand.Next(1000);
        }

        Stopwatch stopwatch = new Stopwatch();
        
        //5
        stopwatch.Start();
        int[] squares = new int[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            squares[i] = numbers[i] * numbers[i];
        }
        stopwatch.Stop();
        Console.WriteLine($"Время выполнения обычного цикла: {stopwatch.ElapsedMilliseconds} мс");

        //5
        stopwatch.Restart();
        int[] parallelSquares = new int[arraySize];
        Parallel.For(0, arraySize, i =>
        {
            parallelSquares[i] = numbers[i] * numbers[i];
        });
        stopwatch.Stop();
        Console.WriteLine($"Время выполнения Parallel.For: {stopwatch.ElapsedMilliseconds} мс");

        //5, 6
        stopwatch.Restart();
        Parallel.Invoke(
            () => CalculateSquare(10),
            () => CalculateCube(3),
            () => CalculateFactorial(5)
        );
        stopwatch.Stop();
        Console.WriteLine($"Время выполнения Parallel.Invoke: {stopwatch.ElapsedMilliseconds} мс");
    }
}