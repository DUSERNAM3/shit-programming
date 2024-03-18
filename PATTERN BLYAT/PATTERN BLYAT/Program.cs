using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

class HP
{
    public int value { get; set; }
}
class MP
{
    public int value { get; set; }
}
class ClassNames
{
    public string cname { get; set; }
}
class Names
{
    public string name { get; set; }
}

class RPGStats
{
    // ХП
    public HP HP { get; set; }
    // Мана
    public MP MP { get; set; }
    // Имя
    public ClassNames ClassName { get; set; }
    public Names Name { get; set; }
    public override string ToString()
    {
        StringBuilder sb = new StringBuilder();
        //Name
        if (Name != null) sb.Append("Имя: " + Name.name + "\n");
        else sb.Append("Имя: NONE\n");
        //ClassName
        if (ClassName != null) sb.Append("Раса: " + ClassName.cname + "\n");
        else sb.Append("Имя: NONE\n");
        //HP
        if (HP != null) sb.Append("HP = " + HP.value + "\n");
        else sb.Append("Не имеет HP, бессмертен\n");
        //MP
        if (MP != null) sb.Append("MP = " + MP.value + "\n");
        else sb.Append("Не имеет ману, не обладает магией\n");
        //возвращаем
        return sb.ToString();
    }
}

class Menu
{
    public int choice;
    public void MenuFunc()
    {
        while (true)
        {
            Console.WriteLine("    Меню:\n" +
            "1) Создать персонажа класса Человек\n" +
            "2) Создать персонажа класса Нежить\n" +
            "3) Создать персонажа класса Эльф\n" +
            "4) Выход\n" +
            "Выберите желаемое действие: \n");
            choice = Convert.ToInt32(Console.ReadLine());
            Console.Clear();
            // создаем объект создателя и билдера
            RPGCreate Creator = new RPGCreate();
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
                    Console.WriteLine("Введена неправильная команда.\n Попробуйте снова");
                    break;
            }
        }
  
        
    }
}
// абстрактный класс строителя
abstract class RPGBuilder
{
    public string readname;
    public RPGStats RPGModel { get; private set; }
    public void CreateModel()
    {
        RPGModel = new RPGStats();
    }
    public abstract void SetHP();
    public abstract void SetMP();
    public abstract void SetClassName();
    public abstract void SetName();
}
// создатель
class RPGCreate
{
    public RPGStats Build(RPGBuilder RolePlay)
    {
        RolePlay.CreateModel();
        RolePlay.SetHP();
        RolePlay.SetMP();
        RolePlay.SetClassName();
        RolePlay.SetName();
        return RolePlay.RPGModel;
    }
}
// строитель для класса Человек
class Human : RPGBuilder
{
    public override void SetHP()
    {
        this.RPGModel.HP = new HP { value = 200 };
    }
    public override void SetMP()
    {
        // не используется
    }
    public override void SetClassName()
    {
        this.RPGModel.ClassName = new ClassNames { cname = "Человек" };
    }
    public override void SetName()
    {
        Console.Write("Введите имя для расы Человек: ");
        while (true)
        {
            readname = Console.ReadLine();
            Console.Clear();
            if (readname.Length > 12) Console.Write("Введенное имя превышает максимальную длину.\nПопробуйте снова.\n");
            else break;
        }
        this.RPGModel.Name = new Names { name = readname };
    }
}
// строитель для класса Нежить
class Undead : RPGBuilder
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
            if (readname.Length > 12) Console.Write("Введенное имя превышает максимальную длину.\nПопробуйте снова.\n");
            else break;
        }
        this.RPGModel.Name = new Names { name = readname };
    }
}
//Строитель для класса Эльф
class Elf : RPGBuilder
{
    public override void SetHP()
    {
        this.RPGModel.HP = new HP { value = 100 };
    }
    public override void SetMP()
    {
        this.RPGModel.MP = new MP { value = 100 };
    }
    public override void SetClassName()
    {
        this.RPGModel.ClassName = new ClassNames { cname = "Эльф" };
    }
    public override void SetName()
    {
        Console.Write("Введите имя для расы Эльф: ");
        while (true) {
            readname = Console.ReadLine();
            Console.Clear();
            if (readname.Length > 12) Console.Write("Введенное имя превышает максимальную длину.\nПопробуйте снова.\n");
            else break;
        }
        this.RPGModel.Name = new Names { name = readname };
    }
}

class None : RPGBuilder
{
    public override void SetHP(){}
    public override void SetMP(){}
    public override void SetClassName(){}
    public override void SetName(){}
}

class Program
{
    static void Main(string[] args)
    {
        Menu menu = new Menu();
        menu.MenuFunc();
        Console.Read();
    }
}