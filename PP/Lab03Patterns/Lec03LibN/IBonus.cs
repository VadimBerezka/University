using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lec03LibN
{
    public interface IBonus {
        float cost1Hour { get; set; }
        float Calculate(
            float number_hours
            );
    }
}