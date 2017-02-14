using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace test01
{
    class Program
    {   static void testStuff()
        {// testing a Str geter and setter
            Entity x = new Entity();
            UI ui = new UI();
            while (1 == 1)
            {
                ui.PrintStats(x);
                ui.PrintEntity(x);
                x.stats.setStr(Convert.ToInt32(Console.ReadLine()));
                if (x.stats.getStr() == 0)
                    break;
            }
        }
 

        static void Main(string[] args)
        {
            Executor ex = new Executor();
            PlayerClass x = new PlayerClass();
            PlayerClass y = new PlayerClass();
            y.setHp(5);
            x.setHp(4);
            x.CreatePlayer(x, 5);
            //y.CreatePlayer(y, 5);
            x.updateAttDef();
            x.setLevel(300);
            //y.updateAttDef();
            Critter alex = new Critter(x.getLevel());
            UI ui = new UI();
            ui.PrintEntity(alex);
            ui.PrintStats(alex);
            Console.ReadKey();
            //ex.fight_sequence_PvP(x, y);
            //testStuff();
        }
    }
}


