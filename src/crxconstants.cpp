#include "crxconstants.h"

#include <QDir>

CrxConstants::CrxConstants()
{
}

QString CrxConstants::storagePath()
{
    return QDir::homePath() + "/.crustax";
}

