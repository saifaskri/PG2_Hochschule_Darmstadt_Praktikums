//#include <iostream>

//class SteuerBrechnen{

//public:
//    virtual void berechen(double amount);

//};

//class USACountry : public SteuerBrechnen{

//public:
//     void berechen(double amount);

//};

//class UKCountry : public SteuerBrechnen{

//public:
//     void berechen(double amount);

//};
//class INCountry: public SteuerBrechnen{

//public:
//     void berechen(double amount);

//};

//class TUNCountry: public SteuerBrechnen{

//public:
//     void berechen(double amount);

//};


//class TaxCalculator {

//public:
//    double CalculateTax(double amount, std::string country) {

//        double taxAmount = 0.0;

//        SteuerBrechnen *s = nullptr  ;

//        if (country == "USA") {
//            s = new USACountry();
//            // Berechnen der Steuer gemäß den Regeln der USA
//        } else if (country == "UK") {
//            s = new UKCountry();

//            // Berechnen der Steuer gemäß den Regeln des Vereinigten Königreichs
//        } else if (country == "IN") {
//            s = new INCountry();
//            // Berechnen der Steuer gemäß den Regeln Indiens
//        }
//        else if (country == "TUN") {
//                   s = new INCountry();
//                   // Berechnen der Steuer gemäß den Regeln Indiens
//               }

//            s->berechen(amount);

//        return taxAmount;
//    }
//};

//int main() {
//    TaxCalculator taxCalculator;

//    double amount = 100.0;
//    std::string country = "USA";
//    double taxAmount = taxCalculator.CalculateTax(amount, country);

//    std::cout << "Tax amount: " << taxAmount << std::endl;

//    return 0;
//}









#include <iostream>
#include <vector>
#include <stdexcept>



class Customer {

    protected:
        std::vector<Customer*> list;

    public:

        virtual void AddCustomer(Customer* obj);

        int Count() const {
            return list.size();
        }

};


class SpecialCustomers : public Customer {


    public:
        void AddCustomer(Customer* obj)  {
            list.push_back(obj);
        }


};



class TopNCustomers : public Customer {
    private:
        int maxCount = 5;
    public:
        void AddCustomer(Customer* obj)  {
            if (Count() < maxCount) {
                list.push_back(obj);
            }
            else {
                throw std::runtime_error("Only " + std::to_string(maxCount) + " customers can be added.");
            }
        }
};

int main() {

    Customer* sc = nullptr;

    sc = new TopNCustomers();

    for (int i = 0; i < 10; i++) {
        Customer* obj = new Customer();
        try {
            sc->AddCustomer(obj);
        }
        catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
            delete obj;
        }
    }

    delete sc;
    return 0;
}










