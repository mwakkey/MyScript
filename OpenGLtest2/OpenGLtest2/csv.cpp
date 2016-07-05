
#include "csv.h"

CSV::CSV()
{
	output.open("output.csv");
}

CSV::CSV(const char* csvFile)
{
	output.open(csvFile);
}

CSV::~CSV()
{
	output.close();
}