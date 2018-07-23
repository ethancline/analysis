#ifndef __TRACKPROJECTORPlaneECAL_H_
#define __TRACKPROJECTORPlaneECAL_H_

/* STL includes */
#include <string>
#include <memory>

/* Forward declarations */
class PHCompositeNode;
class PHFieldUtility;
class SvtxTrack;
class SvtxTrackState;
class RawCluster;
class SvtxTrackMap;

namespace PHGenFit{
  class Fitter;
}

namespace genfit{
  class MeasuredStateOnPlane;
}

class TrackProjectorPlaneECAL {

public:

  enum PROJECTION_SURFACE {SPHERE, CYLINDER, PLANEXY, PLANE_CYLINDER};
  enum PROJECTION_DETECTOR{EEMC, CEMC, FEMC};
  
  TrackProjectorPlaneECAL( PHCompositeNode* topNode );

  bool get_projected_position( SvtxTrack * track, RawCluster* cluster, double arr_pos[3], const PROJECTION_SURFACE surf, const float surface_par ); // Get mean track position

  bool get_projected_momentum( SvtxTrack * track, RawCluster* cluster, double arr_mom[3], const PROJECTION_SURFACE surf, const float surface_par ); // Get momentum of track

  SvtxTrack * get_best_track( SvtxTrackMap * trackmap, RawCluster* cluster); // Get track closest to cluster (within deltaR)

  char get_detector(); // Return capitalized letter of detector

  SvtxTrackState* project_track( SvtxTrack * track, RawCluster* cluster, const PROJECTION_SURFACE surf, const float surface_par );

  void set_detector( char c ); //Sets the detector name

private:

  PHGenFit::Fitter * _fitter;
  enum PROJECTION_DETECTOR detector;
};

#endif
