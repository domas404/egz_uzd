#include <iostream>

using namespace std;

// Abstrakti automobilio klase
class Car{
    protected:
        int production_year; // production year
        int h_power; // horse power
        string fuel_type;
    public:
        Car(){};
        Car(int year, int power, string fuel){
            production_year = year;
            h_power = power;
            fuel_type = fuel;
        }
        virtual void setYear(int year) = 0;
        virtual void setPower(int power) = 0;
        virtual void setFuel(int fuel) = 0;
};
// Isvestine klase
class BMW: public Car{
    private:
        string model;
    public:
        BMW(){};
        // konstruktorius
        BMW(string model, int year, int power, string fuel) :Car(year, power, fuel){
            this->model = model;
        }
        // copy konstruktorius
        BMW(const BMW& m){
            this->model = m.model;
            this->production_year = m.production_year;
            this->h_power = m.h_power;
            this->fuel_type = m.fuel_type;
        }
        // copy priskyrimo operatorius
        BMW& operator=(const BMW& m){
            if(this == &m)
                return *this;
            this->model = m.model;
            this->production_year = m.production_year;
            this->h_power = m.h_power;
            this->fuel_type = m.fuel_type;
        }
        // move konstruktorius
        BMW(BMW&& m): model{m.model}{
            m.model = "";
            m.production_year = 0;
            m.h_power = 0;
            m.fuel_type = "";
        }
        // move priskyrimo operatorius
        BMW& operator=(BMW&& m){
            if(&m == this)
                return *this;
            model = m.model;
            production_year = m.production_year;
            h_power = m.h_power;
            fuel_type = m.fuel_type;
            m.model = "";
            m.production_year = 0;
            m.h_power = 0;
            m.fuel_type = "";
            return *this;
        }
        // destruktorius
        ~BMW(){
            cout << "Iskviestas klases destruktorius." << endl;
        };
        // setter'iai
        void setModel(string model){
            this->model = model;
        }
        void setYear(int year){
            this->production_year = year;
        }
        void setPower(int power){
            this->h_power = power;
        }
        void setFuel(int fuel){
            this->fuel_type = fuel;
        }
        // getter'iai
        string getModel(){
            return model;
        }
        int getYear(){
            return production_year;
        }
        int getPower(){
            return h_power;
        }
        string getFuel(){
            return fuel_type;
        }
    
};

int main(){
    BMW model1 = BMW("3-series", 2010, 120, "Diesel");
    BMW model2 = BMW("5-series", 2020, 220, "Hybrid");
    
    // naudojamas copy konstruktorius
    BMW model3;
    model3 = model1;
    cout << model3.getModel() << " " << model3.getYear() << " " << model3.getPower() << " " << model3.getFuel() << endl;
    cout << model1.getModel() << " " << model1.getYear() << " " << model1.getPower() << " " << model1.getFuel() << endl;

    // naudojamas move konstruktorius
    BMW model4;
    model4 = move(model1);
    cout << model4.getModel() << " " << model4.getYear() << " " << model4.getPower() << " " << model4.getFuel() << endl;
    cout << model1.getModel() << " " << model1.getYear() << " " << model1.getPower() << " " << model1.getFuel() << endl;
}