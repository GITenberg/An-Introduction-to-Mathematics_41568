/* -*-ePiX-*- */
#include "epix.h"
using namespace ePiX;

class conic {
public:
  // A^2 + B^2 must be != 0
  conic(double cA, double cB, double cC, double cD);

  void draw(double tmin, double tmax, unsigned int num_pts) const;
  Segment join(double ht) const;

  P eval(double t) const;

  double psi() const;

private:
  double m_A, m_B, m_C, m_D;
  double m_rad, m_psi;
};
