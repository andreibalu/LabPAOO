// Example program
#include <iostream>
#include <string>

using namespace std;



class Computer{
    
  protected:
    string nume;
    int nrcomp;

  public:
    Computer(string n , int c):nume(n),nrcomp(c){nr++; cout<<"computer object created\n";};
    static int nr;  //pt a stii cate computere exista
    
    void getNrComp()
    {
        cout<<"Computer has "<<nrcomp<<" parts"<<"\n";  
    }
    
    void setNrComp(int a)
    {
        nrcomp = a;   
    }
    
    void getNume()
    {
        cout<<"Computer is called "<<nume<<"\n";
    }

    static void getNrOfComps()
    {
        cout << "There is a total of " << nr << " computers \n";
    }
    virtual ~Computer()
    {
        cout<<"computer object destroyed\n";   
    }

    Computer& operator=(const Computer& rhs)
    {
        if (this == &rhs) return *this;
        nume = rhs.nume;
        nrcomp = rhs.nrcomp;
        return *this;
    }
    
  private:
    Computer(const Computer& other); //uncopyable
};

int Computer::nr = 0;


int main()
{
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
    c2.getNrComp();   
}
