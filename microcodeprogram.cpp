#include "microcodeprogram.h"
#include "code.h"

MicrocodeProgram::MicrocodeProgram(): programVec(),preconditionsVec(),postconditionsVec(),microcodeVec()
{

}

MicrocodeProgram::~MicrocodeProgram()
{
    for(int it = 0;it< programVec.length();it++)
    {
        delete programVec[it];
    }
}

MicrocodeProgram::MicrocodeProgram(QVector<Code*>objectCode):
    programVec(objectCode),preconditionsVec(),postconditionsVec(),microcodeVec()
{
    Code* x;
    for(int it=0; it<objectCode.size();it++)
    {
        x=objectCode[it];
        if(x->hasUnitPre())preconditionsVec.append(it);
        else if(x->hasUnitPost())postconditionsVec.append(it);
        else if(x->isMicrocode())microcodeVec.append(it);
    }
}

const QVector<Code*> MicrocodeProgram::getObjectCode() const
{
    return this->programVec;
}

const QString MicrocodeProgram::format() const
{
    QString output = "";
    for(Code* line : programVec)
    {
        output.append(line->getSourceCode() + "\n");
    }
    return output;
}

int MicrocodeProgram::codeLineToProgramLine(int codeLine) const
{
    return microcodeVec[codeLine];
}

bool MicrocodeProgram::hasMicrocode() const
{
    return !microcodeVec.isEmpty();
}

bool MicrocodeProgram::hasUnitPre() const
{
    return !preconditionsVec.empty();
}

const MicroCode *MicrocodeProgram::getCodeLine(quint16 codeLine) const
{
    if(codeLine<microcodeVec.size())
    {
        return (MicroCode*) programVec[microcodeVec[codeLine]];
    }
    return nullptr;
}

int MicrocodeProgram::codeLength() const
{
    return microcodeVec.length();
}

