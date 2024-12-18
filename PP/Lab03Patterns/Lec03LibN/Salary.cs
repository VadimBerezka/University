using System;

namespace Lec03LibN
{
    public class SalaryL1 : IFactory
    {
        public IBonus GetA(float cost1Hour)
        {
            return new BonusA(cost1Hour);
        }

        public IBonus GetB(float cost1Hour, float x)
        {
            return new BonusB(cost1Hour, x);
        }

        public IBonus GetC(float cost1Hour, float x, float y)
        {
            return new BonusC(cost1Hour, x, y);
        }
    }

    public class SalaryL2 : IFactory
    {
        private readonly float A;

        public SalaryL2(float A)
        {
            this.A = A;
        }

        public IBonus GetA(float cost1Hour)
        {
            return new BonusAL2(cost1Hour, A);
        }

        public IBonus GetB(float cost1Hour, float x)
        {
            return new BonusBL2(cost1Hour, x, A);
        }

        public IBonus GetC(float cost1Hour, float x, float y)
        {
            return new BonusCL2(cost1Hour, x, y, A);
        }
    }

    public class SalaryL3 : IFactory
    {
        private float A { get; set; }
        private float B { get; set; }

        public SalaryL3(float A, float B)
        {
            this.A = A;
            this.B = B;
        }

        public IBonus GetA(float cost1Hour)
        {
            return new BonusAL3(cost1Hour, A, B);
        }

        public IBonus GetB(float cost1Hour, float x)
        {
            return new BonusBL3(cost1Hour, x, A, B);
        }

        public IBonus GetC(float cost1Hour, float x, float y)
        {
            return new BonusCL3(cost1Hour, x, y, A, B);
        }
    }
}