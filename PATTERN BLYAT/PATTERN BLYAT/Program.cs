using System;
using System.Collections.Generic;
using System.Linq;
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
class Program
{
    static void Main(string[] args)
    {
        // содаем объект создателя
        RPGCreate Creator = new RPGCreate();
        // создаем билдер для класса Человек
        RPGBuilder builder = new Human();
        // билдим Человек
        RPGStats Human = Creator.Build(builder);
        Console.WriteLine(Human.ToString());
        // создаем билдер для класса Нежить
        builder = new Undead();
        // билдим Нежить
        RPGStats Undead = Creator.Build(builder);
        Console.WriteLine(Undead.ToString());
        // создаем билдер для класса Нежить
        builder = new Elf();
        // билдим Нежить
        RPGStats Elf = Creator.Build(builder);
        Console.WriteLine(Elf.ToString());

        Console.Read();
    }
}
// абстрактный класс строителя
abstract class RPGBuilder
{
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
// строитель для ржаного хлеба
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
        this.RPGModel.Name = new Names { name = "Player1" };
    }
}
// строитель для пшеничного хлеба
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
        this.RPGModel.Name = new Names { name = "Player2" };
    }
}
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
        this.RPGModel.Name = new Names { name = "Player3" };
    }
}