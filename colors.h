#ifndef COLORS_H
#define COLORS_H
#include <QColor>
#include <QImage>
namespace PepColors{
    struct Colors
    {
        QColor comment;
        QColor rightOfExpression;
        QColor leftOfExpression;

        QColor seqCircuitColor;
        QColor combCircuitRed;
        QColor muxCircuitRed; // A sightly lighter shade of combCircuitRed that is a better background for text
        QColor combCircuitBlue;
        QColor muxCircuitBlue; // A sightly lighter shade of combCircuitBlue that is a better background for text
        QColor aluColor;
        QColor aluOutline;
        QColor combCircuitYellow;
        QColor muxCircuitYellow; // A sightly lighter shade of combCircuitYellow that is a better background for text
        QColor combCircuitGreen;
        QColor muxCircuitGreen; // A sightly lighter shade of combCircuitGreen that is a better background for text
        QColor arrowColorOn;
        QColor arrowColorOff;
        QColor backgroundFill;
        QString arrowImageOn;
        QString arrowImageOff;

        QColor memoryHighlight;
        QColor lineAreaBackground;
        QColor lineAreaText;
        QColor lineAreaHighlight;
    };
    static const QColor transparent = QColor(255,255,255,0);
    const Colors initLight();
    const Colors initDark();
    static const Colors lightMode = {initLight()};
    static const Colors darkMode = {initDark()};
    QColor invert(QColor input);
}
#endif // COLORS_H
