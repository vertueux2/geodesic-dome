#pragma once

namespace geodesic {
    enum class DomeType {
      OTHER_GEODESIC = 0,
      TRIANGULAR_GEODESIC = 1
    };

    class GeodesicManager {
      public:
        static DomeType actual_type;
        GeodesicManager(const GeodesicManager&) = delete;
        GeodesicManager& operator=(const GeodesicManager&) = delete;

        void set(DomeType new_type);
        static GeodesicManager *get();

      private:
        static GeodesicManager *singleton;
        GeodesicManager() {}
    };
}