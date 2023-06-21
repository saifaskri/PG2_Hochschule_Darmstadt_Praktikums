
#include <iostream>
#include <vector>

using namespace std;


class ITag{
public:
    virtual void execute()=0;
};


class ParentTag: public ITag {

private:
    vector<ITag*> list;

public:

    void moveChildToParent(ITag *b){
        list.push_back(b);
    };

    void execute(){

        for(auto p:list){
            p->execute();
        }

    };


};



class ChildTag: public ITag {


    string Content;

public:
    ChildTag(string content):Content(content){};

    void execute(){

        cout<<Content<<endl;

    };


};



int main() {


    ParentTag *html = new ParentTag();

    ParentTag *h1 = new ParentTag();

    ParentTag *p1 = new ParentTag();
    ParentTag *p2 = new ParentTag();

    h1->moveChildToParent(p1);
    h1->moveChildToParent(p2);


    html->moveChildToParent(h1);

    //html->moveChildToParent(p2);

    ChildTag *text1 = new ChildTag("Hello");
    ChildTag *text2 = new ChildTag("Wold !");

    p1->moveChildToParent(text1);
    p2->moveChildToParent(text2);


    html->execute();




    return 0;
}







//#include <iostream>
//#include <vector>

//using namespace std;

//static int counter = 0;

//class Box{
//public:
//    virtual void execute()=0;
//};

//class CompositBox: public Box {

//private:
//    vector<Box*> list;

//public:

//    void moveToBox(Box *b){
//        list.push_back(b);
//    };

//    void execute(){
//        for(auto p:list){
//            p->execute();
//        }
//    };
//};

//class Product : public Box{

//public:
//    void execute(){
//        counter++;
//        cout<<"hier ist Product "<<counter<<endl;
//    };
//};

//int main() {


//    CompositBox *amazonBox = new CompositBox();

//    CompositBox *boxbig1 = new CompositBox();

//    CompositBox *boxsmall1 = new CompositBox();
//    boxsmall1->moveToBox(new Product());
//    boxsmall1->moveToBox(new Product());
//    boxsmall1->moveToBox(new Product());

//    Box *product1 = new Product();
//    Box *productinBox2 = new Product();
//    Box *productinBox1 = new Product();


//    CompositBox *boxsmall2 = new CompositBox();

//    boxbig1->moveToBox(boxsmall1);
//    boxbig1->moveToBox(boxsmall2);

//    CompositBox *boxbig2 = new CompositBox();
//    boxbig2->moveToBox(productinBox2);



//    amazonBox->moveToBox(product1);
//    amazonBox->moveToBox(boxbig2);
//    amazonBox->moveToBox(boxbig1);

//    amazonBox->execute();

//    return 0;
//}



































//#include <iostream>
//#include <thread>
//#include <mutex>
//using namespace std;

//mutex key;
//mutex key2;

//void threadFunction(int threadID) {
//    key.lock();

//        std::cout << "Thread1 ID: " << threadID << " executing." << std::endl;

//   key.unlock();

//}
//void threadFunction2(int threadID) {
//    key.lock();

//        std::cout << "Thread2 ID: " << threadID << " executing." << std::endl;

//    key.unlock();

//}

//int main() {
//    const int numThreads = 5;
//    std::thread threads[numThreads];
//    std::thread threads2[numThreads];

//    for (int i = 0; i < numThreads; ++i) {
//        threads[i] = std::thread(threadFunction, i);
//    }




//    // Wait for all threads to finish
//    for (int i = 0; i < numThreads; ++i) {

//        threads[i].join();

//    }


//    for (int i = 0; i < numThreads; ++i) {
//        threads2[i] = std::thread(threadFunction2, i);
//    }
//    // Wait for all threads to finish
//    for (int i = 0; i < numThreads; ++i) {

//        threads2[i].join();

//    }




//    std::cout << "All threads executed successfully." << std::endl;

//    return 0;
//}

































//#include <iostream>
//#include <string>
//using namespace std;

//class MediaPlayer {
//public:
//    virtual void play(string filename, string audiotype) = 0;
//    virtual ~MediaPlayer(){};
//};

//class MP3Player : public MediaPlayer {
//public:
//    void play(string filename, string audiotype) {
//        cout << "Music lauuft mit MP3 player" << endl;
//    }
//};


//class AdvancedMediaPlayer {
//public:
//    virtual void playWMA(string filename) = 0;
//};

//class WMAPlayer : public AdvancedMediaPlayer {
//public:
//    void playWMA(string filename) {
//        cout << "Music laeuft mit WMA player" << endl;
//    }
//};


//class WMAAdapter : public MediaPlayer {
//private:
//    AdvancedMediaPlayer* wmaPlayer;
//public:
//    WMAAdapter(AdvancedMediaPlayer* player) {
//        wmaPlayer = player;
//    }

//    void play(string filename, string audiotype) {
//        wmaPlayer->playWMA(filename);
//    }
//};

//int main() {
//    MediaPlayer* medi = new MP3Player;
//    medi->play("MP3", "song.mp3");

//    AdvancedMediaPlayer* wmaPlayer = new WMAPlayer;
//    MediaPlayer* wmaAdapter = new WMAAdapter(wmaPlayer);
//    wmaAdapter->play("WMA", "song.wma");

//    delete medi;
//    delete wmaPlayer;
//    delete wmaAdapter;

//    return 0;
//}
