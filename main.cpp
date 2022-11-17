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
        cout<<nrcomp<<"\n";  
    }
    
    void setNrComp(int a)
    {
        nrcomp = a;   
    }
    
    void getNume()
    {
        cout<<nume<<"\n";
    }
    virtual ~Computer()
    {
        cout<<"computer object destroyed\n";   
    }
    
  private:
    Computer(const Computer& other); //uncopyable
    Computer& operator=(const Computer&);//copy assignment not allowed
    
 
};

int Computer::nr = 0;


int main()
{
    Computer c("c1",5);
    
    c.getNume();
    c.getNrComp();
    c.setNrComp(3);
    c.getNrComp();
    
}
