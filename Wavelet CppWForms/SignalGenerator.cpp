#include "pch.h"
#include "SignalGenerator.h"

int sign(double v) {
return (v < 0) ? -1 : ((v > 0) ? 1 : 0);
};