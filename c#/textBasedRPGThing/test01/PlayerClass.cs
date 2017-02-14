using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace test01
{
    class PlayerClass : Entity
    { //This defines the player class, for now has only defence and attack as variables

        public int gold;

        public void setGold(int gold) { this.gold = gold; }
        public int getGold() { return this.gold; }

        private void AssignStat(PlayerClass player, string opt)
        {
            if (opt == "S" || opt == "s")
                player.stats.setStr(player.stats.getStr() + 1);
            if (opt == "D" || opt == "d")
                player.stats.setDex(player.stats.getDex() + 1);
            if (opt == "C" || opt == "c")
                player.stats.setChr(player.stats.getChr() + 1);
            if (opt == "L" || opt == "l")
                player.stats.setLck(player.stats.getLck() + 1);
                    
        }

       public void CreatePlayer(PlayerClass player,int points)
        {    //int points is how many points can be invested into a character's stat sheet
            string temp;
            Console.WriteLine("Create character:");

            Console.WriteLine("\nInsert name:");
            temp = Console.ReadLine(); // reads new name. sets it to temp
            player.setName(temp);

            Console.WriteLine("\nInsert Class:"); 
            temp = Console.ReadLine(); //reads new class. sets it to temp
            player.setSpec(temp);

            UI a = new UI(); //retypes player stats
            while (points > 0) //start distributing points
            {
                Console.WriteLine("Remaining points: {0}", points);
                a.PrintStats ( player );
                Console.WriteLine( "Type in the initial of the stat you want to improve:" );
                string opt = "default";
                while (opt != "S" && opt != "D" && opt != "C" && opt != "L" )//main 4 stats, can be changed at any point
                     opt = Console.ReadLine(); 
                AssignStat(player, opt);
                points--; // decrement to exit the loop, after a point has been assigned
                Console.Clear();
            }
            this.setGold(0);
            Console.WriteLine("Character creation successful!\n");
            a.PrintEntity(player);
            a.PrintStats(player);
        }
    }
}
