//  Saksham Attri 2021A7PS2950H
//  Pritam  Basu  2021A7PS2715H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lock = 0;

void swap (int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void degree(int n, int e, int matrix[][2], int * degr){
  for(int i = 0; i<n; i++){
    degr[i]=0;
  }
  for(int i = 0; i<e; i++){
    degr[matrix[i][0]-1]++;
    degr[matrix[i][1]-1]++;
  }
}

int check(int * degr1,int * ordering, int n1, int e1, int oldadj[][n1],int matrix2[][2]){
  int degr2[n1];
  degree(n1,e1,matrix2,degr2);
  for(int i = 0; i<n1;i++){
    if(degr2[ordering[i]]!=degr1[i]){
      return 0;
    }
  }
  int newadj[n1][n1];
  for (int i = 0; i < n1; i++){
    for (int j = 0; j<n1;j++){
      newadj[i][j]=0;
    }
  }
  for (int i = 0; i < e1; i++){
    int iii=0;
    int j=0;
    for(int ii = 0; ii < n1; ii++){
      if(ordering[ii]==matrix2[i][0]-1){
        j=ii;
      }
      if(ordering[ii]==matrix2[i][1]-1){
        iii=ii;
      }
    }
    newadj[j][iii]++;
    newadj[iii][j]++;
  }
  for (int i = 0; i < n1; i++){
    for (int j = 0; j < n1; j++){
      if(newadj[i][j]!=oldadj[i][j]){
        return 0;
      }
    }
  }
  return 1;
}

void checkpermute(FILE * f3,int *ordering,int i, int * degr1, int n1, int e1, int oldadj[][n1], int matrix2[][2]) { 
  if (n1 == i){
    if (!check(degr1,ordering,n1,e1,oldadj,matrix2)){
    return;
    }
    else{
      lock = 1;
      printf("Isomorphic.\n");
      fprintf(f3,"Isomorphic.\n");
      for(int i = 0; i<n1; i++){
        printf("%d %d\n",i+1,ordering[i]+1);
        fprintf(f3,"%d %d\n",i+1,ordering[i]+1);
      }
      fclose(f3);
      exit(0);
    }
  }
  if(!lock){
    int j = i;
    for (j = i; j < n1; j++) { 
      swap(ordering+i,ordering+j);
      checkpermute(f3,ordering,i+1,degr1,n1,e1,oldadj,matrix2);
      swap(ordering+i,ordering+j);
    }
    return;
  }
}

void asc(int n, int * degr){
  int a;
  for (int i = 0; i < n; ++i){
    for (int j = i + 1; j < n; ++j){
      if (degr[i] > degr[j]){
         a = degr[i];
         degr[i] = degr[j];
         degr[j] = a;
      }
    }
  }
}

int compdegree(int n, int * degr1, int * degr2){
  for(int i = 0; i<n; i++){
    if(degr1[i]!=degr2[i]){
      return 0;
    }
  }
  return 1;
}

int main(int argc, char **argv){
  FILE* f1, * f2, * f3;
  int n1, n2, e1, e2;
  f1 = fopen(argv[1],"r");
  f2 = fopen(argv[2],"r");
  char newstr[strlen(argv[1])];
  int y;
  for(y = 0; y < strlen(argv[1]); y++){
    if(argv[1][y]=='.')
      break;
    newstr[y]=argv[1][y];
  }
  newstr[y]='\0';
  char * aa = strcat(newstr,argv[2]);
  char aaa[strlen(aa)+1];
  for (int h = 0; h<strlen(aa);h++){
    aaa[h]=aa[h];
  }
  aaa[strlen(aa)]='\0';
  char ok[100] = {'o','u','t','-','\0'};
  char * fin = strcat(ok,aaa);
  f3 = fopen(fin,"w");
  fscanf(f1,"%d",&n1);
  fscanf(f2,"%d",&n2);
  fscanf(f1,"%d",&e1);
  fscanf(f2,"%d",&e2);
  if(n1 == n2 && e1 == e2){
    int matrix1[e1][2]; int matrix2[e2][2];
    for (int i = 0; i < e1; i++){
      fscanf(f1," %d %d",&matrix1[i][0],&matrix1[i][1]);
    }
    for (int i = 0; i < e2; i++){
      fscanf(f2,"%d %d",&matrix2[i][0],&matrix2[i][1]);
    }
    fclose(f1); fclose(f2);
    int degree1[n1], degree2[n2];
    degree(n1,e1,matrix1,degree1);
    degree(n2,e2,matrix2,degree2);
    int copy1[n1], copy2[n2];
    for(int i =0;i<n1;i++){
      copy1[i]=degree1[i];
      copy2[i]=degree2[i];
    }
    asc(n1,copy1);
    asc(n2,copy2);
    if(compdegree(n1,copy1,copy2)){
      int ordering[n1];
      int adjacencyMatrix[n1][n1];
      for(int i = 0; i<n1; i++){
        ordering[i]=i;
        for(int j = 0; j<n1; j++){
          adjacencyMatrix[i][j]=0;
        }
      }
      for(int i = 0; i<e1; i++){
        adjacencyMatrix[matrix1[i][0]-1][matrix1[i][1]-1]++;
        adjacencyMatrix[matrix1[i][1]-1][matrix1[i][0]-1]++;
      }
      checkpermute(f3,ordering,0,degree1,n1,e1,adjacencyMatrix,matrix2);
    }
  }
  if(!lock){
    printf("Not Isomorphic, no bijection found.\n");
    fprintf(f3,"Not Isomorphic, no bijection found.\n");
    fclose(f3);
  }
  return 0;
}