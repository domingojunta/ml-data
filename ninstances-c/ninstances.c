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


  //Ahora voy a leer la primera linea del fichero con datos

  int num_columnas = data_features+data_labels;
  printf("El numero de columnas es: %d \n", num_columnas);
  int labels[data_size][data_labels];

  int sumatorio_labels=0;


  for (int registro	= 0; registro < data_size; registro++) {

	  //printf("Registro: %d \t", registro);
	  int indice=0;

	  for (int item=0; item<num_columnas;item++){
	  	  if (item<data_features) {
	  		float feature;
	  		fscanf(data_file,"%f \n",&feature);
	  		//printf("%f \t",feature);
	  	  } else {
	  		  int dato;

	  		  fscanf(data_file,"%d \n",&dato);
	  		  //printf("%d \t", dato);
	  		  labels[registro][indice]=dato;
	  		  indice++;
	  		  sumatorio_labels=sumatorio_labels+dato;
	  	  	  }
	    };

  };

  float n = (float)data_size;
  float suma_labels = (float)sumatorio_labels;
  float LCard= suma_labels/n;
  float num_labels = (float)data_labels;
  float LDen = LCard/num_labels;

  printf("\n");
  printf("====================================== \n");
  printf("Estadisticas del fichero:              \n");
  printf("====================================== \n");

//  for (int registro=0;registro<data_size;registro++ ) {
//
//	  for (int item=0; item<data_labels;item++) {
//
//	  	printf("(%d,%d):%2d ",registro,item,labels[registro][item]);
//
//	  };
//
//  };

  printf("data_file: %s, instances: %d, features: %d, labels: %d",
     	  data_filename, data_size, data_features, data_labels);
  printf("\n");
    printf("El sumatorio de los labels es: %d",sumatorio_labels);
    printf("\n");
    printf("La cardinalidad LCard es: %0.5f",LCard);
  printf("\n");
  printf("La densidad LDen es: %0.5f",LDen);
    printf("\n");
    printf("\n");
    printf("\n");



  // en el programa original había un error y es que cerraba con data_filename que es un char
  fclose(data_file);
}
