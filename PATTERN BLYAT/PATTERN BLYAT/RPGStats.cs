using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PATTERN;

namespace PATTERN
{
    internal class RPGStats
    {
        // ХП
        public HP HP { get; set; }
        // Мана
        public MP MP { get; set; }
        // Имя
        public ClassNames ClassName { get; set; }
        public Names Name { get; set; }
        public Weapons Weapon { get; set; }
        public override string ToString()
        {
            StringBuilder SB = new StringBuilder();
            //Name
            if (Name != null) SB.AppendLine("Имя: " + Name.name);
            else SB.AppendLine("Имя: NONE");
            //ClassName
            if (ClassName != null) SB.AppendLine("Раса: " + ClassName.cname);
            else SB.AppendLine("Раса: NONE");
            //HP
            if (HP != null) SB.AppendLine("HP = " + HP.value);
            else SB.AppendLine("Не имеет HP, бессмертен");
            //MP
            if (MP != null) SB.AppendLine("MP = " + MP.value);
            else SB.AppendLine("Не имеет ману, не обладает магией");
            //возвращаем
            if (Weapon != null) SB.AppendLine("Оружие = " + Weapon.name + "; " + "Сила = " + Weapon.power);
            else SB.AppendLine("Не имеет оружия");
            return SB.ToString();
        }
    }
}
