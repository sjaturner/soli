#include<stdio.h>
#include<stdlib.h>
#define BOARDSZ 15
void show();
int move(int ix,int iy,int idx,int idy);
int hunt();
char acb[][BOARDSZ]={
  "              ",
  "     ***      ",
  "     ***      ",
  "   *******    ",
  "   ***0***    ",
  "   *******    ",
  "     ***      ",
  "     ***      ",
  "              ",
  ""
};
int im;
char *pch=0;
void show()
{
  int iy;
  for(iy=0;acb[iy][0];++iy)
    printf("%s\n",acb[iy]);
}
int ic;
int move(int ix,int iy,int idx,int idy)
{
  int ir;
  char *pch=&acb[iy][ix];
  char *pca=&acb[iy+idy][ix+idx];
  char *pcr=&acb[iy+2*idy][ix+2*idx];
  if(*pca!='*'||*pcr!='0')
    return 0;
  *pch='0';
  *pca='0';
  *pcr='*';
  --im;
  if((ir=hunt()))
    show();
  *pch='*';
  *pca='*';
  *pcr='0';
  ++im;
  return ir;
}
int hunt()
{
  int ix;
  int iy;
  if(im==1&&*pch=='*')
    return !0;
  for(iy=0;iy<BOARDSZ&&acb[iy][0];++iy)
    for(ix=0;ix<BOARDSZ&&acb[iy][ix];++ix)
      if(acb[iy][ix]=='*'&&(move(ix,iy, 0,+1)||move(ix,iy,+1, 0)||move(ix,iy, 0,-1)||move(ix,iy,-1, 0)))
        return !0;
  return 0;
}
int main()
{
  int ix;
  int iy;
  im=0;
  for(iy=0;iy<BOARDSZ&&acb[iy][0];++iy)
    for(ix=0;ix<BOARDSZ&&acb[iy][ix];++ix){
      if(acb[iy][ix]=='*')
        ++im;
      if(acb[iy][ix]=='0')
        pch=&acb[iy][ix];
    }
  if(!pch){
    printf("no hole\n");
    exit(0);
  }
  hunt();
}
