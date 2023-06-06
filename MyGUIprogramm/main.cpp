
#include <QApplication>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QObject>
#include <QLabel>

int main(int argc, char *argv[])
{



    //the entire App
    QApplication a(argc, argv);


    //create the Frame
    QFrame win;
    win.setMinimumSize(500, 500);
    win.setWindowTitle("GUI-Test");

    // convert int to QString
    //Remember to include the QtCore module to access the QString class
    QString argcToString = QString::number(argc);
    qDebug() << argcToString; // Output: "42"

    // add input text
    QLineEdit *txt = new QLineEdit("Test", &win);
    txt->setGeometry(0, 0, 80, 30);

    //Add button
    QPushButton *btn = new QPushButton("Klick mich!", &win);
    btn->setGeometry(120, 20, 80, 30);

    QLabel *lbl = new QLabel("here", &win);
    //lbl->setFrameStyle(QFrame::StyledPanel);
    lbl->setGeometry(20, 60, 180, 30);

    //add the Input Value to the label
    QObject::connect(btn, &QPushButton::clicked, [=]() {


        str = str.length() ? str + '\n' : "";
        lbl->setText(str + txt->text());

        lbl->setText(txt->text());

    });

    //set the text for an input
    QObject::connect(btn, &QPushButton::clicked, [=]() { txt->setText(txt->text()); });

    //set titel for the window
    QObject::connect(btn, &QPushButton::clicked, [&win, &txt]() { win.setWindowTitle(txt->text()); });

    //set size for the window
    QObject::connect(btn, &QPushButton::clicked, [&win, &txt]() {
      // Get the user input from the QLineEdit and convert it to integers
       int width = txt->text().toInt();
       int height = txt->text().toInt();

       // Remove the minimum size constraint
       win.setMinimumSize(0, 0);

       // Set the window size based on the user input
       win.resize(width, height);
    });

    //show the Frame
    win.show();

    return a.exec();


}
