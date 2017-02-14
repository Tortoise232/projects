using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace test01
{
    class AI
    { public void decideCreep(Critter a, PlayerClass b)
        {
            if (EvaluatePlayer(a, b) == 1)
            {
                   
            }
        }
        public int EvaluatePlayer(Critter a, PlayerClass b)
        {//this function determines the action of the creep, if it will att or def 
         // returns 1 for att. 2 for def

            if (b.getAtt() - a.getDef() > a.getHp())
                return 2;
            else
                return 1;
        
        }

    }
}
