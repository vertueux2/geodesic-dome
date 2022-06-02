#include "geodesic_shape_manager.hpp"

namespace geodesic {
  GeodesicManager *GeodesicManager::singleton = nullptr;
  DomeType GeodesicManager::actual_type = DomeType::OTHER_GEODESIC;
  
  GeodesicManager *GeodesicManager::get() {
    if (!singleton) 
      singleton = new GeodesicManager;
    return singleton;
  }

  void GeodesicManager::set(DomeType new_type) {
    actual_type = new_type;
  }
}