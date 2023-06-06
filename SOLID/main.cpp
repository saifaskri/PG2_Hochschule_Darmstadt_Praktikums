#include <iostream>
#include <thread>
#include <chrono>

void threadFunction() {
    std::cout << "Thread gestartet" << std::endl;

    // Pausieren des Threads für 2 Sekunden
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Thread fortgesetzt" << std::endl;
}

int main() {
    int a;

    std::cout << "Hauptthread gestartet" << std::endl;

    // Erstellen und Starten des Threads
    std::thread t(threadFunction);

    // Warten auf die Beendigung des Threads
    //t.join();

    std::cout << "Hauptthread beendet" << std::endl;

    std::cin >> a;
    //return 0;
}




















#include <iostream>
#include <list>

using namespace std;

class BaseUser{
public:
    virtual void update() = 0;
};

class EmailUser : public BaseUser{
public:
    void update(){
       cout<<"notify Email User "<<endl;
    }
};

class SMSUser : public BaseUser{

public:
    void update(){
        cout<<"notify SMS User "<<endl;
    }
};



class NotificationService{

    list<BaseUser*> usersList;

public:

    void addNewUser(BaseUser* user){
        usersList.push_back(user);
    }

    void removeUser(){

    }

    void notify(){
        for(auto user : usersList) {
            user->update();
        }
    }
};

class Product{
public:
    int id;
    string name;
    //......
};

class Store{
private:
    list<Product*> productsList;
    NotificationService notification;

public:


    void addNewUserToBeNotificated(BaseUser* user){
        notification.addNewUser(user);
        //notification.usersList.push_back(user);

    }

    void addNewItemToTheStore(Product* prod){

        productsList.push_back(prod);

        //notificate all subscribed Users after adding new Product
        notification.notify();
    }


};




int main2() {

    Store store;

    BaseUser *emialuser  = new EmailUser();
    store.addNewUserToBeNotificated(emialuser);

    store.addNewUserToBeNotificated(new SMSUser());
    store.addNewUserToBeNotificated(new EmailUser());


    store.addNewItemToTheStore(new Product());




    return 0;
}

























//#include <iostream>
//#include <string>

//class EmailNotifier {
//public:
//    void Notify(const std::string& email, const std::string& message) {
//        // Send email here
//        std::cout << "Email sent to: " << email << std::endl;
//        std::cout << "Message: " << message << std::endl;
//    }
//};

//class UserManager {
//private:
//    EmailNotifier notifier;

//public:
//    void CreateUser(const std::string& userid, const std::string& password, const std::string& email) {
//        // Create user here
//        notifier.Notify(email, "User created successfully!");
//    }

//    void ChangePassword(const std::string& userid, const std::string& oldpassword, const std::string& newpassword) {
//        // Change password here
//        std::string email = GetUserEmail(userid); // Assuming there's a method to retrieve user's email
//        notifier.Notify(email, "Password changed successfully");
//    }

//    std::string GetUserEmail(const std::string& userid) {
//        // Retrieve user's email from database or other data source
//        // Placeholder implementation
//        if (userid == "user123") {
//            return "user@example.com";
//        } else {
//            return "";
//        }
//    }
//};





















//#include <iostream>
//#include <stdexcept>

//class IOrder {
//public:
//    virtual void Purchase() = 0;
//    virtual void ProcessCreditCard() = 0;
//};

//class OnlineOrder : public IOrder {
//public:
//    void Purchase() override {
//        // Kauf durchführen
//    }

//    void ProcessCreditCard() override {
//        // Zahlung per Kreditkarte verarbeiten
//    }
//};

//class InpersonOrder : public IOrder {
//public:
//    void Purchase() override {
//        // Kauf durchführen
//    }

//    void ProcessCreditCard() override {
//        throw std::logic_error("Für einen persönlichen Kauf nicht erforderlich.");
//    }
//};

//int main() {
//    IOrder* onlineOrder = new OnlineOrder();
//    onlineOrder->Purchase();
//    onlineOrder->ProcessCreditCard();
//    delete onlineOrder;

//    IOrder* inPersonOrder = new InpersonOrder();
//    inPersonOrder->Purchase();
//    inPersonOrder->ProcessCreditCard();
//    delete inPersonOrder;

//    return 0;
//}



















































//#include <iostream>
//#include <stdexcept>

//class OrderProcessor {
//public:
//    virtual bool ValidatePaymentInfo() = 0;
//    virtual bool ValidateShippingAddress() = 0;
//    virtual void ProcessOrder() = 0;
//};

