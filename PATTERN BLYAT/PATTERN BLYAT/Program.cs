using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
namespace PATTERN
{
    class Program
    {
        static void Main(string[] args)
        {
            Menu menu = new Menu();
            menu.MenuFunc();
            Console.Read();
        }
    }
}