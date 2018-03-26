#include "FlyBehavior.h"
#include "AimFly.h"
#include "Resource.h"
#include "Point.h"

AimFly::AimFly(Point& a,Point* b, double xp,double yp) :FlyBehavior(a),aim_(b), xp_(xp),yp_(yp) {};

AimFly::~AimFly() {};

void AimFly::Fly()
{
	if (a_->X() < aim_->X())
	{
		a_->MoveX(xp_);
	}
	else if (a_->X() > aim_->X())
	{
		a_->MoveX(-xp_);
	}
	if (a_->Y() < aim_->Y())
	{
		a_->MoveY(yp_);
	}
	else if (a_->Y() > aim_->Y())
	{
		a_->MoveY(-yp_);
	}
}