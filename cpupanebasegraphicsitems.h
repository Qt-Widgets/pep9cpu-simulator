// File: cpupanebasegraphicsitems.h
/*
    Pep9CPU is a CPU simulator for executing microcode sequences to
    implement instructions in the instruction set of the Pep/9 computer.

    Copyright (C) 2010  J. Stanley Warford, Pepperdine University

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef CPUPANEBASEGRAPHICSITEMS_H
#define CPUPANEBASEGRAPHICSITEMS_H

#include <QGraphicsItem>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>

#include "tristatelabel.h"

class CpuPaneBaseGraphicsItems : public QGraphicsItem
{
public:
    CpuPaneBaseGraphicsItems(QWidget *widgetParent, QGraphicsItem *itemParent = 0,
                             QGraphicsScene *scene = 0);
    ~CpuPaneBaseGraphicsItems();

    QRectF boundingRect() const;

    bool aluHasCorrectOutput();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    // OUTSIDE REGISTERS
    QCheckBox *loadCk;
    QLabel *cLabel;
    QLineEdit *cLineEdit;
    QLabel *bLabel;
    QLineEdit *bLineEdit;
    QLabel *aLabel;
    QLineEdit *aLineEdit;

    QCheckBox *MARCk;
    QLabel *MARALabel; // data section
    QLabel *MARBLabel; // data section
    QCheckBox *MDRCk;

    QLabel *aMuxLabel;
    QLabel *aMuxerDataLabel; // data section
    QGraphicsRectItem *aMuxerBorder; // data section
    TristateLabel *aMuxTristateLabel;

    QLabel *MDRMuxLabel;
    QLabel *MDRMuxerDataLabel; // data section
    TristateLabel *MDRMuxTristateLabel;
    QLabel *MDRLabel; // data section

    QLabel *cMuxLabel;
    TristateLabel *cMuxTristateLabel;
    QLabel *cMuxerLabel; // data section

    QLabel *ALULabel;
    QLineEdit *ALULineEdit;
    QLabel *ALUFunctionLabel; // data section
    QGraphicsPolygonItem *ALUPoly; //data section

    QLabel *CSMuxLabel;
    QLabel *CSMuxerDataLabel;
    TristateLabel *CSMuxTristateLabel;
    QCheckBox *SCkCheckBox;

    QCheckBox *CCkCheckBox;

    QCheckBox *VCkCheckBox;
    QLabel *AndZLabel;
    TristateLabel *AndZTristateLabel;
    QLabel *AndZMuxLabel; // data section

    QCheckBox *ZCkCheckBox;

    QCheckBox *NCkCheckBox;

    TristateLabel *nBitLabel; // data section
    TristateLabel *zBitLabel; // data section
    TristateLabel *vBitLabel; // data section
    TristateLabel *cBitLabel; // data section
    TristateLabel *sBitLabel; // data section

    QLabel *MemReadLabel;
    TristateLabel *MemReadTristateLabel;

    QLabel *MemWriteLabel;
    TristateLabel *MemWriteTristateLabel;

    // REGISTER BANK
    QLineEdit *aRegLineEdit;
    QLineEdit *xRegLineEdit;
    QLineEdit *spRegLineEdit;
    QLineEdit *pcRegLineEdit;
    QLineEdit *irRegLineEdit;
    QLineEdit *t1RegLineEdit;
    QLineEdit *t2RegLineEdit;
    QLineEdit *t3RegLineEdit;
    QLineEdit *t4RegLineEdit;
    QLineEdit *t5RegLineEdit;
    QLineEdit *t6RegLineEdit;

    // Two byte data bus model features:
    QCheckBox *MDROCk;
    QCheckBox *MDRECk;
    TristateLabel *MDROMuxTristateLabel;
    TristateLabel *MDREMuxTristateLabel;
    TristateLabel *EOMuxTristateLabel;
    TristateLabel *MARMuxTristateLabel;
private:
    QGraphicsScene *parentScene;
    QWidget *parent;

    QColor seqCircuitColor;
    QColor combCircuitRed;
    QColor combCircuitBlue;
    QColor combCircuitYellow;
    QColor combCircuitGreen;

    QImage arrowLeft;
    QImage arrowRight;
    QImage arrowUp;
    QImage arrowDown;

    QImage arrowLeftGray;
    QImage arrowRightGray;
    QImage arrowUpGray;
    QImage arrowDownGray;

    void repaintLoadCk(QPainter *painter);
    void repaintCSelect(QPainter *painter);
    void repaintBSelect(QPainter *painter);
    void repaintASelect(QPainter *painter);
    void repaintMARCk(QPainter *painter);
    void repaintMDRCk(QPainter *painter);
    void repaintAMuxSelect(QPainter *painter);

    void repaintCMuxSelect(QPainter *painter);

    void repaintSCk(QPainter *painter);
    void repaintCCk(QPainter *painter);
    void repaintVCk(QPainter *painter);
    void repaintZCk(QPainter *painter);
    void repaintNCk(QPainter *painter);
    void repaintMemRead(QPainter *painter);
    void repaintMemWrite(QPainter *painter);
    void repaintSBitOut(QPainter *painter);
    void repaintCBitOut(QPainter *painter);
    void repaintVBitOut(QPainter *painter);
    void repaintZBitOut(QPainter *painter);
    void repaintNBitOut(QPainter *painter);

    void repaintCSMuxSelect(QPainter *painter);
    void repaintAndZSelect(QPainter *painter);
    void repaintALUSelect(QPainter *painter);
    void repaintMDRMuxSelect(QPainter *painter);
};

#endif // CPUPANEBASEGRAPHICSITEMS_H
