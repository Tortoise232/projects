using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace test01
{
    public class UI
    { 
        public void PrintEntity(Entity x)
        {
            Console.WriteLine("Behold, the mighty {0}, level: {1}, class: {2}, HP:{3}", x.getName(), x.getLevel(), x.getSpec(), x.getHp());
        }

        public void PrintStats(Entity x)
        {
            Console.WriteLine(x.getName());
            Console.WriteLine("___________");
            Console.WriteLine("STRENGTH: {0}", x.stats.getStr());
            Console.WriteLine("DEXTERITY: {0}", x.stats.getDex());
            Console.WriteLine("CHARISMA: {0}", x.stats.getChr());
            Console.WriteLine("LUCK: {0}", x.stats.getLck());
            Console.WriteLine("___________");
        }
        public void DecisionPrint()
        {

        }

    }
}
