using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PATTERN
{
    internal class RPGCreator
    {
        // создатель
        public void Build(RPGBuilder RPBuilder)
        {
            RPBuilder.CreateModel();
            RPBuilder.SetHP();
            RPBuilder.SetMP();
            RPBuilder.SetClassName();
            RPBuilder.SetName();
            RPBuilder.SetWeapon();
            Console.Clear();
   
        }
    }
}
