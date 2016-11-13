//Dave Van
//
//I received no help

#include "ri.h"

#define L -.005
#define R .3
#define D -.005
#define U .9
#define N -.005
#define F .005

static RtColor Street = {.244, .244, .244};
static RtColor Wheel = {.600, .600, 0};
static RtColor Board = {.250, .200, .160};

static RtPoint Cube[6][4] = {
   {{L,D,F}, {R,D,F}, {R,D,N}, {L,D,N}}, // bottom
   {{L,D,F}, {L,U,F}, {L,U,N}, {L,D,N}}, // left
   {{R,U,N}, {L,U,N}, {L,U,F}, {R,U,F}}, // top
   {{R,U,N}, {R,U,F}, {L,U,F}, {L,D,F}}, // right
   {{R,D,F}, {R,U,F}, {L,U,F}, {L,D,F}}, // far
   {{L,U,N}, {R,U,N}, {R,D,N}, {L,D,N}}};  //near

RtPoint Square[4]={{.8,.9,.8},
		   {.8,-.8,.8},
		   {-.8,-.8,.8},
		   {-.8,.8,.8}};

RtPoint Square2[4]={{.05,.9,.7},
		    {.05,-.9,.7},
		    {-.7,-.9,.7},
		    {-.7,.9,.7}};

main () 
{
   RiBegin(RI_NULL); /* start the renderer */
   RiLightSource("distantlight", RI_NULL);
   RiProjection("perspective", RI_NULL);
   RiTranslate(0.0,.5,.5);
   RiRotate (70, .2, -.2, .3);
   RiWorldBegin();

   //street
   RiTranslate(.30,0,-.1);
   RiSurface ("matte", RI_NULL);
   RiColor (Street); /* declare color */
   RiPolygon (4, /* declare the square */
              RI_P, (RtPointer) Square2, RI_NULL);

   //Board
   RiTransformBegin();
   RiLightSource("ambientlight", RI_NULL);
   RiTranslate(-.437, -.3, .59);
   RiSurface("matte", RI_NULL);
   RiColor(Board);
   int i;
   for (i = 0; i < 6; i++)
   {
      RiPolygon(4,RI_P,(RtPointer)Cube[i],RI_NULL);
   }
   RiTransformEnd();

   //Wheel 1
   RiTransformBegin();
   RiLightSource("spotlight", RI_NULL);
   RiTranslate(-.83, .4, .65);
   RiRotate(120, .1, .1, .1);
   RiSurface("matte", RI_NULL);
   RiColor(Wheel);
   RiCylinder(.05, .7, .6, 360, RI_NULL);
   RiTransformEnd();

   //Wheel 2
   RiTransformBegin();
   RiLightSource("spotlight", RI_NULL);
   RiTranslate(-1.05, .4, .65);
   RiRotate(120, .1, .1, .1);
   RiSurface("matte", RI_NULL);
   RiColor(Wheel);
   RiCylinder(.05, .7, .6, 360, RI_NULL);
   RiTransformEnd();

   //Wheel 3
   RiTransformBegin();
   RiLightSource("spotlight", RI_NULL);
   RiTranslate(-1.05, -.1, .65);
   RiRotate(120, .1, .1, .1);
   RiSurface("matte", RI_NULL);
   RiColor(Wheel);
   RiCylinder(.05, .7, .6, 360, RI_NULL);
   RiTransformEnd();

   //Wheel 4
   RiTransformBegin();
   RiLightSource("spotlight", RI_NULL);
   RiTranslate(-.83, -.1, .65);
   RiRotate(120, .1, .1, .1);
   RiSurface("matte", RI_NULL);
   RiColor(Wheel);
   RiCylinder(.05, .7, .6, 360, RI_NULL);
   RiTransformEnd();

   RiWorldEnd();
   RiEnd();
}
