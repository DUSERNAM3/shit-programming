using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PATTERN
{
    public class Weapons
    {
        public string name { get; set; }
        public int power { get; set; }
    }
    class Sword : Weapons { }
    class Bow : Weapons { }
    class HealBook : Weapons { }
}
