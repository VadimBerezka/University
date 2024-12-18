using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lec03LibN
{
    public class BonusC : IBonus
    {
        public float cost1Hour { get; set; }
        private float x;
        private float y;
        public BonusC(float cost1Hour, float x, float y)
        {
            this.cost1Hour = cost1Hour;
            this.x = x;
            this.y = y;
        }
        public float Calculate(float number_hours)
        {
            return cost1Hour * number_hours * x + y;
        }
    }
    public class BonusCL2 : IBonus
    {
        private float A;
        private float x;
        private float y;
        public float cost1Hour { get; set; }
        public BonusCL2(float cost1Hour, float x, float y, float A)
        {
            this.cost1Hour = cost1Hour;
            this.A = A;
            this.x = x;
            this.y = y;
        }
        public float Calculate(float number_hours)
        {
            return (number_hours + A) * cost1Hour * x + y;
        }
    }
    public class BonusCL3 : IBonus
    {
        public float cost1Hour { get; set; }
        private float x { get; set; }
        private float y { get; set; }
        private float A { get; set; }
        private float B { get; set; }
        public BonusCL3(float cost1Hour, float x, float y, float A, float B)
        {
            this.cost1Hour = cost1Hour;
            this.x = x;
            this.y = y;
            this.A = A;
            this.B = B;
        }
        public float Calculate(float number_hours)
        {
            return (number_hours + A) * (cost1Hour + B) * x + y;
        }
    }
}