using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PATTERN;

namespace PATTERN
{
    internal class Menu
    {
        public int choice;
        public void MenuFunc()
        {
            while (true)
            {
                Console.Write("    Меню:\n" +
                "1) Создать персонажа класса Человек\n" +
                "2) Создать персонажа класса Нежить\n" +
                "3) Создать персонажа класса Эльф\n" +
                "4) Выход\n" +
                "Выберите желаемое действие: ");
                choice = Convert.ToInt32(Console.ReadLine());
                Console.Clear();
                // создаем объект создателя и билдера
                RPGCreator Creator = new RPGCreator();
                RPGBuilder builder;
                switch (choice)
                {
                    case 1:
                        builder = new Human();
                        RPGStats Human = Creator.Build(builder);
                        Console.WriteLine(Human.ToString());
                        break;
                    case 2:
                        builder = new Undead();
                        RPGStats Undead = Creator.Build(builder);
                        Console.WriteLine(Undead.ToString());
                        break;
                    case 3:
                        builder = new Elf();
                        RPGStats Elf = Creator.Build(builder);
                        Console.WriteLine(Elf.ToString());
                        break;
                    case 4: return;
                    default:
                        Console.WriteLine("Введена неправильная команда.\n\tПопробуйте снова");
                        break;
                }
            }
        }

    }
}
