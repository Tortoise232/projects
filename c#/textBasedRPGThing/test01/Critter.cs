using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace test01
{
    class Critter : Entity 
    //this is to be used as a template for neutral/hostile mobs
    {
        public Critter(int plevel)
        {
            this.CritterInit(plevel);
        }

        public string NameGen()
        {
            /*
            char[] name1 = {'N','a','m','e'}
            string name = new string(name1);
            char temp;
            temp = (char)r.Next(65, 90);
            int i;
            for (i = 1; i <= r.Next(3, 12); ++i)
            {
                if (name[i - 1] == 'A' || name[i - 1] == 'E' || name[i - 1] == 'I' || name[i - 1] == 'O' || name[i - 1] == 'U')
                    do { name[i] = (char)r.Next(65, 90); } while (name[i] == 'A' || name[i] == 'E' || name[i] == 'I' || name[i] == 'U' || name[i] == 'Y');
               
            } */
            return "Gaichi";
        }

    public void CritterStatAssign(int points)
        {//only assigns strength and dexterity, lel but is used for random assigning of points in critters
            Random r = new Random();
            while (points > 0)
            {

                if (r.Next() % 2 == 0)
                    this.stats.setStr(this.stats.getStr() + 1);
                else
                    this.stats.setDex(this.stats.getDex() + 1);
                points--;

            }
        }  

     public void CritterInit(int plevel) //asking for player level for hp, and point assignment
        {   // some Critter Generation, unfortunately all of them are named Gachi
            this.setLevel(plevel);
            this.setHp(plevel * 3 + plevel);
            Random r = new Random();
            this.CritterStatAssign(r.Next(plevel, plevel * 3));
            this.setName(this.NameGen());
            this.updateAttDef();
            
        }
                 
   }
            
    }


