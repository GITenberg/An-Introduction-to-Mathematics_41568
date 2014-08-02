/* -*-ePiX-*- */
#include "conic.h"

conic::conic(double cA, double cB, double cC, double cD) :
  m_A(cA), m_B(cB), m_C(cC), m_D(cD),
  m_rad(hypot(cA, cB)),
  m_psi(cB >= 0 ? Acos(cA/m_rad) : -Acos(cA/m_rad)) { }

void conic::draw(double tmin, double tmax, unsigned int num_pts) const
{
  const double dt((tmax - tmin)/num_pts);
  double t(tmin);
  path bd;
  for (unsigned int i = 0; i <= num_pts; ++i, t += dt)
    bd.pt(eval(t));

  bd.draw();
}

Segment conic::join(double ht) const
{
  double tmp(Acos(((m_D/ht) - m_C)/m_rad));
  return Segment(eval(tmp + m_psi), eval(-tmp + m_psi));
}

P conic::eval(double t) const
{
  double C(Cos(t)), S(Sin(t)), rad(m_D/(m_C + m_A*C + m_B*S));
  return rad*P(C, S, 1);
}

double conic::psi() const
{
  return m_psi;
}