//class OnlineOrder : public OrderProcessor {
//public:
//    bool ValidatePaymentInfo() override {
//        return true;
//    }

//    bool ValidateShippingAddress() override {
//        return true;
//    }

//    void ProcessOrder() override {
//        // Bestellung hier durchführen, wenn alles in Ordnung ist.
//    }
//};

//class CashOnDeliveryOrder : public OrderProcessor {
//public:

//    bool ValidatePaymentInfo() override {
//        //throw std::runtime_error("Not implemented");
//        std::cout << "ValidatePaymentInfo wird hier nicht benoetigt." << std::endl;
//        return true;
//    }

//    bool ValidateShippingAddress() override {
//        //throw std::runtime_error("Not implemented");
//        std::cout << "ValidateShippingAddress wird hier nicht benoetigt." << std::endl;
//        return true;
//    }

//    void ProcessOrder() override {
//        // Bestellung hier durchführen, wenn alles in Ordnung ist.
//    }
//};

//int main() {
//    OrderProcessor* order = nullptr;

//    order = new OnlineOrder();
//    order->ValidatePaymentInfo();
//    order->ValidateShippingAddress();
//    order->ProcessOrder();

//    order = new CashOnDeliveryOrder();
//    // Die folgenden Methodenaufrufe werden eine Ausnahme auslösen, da sie nicht implementiert sind.
//    order->ValidatePaymentInfo();
//    order->ValidateShippingAddress();
//    order->ProcessOrder();

//    delete order;
//    return 0;
//}
















































//#include <iostream>
//#include <string>

//class Apple {
//public:
//    virtual std::string GetColor() {
//        return "Red";
//    }
//};

//class Orange : public Apple {
//public:
//    std::string GetColor() override {
//        return "Orange";
//    }
//};

//int main() {
//    Apple* apple = new Orange();
//    std::cout << "Die Farbe des neu erzeugten Apple-Objektes ist " << apple->GetColor() << std::endl;
//    delete apple;

//    return 0;
//}











































//#include <iostream>
//#include <vector>
//#include <stdexcept>

//class Customer {
//public:
//    virtual void AddCustomer(Customer* ){};
//    virtual void x(Customer* ){};
//    virtual void y(Customer* ){};
//    virtual void f(Customer* ){};


//    int Count() const {
//        return list.size();
//    }

//protected:
//    std::vector<Customer*> list; //was heisst protected
//};



//class SpecialCustomers : public Customer {

//public:
//    void AddCustomer(Customer* obj)  {
//        list.push_back(obj);
//    }

//};



//class TopNCustomers : public Customer {

//private:
//    int maxCount = 0;
//public:
//    void AddCustomer(Customer* obj)  {
//        if (Count() < maxCount) {
//            list.push_back(obj);
//        }
//        else {
//            throw std::runtime_error("Only " + std::to_string(maxCount) + " customers can be added.");
//        }
//    }
//};

//int main() {


//    //TopNCustomers *tp = new TopNCustomers();

//    std::string CustomerType;
//    Customer* obj;

//    for (int i = 0; i < 10; i++) {
//        std::cout<<"geben Sie Customer Type ein"<<std::endl;
//        std::cin>> CustomerType;

//        if(CustomerType == "TopN"){
//            obj = new TopNCustomers();
//        }else if(CustomerType == "Special"){
//            obj = new SpecialCustomers();
//        }else{
//            continue;
//        }

//        try {
//            obj->AddCustomer(obj);
//        }

//        catch (const std::runtime_error& e) {
//            std::cout << e.what() << std::endl;
//            delete obj;
//        }


//    }

//    //delete sc;
//    return 0;
//}

























//#include <iostream>
//#include <vector>
//#include <string>

//class Car {
//public:
//    std::string Name;
//    virtual  void  CalculateMileage(){};
//    virtual ~Car(){} ; // Add virtual destructor

//};

//class AudiCar : public Car {
//public:
//    void CalculateMileage() {
//        std::cout << "Mileage of the car " << Name << " is 10M" << std::endl;
//    };
//    void hallo (){};
//};

//class MercedecCar : public Car {
//public:
//    void CalculateMileage() {
//        std::cout << "Mileage of the car " << Name << " is 20M" << std::endl;
//    };
//};


//class MileageCalculator {
//private:

//    std::vector<Car*> _cars ;
//public:

//    MileageCalculator(const std::vector<Car*> cars) : _cars(cars) {}

//    void CalculateMileage() {
//        for (const auto& car : _cars) {
//            car->CalculateMileage();
//        }
//    }
//};

//int main() {


//    std::vector<Car*> cars;

