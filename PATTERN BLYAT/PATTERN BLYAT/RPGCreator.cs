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
        public RPGStats Build(RPGBuilder RolePlay)
        {
            RolePlay.CreateModel();
            RolePlay.SetHP();
            RolePlay.SetMP();
            RolePlay.SetClassName();
            RolePlay.SetName();
            RolePlay.SetWeapon();
            Console.Clear();
            return RolePlay.RPGModel;
        }
    }
}
