#include "triangular_geodesic_dome.hpp"
#include "geodesic_shape_manager.hpp"

#include <math.h>
#include <iostream>

namespace geodesic {

  char TriangularGeodesicDome::surface_method = '/';
  TriangularGeodesicDome::TriangularGeodesicDome() {
    if (GeodesicManager::actual_type != DomeType::TRIANGULAR_GEODESIC) {
      GeodesicManager::get()->set(DomeType::TRIANGULAR_GEODESIC);
    }
  }

  double TriangularGeodesicDome::calculate_surface_to_meters(const double& surface) {
    return sqrt(surface / M_PI);
  }

  double TriangularGeodesicDome::calculate_surface_to_centimeters(const double& surface) {
    return calculate_surface_to_meters(surface) * 100;
  }

  void TriangularGeodesicDome::calculate_struts(const double& radius) {
    using namespace std;

    if (surface_method == '1') {
      cout << "\n * A: " << radius * A_FACTOR << "m\n";
      cout << " * B: " << radius * B_FACTOR << "m\n";
      cout << " * C: " << radius * C_FACTOR << "m\n";
      cout << " * D: " << radius * D_FACTOR << "m\n";
      cout << " * E: " << radius * E_FACTOR << "m\n";
      cout << " * F: " << radius * F_FACTOR << "m\n\n";
    } else {
      cout << "\n * A: " << (radius * A_FACTOR) << "cm\n";
      cout << " * B: " << (radius * B_FACTOR) << "cm\n";
      cout << " * C: " << (radius * C_FACTOR) << "cm\n";
      cout << " * D: " << (radius * D_FACTOR) << "cm\n";
      cout << " * E: " << (radius * E_FACTOR) << "cm\n";
      cout << " * F: " << (radius * F_FACTOR) << "cm\n\n";
    }
  }
}