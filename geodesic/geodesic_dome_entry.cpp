// Please note that I didn't optimize this program as I don't have time to do it.

#include "triangular_geodesic_dome.hpp"
#include "geodesic_shape_manager.hpp"
#include <iostream>

// I allow myself to put this char on globally due to the fact that this project hasn't a library provided.
char method = '/';
char surface_method = '/';
double surface = 0; 
double triangle_perimeters = 0;
double triangle_height = 0;

// Calculated values
double calculated_radius = 0;

using namespace geodesic;

void choose_dome_method() {
  std::cout << "=> [1] 4V Icosaedric Geodesic Dome \n";
  std::cout << "=> [2] Exit (I will add more options later on)\n: ";
  std::cin >> method;
}

void choose_surface_method() {
  std::cout << "=> [1] In meters \n";
  std::cout << "=> [2] In centimeters\n: ";
  std::cin >> surface_method;
  TriangularGeodesicDome::surface_method = surface_method;
}

void choose_surface_value(char s_v_method) {
  std::cout << "Please choose the surface value (value has to be in squared meters)\n : ";
  std::cin >> surface;
  if (s_v_method == '1') {
    calculated_radius = TriangularGeodesicDome::calculate_surface_to_meters(surface);
    std::cout << "Succesfully calculated surface [Radius = " << calculated_radius << "m" << "]\n";
  } else if (s_v_method == '2') {
    calculated_radius = TriangularGeodesicDome::calculate_surface_to_centimeters(surface);
    std::cout << "Succesfully calculated surface [Radius = " << calculated_radius << "cm" << "]\n";
  } else {
    std::cout << "Sorry, invalid value, please choose again.\n";
    choose_surface_value(s_v_method);
  }
}

int main() {
  std::cout << "\n Hi and welcome to Vertueux's geodesic dome calculator \n";
  std::cout << "_____________________________________________________\n \n";
  std::cout << "\n Please choose the method you're gonna use to create your geodesic home: \n";

  choose_dome_method();

  // I used the switch method for some modular purposes (easily make changes in the future).
  switch (method) {
    case '1': 
      GeodesicManager::get()->set(DomeType::TRIANGULAR_GEODESIC);
      std::cout << "Succesfully choose the 4V Icosaedric Geodesic Dome method. \n";
      break;
    case '2':
      std::cout << "Exiting... \n";
      return 0;
      break;
    default: 
      std::cout << "Sorry, invalid number, please choose between 1 and 2 \n";
      choose_dome_method();
      GeodesicManager::get()->set(DomeType::OTHER_GEODESIC);
      break;
  }

  std::cout << "Now, choose the calculation method of your surface: \n";

  choose_surface_method();

  switch (surface_method) {
    case '1': 
      std::cout << "The dome surface will be calculated in meters \n";
      break;
    case '2':
      std::cout << "The dome surface will be calculated in centimeters \n";
      break;
    default: 
      std::cout << "Sorry, invalid number, please choose between 1 and 2 \n";
      choose_surface_method();
      break;
  }

  choose_surface_value(surface_method);

  TriangularGeodesicDome::calculate_struts(calculated_radius);
  return 0;
}