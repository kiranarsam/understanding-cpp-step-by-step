// This class provides API to deal with various image operations
// Different platforms can implement these operations in different ways.
// image.h : A header file to store class declaration
class CImage {
    public:
        CImage();
        ~CImage();
        struct SImageInfo* pImageInfo;
        void Rotate(double angle);
        void Scale(double scaleFactorX, double scaleFactorY);
        void Move(int toX, int toY);
    private:
        void InitImageInfo();
};
//=============================================================//
// image.cpp : code that will be shared across different end-points
// Constructor and Destructor for CImage
CImage::CImage() {
    InitImageInfo();
}

CImage::~CImage() {
    // Destroy stuffs here
}
//==================================================================//
// image_windows.cpp : Code specific to Windows will resides here

struct SImageInfo {
    // Windows specific DataSet
};

void CImage::InitImageInfo() {
    pImageInfo = new SImageInfo;
    // Initialise windows specific info here
}

void CImage::Rotate(double angle) {
    // Make use of windows specific SImageInfo
}
//==============================================================//
// image_apple.cpp " Code specific to Apple will resides here "
struct SImageInfo 
{ 
	// Apple specific DataSet 
}; 
void CImage::InitImageInfo() 
{ 
	pImageInfo = new SImageInfo; 
	
	// Initialize apple specific info here 
} 
void CImage::Rotate(double angle) 
{ 
	// Make use of apple specific SImageInfo 
}
//============================================================//
/*
The content of SImageInfo data structure is unknown. 
Now it is the responsibility of clients(windows, apple, android) to define 
that data structure and use it as per their requirement.
*/