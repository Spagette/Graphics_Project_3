/******************************************************************
To use this reader, you need to make sure your input mesh
has the keyword "OFF" in the beginning, followed by the mesh.
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>


typedef struct {
  float x;
  float y;
  float z;
}FLTVECT;

typedef struct {
  int a;
  int b;
  int c;
}INT3VECT;

typedef struct {
  int nv;
  int nf;
  FLTVECT *vertex;
  INT3VECT *face;
}SurFaceMesh;


int main(int argc, char *argv[])
{
  int num,n,m;
  int a,b,c,d,e;
  float x,y,z;
  SurFaceMesh *surfmesh;
  char line[256];
  FILE *fin;


  if ((fin=fopen("inputmesh.off", "r"))==NULL){
    printf("read error...\n");
    exit(0);
  };
  
  /* OFF format */
  while (fgets(line,256,fin) != NULL) {
    if (line[0]=='O' && line[1]=='F' && line[2]=='F')
      break;
  }
  fscanf(fin,"%d %d %d\n",&m,&n,&num);
  
  surfmesh = (SurFaceMesh*)malloc(sizeof(SurFaceMesh));
  surfmesh->nv = m;
  surfmesh->nf = n;
  surfmesh->vertex = (FLTVECT *)malloc(sizeof(FLTVECT)*surfmesh->nv);
  surfmesh->face = (INT3VECT *)malloc(sizeof(INT3VECT)*surfmesh->nf);

  for (n = 0; n < surfmesh->nv; n++) {
    fscanf(fin,"%f %f %f\n",&x,&y,&z);
    surfmesh->vertex[n].x = x;
    surfmesh->vertex[n].y = y;
    surfmesh->vertex[n].z = z;
  }
  
  for (n = 0; n < surfmesh->nf; n++) {
    fscanf(fin,"%d %d %d %d\n",&a,&b,&c,&d);
    surfmesh->face[n].a = b;
    surfmesh->face[n].b = c;
    surfmesh->face[n].c = d;
    if(a != 3)
      printf("Errors: reading mesh .... \n");
  }
  fclose(fin);
  
  return 0;
}