/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CNAVIGATIONSYSTEM.H
* Author          : Shahid Mobin
* Description     :
*
*
****************************************************************************/

#ifndef CNAVIGATIONSYSTEM_H
#define CNAVIGATIONSYSTEM_H
#include "CRoute.h"
#include "CGPSSensor.h"
#include "CPoiDatabase.h"
class CNavigationSystem:public CRoute {
public:

    CNavigationSystem();

    void run();

private:
    void printDistanceCurPosNextPoi();
    void printRoute();
    void enterRoute();
    CRoute m_route;
    CGPSSensor m_GPSSensor;
    CPoiDatabase m_PoiDatabase;
};
/********************
**  CLASS END
*********************/
#endif /* CNAVIGATIONSYSTEM_H */
