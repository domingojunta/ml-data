#include <stdio.h>
#include <string.h>

int ninstances(char *filename)
{
  //FILE *data_file;
  char data_filename[50], c;
  int data_size, data_labels, data_features;
  strcpy(data_filename,"data/");
  strcat(data_filename,filename);
  FILE *data_file = data_file=fopen(data_filename, "r");
  fscanf(data_file,"%c %d \n", &c, &data_size);
  fscanf(data_file,"%c %d \n", &c, &data_features);
  fscanf(data_file,"%c %d \n", &c, &data_labels);
  printf("data_file: %s, instances: %d, features: %d, labels: %d \n",
   	  data_filename, data_size, data_features, data_labels);
  printf("\n");
  // en el programa original había un error y es que cerraba con data_filename que es un char
  fclose(data_file);
}