//    AudiCar *ac = new AudiCar();
//    ac->Name = "Audi";
//    MercedecCar *mc = new MercedecCar();
//    mc->Name = "Mercedes";

//    cars.push_back(ac);
//    cars.push_back(mc);

//    MileageCalculator calculator(cars);
//    calculator.CalculateMileage();

//    return 0;
//}






























////#include <iostream>
//// class LAND{
////     public:
////     virtual double calculate(float amount);
//// };



////class USA_LAND : public LAND{
////public:
////    double calculate(float amount){

////    };
////};

////class UK_LAND : public LAND {
////public:
////    double calculate(float amount){
////       return 5;
////    };
////};

////class DE_LAND : public LAND {
////public:
////    double calculate(float amount){
////       return 5;
////    };
////};



////class TaxCalculator {
////public:
////    double CalculateTax(double amount, std::string country) {

////        LAND *l;

////        double taxAmount = 0.0;
////        if (country == "USA") {
////           l = new USA_LAND();
////        }else if (country == "UK") {
////           l = new UK_LAND();
////        }else if (country == "DE") {
////            l = new DE_LAND();
////        }

////        return l->calculate(amount);
////    }

////};



//// This code violates the SRP of SOLID
//// It is not really functional
//// Can you identify the problem?
//// What do you propose to fix it?

//#include <iostream>
//#include <list>
//#include <string>
//#include <vector>
//using namespace std;


//class Customer {

//public:
//     string CustomerID;
//     string CompanyName;
//     string ContactName;
//     string Country;
//};

//class NorthwindEntities {
//    // Dummy
//public:
//    list<Customer> Customers;
//    list<Customer> GetAllCustomers(){
//        return Customers;
//    }
//    Customer GetCustomerByID(string customerid){
//        //return db->Customers.find(customerid);
//        return Customers.front();
//    }
//};

//class CustomerDataService{


//public:
//    string ExportCustomerData( list<Customer> data){
//        string sb;

//        for (Customer item : data){
//            sb.append(item.CustomerID);
//            sb.append(",");
//            sb.append(item.CompanyName);
//            sb.append(",");
//            sb.append(item.ContactName);
//            sb.append(",");
//            sb.append(item.Country);
//        }

//        return sb;
//    }
//};

//class CustomerHelper{

//private:
//    NorthwindEntities* db = new NorthwindEntities();
//    CustomerDataService customerDataService;
//public:
//    string sb = customerDataService.ExportCustomerData(costomors);
//    list<Customer> costomors = db->GetAllCustomers();

////    list<Customer>  GetAllCustomers(){
////        return db->Customers;
////    }

////    Customer GetCustomerByID(string customerid){
////        //return db->Customers.find(customerid);
////        return db->Customers.front();
////    }

////    string ExportCustomerData(){
////        string sb;
////        list<Customer> data = db->GetAllCustomers();

////        for (Customer item : data){
////            sb.append(item.CustomerID);
////            sb.append(",");
////            sb.append(item.CompanyName);
////            sb.append(",");
////            sb.append(item.ContactName);
////            sb.append(",");
////            sb.append(item.Country);
////        }

////        return sb;
////    }

//};





//int main() {
//    CustomerHelper customerHelper;
//    // Kundendaten exportieren
//    std::cout << "Exportierte Kundendaten:\n";
//    std::string exportedData = customerHelper.sb;
//    std::cout << exportedData;

//    // Alle Kunden abrufen
//    std::list<Customer> customers = customerHelper.GetAllCustomers();
//    std::cout << "Alle Kunden:\n";
//    for (const Customer& customer : customers) {
//        std::cout << "Kunden-ID: " << customer.CustomerID << "\n";
//        std::cout << "Firmenname: " << customer.CompanyName << "\n";
//        std::cout << "Ansprechpartner: " << customer.ContactName << "\n";
//        std::cout << "Land: " << customer.Country << "\n";
//        std::cout << "-------------------------------\n";
//    }

//    // Einen Kunden anhand der ID abrufen
//    std::string customerId = "ALFKI";
//    std::cout << "Gesuchter Kunde:\n";
//    Customer foundCustomer = customerHelper.GetCustomerByID(customerId);
//    std::cout << "Gefundener Kunde mit ID " << customerId << ":\n";
//    std::cout << "Kunden-ID: " << foundCustomer.CustomerID << "\n";
//    std::cout << "Firmenname: " << foundCustomer.CompanyName << "\n";
//    std::cout << "Ansprechpartner: " << foundCustomer.ContactName << "\n";
//    std::cout << "Land: " << foundCustomer.Country << "\n";



//    return 0;
//}

























































