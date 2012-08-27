/** 
* @file CatPictureApp.cpp
* A simple app to display a cat picture using cinder
* 
* @author Adam Brush
* @date 2012-08-27
* 
* @note This file is (c) 2012. It is licensed under the
* CC BY 3.0 licenses (http://creativecommons.org/licenses/by/3.0/),
* which means you are free to use, share, and remix it as long as you
* give attribution. Commercial uses are allowed.
*/

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

private:
	/// Brightness of the screen. Must be between 0.0f (black) and 1.0f (white), inclusive.
	float brightnessR_;
	float brightnessG_;
	float brightnessB_;
};

void CatPictureApp::setup()
{
	brightnessR_ = 0.0f;
	brightnessG_ = 0.0f;
	brightnessB_ = 0.0f;
}

void CatPictureApp::mouseDown( MouseEvent event )
{
}

void CatPictureApp::update()
{
	brightnessR_ = brightnessR_ - 0.01f;
	if(brightnessR_<0.0f)
		brightnessR_ = 1.0f;
	brightnessG_ = brightnessG_ + 0.01f;
	if(brightnessG_>1.0f)
		brightnessG_ = 0.0f;
	brightnessB_ = brightnessB_ - 0.01f;
	if(brightnessB_<0.0f)
		brightnessB_ = 1.0f;
}

void CatPictureApp::draw()
{
	// clear out the window with black
	gl::clear( Color( brightnessR_, brightnessG_, brightnessB_ ) ); 
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
