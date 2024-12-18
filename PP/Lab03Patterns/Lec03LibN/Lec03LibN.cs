namespace Lec03LibN
{
    public class Lec03LibN {
        static public IFactory getL1() 
        {
            return new SalaryL1();
        }

        static public IFactory getL2(
            float a
            ) 
        {
            return new SalaryL2(a);
        }
        static public IFactory getL3(
            float a,
            float b
            ) 
        {
            return new SalaryL3(a, b);
        }
    }
}