#ifndef MAPPING_H_
#define MAPPING_H_

#define MAP(var, INPUT_START, INPUT_END, OUTPUT_START, OUTPUT_END) \
    (((float)((OUTPUT_END) - (OUTPUT_START)) / ((INPUT_END) - (INPUT_START))) * (var - INPUT_START)) + (OUTPUT_START)

double map(double var, double INPUT_START, double INPUT_END, double OUTPUT_START, double OUTPUT_END)
{
    return ((((OUTPUT_END) - (OUTPUT_START)) / ((INPUT_END) - (INPUT_START))) * (var - INPUT_START)) + (OUTPUT_START);
}
#endif