#pragma once 

#define A_FACTOR 0.25318
#define B_FACTOR 0.29524
#define C_FACTOR 0.29453
#define D_FACTOR 0.31287
#define E_FACTOR 0.32492
#define F_FACTOR 0.29859

namespace geodesic {
  class TriangularGeodesicDome {
    public:
      static char surface_method;
      
      TriangularGeodesicDome();
      static double calculate_surface_to_meters(const double& surface);
      static double calculate_surface_to_centimeters(const double& surface);
      static void calculate_struts(const double& radius);
  };
}