#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QColorDialog>
#include <QGridLayout>
#include <QCheckBox>
#include <QDebug>
#include "paint.h"
#include "canvas.h"

/** c'tor */
Paint::Paint(QWidget *parent): QWidget(parent)
{
	// instantiate Canvas and button
	viewport = new Canvas();

	btnClearCanvas = new QPushButton("&Clear Canvas");

    cobPrimModes = new QComboBox();
    cobPrimModes->addItem(tr("None"), Canvas::NONE);
    cobPrimModes->addItem(tr("Line"), Canvas::LINE);
    cobPrimModes->addItem(tr("Freehand"), Canvas::FREE_HAND);
    cobPrimModes->addItem(tr("Circle"), Canvas::CIRCLE);
    cobPrimModes->addItem(tr("Rectangle"), Canvas::RECTANGLE);
    cobPrimModes->addItem(tr("Triangle"), Canvas::TRIANGLE);
    //cobPrimModes->addItem(tr("Polygon"), Canvas::POLYGON);

	lblPrimModes = new QLabel("Primitive Mode");
	lblPrimModes->setBuddy(cobPrimModes);

    btnDeleteObj = new QPushButton("&Delete Selected");
    btnDeleteObj->setDisabled(false);
    btnChangeCol = new QPushButton("C&hange Color");

    cbOutline = new QCheckBox("Show Only &Outline", this);
    BBox = new QCheckBox("Show BBox", this);




    //1
     groupBox = new QGroupBox("Radio Buttons");
    //2
    QVBoxLayout* groupBoxLayout = new QVBoxLayout();
    groupBox->setLayout(groupBoxLayout);
    //3
    QRadioButton* creating = new QRadioButton("Create");
    QRadioButton* deleting = new QRadioButton("Delete Selected");
    QRadioButton* coloring = new QRadioButton("Change Color");
    QRadioButton* moving = new QRadioButton("Move Selected");
    //4
    action = new QButtonGroup(this);
    //5
    action->addButton(creating);
    action->addButton(deleting);
    action->addButton(coloring);
    action->addButton(moving);
    //6
    action->addButton(creating,Canvas::InteractionMode::CREAT);
    action->addButton(deleting,Canvas::InteractionMode::DEL);
    action->addButton(coloring,Canvas::InteractionMode::COL);
    action->addButton(moving,Canvas::InteractionMode::TRAFO);
    //7
    groupBoxLayout->addWidget(creating);
    groupBoxLayout->addWidget(deleting);
    groupBoxLayout->addWidget(coloring);
    groupBoxLayout->addWidget(moving);
    //8
    //connect(action, QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked), this, &Paint::groupBoxChanged);




	// create layout and add gui elements to it
	QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addWidget(viewport,       0, 0, 1, 4);
    mainLayout->addWidget(groupBox,   1, 0 ,3,2);

    mainLayout->addWidget(lblPrimModes,   1, 2,Qt::AlignRight);
    mainLayout->addWidget(cobPrimModes,   1, 3);

    mainLayout->addWidget(btnChangeCol,   2, 3);

    mainLayout->addWidget(cbOutline,      2, 2, Qt::AlignRight);

    mainLayout->addWidget(btnClearCanvas,3, 3);
    mainLayout->addWidget(BBox,      3, 2, Qt::AlignRight);

    //mainLayout->addWidget(btnDeleteObj,   2, 0);


	// add layout to this widget instance
	setLayout(mainLayout);
	
    // connect button click event to clear canvas handler
    connect(btnClearCanvas, SIGNAL(clicked()),
            this, SLOT(clearBtnPressed()));
    // connect button click event to delete selected object handler
    connect(btnDeleteObj, SIGNAL(clicked()),
            this, SLOT(deleteBtnPressed()));
    // connect button click event to color chooser handler
    connect(btnChangeCol, SIGNAL(clicked()),
            this, SLOT(colorBtnPressed()));
    // connect list view to primitive changed event handler
    connect(cobPrimModes, SIGNAL(activated(int)),
            this, SLOT(primModeChanged()));
    // connect checkbox to toggle outline event handler
    connect(cbOutline, SIGNAL(toggled(bool)),
            this, SLOT(showOutlineOnly(bool)));
    // connect checkbox to toggle BBox event handler
    connect(BBox, SIGNAL(toggled(bool)),
            this, SLOT(BBoxPressed(bool)));
    // connect groupButton to toggle action event handler
    connect(action, QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked),
            this, &Paint::groupBoxChanged);

}

/** d'tor */
Paint::~Paint(){
    delete groupBox;
    delete groupBoxLayout;
    delete creating;
    delete deleting;
    delete coloring;
    delete moving;
    delete action;
}

/** method for handling button clicked event */
void Paint::clearBtnPressed(){

	viewport->clearCanvas();
    viewport->update();

}

void Paint::deleteBtnPressed()
{

    if(viewport->getSelectedIndex() != -1){
        viewport->AllShape.erase(viewport->AllShape.begin()+viewport->getSelectedIndex());
        //reset SelectedIndex to -1 for the next Shape
        viewport->setSelectedIndex(-1) ;
        viewport->update();
    }


}

void Paint::colorBtnPressed(){

    QColor color = QColorDialog::getColor(Qt::yellow, this );
    if (color.isValid()) {
        //set color from the GUI
        viewport->setColor(color);
    }
    //qDebug() << "Color Choosen : " << color.name();

}

void Paint::showOutlineOnly(bool outline){
    qDebug() << "Only show outline: " << outline;
    viewport->setOutline(!viewport->getOutline());
}

void Paint::BBoxPressed(bool bbox)
{
    qDebug() << "BBox : " << bbox;
}

void Paint::groupBoxChanged()
{
    std::cout<<"action change"<<std::endl;
    // you need to cast das here
    viewport->setOparation((Canvas::InteractionMode)action->checkedId());
}


void Paint::primModeChanged(){
	int mode = cobPrimModes->itemData(cobPrimModes->currentIndex(), Qt::UserRole).toInt();
	viewport->setPrimitiveMode(mode);
    qDebug() << "Primitive Mode changed to " << mode;
}

