#include "colors.h"
#include <QColor>
#include <QDebug>
const PepColors::Colors PepColors::initDark()
{
    auto retVal =  PepColors::Colors();
    retVal.comment = QColor(Qt::green).lighter();
    retVal.leftOfExpression = QColor("lightsteelblue");
    retVal.rightOfExpression = QColor(Qt::red).lighter();
    retVal.memoryHighlight = QColor("lightgreen").darker(130);

    retVal.seqCircuitColor= QColor(0x3B3630).lighter(200); //Used to be 370 0x3B3630
    retVal.combCircuitRed = QColor(0xDF5A49);
    retVal.combCircuitGreen = QColor(0x008A1C);
    retVal.combCircuitBlue = QColor(0x506082);
    retVal.combCircuitYellow = QColor(0xE0B010);

    retVal.muxCircuitRed = retVal.combCircuitRed.darker(110); // A sightly lighter shade of combCircuitRed that is a better background for text
    retVal.muxCircuitBlue = retVal.combCircuitBlue.darker(110); // A sightly lighter shade of combCircuitBlue that is a better background for text
    retVal.aluColor = retVal.combCircuitBlue;
    retVal.aluOutline = retVal.combCircuitBlue.lighter(140);
    retVal.muxCircuitYellow = retVal.combCircuitYellow.darker(110); // A sightly lighter shade of combCircuitYellow that is a better background for text
    retVal.muxCircuitGreen = retVal.combCircuitGreen.darker(110); // A sightly lighter shade of combCircuitGreen that is a better background for text
    retVal.arrowColorOn = QColor(0xeeeeee); //Used to be Qt::white
    retVal.arrowColorOff = QColor(Qt::gray); //Used to be Qt:gray
    retVal.backgroundFill= QColor(0x31363b);
    retVal.arrowImageOn=(":/images/arrowhead_dark.png");
    retVal.arrowImageOff=(":/images/arrowhead_gray.png");
    return retVal;
}

const PepColors::Colors PepColors::initLight()
{
    auto retVal =  PepColors::Colors();
    retVal.comment = Qt::darkGreen;
    retVal.leftOfExpression = Qt::darkBlue;
    retVal.rightOfExpression = Qt::darkMagenta;
    retVal.memoryHighlight = QColor("green");

    retVal.seqCircuitColor= QColor(0x3B3630).lighter(370);
    retVal.combCircuitRed = QColor(0xD92405).lighter(140);
    retVal.muxCircuitRed = retVal.combCircuitRed.lighter(140); // A sightly lighter shade of combCircuitRed that is a better background for text
    retVal.combCircuitBlue = QColor(0x3563EB).lighter(120);
    retVal.muxCircuitBlue = retVal.combCircuitBlue.lighter(140); // A sightly lighter shade of combCircuitBlue that is a better background for text
    retVal.aluColor = retVal.combCircuitBlue.lighter(140);
    retVal.aluOutline = retVal.combCircuitBlue;

    retVal.combCircuitYellow = QColor(0xEAC124).lighter(120);
    retVal.muxCircuitYellow = retVal.combCircuitYellow.lighter(140); // A sightly lighter shade of combCircuitYellow that is a better background for text
    retVal.combCircuitGreen = QColor(0x739211).lighter(130);
    retVal.muxCircuitGreen = retVal.combCircuitGreen.lighter(140); // A sightly lighter shade of combCircuitGreen that is a better background for text
    retVal.arrowColorOn = Qt::black;
    retVal.arrowColorOff = Qt::gray;
    retVal.backgroundFill= QColor(Qt::white);
    retVal.arrowImageOn=(":/images/arrowhead.png");
    retVal.arrowImageOff=(":/images/arrowhead_gray.png");
    return retVal;
}

