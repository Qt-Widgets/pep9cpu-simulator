// File: microcodeeditor.h
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
#ifndef MICROCODEEDITOR_H
#define MICROCODEEDITOR_H

#include <QPlainTextEdit>
#include <QObject>
#include "colors.h"
class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
class QSettings;

class LineNumberArea;

class MicrocodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    MicrocodeEditor(QWidget *parent = 0, bool highlightCurrentLine = true, bool isReadOnly = false);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

    void highlightSimulatedLine();
    void clearSimulationView();

    void unCommentSelection();
    void readSettings(QSettings& settings);
    void writeSettings(QSettings& settings);

public slots:
    void onDarkModeChanged(bool darkMode);
protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void updateLineNumberArea(const QRect &, int);

private:
    QWidget *lineNumberArea;

    bool highlightCurLine;
    const PepColors::Colors *colors;
    int getMicrocodeBlockNumbers();
};


class LineNumberArea : public QWidget
{
public:
    LineNumberArea(MicrocodeEditor *editor) : QWidget(editor) {
        microcodeEditor = editor;
    }

    QSize sizeHint() const {
        return QSize(microcodeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) {
        microcodeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    MicrocodeEditor *microcodeEditor;
};

#endif // MICROCODEEDITOR_H
