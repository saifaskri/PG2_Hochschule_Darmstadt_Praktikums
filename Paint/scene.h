#ifndef SCENE_H
#define SCENE_H


#include <vector>
#include <QMouseEvent>
#include <QColor>

#include"graphobj.h"


class Scene
{
public:

    Scene();

    Scene(const Scene& scene) ;
    Scene& operator=(const Scene& scene)   ;
    ~Scene();

    void draw(QPainter &painter);
    void deleteShape(QMouseEvent *event);
    void AddShape(GraphObj* obj);
    void DeleteAllShape();

    void moveShape(QPoint startPoint, QPoint endPoint );
    void colorShape(QMouseEvent *event,QColor color);

    int selectObj(QMouseEvent *event);
    // function overload
    int selectObj(QPoint p);
    int getSelectedIndex() const;
    void setSelectedIndex(int newSelectedIndex);
    std::vector<GraphObj *> AllShape;

private:
    int SelectedIndex = -1 ;

};

#endif // SCENE_H



//    MOV R7 , #0                 @ R7 ist der Counter für die Anzhal der Ketten                             @das Brauchen wir um zu überprüfen ob unsere Zeichnenkette über 255 ist
//loop:

//    CMP  R7 , 254                @ prüfen ob wir unsere Maximal erreicht haben
//    BEQ  checkIfStringover255    @ retrun function die /0 am Ende kopiert

//    ADD  R7 ,  #1                @ increment den Counter

//    LDRB R1 , [R0] , #1  ;       @ R0 ist der Zeiger auf StringA
//    STRB R1 , [R2] , #1  ;       @ R2 ist ein Zeiger auf StringB
//    CMP  R1 , #0                 @ R1 hat immer eine Kopie von dem aktuellen Inhalt
//    BNE  loop                    @ noch mal incremetieren und kopieren den nächsten Inhalt

//checkIfStringover255:
//    MOV  R9 #0                   @ Mov 0 zu r9 weil wir nicht sagen können speichere #0 in R2
//    STRB R9,[R2,#1]              @ incrementieren den Zeiger vor dem Speichern

// @//.......................... weiter code

//    MOV R5, #0;
//PushNumberInStack:

//    ADD R5,#1;

//    LDRB R8 , [R2] , #1  ;      @ R2 ist der Zeiger auf StringB
//                                @ charakter laden von dem Speicher
//                                @ und Zeiger Incrementieren

//    CMP  R8 , #0     ;          @ check ob zeichen ist 0 (Terminiert)
//    BEQ PopNumberInSpeicher ;   @ überprüfung ist fertig

//    CMP R8 , 49                 @ Vergeleiche charakter mit 0
//    BLT PushNumberInStack  ;            @ Ignore
//    CMP R8 , 57                 @ Vergeleiche charakter mit 9
//    BGT PushNumberInStack  ;            @ Ignore
//    PUSH R8 ;
//    B  SaveNumberInStack ;                   @ noch mal incremetieren und kopieren den nächsten Inhalt


//PopNumberInSpeicher:

//    POP R8;
//    STR R8 , [R2], #1;        @ Speichern Zahlen in den Speicher
//    SUBS R5, #1;              @ Counter Dekrimentieren
//    BNE PopNumberInSpeicher ; @ Jump wenn R5 nicht 0 ist

//@//.......................... weiter code








