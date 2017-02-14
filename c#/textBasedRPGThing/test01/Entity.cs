using System;

public class Entity
{ public class Stats
    {
        public int str;
        public int dex;
        public int chr;
        public int lck;
        //Constructor defaults every stat sheet to basic 1-1-1-1
        public void setStr(int str) { this.str = str; }
        public int getStr() { return this.str; }

        public void setDex(int dex) { this.dex = dex; }
        public int getDex() { return this.dex; }

        public void setChr(int chr) { this.chr = chr; }
        public int getChr() { return this.chr; }

        public void setLck(int lck) { this.lck = lck; }
        public int getLck() { return this.lck; }
        
        public Stats()
        { str = dex = chr = lck = 1; }
    }
    //Calculated by strength and dexterity
    public float defence;
    public float attack;

    public float getAtt() { return this.attack; }
    public void setAtt(float att) { this.attack = att; }

    public float getDef() { return this.defence; }
    public void setDef(float def) { this.defence = def; }

    public void updateAttDef()
    { //This updates Attack and Defence depending on strengh & dexterity, 1:1 ratio
        this.setDef(this.stats.getDex());
        this.setAtt(this.stats.getStr());
    }

    public string name;
    public float hp;
    public int xp;
    public int level;
    public Stats stats;
    public string spec;

    public void setName(string name) { this.name = name;}
    public string getName() { return this.name; }
    
    public void setHp(float hp) { this.hp = hp; }
    public float getHp() { return this.hp; }

    public void setLevel(int level) { this.level = level; }
    public int getLevel() { return this.level; }

    public void setXp(int xp) { this.xp = xp; }
    public int getXp() { return this.xp; }

    public void setSpec(string spec) { this.spec = spec; }
    public string getSpec() { return this.spec; }


    //Constructor  defines initial state of a created object 
    public Entity()
    {
        this.stats = new Stats();
        attack = this.stats.getStr();
        defence = this.stats.getDex();
        spec = "Farmer";
        name = "Bob";
        hp = xp = level = 1;
    }

}


