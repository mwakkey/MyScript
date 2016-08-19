
#include "csv.h"

CSV::CSV()
{
;
}

CSV::CSV(const char* csvFile, std::string dlm)
{
	output.open(csvFile);
	delimiter = dlm;
}

CSV::~CSV()
{
	output.close();
}

void CSV::set(const char* csvFile, std::string dlm){
	output.open(csvFile);
	delimiter = dlm;
}
void CSV::reset(){
	output.close();
}