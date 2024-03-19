using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PATTERN;

namespace PATTERN
{
    // билдер для класса Нежить
    internal class Undead : RPGBuilder
    {
        public override void SetHP()
        {
            //не используется;
        }
        public override void SetMP()
        {
            this.RPGModel.MP = new MP { value = 200 };
        }
        public override void SetClassName()
        {
            this.RPGModel.ClassName = new ClassNames { cname = "Нежить" };
        }
        public override void SetName()
        {
            Console.Write("Введите имя для расы Нежить: ");
            while (true)
            {
                readname = Console.ReadLine();
                Console.Clear();
                if (readname.Length > 12) Console.Write("Введенное имя превышает максимальную длину.\n\tПопробуйте снова.\n");
                else break;
            }
            this.RPGModel.Name = new Names { name = readname };
        }
        public override void SetWeapon()
        {
            //не используется
        }
    }
}
