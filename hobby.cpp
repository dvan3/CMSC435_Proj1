#include "ri.h"
RtPoint Square[4]={{.5,.5,.5},{.5,-.5,.5},{-.5,-
					   .5,.5},{-.5,.5,.5}};
static RtColor Color = {0, 0, 1};
static RtColor Color2 = {1, 0, 0};

void square();
void cylinder();

main () 
{
   square();
}

void cylinder()
{
   RtFloat radius=1.0, zmin=-1, zmax=1, thetamax=360;
   RiBegin(RI_NULL); /* start the renderer */
   RiLightSource ("distantlight", RI_NULL);
   //RiProjection("perspective", RI_NULL);
   RiTranslate(0,0,0);
   RiRotate (0.0, 0, 0, 0);
   RiWorldBegin();
   RiSurface ("matte", RI_NULL);
   RiColor (Color); /* declare color */
   RiCylinder (radius, zmin, zmax, thetamax, RI_NULL);
   RiWorldEnd();
   RiEnd();
}

void square()
{
   RiBegin(RI_NULL); /* start the renderer */
   RiLightSource ("distantlight", RI_NULL);
   RiProjection("perspective", RI_NULL);
   RiTranslate(0,0,1);
   RiRotate (0, -1, 1, 0);
   RiWorldBegin();
   RiSurface ("chrome", RI_NULL);
   RiColor (Color); /* declare color */
   RiPolygon (4, /* declare the square */
	      RI_P, (RtPointer) Square, RI_NULL);
   RiWorldEnd();
   RiEnd();

}
