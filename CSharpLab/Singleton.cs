using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Singleton
{
    class Nested
    {
        internal static Singleton s_Instance = new Singleton();
    }

    public static Singleton Instance
    {
        get { return Nested.s_Instance; }
    }

    static void Main(string[] args)
    {
        //创建实例
        Singleton inst1 = Singleton.Instance;
        Singleton inst2 = Singleton.Instance;

        System.Console.WriteLine("compare 2 singleton");
        System.Diagnostics.Debug.Assert(inst1 == inst2, "compare 2 singleton");
        System.Console.ReadLine();
    }
}
