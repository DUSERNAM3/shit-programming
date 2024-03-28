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
        RPGProduct Character = new RPGProduct();
        // Меню создания
        public void MenuFunc()
        {

            while (true)
            {
                // создаем объект создателя и билдера
                RPGCreator Creator = new RPGCreator();
                RPGBuilder builder;
                Console.Write("    Меню:\n" +
                "1) Создать персонажа класса Человек\n" +
                "2) Создать персонажа класса Нежить\n" +
                "3) Создать персонажа класса Эльф\n" +
                "4) Переход к действиям созданного персонажа\n" +
                "5) Выход\n" +
                "Выберите желаемое действие: ");
                choice = Convert.ToInt32(Console.ReadLine());
                Console.Clear();
                switch (choice)
                {
                    case 1:
                        builder = new Human();
                        Creator.Build(builder);
                        Character = builder.GetResult();
                        Console.WriteLine(Character.ToString());
                        break;
                    case 2:
                        builder = new Undead();
                        Creator.Build(builder);
                        Character = builder.GetResult();
                        Console.WriteLine(Character.ToString());
                        break;
                    case 3:
                        builder = new Elf();
                        Creator.Build(builder);
                        Character = builder.GetResult();
                        Console.WriteLine(Character.ToString());
                        break;
                    case 4:
                        ActFunc(Character);
                        break;
                    case 5: return;
                    default:
                        Console.WriteLine("Введена неправильная команда.\n\tПопробуйте снова");
                        break;
                }
            }
        }
        public void ActFunc(RPGProduct Player)
        {
            RPGCreator Creator = new RPGCreator();
            RPGBuilder builder;
            // создаем манекен
            builder = new Dummy();
            Creator.Build(builder);
            RPGProduct Dummy = builder.GetResult();
            while (true)
            {
                Console.WriteLine(Player.ToString());
                Console.WriteLine(Dummy.ToString());
                Console.Write("    Действия с манекеном:\n" +
                "1) Атаковать\n" +
                "2) Атаковать манекеном персонажа\n" +
                "3) Исцелиться от манекена\n" +
                "4) Исцелить манекен\n" +
                "5) Вернуться назад\n" +
                "Выберите желаемое действие: ");
                choice = Convert.ToInt32(Console.ReadLine());
                Console.Clear();
                switch (choice)
                {
                    case 1:
                        Player.Attack(Dummy);
                        break;
                    case 2:
                        Dummy.Attack(Player);
                        break;  
                    case 3:
                        Dummy.SetStrategy(builder.healer);
                        Dummy.Heal(Player);
                        Dummy.SetStrategy(builder.warrior);
                        break;
                    case 4:
                        Player.Heal(Dummy);
                        break;
                    case 5:
                        return;
                    default:
                        Console.WriteLine("Введена неправильная команда.\n\tПопробуйте снова");
                        break;
                }
            }
        }
    }
}
