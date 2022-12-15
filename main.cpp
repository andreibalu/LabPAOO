// https://github.com/andreibalu/LabPAOO
#include <iostream>
#include <string>
#include <memory>

using namespace std;



class Computer{

  protected:
    string nume;
    int nrcomp;     //nr componente
    bool asamblat;

  public:
    Computer(string n , int c):nume(n),nrcomp(c),asamblat(false) {nr++; cout<<"*****computer object created*******\n";};
    Computer(const Computer &c):nume(c.nume),nrcomp(c.nrcomp) {cout<<"****Computer copy-constr****";};
    Computer() = default;
    static int nr;  //pt a stii cate computere exista

    void getNume()
    {
        cout<<nume<<"\n";
    }

    void getNrComp()
    {
        cout<<nrcomp<<"\n";
    }

    void setNrComp(int a)
    {
        nrcomp = a;
    }

    void setStatus(bool  r)
    {
        this->asamblat=r;
    }

    void checkStatus()
    {
        if(this->asamblat)
            cout<<"Comp asamblat \n";
        else
            cout<<"Comp dezasamblat \n";
    }

    static void getNrOfComps()
    {
        cout << "There is a total of " << nr << " computers \n";
    }
    virtual ~Computer()
    {
        cout<<"******computer object destroyed******\n";
    }

    Computer& operator=(const Computer& rhs)
    {
        if (this == &rhs) return *this;
        nume = rhs.nume;
        nrcomp = rhs.nrcomp;
        return *this;
    }
/*
  private:
    Computer(const Computer& other); //uncopyable*/
};

void asamblare(Computer *c)
{
    cout<<"Computerul a fost asamblat \n";
    c->setStatus(true);
}

void dezasamblare(Computer *c)
{
    cout<<"Computerul a fost  dezasamblat \n";
    c->setStatus(false);
}


Computer* createComputerInstance(string s, int c)
{
    return (new Computer(s,c));
}

int Computer::nr = 0;


class GamingComputer: public Computer
{
    private:
    std::shared_ptr<Computer> computerPtr;
    GamingComputer(const GamingComputer& other); //uncopyable

  public:
    explicit GamingComputer(Computer *c): computerPtr(c, dezasamblare) {asamblare(computerPtr.get());}


};




int main()
{   /*
    Computer c1("c1",5);        //obiectul c1
    Computer c2("c2", 6);       //obiectul c2
    Computer::getNrOfComps();

    c1.getNume();
    c1.getNrComp();
    c2.getNume();
    c2.getNrComp();
    c1.setNrComp(3);
    c1.getNrComp();

    c2 = c1;                   //c2 devine c1
    c2.getNume();
    c2.getNrComp();*/
    cout << "\n ////// \n";     //tema 3


//    Computer ac1("autoc1",5);
    auto_ptr<Computer> autoComp1(createComputerInstance("autoc1",5));
    autoComp1->getNume();

    shared_ptr<Computer> sharedComp1(createComputerInstance("shc1",5));
    shared_ptr<Computer> sharedComp2(sharedComp1);
    shared_ptr<Computer> sharedComp3(sharedComp1);
    cout<<"\n nr shared ptr "<<sharedComp1.use_count()<<"\n";   //3 pointeri shared spre computerul creat in sharedcomp1

    auto_ptr<Computer> autoComp2(autoComp1);
    autoComp2->getNume();
    //autoComp1->getNume();             //nu va merge deoarece dupa autoComp2(autoComp1), autoComp1 va deveni null





    Computer c1gaming("g1",5);
    c1gaming.checkStatus();

    GamingComputer g1(&c1gaming);
    c1gaming.checkStatus();

//    GamingComputer g2(g1);      //nu merge copy
//    c1gaming.checkStatus();

    //se dezasambleaza automat
}
