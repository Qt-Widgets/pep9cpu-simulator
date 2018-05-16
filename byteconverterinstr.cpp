// File: byteconverterinstr.cpp
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

#include "byteconverterinstr.h"
#include "ui_byteconverterinstr.h"

#include "pep.h"

ByteConverterInstr::ByteConverterInstr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ByteConverterInstr)
{
    ui->setupUi(this);
}

ByteConverterInstr::~ByteConverterInstr()
{
    delete ui;
}

//void ByteConverterInstr::setValue(int data)
//{
//    ui->label->setText(" " + Pep::enumToMnemonMap.value(Pep::decodeMnemonic[data])
//                       + Pep::commaSpaceToAddrMode(Pep::decodeAddrMode[data]));
//}

void ByteConverterInstr::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
