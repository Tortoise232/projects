using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace test01
{
     class Executor
    { // Class executes different actions within the game.
        public void decidePvE_Player(PlayerClass a,Critter b)
        {
            char input;
            Console.WriteLine("1.Attack\n2.Defend\n");
            input = Convert.ToChar(Console.Read());
            if (input == '1')
            {
                Console.WriteLine("{0} Attacked {1} for {2}", a.getName(), b.getName(), a.getAtt() - b.getDef());
                b.setHp(b.getHp() + b.getDef() - a.getAtt());
            }
            else
                if (input == '2')
                a.setDef(a.getDef() + 1);


        }

        public void decidePvE_Critter(Critter a, PlayerClass b)
        {

        }


        public void decidePvP(PlayerClass a, PlayerClass b)
        {/* decide 1v1 is the first class that simulates combat
            it has only one player attacking another player or increasing their defence (permanently) by 1
            should be changed!!! */
           
            char input;
            Console.WriteLine("1.Attack\n2.Defend\n");
            input = Convert.ToChar(Console.Read());

            if (input == '1')
            {// if input = 1, attacks player b
                Console.WriteLine("{0} Attacked {1} for {2}", a.getName(), b.getName(), a.getAtt() - b.getDef());
                b.setHp(b.getHp() + b.getDef() - a.getAtt());

            }
            else
                if (input == '2')
                a.setDef(a.getDef() + 1);
        }

        public void fight_sequence_PvP(PlayerClass a, PlayerClass b)
        {   //function computes 1v1 between any 2 "PlayerClass" entities; 
            //uses UI to print their status, uses decide function to pick between possible actions
            UI ui = new UI();
            int turn = 0; // if turn is 0 , a goes first. otherwise b goes first
            if (a.stats.getChr() > b.stats.getChr())
                turn = 0;
            else
                turn = 1;
            while (a.getHp() > 0 && b.getHp() > 0)
            {
                if (turn == 1)
                {
                    ui.PrintEntity(a);
                    ui.PrintEntity(b);
                    decidePvP(a, b);
                    decidePvP(b, a);
                    
                }
            }
        }
        public Executor()
        {}
    }
}   
       
        
